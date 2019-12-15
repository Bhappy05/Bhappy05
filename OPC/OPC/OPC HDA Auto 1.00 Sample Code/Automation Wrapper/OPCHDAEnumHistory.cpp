/*  ____________________________________________________________________________

    OPCHDAEnumHistory.cpp

    COPCHDAEnumHistory class implementation.
    ____________________________________________________________________________

    Copyright © 2000 The OPC Foundation

    #292, 20423 State Road 7
    Bacon Raton, FL
    United States 33498
    (561) 477-1375 Phone
    (561) 477-0520 Fax
    www.opcfoundation.org
    opc@powerinternet.com
    ____________________________________________________________________________

    Disclaimer

    This sample code is provided by the OPC Foundation solely to assist
    in understanding the OPC Specifications and may be used
    as set forth in the License Grant section of the OPC Specification.
    This code is provided as-is and without warranty or support of any sort
    and is subject to the Warranty and Liability Disclaimers which appear
    in the printed OPC Specification.
    ____________________________________________________________________________

    Credits

    This code was generously provided to the OPC Foundation by
    Jeff Caulfield, Matrikon Consulting Inc.
    ____________________________________________________________________________

    revision history

    2000-11-15 Jeff Caulfield
    ____________________________________________________________________________
*/
#include "stdafx.h"
#include "OPCHDAEnumHistory.h"

#include "OPCHDAHistory.h"

COPCHDAEnumHistory::COPCHDAEnumHistory()
{
    m_index = 1;
    m_pHistory = NULL;
}

COPCHDAEnumHistory::~COPCHDAEnumHistory()
{
    if (NULL != m_pHistory)
    {
        m_pHistory->Release();
    }
}

STDMETHODIMP COPCHDAEnumHistory::Initialize(
    COPCHDAHistory* pHistory,
    LONG index)
{
    pHistory->AddRef();
    m_pHistory = pHistory;

    m_index = index;

    return S_OK;
}

STDMETHODIMP COPCHDAEnumHistory::Next( 
    ULONG celt,
    VARIANT * rgVar,
    ULONG * pCeltFetched)
{
    HRESULT hr = E_FAIL;

    LONG lCount = 0;

    hr = m_pHistory->get_Count(&lCount);

    if (SUCCEEDED(hr))
    {
        OPCHDAValue* pOPCHDAValue;
        VARIANT v;
        ULONG elt;

        VariantInit(&v);

        for (elt = 0; elt < celt; elt++)
        {
            VariantInit(&rgVar[elt]);
        }

        elt = 0;

        while ((elt < celt) && (m_index <= lCount))
        {
            v.vt = VT_UI4;
            v.ulVal = m_index;

            if (SUCCEEDED(m_pHistory->Item(v, &pOPCHDAValue)))
            {
                rgVar[elt].vt = VT_DISPATCH;
                rgVar[elt].pdispVal = pOPCHDAValue;
            }

            elt++;
            m_index++;
        }

        if (NULL != pCeltFetched)
        {
            *pCeltFetched = elt;
        }

        hr = (elt < celt) ? S_FALSE : S_OK;

        VariantClear(&v);
    }

    return hr;
}

STDMETHODIMP COPCHDAEnumHistory::Skip( 
    ULONG celt)
{
    HRESULT hr = E_FAIL;

    LONG lCount = 0;

    hr = m_pHistory->get_Count(&lCount);

    if (SUCCEEDED(hr))
    {
        m_index += celt;

        if (m_index > lCount)
        {
            m_index = lCount;

            hr = S_FALSE;
        }
        else
        {
            hr = S_OK;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAEnumHistory::Reset()
{
    m_index = 1;

    return S_OK;
}

STDMETHODIMP COPCHDAEnumHistory::Clone( 
    IEnumVARIANT ** ppEnum)
{
    if (NULL == ppEnum)
    {
        return E_POINTER;
    }

    *ppEnum = NULL;

    HRESULT hr = E_FAIL;

    CComObject<COPCHDAEnumHistory>* pEnum = NULL;

    hr = CComObject<COPCHDAEnumHistory>::CreateInstance(&pEnum);

    if (SUCCEEDED(hr))
    {
        pEnum->Initialize(m_pHistory, m_index);

        hr = pEnum->QueryInterface(IID_IEnumVARIANT, reinterpret_cast<void**>(ppEnum));
        _ASSERTE(*ppEnum);
    }

    return hr;
}
