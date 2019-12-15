/*  ____________________________________________________________________________

    OPCHDAHistory.cpp

    COPCHDAHistory class implementation.
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
#include "OPCHDAHistory.h"

#include "OPCHDAEnumHistory.h"
#include "OPCHDAValue.h"
#include "OPCHDAEntry.h"

int __cdecl bsearchCompareTimeStamps(const void* elem1, const void* elem2)
{
    SYSTEMTIME st;
    FILETIME ft;
    DATE date1, date2;

    date1 = *reinterpret_cast<CONST DATE*>(elem1);

    FileTimeToLocalFileTime(reinterpret_cast<CONST FILETIME*>(elem2), &ft);
    FileTimeToSystemTime(&ft, &st);
    SystemTimeToVariantTime(&st, &date2);

    return ((date1 < date2) ? -1 : ((date2 < date1) ? 1 : 0));
}

COPCHDAHistory::COPCHDAHistory()
{
    m_dwCount = 0;
    m_entries = false;

    m_pftTimeStamps = NULL;
    m_pvDataValues = NULL;
    m_pdwQualities = NULL;

    m_pftEntryTimes = NULL;
    m_pdwEntryTypes = NULL;
    m_pszUsers = NULL;
}

COPCHDAHistory::~COPCHDAHistory()
{
    if (NULL != m_pftTimeStamps) delete m_pftTimeStamps;
    if (NULL != m_pvDataValues) delete [] m_pvDataValues;
    if (NULL != m_pdwQualities) delete m_pdwQualities;

    if (NULL != m_pftEntryTimes) delete m_pftEntryTimes;
    if (NULL != m_pdwEntryTypes) delete m_pdwEntryTypes;
    if (NULL != m_pszUsers) delete [] m_pszUsers;
}

STDMETHODIMP COPCHDAHistory::Initialize(OPCHDA_ITEM* pItemValue) 
{
    m_dwCount = pItemValue->dwCount;

    m_pftTimeStamps = new FILETIME[m_dwCount];
    m_pvDataValues = new CComVariant[m_dwCount];
    m_pdwQualities = new DWORD[m_dwCount];

    memcpy(m_pftTimeStamps, pItemValue->pftTimeStamps, sizeof(FILETIME) * m_dwCount);

    for (DWORD dwIndex = 0; dwIndex < m_dwCount; dwIndex++)
    {
        m_pvDataValues[dwIndex] = pItemValue->pvDataValues[dwIndex];
    }

    memcpy(m_pdwQualities, pItemValue->pdwQualities, sizeof(DWORD) * m_dwCount);

    return S_OK;
}

STDMETHODIMP COPCHDAHistory::Initialize(OPCHDA_ATTRIBUTE* pAttributeValue) 
{
    m_dwCount = pAttributeValue->dwNumValues;

    m_pftTimeStamps = new FILETIME[m_dwCount];
    m_pvDataValues = new CComVariant[m_dwCount];

    memcpy(m_pftTimeStamps, pAttributeValue->ftTimeStamps, sizeof(FILETIME) * m_dwCount);

    for (DWORD dwIndex = 0; dwIndex < m_dwCount; dwIndex++)
    {
        m_pvDataValues[dwIndex] = pAttributeValue->vAttributeValues[dwIndex];
    }

    return S_OK;
}

STDMETHODIMP COPCHDAHistory::Initialize(OPCHDA_MODIFIEDITEM* pItemValue) 
{
    m_dwCount = pItemValue->dwCount;
    m_entries = true;

    m_pftTimeStamps = new FILETIME[m_dwCount];
    m_pvDataValues = new CComVariant[m_dwCount];
    m_pdwQualities = new DWORD[m_dwCount];
    m_pftEntryTimes = new FILETIME[m_dwCount];
    m_pdwEntryTypes = new DWORD[m_dwCount];
    m_pszUsers = new CComBSTR[m_dwCount];

    memcpy(m_pftTimeStamps, pItemValue->pftTimeStamps, sizeof(FILETIME) * m_dwCount);
    memcpy(m_pdwQualities, pItemValue->pdwQualities, sizeof(DWORD) * m_dwCount);
    memcpy(m_pftEntryTimes, pItemValue->pftModificationTime, sizeof(FILETIME) * m_dwCount);
    memcpy(m_pdwEntryTypes, pItemValue->pEditType, sizeof(DWORD) * m_dwCount);

    for (DWORD dwIndex = 0; dwIndex < m_dwCount; dwIndex++)
    {
        m_pvDataValues[dwIndex] = pItemValue->pvDataValues[dwIndex];

        m_pszUsers[dwIndex] = pItemValue->szUser[dwIndex];
    }

    return S_OK;
}

STDMETHODIMP COPCHDAHistory::Initialize(OPCHDA_ANNOTATION* pAnnotationValue) 
{
    m_dwCount = pAnnotationValue->dwNumValues;
    m_entries = true;

    m_pftTimeStamps = new FILETIME[m_dwCount];
    m_pvDataValues = new CComVariant[m_dwCount];
    m_pftEntryTimes = new FILETIME[m_dwCount];
    m_pszUsers = new CComBSTR[m_dwCount];

    memcpy(m_pftTimeStamps, pAnnotationValue->ftTimeStamps, sizeof(FILETIME) * m_dwCount);
    memcpy(m_pftEntryTimes, pAnnotationValue->ftAnnotationTime, sizeof(FILETIME) * m_dwCount);

    for (DWORD dwIndex = 0; dwIndex < m_dwCount; dwIndex++)
    {
        m_pvDataValues[dwIndex] = pAnnotationValue->szAnnotation[dwIndex];

        m_pszUsers[dwIndex] = pAnnotationValue->szUser[dwIndex];
    }

    return S_OK;
}

STDMETHODIMP COPCHDAHistory::get_Count(LONG * pCount)
{
    if (NULL == pCount)
    {
        return E_POINTER;
    }

    *pCount = m_dwCount;

    return S_OK;
}

STDMETHODIMP COPCHDAHistory::get__NewEnum(IUnknown ** ppUnk)
{
    if (NULL == ppUnk)
    {
        return E_POINTER;
    }

    *ppUnk = NULL;

    HRESULT hr = E_FAIL;

    CComObject<COPCHDAEnumHistory>* pEnum = NULL;

    hr = CComObject<COPCHDAEnumHistory>::CreateInstance(&pEnum);

    if (SUCCEEDED(hr))
    {
        pEnum->Initialize(this);

        hr = pEnum->QueryInterface(IID_IUnknown, reinterpret_cast<void**>(ppUnk));
        _ASSERTE(*ppUnk);
    }

    return hr;
}

STDMETHODIMP COPCHDAHistory::Item(
    VARIANT ItemSpecifier,
    OPCHDAValue ** ppValue)
{
    if (NULL == ppValue)
    {
        return E_POINTER;
    }

    if ((VT_DATE != ItemSpecifier.vt) &&
        ((FAILED(VariantChangeType(&ItemSpecifier, &ItemSpecifier, 0, VT_UI4)) ||
         (ItemSpecifier.ulVal < 1) ||
         (ItemSpecifier.ulVal > m_dwCount))))
    {
        return E_INVALIDARG;
    }

    *ppValue = NULL;

    HRESULT hr = S_OK;

    LONG index = 0;

    if (VT_DATE == ItemSpecifier.vt)
    {
        FILETIME* pft;

        pft = (FILETIME*)bsearch(&ItemSpecifier.date, m_pftTimeStamps, m_dwCount, sizeof(FILETIME), bsearchCompareTimeStamps);

        if (NULL != pft)
        {
            index = pft - m_pftTimeStamps;
        }
        else
        {
            hr = E_FAIL;
        }
    }
    else
    {
        index = ItemSpecifier.ulVal - 1;
    }

    if (SUCCEEDED(hr))
    {
        if (!m_entries)
        {
            CComObject<COPCHDAValue>* pValue = NULL;

            hr = CComObject<COPCHDAValue>::CreateInstance(&pValue);

            if (SUCCEEDED(hr))
            {
                FILETIME ft;
                SYSTEMTIME st;
                DATE TimeStamp;
                DWORD Quality;

                FileTimeToLocalFileTime(&m_pftTimeStamps[index], &ft);
                FileTimeToSystemTime(&ft, &st);
                SystemTimeToVariantTime(&st, &TimeStamp);

                if (NULL != m_pdwQualities)
                {
                    Quality = m_pdwQualities[index];
                }
                else
                {
                    Quality = Q_GOOD;
                }

                pValue->Initialize(TimeStamp, m_pvDataValues[index], Quality);

                hr = pValue->QueryInterface(IID_OPCHDAValue, reinterpret_cast<void**>(ppValue));
                _ASSERTE(*ppValue);
            }
        }
        else
        {
            CComObject<COPCHDAEntry>* pEntry = NULL;

            hr = CComObject<COPCHDAEntry>::CreateInstance(&pEntry);

            if (SUCCEEDED(hr))
            {
                FILETIME ft;
                SYSTEMTIME st;
                DATE TimeStamp;
                DWORD Quality;
                DATE EntryTime;
                DWORD EntryType;

                FileTimeToLocalFileTime(&m_pftTimeStamps[index], &ft);
                FileTimeToSystemTime(&ft, &st);
                SystemTimeToVariantTime(&st, &TimeStamp);

                if (NULL != m_pdwQualities)
                {
                    Quality = m_pdwQualities[index];
                }
                else
                {
                    Quality = Q_GOOD;
                }

                FileTimeToLocalFileTime(&m_pftEntryTimes[index], &ft);
                FileTimeToSystemTime(&ft, &st);
                SystemTimeToVariantTime(&st, &EntryTime);

                if (NULL != m_pdwEntryTypes)
                {
                    EntryType = m_pdwEntryTypes[index];
                }
                else
                {
                    EntryType = OPCHDAAnnotate;
                }

                pEntry->Initialize(TimeStamp, m_pvDataValues[index], Quality, EntryTime, EntryType, m_pszUsers[index]);

                hr = pEntry->QueryInterface(IID_OPCHDAValue, reinterpret_cast<void**>(ppValue));
                _ASSERTE(*ppValue);
            }
        }
    }

    return hr;
}
