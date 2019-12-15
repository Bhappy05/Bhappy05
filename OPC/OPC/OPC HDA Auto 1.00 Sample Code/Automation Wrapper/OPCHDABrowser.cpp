/*  ____________________________________________________________________________

    OPCHDABrowser.cpp

    COPCHDABrowser class implementation.
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
#include "OPCHDABrowser.h"

COPCHDABrowser::COPCHDABrowser()
{
}

COPCHDABrowser::~COPCHDABrowser()
{
}

STDMETHODIMP COPCHDABrowser::Initialize( 
    IOPCHDA_Browser* pOPCHDA_Browser)
{
    pOPCHDA_Browser->AddRef();
    m_pOPCHDA_Browser = pOPCHDA_Browser;

    return S_OK;
}

STDMETHODIMP COPCHDABrowser::get_CurrentPosition(BSTR * pCurrentPosition)
{
    if (NULL == pCurrentPosition)
    {
        return E_POINTER;
    }

    *pCurrentPosition = NULL;

    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Browser)
    {
        LPWSTR szBranchPos = NULL;

        hr = m_pOPCHDA_Browser->GetBranchPosition(&szBranchPos);

        if (SUCCEEDED(hr))
        {
            *pCurrentPosition = SysAllocString(szBranchPos);

            CoTaskMemFree(szBranchPos);
        }
    }

    return hr;
}

STDMETHODIMP COPCHDABrowser::get_OPCHDABranches(VARIANT * pOPCHDABranches)
{
    if (NULL == pOPCHDABranches)
    {
        return E_POINTER;
    }

    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Browser)
    {
        IEnumString* pEnumString = NULL;

        hr = m_pOPCHDA_Browser->GetEnum(OPCHDA_BRANCH, &pEnumString);

        if (SUCCEEDED(hr))
        {
            ULONG count, index;
            LPWSTR szNode;
            LPWSTR szNodes[NEXT_COUNT];

            std::list<LPWSTR> NodeList;
            std::list<LPWSTR>::iterator it;

            do
            {
                count = 0;

                hr = pEnumString->Next(NEXT_COUNT, szNodes, &count);

                for (index = 0; index < count; index++)
                {
                    NodeList.push_back(szNodes[index]);
                }
            }
            while (S_OK == hr);

            if (SUCCEEDED(hr))
            {
                SAFEARRAY* parray = SafeArrayCreateVector(VT_BSTR, 1, NodeList.size());

                if (NULL != parray)
                {
                    LONG lIndex = 0;
                    BSTR bstr;

                    for (it = NodeList.begin(); NodeList.end() != it; it++)
                    {
                        lIndex++;

                        szNode = *it;

                        bstr = SysAllocString(szNode);

                        CoTaskMemFree(szNode);

                        SafeArrayPutElement(parray, &lIndex, reinterpret_cast<void*>(bstr));
                    }

                    VariantClear(pOPCHDABranches);

                    pOPCHDABranches->vt = VT_ARRAY | VT_BSTR;
                    pOPCHDABranches->parray = parray;
                }
                else
                {
                    hr = E_FAIL;
                }
            }

            if (FAILED(hr))
            {
                for (it = NodeList.begin(); NodeList.end() != it; it++)
                {
                    szNode = *it;

                    CoTaskMemFree(szNode);
                }
            }

            pEnumString->Release();
        }
    }

    return hr;
}

STDMETHODIMP COPCHDABrowser::get_OPCHDALeaves(VARIANT * pOPCHDALeaves)
{
    if (NULL == pOPCHDALeaves)
    {
        return E_POINTER;
    }

    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Browser)
    {
        IEnumString* pEnumString = NULL;

        hr = m_pOPCHDA_Browser->GetEnum(OPCHDA_LEAF, &pEnumString);

        if (SUCCEEDED(hr))
        {
            ULONG count, index;
            LPWSTR szNode;
            LPWSTR szNodes[NEXT_COUNT];

            std::list<LPWSTR> NodeList;
            std::list<LPWSTR>::iterator it;

            do
            {
                count = 0;

                hr = pEnumString->Next(NEXT_COUNT, szNodes, &count);

                for (index = 0; index < count; index++)
                {
                    NodeList.push_back(szNodes[index]);
                }
            }
            while (S_OK == hr);

            if (SUCCEEDED(hr))
            {
                SAFEARRAY* parray = SafeArrayCreateVector(VT_BSTR, 1, NodeList.size());

                if (NULL != parray)
                {
                    LONG lIndex = 0;
                    BSTR bstr;

                    for (it = NodeList.begin(); NodeList.end() != it; it++)
                    {
                        lIndex++;

                        szNode = *it;

                        bstr = SysAllocString(szNode);

                        CoTaskMemFree(szNode);

                        SafeArrayPutElement(parray, &lIndex, reinterpret_cast<void*>(bstr));
                    }

                    VariantClear(pOPCHDALeaves);

                    pOPCHDALeaves->vt = VT_ARRAY | VT_BSTR;
                    pOPCHDALeaves->parray = parray;
                }
                else
                {
                    hr = E_FAIL;
                }
            }

            if (FAILED(hr))
            {
                for (it = NodeList.begin(); NodeList.end() != it; it++)
                {
                    szNode = *it;

                    CoTaskMemFree(szNode);
                }
            }

            pEnumString->Release();
        }
    }

    return hr;
}

STDMETHODIMP COPCHDABrowser::get_OPCHDAItems(VARIANT * pOPCHDAItems)
{
    if (NULL == pOPCHDAItems)
    {
        return E_POINTER;
    }

    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Browser)
    {
        IEnumString* pEnumString = NULL;

        hr = m_pOPCHDA_Browser->GetEnum(OPCHDA_ITEMS, &pEnumString);

        if (SUCCEEDED(hr))
        {
            ULONG count, index;
            LPWSTR szNode;
            LPWSTR szNodes[NEXT_COUNT];

            std::list<LPWSTR> NodeList;
            std::list<LPWSTR>::iterator it;

            do
            {
                count = 0;

                hr = pEnumString->Next(NEXT_COUNT, szNodes, &count);

                for (index = 0; index < count; index++)
                {
                    NodeList.push_back(szNodes[index]);
                }
            }
            while (S_OK == hr);

            if (SUCCEEDED(hr))
            {
                SAFEARRAY* parray = SafeArrayCreateVector(VT_BSTR, 1, NodeList.size());

                if (NULL != parray)
                {
                    LONG lIndex = 0;
                    BSTR bstr;

                    for (it = NodeList.begin(); NodeList.end() != it; it++)
                    {
                        lIndex++;

                        szNode = *it;

                        bstr = SysAllocString(szNode);

                        CoTaskMemFree(szNode);

                        SafeArrayPutElement(parray, &lIndex, reinterpret_cast<void*>(bstr));
                    }

                    VariantClear(pOPCHDAItems);

                    pOPCHDAItems->vt = VT_ARRAY | VT_BSTR;
                    pOPCHDAItems->parray = parray;
                }
                else
                {
                    hr = E_FAIL;
                }
            }

            if (FAILED(hr))
            {
                for (it = NodeList.begin(); NodeList.end() != it; it++)
                {
                    szNode = *it;

                    CoTaskMemFree(szNode);
                }
            }

            pEnumString->Release();
        }
    }

    return hr;
}

STDMETHODIMP COPCHDABrowser::MoveUp()
{
    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Browser)
    {
        hr = m_pOPCHDA_Browser->ChangeBrowsePosition(OPCHDA_BROWSE_UP, L"");
    }

    return hr;
}

STDMETHODIMP COPCHDABrowser::MoveToRoot()
{
    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Browser)
    {
        hr = m_pOPCHDA_Browser->ChangeBrowsePosition(OPCHDA_BROWSE_DIRECT, L"");
    }

    return hr;
}

STDMETHODIMP COPCHDABrowser::MoveDown(
    BSTR BranchName)
{
    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Browser)
    {
        hr = m_pOPCHDA_Browser->ChangeBrowsePosition(OPCHDA_BROWSE_DOWN, BranchName);
    }

    return hr;
}

STDMETHODIMP COPCHDABrowser::MoveTo(
    BSTR NewPosition)
{
    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Browser)
    {
        hr = m_pOPCHDA_Browser->ChangeBrowsePosition(OPCHDA_BROWSE_DIRECT, NewPosition);
    }

    return hr;
}

STDMETHODIMP COPCHDABrowser::GetItemID(
    BSTR ItemName,
    BSTR * pItemID)
{
    if (NULL == pItemID)
    {
        return E_POINTER;
    }

    *pItemID = NULL;

    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Browser)
    {
        LPWSTR szItemID = NULL;

        hr = m_pOPCHDA_Browser->GetItemID(ItemName, &szItemID);

        if (SUCCEEDED(hr))
        {
            *pItemID = SysAllocString(szItemID);

            CoTaskMemFree(szItemID);
        }
    }

    return hr;
}
