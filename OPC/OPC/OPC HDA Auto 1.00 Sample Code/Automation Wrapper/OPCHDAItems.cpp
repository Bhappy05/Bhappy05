/*  ____________________________________________________________________________

    OPCHDAItems.cpp

    COPCHDAAutoServer class implementation of IOPCHDAItems.
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
#include "OPCHDAAutoServer.h"

#include "OPCHDAItem.h"
#include "OPCHDAHistory.h"

STDMETHODIMP COPCHDAAutoServer::OnDataChange( 
    DWORD dwTransactionID,
    HRESULT hrStatus,
    DWORD dwNumItems,
    OPCHDA_ITEM * pItemValues,
    HRESULT * phrErrors)
{
    SAFEARRAY* pClientHandles = SafeArrayCreateVector(VT_I4, 1, dwNumItems);
    SAFEARRAY* pAggregates = SafeArrayCreateVector(VT_I4, 1, dwNumItems);
    SAFEARRAY* pItemValues2 = SafeArrayCreateVector(VT_VARIANT, 1, dwNumItems);
    SAFEARRAY* pErrors = SafeArrayCreateVector(VT_I4, 1, dwNumItems);

    if ((NULL != pClientHandles) && (NULL != pAggregates) && (NULL != pItemValues2) && (NULL != pErrors))
    {
        LONG index, vbIndex;

        CComObject<COPCHDAHistory>* pHistory;
        OPCHDAHistory* pOPCHDAHistory;
        HRESULT hr;
        VARIANT v;

        VariantInit(&v);

        for (index = 0; index < dwNumItems; index++)
        {
            vbIndex = index + 1;

            if (SUCCEEDED(phrErrors[index]))
            {
                pHistory = NULL;
                pOPCHDAHistory = NULL;

                hr = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                _ASSERTE(SUCCEEDED(hr));

                pHistory->Initialize(&pItemValues[index]);
            
                pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                _ASSERTE(pOPCHDAHistory);

                v.vt = VT_DISPATCH;
                v.pdispVal = pOPCHDAHistory;
            }

            SafeArrayPutElement(pClientHandles, &vbIndex, &pItemValues[index].hClient);
            SafeArrayPutElement(pAggregates, &vbIndex, &pItemValues[index].haAggregate);
            SafeArrayPutElement(pItemValues2, &vbIndex, &v);
            SafeArrayPutElement(pErrors, &vbIndex, &phrErrors[index]);

            VariantClear(&v);
        }

        Fire_DataChange(dwTransactionID, hrStatus, dwNumItems, pClientHandles, pAggregates, pItemValues2, pErrors);
    }

    if (NULL != pClientHandles) SafeArrayDestroy(pClientHandles);
    if (NULL != pAggregates) SafeArrayDestroy(pAggregates);
    if (NULL != pItemValues2) SafeArrayDestroy(pItemValues2);
    if (NULL != pErrors) SafeArrayDestroy(pErrors);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::OnReadComplete( 
    DWORD dwTransactionID,
    HRESULT hrStatus,
    DWORD dwNumItems,
    OPCHDA_ITEM * pItemValues,
    HRESULT * phrErrors)
{
    SAFEARRAY* pClientHandles = SafeArrayCreateVector(VT_I4, 1, dwNumItems);
    SAFEARRAY* pAggregates = SafeArrayCreateVector(VT_I4, 1, dwNumItems);
    SAFEARRAY* pItemValues2 = SafeArrayCreateVector(VT_VARIANT, 1, dwNumItems);
    SAFEARRAY* pErrors = SafeArrayCreateVector(VT_I4, 1, dwNumItems);

    if ((NULL != pClientHandles) && (NULL != pAggregates) && (NULL != pItemValues2) && (NULL != pErrors))
    {
        LONG index, vbIndex;

        CComObject<COPCHDAHistory>* pHistory;
        OPCHDAHistory* pOPCHDAHistory;
        HRESULT hr;
        VARIANT v;

        VariantInit(&v);

        for (index = 0; index < dwNumItems; index++)
        {
            vbIndex = index + 1;

            if (SUCCEEDED(phrErrors[index]))
            {
                pHistory = NULL;
                pOPCHDAHistory = NULL;

                hr = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                _ASSERTE(SUCCEEDED(hr));

                pHistory->Initialize(&pItemValues[index]);
            
                pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                _ASSERTE(pOPCHDAHistory);

                v.vt = VT_DISPATCH;
                v.pdispVal = pOPCHDAHistory;
            }

            SafeArrayPutElement(pClientHandles, &vbIndex, &pItemValues[index].hClient);
            SafeArrayPutElement(pAggregates, &vbIndex, &pItemValues[index].haAggregate);
            SafeArrayPutElement(pItemValues2, &vbIndex, &v);
            SafeArrayPutElement(pErrors, &vbIndex, &phrErrors[index]);

            VariantClear(&v);
        }

        Fire_AsyncReadComplete(dwTransactionID, hrStatus, dwNumItems, pClientHandles, pAggregates, pItemValues2, pErrors);
    }

    if (NULL != pClientHandles) SafeArrayDestroy(pClientHandles);
    if (NULL != pAggregates) SafeArrayDestroy(pAggregates);
    if (NULL != pItemValues2) SafeArrayDestroy(pItemValues2);
    if (NULL != pErrors) SafeArrayDestroy(pErrors);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::OnReadModifiedComplete( 
    DWORD dwTransactionID,
    HRESULT hrStatus,
    DWORD dwNumItems,
    OPCHDA_MODIFIEDITEM * pItemValues,
    HRESULT * phrErrors)
{
    SAFEARRAY* pClientHandles = SafeArrayCreateVector(VT_I4, 1, dwNumItems);
    SAFEARRAY* pItemValues2 = SafeArrayCreateVector(VT_VARIANT, 1, dwNumItems);
    SAFEARRAY* pErrors = SafeArrayCreateVector(VT_I4, 1, dwNumItems);

    if ((NULL != pClientHandles) && (NULL != pItemValues2) && (NULL != pErrors))
    {
        LONG index, vbIndex;

        CComObject<COPCHDAHistory>* pHistory;
        OPCHDAHistory* pOPCHDAHistory;
        HRESULT hr;
        VARIANT v;

        VariantInit(&v);

        for (index = 0; index < dwNumItems; index++)
        {
            vbIndex = index + 1;

            if (SUCCEEDED(phrErrors[index]))
            {
                pHistory = NULL;
                pOPCHDAHistory = NULL;

                hr = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                _ASSERTE(SUCCEEDED(hr));

                pHistory->Initialize(&pItemValues[index]);
            
                pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                _ASSERTE(pOPCHDAHistory);

                v.vt = VT_DISPATCH;
                v.pdispVal = pOPCHDAHistory;
            }

            SafeArrayPutElement(pClientHandles, &vbIndex, &pItemValues[index].hClient);
            SafeArrayPutElement(pItemValues2, &vbIndex, &v);
            SafeArrayPutElement(pErrors, &vbIndex, &phrErrors[index]);

            VariantClear(&v);
        }

        Fire_AsyncReadModifiedComplete(dwTransactionID, hrStatus, dwNumItems, pClientHandles, pItemValues2, pErrors);
    }

    if (NULL != pClientHandles) SafeArrayDestroy(pClientHandles);
    if (NULL != pItemValues2) SafeArrayDestroy(pItemValues2);
    if (NULL != pErrors) SafeArrayDestroy(pErrors);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::OnReadAttributeComplete( 
    DWORD dwTransactionID,
    HRESULT hrStatus,
    OPCHANDLE hClient,
    DWORD dwNumItems,
    OPCHDA_ATTRIBUTE * pAttributeValues,
    HRESULT * phrErrors)
{
    SAFEARRAY* pAttributeIDs = SafeArrayCreateVector(VT_I4, 1, dwNumItems);
    SAFEARRAY* pAttributeValues2 = SafeArrayCreateVector(VT_VARIANT, 1, dwNumItems);
    SAFEARRAY* pErrors = SafeArrayCreateVector(VT_I4, 1, dwNumItems);

    if ((NULL != pAttributeIDs) && (NULL != pAttributeValues2) && (NULL != pErrors))
    {
        LONG index, vbIndex;

        CComObject<COPCHDAHistory>* pHistory;
        OPCHDAHistory* pOPCHDAHistory;
        HRESULT hr;
        VARIANT v;

        VariantInit(&v);

        for (index = 0; index < dwNumItems; index++)
        {
            vbIndex = index + 1;

            if (SUCCEEDED(phrErrors[index]))
            {
                pHistory = NULL;
                pOPCHDAHistory = NULL;

                hr = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                _ASSERTE(SUCCEEDED(hr));

                pHistory->Initialize(&pAttributeValues[index]);
            
                pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                _ASSERTE(pOPCHDAHistory);

                v.vt = VT_DISPATCH;
                v.pdispVal = pOPCHDAHistory;
            }

            SafeArrayPutElement(pAttributeIDs, &vbIndex, &pAttributeValues[index].dwAttributeID);
            SafeArrayPutElement(pAttributeValues2, &vbIndex, &v);
            SafeArrayPutElement(pErrors, &vbIndex, &phrErrors[index]);

            VariantClear(&v);
        }

        Fire_AsyncReadAttributesComplete(dwTransactionID, hrStatus, hClient, dwNumItems, pAttributeIDs, pAttributeValues2, pErrors);
    }

    if (NULL != pAttributeIDs) SafeArrayDestroy(pAttributeIDs);
    if (NULL != pAttributeValues2) SafeArrayDestroy(pAttributeValues2);
    if (NULL != pErrors) SafeArrayDestroy(pErrors);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::OnReadAnnotations( 
    DWORD dwTransactionID,
    HRESULT hrStatus,
    DWORD dwNumItems,
    OPCHDA_ANNOTATION * pAnnotationValues,
    HRESULT * phrErrors)
{
    SAFEARRAY* pClientHandles = SafeArrayCreateVector(VT_I4, 1, dwNumItems);
    SAFEARRAY* pAnnotationValues2 = SafeArrayCreateVector(VT_VARIANT, 1, dwNumItems);
    SAFEARRAY* pErrors = SafeArrayCreateVector(VT_I4, 1, dwNumItems);

    if ((NULL != pClientHandles) && (NULL != pAnnotationValues2) && (NULL != pErrors))
    {
        LONG index, vbIndex;

        CComObject<COPCHDAHistory>* pHistory;
        OPCHDAHistory* pOPCHDAHistory;
        HRESULT hr;
        VARIANT v;

        VariantInit(&v);

        for (index = 0; index < dwNumItems; index++)
        {
            vbIndex = index + 1;

            if (SUCCEEDED(phrErrors[index]))
            {
                pHistory = NULL;
                pOPCHDAHistory = NULL;

                hr = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                _ASSERTE(SUCCEEDED(hr));

                pHistory->Initialize(&pAnnotationValues[index]);
            
                pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                _ASSERTE(pOPCHDAHistory);

                v.vt = VT_DISPATCH;
                v.pdispVal = pOPCHDAHistory;
            }

            SafeArrayPutElement(pClientHandles, &vbIndex, &pAnnotationValues[index].hClient);
            SafeArrayPutElement(pAnnotationValues2, &vbIndex, &v);
            SafeArrayPutElement(pErrors, &vbIndex, &phrErrors[index]);

            VariantClear(&v);
        }

        Fire_AsyncReadAnnotationsComplete(dwTransactionID, hrStatus, dwNumItems, pClientHandles, pAnnotationValues2, pErrors);
    }

    if (NULL != pClientHandles) SafeArrayDestroy(pClientHandles);
    if (NULL != pAnnotationValues2) SafeArrayDestroy(pAnnotationValues2);
    if (NULL != pErrors) SafeArrayDestroy(pErrors);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::OnInsertAnnotations( 
    DWORD dwTransactionID,
    HRESULT hrStatus,
    DWORD dwCount,
    OPCHANDLE * phClients,
    HRESULT * phrErrors)
{
    SAFEARRAY* pClientHandles = SafeArrayCreateVector(VT_I4, 1, dwCount);
    SAFEARRAY* pErrors = SafeArrayCreateVector(VT_I4, 1, dwCount);

    if ((NULL != pClientHandles) && (NULL != pErrors))
    {
        LONG index, vbIndex;

        for (index = 0; index < dwCount; index++)
        {
            vbIndex = index + 1;

            SafeArrayPutElement(pClientHandles, &vbIndex, reinterpret_cast<void*>(&phClients[index]));
            SafeArrayPutElement(pErrors, &vbIndex, reinterpret_cast<void*>(&phrErrors[index]));
        }

        Fire_AsyncUpdateComplete(dwTransactionID, hrStatus, dwCount, pClientHandles, pErrors);
    }

    if (NULL != pClientHandles) SafeArrayDestroy(pClientHandles);

    if (NULL != pErrors) SafeArrayDestroy(pErrors);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::OnPlayback( 
    DWORD dwTransactionID,
    HRESULT hrStatus,
    DWORD dwNumItems,
    OPCHDA_ITEM ** ppItemValues,
    HRESULT * phrErrors)
{
    SAFEARRAY* pClientHandles = SafeArrayCreateVector(VT_I4, 1, dwNumItems);
    SAFEARRAY* pAggregates = SafeArrayCreateVector(VT_I4, 1, dwNumItems);
    SAFEARRAY* pItemValues = SafeArrayCreateVector(VT_VARIANT, 1, dwNumItems);
    SAFEARRAY* pErrors = SafeArrayCreateVector(VT_I4, 1, dwNumItems);

    if ((NULL != pClientHandles) && (NULL != pAggregates) && (NULL != pItemValues) && (NULL != pErrors))
    {
        LONG index, vbIndex;

        CComObject<COPCHDAHistory>* pHistory;
        OPCHDAHistory* pOPCHDAHistory;
        HRESULT hr;
        VARIANT v;

        VariantInit(&v);

        for (index = 0; index < dwNumItems; index++)
        {
            vbIndex = index + 1;

            if (SUCCEEDED(phrErrors[index]))
            {
                pHistory = NULL;
                pOPCHDAHistory = NULL;

                hr = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                _ASSERTE(SUCCEEDED(hr));

                pHistory->Initialize(ppItemValues[index]);
            
                pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                _ASSERTE(pOPCHDAHistory);

                v.vt = VT_DISPATCH;
                v.pdispVal = pOPCHDAHistory;
            }

            SafeArrayPutElement(pClientHandles, &vbIndex, &ppItemValues[index]->hClient);
            SafeArrayPutElement(pAggregates, &vbIndex, &ppItemValues[index]->haAggregate);
            SafeArrayPutElement(pItemValues, &vbIndex, &v);
            SafeArrayPutElement(pErrors, &vbIndex, &phrErrors[index]);

            VariantClear(&v);
        }

        Fire_Playback(dwTransactionID, hrStatus, dwNumItems, pClientHandles, pAggregates, pItemValues, pErrors);
    }

    if (NULL != pClientHandles) SafeArrayDestroy(pClientHandles);
    if (NULL != pAggregates) SafeArrayDestroy(pAggregates);
    if (NULL != pItemValues) SafeArrayDestroy(pItemValues);
    if (NULL != pErrors) SafeArrayDestroy(pErrors);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::OnUpdateComplete( 
    DWORD dwTransactionID,
    HRESULT hrStatus,
    DWORD dwCount,
    OPCHANDLE * phClients,
    HRESULT * phrErrors)
{
    SAFEARRAY* pClientHandles = SafeArrayCreateVector(VT_I4, 1, dwCount);
    SAFEARRAY* pErrors = SafeArrayCreateVector(VT_I4, 1, dwCount);

    if ((NULL != pClientHandles) && (NULL != pErrors))
    {
        LONG index, vbIndex;

        for (index = 0; index < dwCount; index++)
        {
            vbIndex = index + 1;

            SafeArrayPutElement(pClientHandles, &vbIndex, reinterpret_cast<void*>(&phClients[index]));
            SafeArrayPutElement(pErrors, &vbIndex, reinterpret_cast<void*>(&phrErrors[index]));
        }

        Fire_AsyncUpdateComplete(dwTransactionID, hrStatus, dwCount, pClientHandles, pErrors);
    }

    if (NULL != pClientHandles) SafeArrayDestroy(pClientHandles);

    if (NULL != pErrors) SafeArrayDestroy(pErrors);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::OnCancelComplete( 
    DWORD dwCancelID)
{
    Fire_AsyncCancelComplete(dwCancelID);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_Parent(IOPCHDAAutoServer ** ppParent)
{
	if (ppParent == NULL)
    {
		return E_POINTER;
    }

    *ppParent = NULL;

    HRESULT hr;

    hr = ((CComObject<COPCHDAAutoServer>*)this)->QueryInterface(
        IID_IOPCHDAAutoServer,
        reinterpret_cast<void**>(ppParent));

   _ASSERTE(*ppParent);

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_Count(LONG * pCount)
{
	if (pCount == NULL)
    {
		return E_POINTER;
    }

    *pCount = m_items.size();
		
	return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get__NewEnum(IUnknown ** ppUnk)
{
    typedef CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > CEnumVariant;

	if (ppUnk == NULL)
    {
		return E_POINTER;
    }

    *ppUnk = NULL;

    HRESULT hr = E_FAIL;

    CComObject<CEnumVariant>* pEnumVariant = new CComObject<CEnumVariant>;

    _ASSERTE(pEnumVariant);

    pEnumVariant->AddRef();

    VARIANT* pvArray = NULL;
    VARIANT* pvArrayEnd = NULL;

    if (!m_items.empty())
    {
        pvArray = new VARIANT[m_items.size()];
        
        pvArrayEnd = &pvArray[m_items.size()];

        TOPCHDAItemCollection::iterator it = m_items.begin();
        long index = 0;

        COPCHDAItem* pItem;
        OPCHDAItem* pOPCHDAItem;

        while (m_items.end() != it)
        {
            pItem = *it;

            pOPCHDAItem = NULL;
            pItem->QueryInterface(IID_OPCHDAItem, reinterpret_cast<void**>(&pOPCHDAItem));
            _ASSERTE(pOPCHDAItem);

            VariantInit(&pvArray[index]);

            pvArray[index].vt = VT_DISPATCH;
            pvArray[index].pdispVal = pOPCHDAItem;

            it++;
            index++;
        }        
    }

    hr = pEnumVariant->Init(pvArray, pvArrayEnd, NULL, AtlFlagTakeOwnership);

    if (SUCCEEDED(hr))
    {
        hr = pEnumVariant->QueryInterface(IID_IEnumVARIANT, reinterpret_cast<void**>(ppUnk));
    }

    pEnumVariant->Release();
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::Item(
    VARIANT ItemSpecifier,
    OPCHDAItem ** ppItem)
{
	if (ppItem == NULL)
    {
		return E_POINTER;
    }

    if ((VT_BSTR != ItemSpecifier.vt) &&
        ((FAILED(VariantChangeType(&ItemSpecifier, &ItemSpecifier, 0, VT_I4)) ||
         (ItemSpecifier.lVal < 1) ||
         (ItemSpecifier.lVal > m_items.size()))))
    {
        return E_INVALIDARG;
    }
		
    *ppItem = NULL;

    HRESULT hr = E_FAIL;

    TOPCHDAItemCollection::iterator it = m_items.begin();
    COPCHDAItem* pItem;

    if (VT_BSTR == ItemSpecifier.vt)
    {
        while (m_items.end() != it)
        {
            pItem = *it;

            if (0 == wcscmp(pItem->GetItemID(), ItemSpecifier.bstrVal))
            {
                hr = pItem->QueryInterface(IID_OPCHDAItem, reinterpret_cast<void**>(ppItem));
                _ASSERTE(*ppItem);
                break;
            }

            it++;
        }
    }
    else
    {
        LONG index = 0;

        while (m_items.end() != it)
        {
            pItem = *it;

            index++;

            if (index == ItemSpecifier.lVal)
            {
                hr = pItem->QueryInterface(IID_OPCHDAItem, reinterpret_cast<void**>(ppItem));
                _ASSERTE(*ppItem);
                break;
            }

            it++;
        }
    }

	return hr;
}

STDMETHODIMP COPCHDAAutoServer::GetOPCHDAItem(
    LONG ServerHandle,
    OPCHDAItem ** ppItem)
{
	if (ppItem == NULL)
    {
		return E_POINTER;
    }

    *ppItem = NULL;

    HRESULT hr = E_FAIL;

    TOPCHDAItemCollection::iterator it = m_items.begin();
    COPCHDAItem* pItem;

    while (m_items.end() != it)
    {
        pItem = *it;

        if (pItem->GetServerHandle() == ServerHandle)
        {
            hr = pItem->QueryInterface(IID_OPCHDAItem, reinterpret_cast<void**>(ppItem));

            break;
        }

        it++;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AddItem(
    BSTR ItemID,
    LONG ClientHandle,
    OPCHDAItem ** ppItem)
{
	if (ppItem == NULL)
    {
		return E_POINTER;
    }

    *ppItem = NULL;

    HRESULT hr = E_FAIL;

    if (m_pOPCHDAServer)
    {
        OPCHANDLE hClient = ClientHandle;
        OPCHANDLE* phServer = NULL;
        HRESULT* pErrors = NULL;

        hr = m_pOPCHDAServer->GetItemHandles(1, &ItemID, &hClient, &phServer, &pErrors);

        if (SUCCEEDED(hr))
        {
            hr = pErrors[0];

            if (SUCCEEDED(hr))
            {
                CComObject<COPCHDAItem>* pItem = NULL;

                hr = CComObject<COPCHDAItem>::CreateInstance(&pItem);
                
                if (SUCCEEDED(hr))
                {
                    pItem->Initialize(ItemID, ClientHandle, phServer[0], this);

                    pItem->AddRef();
                    m_items.push_back(pItem);

                    hr = pItem->QueryInterface(IID_OPCHDAItem, reinterpret_cast<void**>(ppItem));
                    _ASSERTE(*ppItem);
                }
            }

            CoTaskMemFree(phServer);
            CoTaskMemFree(pErrors);
        }
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AddItems(
    LONG NumItems,
    SAFEARRAY ** ppItemIDs,
    SAFEARRAY ** ppClientHandles,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors)
{
	if (*ppItemIDs == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppClientHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppServerHandles = NULL;
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppItemIDs, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppItemIDs, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppClientHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppClientHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDAServer)
    {
        LPWSTR* pszItemIDs = NULL;
        OPCHANDLE* phClient = NULL;
        OPCHANDLE* phServer = NULL;
        HRESULT* pErrors = NULL;

        pszItemIDs = new LPWSTR[NumItems];
        phClient = new OPCHANDLE[NumItems];

        LONG index, vbIndex;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            SafeArrayGetElement(*ppItemIDs, &vbIndex, reinterpret_cast<void*>(&pszItemIDs[index]));
            SafeArrayGetElement(*ppClientHandles, &vbIndex, reinterpret_cast<void*>(&phClient[index]));

            if (NULL == pszItemIDs[index])
            {
                pszItemIDs[index] = L"";
            }
        }

        hr = m_pOPCHDAServer->GetItemHandles(NumItems, pszItemIDs, phClient, &phServer, &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppServerHandles = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL == *ppServerHandles)
            {
                hr = E_FAIL;
            }
            else
            {
                *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

                if (NULL == *ppErrors)
                {
                    hr = E_FAIL;

                    SafeArrayDestroy(*ppServerHandles);

                    *ppServerHandles = NULL;
                }
            }

            CComObject<COPCHDAItem>* pItem = NULL;
            HRESULT hr2;

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                if (SUCCEEDED(pErrors[index]))
                {
                    hr2 = CComObject<COPCHDAItem>::CreateInstance(&pItem);
                    _ASSERTE(SUCCEEDED(hr2));
                    
                    pItem->Initialize(pszItemIDs[index], phClient[index], phServer[index], this);

                    pItem->AddRef();
                    m_items.push_back(pItem);
                }
                else
                {
                    phServer[index] = NULL;
                }

                if (NULL != *ppServerHandles)
                {
                    SafeArrayPutElement(*ppServerHandles, &vbIndex, &phServer[index]);
                }

                if (NULL != *ppErrors)
                {
                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }
            }

            CoTaskMemFree(phServer);
            CoTaskMemFree(pErrors);
        }

        delete pszItemIDs;
        delete phClient;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::Remove(
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;
		
    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDAServer)
    {
        OPCHANDLE* phServer = NULL;
        HRESULT* pErrors = NULL;

        phServer = new OPCHANDLE[NumItems];

        LONG index, vbIndex;

        TOPCHDAItemCollection::iterator it;
        COPCHDAItem* pItem;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));

            it = m_items.begin();

            while (m_items.end() != it)
            {
                pItem = *it;

                if (pItem->GetServerHandle() == phServer[index])
                {
                    m_items.erase(it);

                    pItem->Release();

                    break;
                }
                
                it++;
            }
        }

        hr = m_pOPCHDAServer->ReleaseItemHandles(NumItems, phServer, &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        delete phServer;
    }

	return hr;
}

STDMETHODIMP COPCHDAAutoServer::RemoveAll()
{
    if (m_items.empty())
    {
        return S_OK;
    }

    HRESULT hr = E_FAIL;

    if (m_pOPCHDAServer)
    {
        OPCHANDLE* phServer = new OPCHANDLE[m_items.size()];

        TOPCHDAItemCollection::iterator it = m_items.begin();

        COPCHDAItem* pItem;
        long index = 0;

        while (m_items.end() != it)
        {
            pItem = *it;

            phServer[index] = pItem->GetServerHandle();

            pItem->Release();

            index++;

            it++;
        }

        m_items.clear();

        hr = S_OK;

        HRESULT* pErrors = NULL;

        HRESULT hr2;
        
        hr2 = m_pOPCHDAServer->ReleaseItemHandles(m_items.size(), phServer, &pErrors);

        if (SUCCEEDED(hr2))
        {
            CoTaskMemFree(pErrors);
        }
    }

	return hr;
}

STDMETHODIMP COPCHDAAutoServer::Validate(
    LONG NumItems,
    SAFEARRAY ** ppItemIDs,
    SAFEARRAY ** ppErrors)
{
	if (*ppItemIDs == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }
		
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppItemIDs, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppItemIDs, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDAServer)
    {
        LPWSTR* pszItemIDs = NULL;
        HRESULT* pErrors = NULL;

        pszItemIDs = new LPWSTR[NumItems];

        LONG index, vbIndex;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            SafeArrayGetElement(*ppItemIDs, &vbIndex, reinterpret_cast<void*>(&pszItemIDs[index]));

            if (NULL == pszItemIDs[index])
            {
                pszItemIDs[index] = L"";
            }
        }

        hr = m_pOPCHDAServer->ValidateItemIDs(NumItems, pszItemIDs, &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        delete pszItemIDs;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncReadRaw(
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumValues,
    BOOL Bounds,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppItemValues,
    SAFEARRAY ** ppErrors)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppItemValues == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppItemValues = NULL;
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncRead)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        OPCHDA_ITEM* pItemValues = NULL;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            OPCHANDLE* phServer = NULL;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_SyncRead->ReadRaw(
                &htStartTime,
                &htEndTime,
                NumValues,
                Bounds,
                NumItems,
                phServer,
                &pItemValues,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppItemValues = SafeArrayCreateVector(VT_VARIANT, 1, NumItems);

            if (NULL == *ppItemValues)
            {
                hr = E_FAIL;
            }
            else
            {
                *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

                if (NULL == *ppErrors)
                {
                    hr = E_FAIL;

                    SafeArrayDestroy(*ppItemValues);

                    *ppItemValues = NULL;
                }
            }

            if (SUCCEEDED(hr))
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                CComObject<COPCHDAHistory>* pHistory;
                OPCHDAHistory* pOPCHDAHistory;
                HRESULT hr2;
                VARIANT v;

                VariantInit(&v);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    if (SUCCEEDED(pErrors[index]))
                    {
                        pHistory = NULL;
                        pOPCHDAHistory = NULL;

                        hr2 = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                        _ASSERTE(SUCCEEDED(hr2));

                        pHistory->Initialize(&pItemValues[index]);
                    
                        pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                        _ASSERTE(pOPCHDAHistory);

                        v.vt = VT_DISPATCH;
                        v.pdispVal = pOPCHDAHistory;
                    }

                    SafeArrayPutElement(*ppItemValues, &vbIndex, &v);
                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);

                    VariantClear(&v);
                }
            }

            for (index = 0; index < NumItems; index++)
            {
                for (vbIndex = 0; vbIndex < pItemValues[index].dwCount; vbIndex++)
                {
                    VariantClear(&pItemValues[index].pvDataValues[vbIndex]);
                }

                CoTaskMemFree(pItemValues[index].pftTimeStamps);
                CoTaskMemFree(pItemValues[index].pdwQualities);
                CoTaskMemFree(pItemValues[index].pvDataValues);
            }

            CoTaskMemFree(pItemValues);

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncReadProcessed(
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    DATE ResampleInterval,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppAggregates,
    SAFEARRAY ** ppItemValues,
    SAFEARRAY ** ppErrors)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppAggregates == NULL)
    {
		return E_POINTER;
    }
		
	if (ppItemValues == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppItemValues = NULL;
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppAggregates, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppAggregates, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncRead)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        OPCHDA_ITEM* pItemValues = NULL;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            ULONGLONG ulResampleInterval;
            OPCHANDLE* phServer = NULL;
            OPCHDA_AGGREGATE* haAggregate = NULL;

            // convert days to 100ns intervals
            ulResampleInterval = ResampleInterval * 24.0 * 60.0 * 60.0 / 100e-9;

            phServer = new OPCHANDLE[NumItems];
            haAggregate = new OPCHDA_AGGREGATE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
                SafeArrayGetElement(*ppAggregates, &vbIndex, reinterpret_cast<void*>(&haAggregate[index]));
            }

            hr = m_pOPCHDA_SyncRead->ReadProcessed(
                &htStartTime,
                &htEndTime,
                *reinterpret_cast<FILETIME*>(&ulResampleInterval),
                NumItems,
                phServer,
                (DWORD*) haAggregate,
                &pItemValues,
                &pErrors);

            delete phServer;
            delete haAggregate;
        }

        if (SUCCEEDED(hr))
        {
            *ppItemValues = SafeArrayCreateVector(VT_VARIANT, 1, NumItems);

            if (NULL == *ppItemValues)
            {
                hr = E_FAIL;
            }
            else
            {
                *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

                if (NULL == *ppErrors)
                {
                    hr = E_FAIL;

                    SafeArrayDestroy(*ppItemValues);

                    *ppItemValues = NULL;
                }
            }

            if (SUCCEEDED(hr))
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                CComObject<COPCHDAHistory>* pHistory;
                OPCHDAHistory* pOPCHDAHistory;
                HRESULT hr2;
                VARIANT v;

                VariantInit(&v);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    if (SUCCEEDED(pErrors[index]))
                    {
                        pHistory = NULL;
                        pOPCHDAHistory = NULL;

                        hr2 = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                        _ASSERTE(SUCCEEDED(hr2));

                        pHistory->Initialize(&pItemValues[index]);
                    
                        pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                        _ASSERTE(pOPCHDAHistory);

                        v.vt = VT_DISPATCH;
                        v.pdispVal = pOPCHDAHistory;
                    }

                    SafeArrayPutElement(*ppItemValues, &vbIndex, &v);
                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);

                    VariantClear(&v);
                }
            }

            for (index = 0; index < NumItems; index++)
            {
                for (vbIndex = 0; vbIndex < pItemValues[index].dwCount; vbIndex++)
                {
                    VariantClear(&pItemValues[index].pvDataValues[vbIndex]);
                }

                CoTaskMemFree(pItemValues[index].pftTimeStamps);
                CoTaskMemFree(pItemValues[index].pdwQualities);
                CoTaskMemFree(pItemValues[index].pvDataValues);
            }

            CoTaskMemFree(pItemValues);

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncReadAtTime(
    LONG NumTimeStamps,
    SAFEARRAY ** ppTimeStamps,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppItemValues,
    SAFEARRAY ** ppErrors)
{
	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppItemValues == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
    if (NumTimeStamps < 1)
    {
        return E_INVALIDARG;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppItemValues = NULL;
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumTimeStamps))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncRead)
    {
        FILETIME* pftTimeStamps = NULL;
        OPCHANDLE* phServer = NULL;
        OPCHDA_ITEM* pItemValues = NULL;
        HRESULT* pErrors = NULL;

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        pftTimeStamps = new FILETIME[NumTimeStamps];

        for (index = 0; index < NumTimeStamps; index++)
        {
            vbIndex = index + 1;

            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        phServer = new OPCHANDLE[NumItems];

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
        }

        hr = m_pOPCHDA_SyncRead->ReadAtTime(
            NumTimeStamps,
            pftTimeStamps,
            NumItems,
            phServer,
            &pItemValues,
            &pErrors);

        delete pftTimeStamps;

        delete phServer;

        if (SUCCEEDED(hr))
        {
            *ppItemValues = SafeArrayCreateVector(VT_VARIANT, 1, NumItems);

            if (NULL == *ppItemValues)
            {
                hr = E_FAIL;
            }
            else
            {
                *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

                if (NULL == *ppErrors)
                {
                    hr = E_FAIL;

                    SafeArrayDestroy(*ppItemValues);

                    *ppItemValues = NULL;
                }
            }

            if (SUCCEEDED(hr))
            {
                CComObject<COPCHDAHistory>* pHistory;
                OPCHDAHistory* pOPCHDAHistory;
                HRESULT hr2;
                VARIANT v;

                VariantInit(&v);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    if (SUCCEEDED(pErrors[index]))
                    {
                        pHistory = NULL;
                        pOPCHDAHistory = NULL;

                        hr2 = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                        _ASSERTE(SUCCEEDED(hr2));

                        pHistory->Initialize(&pItemValues[index]);
                    
                        pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                        _ASSERTE(pOPCHDAHistory);

                        v.vt = VT_DISPATCH;
                        v.pdispVal = pOPCHDAHistory;
                    }

                    SafeArrayPutElement(*ppItemValues, &vbIndex, &v);
                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);

                    VariantClear(&v);
                }
            }

            for (index = 0; index < NumItems; index++)
            {
                for (vbIndex = 0; vbIndex < pItemValues[index].dwCount; vbIndex++)
                {
                    VariantClear(&pItemValues[index].pvDataValues[vbIndex]);
                }

                CoTaskMemFree(pItemValues[index].pftTimeStamps);
                CoTaskMemFree(pItemValues[index].pdwQualities);
                CoTaskMemFree(pItemValues[index].pvDataValues);
            }

            CoTaskMemFree(pItemValues);

            CoTaskMemFree(pErrors);
        }
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncReadModified(
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumValues,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppItemValues,
    SAFEARRAY ** ppErrors)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppItemValues == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppItemValues = NULL;
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncRead)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        OPCHDA_MODIFIEDITEM* pItemValues = NULL;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            OPCHANDLE* phServer = NULL;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_SyncRead->ReadModified(
                &htStartTime,
                &htEndTime,
                NumValues,
                NumItems,
                phServer,
                &pItemValues,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppItemValues = SafeArrayCreateVector(VT_VARIANT, 1, NumItems);

            if (NULL == *ppItemValues)
            {
                hr = E_FAIL;
            }
            else
            {
                *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

                if (NULL == *ppErrors)
                {
                    hr = E_FAIL;

                    SafeArrayDestroy(*ppItemValues);

                    *ppItemValues = NULL;
                }
            }

            if (SUCCEEDED(hr))
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                CComObject<COPCHDAHistory>* pHistory;
                OPCHDAHistory* pOPCHDAHistory;
                HRESULT hr2;
                VARIANT v;

                VariantInit(&v);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    if (SUCCEEDED(pErrors[index]))
                    {
                        pHistory = NULL;
                        pOPCHDAHistory = NULL;

                        hr2 = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                        _ASSERTE(SUCCEEDED(hr2));

                        pHistory->Initialize(&pItemValues[index]);
                    
                        pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                        _ASSERTE(pOPCHDAHistory);

                        v.vt = VT_DISPATCH;
                        v.pdispVal = pOPCHDAHistory;
                    }

                    SafeArrayPutElement(*ppItemValues, &vbIndex, &v);
                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);

                    VariantClear(&v);
                }
            }

            for (index = 0; index < NumItems; index++)
            {
                for (vbIndex = 0; vbIndex < pItemValues[index].dwCount; vbIndex++)
                {
                    VariantClear(&pItemValues[index].pvDataValues[vbIndex]);
                    CoTaskMemFree(&pItemValues[index].szUser[vbIndex]);
                }

                CoTaskMemFree(pItemValues[index].pftTimeStamps);
                CoTaskMemFree(pItemValues[index].pdwQualities);
                CoTaskMemFree(pItemValues[index].pvDataValues);
                CoTaskMemFree(pItemValues[index].pftModificationTime);
                CoTaskMemFree(pItemValues[index].pEditType);
                CoTaskMemFree(pItemValues[index].szUser);
            }

            CoTaskMemFree(pItemValues);

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncReadAttribute(
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG ServerHandle,
    LONG NumAttributes,
    SAFEARRAY ** ppAttributeIDs,
    SAFEARRAY ** ppAttributeValues,
    SAFEARRAY ** ppErrors)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppAttributeIDs == NULL)
    {
		return E_POINTER;
    }
		
	if (ppAttributeValues == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
    if (NumAttributes < 1)
    {
        return E_INVALIDARG;
    }

    *ppAttributeValues = NULL;
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppAttributeIDs, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppAttributeIDs, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumAttributes))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncRead)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        OPCHDA_ATTRIBUTE* pAttributeValues = NULL;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            DWORD* pdwAttributeIDs = NULL;

            pdwAttributeIDs = new DWORD[NumAttributes];

            for (index = 0; index < NumAttributes; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppAttributeIDs, &vbIndex, reinterpret_cast<void*>(&pdwAttributeIDs[index]));
            }

            hr = m_pOPCHDA_SyncRead->ReadAttribute(
                &htStartTime,
                &htEndTime,
                ServerHandle,
                NumAttributes,
                pdwAttributeIDs,
                &pAttributeValues,
                &pErrors);

            delete pdwAttributeIDs;
        }

        if (SUCCEEDED(hr))
        {
            *ppAttributeValues = SafeArrayCreateVector(VT_VARIANT, 1, NumAttributes);

            if (NULL == *ppAttributeValues)
            {
                hr = E_FAIL;
            }
            else
            {
                *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumAttributes);

                if (NULL == *ppErrors)
                {
                    hr = E_FAIL;

                    SafeArrayDestroy(*ppAttributeValues);

                    *ppAttributeValues = NULL;
                }
            }

            if (SUCCEEDED(hr))
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                CComObject<COPCHDAHistory>* pHistory;
                OPCHDAHistory* pOPCHDAHistory;
                HRESULT hr2;
                VARIANT v;

                VariantInit(&v);

                for (index = 0; index < NumAttributes; index++)
                {
                    vbIndex = index + 1;

                    if (SUCCEEDED(pErrors[index]))
                    {
                        pHistory = NULL;
                        pOPCHDAHistory = NULL;

                        hr2 = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                        _ASSERTE(SUCCEEDED(hr2));

                        pHistory->Initialize(&pAttributeValues[index]);
                    
                        pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                        _ASSERTE(pOPCHDAHistory);

                        v.vt = VT_DISPATCH;
                        v.pdispVal = pOPCHDAHistory;
                    }

                    SafeArrayPutElement(*ppAttributeValues, &vbIndex, &v);
                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);

                    VariantClear(&v);
                }
            }

            for (index = 0; index < NumAttributes; index++)
            {
                for (vbIndex = 0; vbIndex < pAttributeValues[index].dwNumValues; vbIndex++)
                {
                    VariantClear(&pAttributeValues[index].vAttributeValues[vbIndex]);
                }

                CoTaskMemFree(pAttributeValues[index].ftTimeStamps);
                CoTaskMemFree(pAttributeValues[index].vAttributeValues);
            }

            CoTaskMemFree(pAttributeValues);

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncInsert(
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppDataValues,
    SAFEARRAY ** ppQualities,
    SAFEARRAY ** ppErrors)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }

	if (*ppDataValues == NULL)
    {
		return E_POINTER;
    }

	if (*ppQualities == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppDataValues, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppDataValues, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppQualities, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppQualities, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHANDLE* phServer = NULL;
        FILETIME* pftTimeStamps = NULL;
        VARIANT* pvDataValues = NULL;
        DWORD* pdwQualities = NULL;
        HRESULT* pErrors = NULL;

        phServer = new OPCHANDLE[NumItems];
        pftTimeStamps = new FILETIME[NumItems];
        pvDataValues = new VARIANT[NumItems];
        pdwQualities = new DWORD[NumItems];

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            VariantInit(&pvDataValues[index]);

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));
            SafeArrayGetElement(*ppDataValues, &vbIndex, reinterpret_cast<void*>(&pvDataValues[index]));
            SafeArrayGetElement(*ppQualities, &vbIndex, reinterpret_cast<void*>(&pdwQualities[index]));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        hr = m_pOPCHDA_SyncUpdate->Insert(
            NumItems,
            phServer,
            pftTimeStamps,
            pvDataValues,
            pdwQualities,
            &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        for (index = 0; index < NumItems; index++)
        {
            VariantClear(&pvDataValues[index]);
        }

        delete phServer;
        delete pftTimeStamps;
        delete pvDataValues;
        delete pdwQualities;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncReplace(
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppDataValues,
    SAFEARRAY ** ppQualities,
    SAFEARRAY ** ppErrors)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }

	if (*ppDataValues == NULL)
    {
		return E_POINTER;
    }

	if (*ppQualities == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;
		
    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppDataValues, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppDataValues, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppQualities, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppQualities, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHANDLE* phServer = NULL;
        FILETIME* pftTimeStamps = NULL;
        VARIANT* pvDataValues = NULL;
        DWORD* pdwQualities = NULL;
        HRESULT* pErrors = NULL;

        phServer = new OPCHANDLE[NumItems];
        pftTimeStamps = new FILETIME[NumItems];
        pvDataValues = new VARIANT[NumItems];
        pdwQualities = new DWORD[NumItems];

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            VariantInit(&pvDataValues[index]);

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));
            SafeArrayGetElement(*ppDataValues, &vbIndex, reinterpret_cast<void*>(&pvDataValues[index]));
            SafeArrayGetElement(*ppQualities, &vbIndex, reinterpret_cast<void*>(&pdwQualities[index]));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        hr = m_pOPCHDA_SyncUpdate->Replace(
            NumItems,
            phServer,
            pftTimeStamps,
            pvDataValues,
            pdwQualities,
            &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        for (index = 0; index < NumItems; index++)
        {
            VariantClear(&pvDataValues[index]);
        }

        delete phServer;
        delete pftTimeStamps;
        delete pvDataValues;
        delete pdwQualities;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncInsertReplace(
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppDataValues,
    SAFEARRAY ** ppQualities,
    SAFEARRAY ** ppErrors)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }

	if (*ppDataValues == NULL)
    {
		return E_POINTER;
    }

	if (*ppQualities == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;
		
    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppDataValues, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppDataValues, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppQualities, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppQualities, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHANDLE* phServer = NULL;
        FILETIME* pftTimeStamps = NULL;
        VARIANT* pvDataValues = NULL;
        DWORD* pdwQualities = NULL;
        HRESULT* pErrors = NULL;

        phServer = new OPCHANDLE[NumItems];
        pftTimeStamps = new FILETIME[NumItems];
        pvDataValues = new VARIANT[NumItems];
        pdwQualities = new DWORD[NumItems];

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            VariantInit(&pvDataValues[index]);

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));
            SafeArrayGetElement(*ppDataValues, &vbIndex, reinterpret_cast<void*>(&pvDataValues[index]));
            SafeArrayGetElement(*ppQualities, &vbIndex, reinterpret_cast<void*>(&pdwQualities[index]));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        hr = m_pOPCHDA_SyncUpdate->InsertReplace(
            NumItems,
            phServer,
            pftTimeStamps,
            pvDataValues,
            pdwQualities,
            &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        for (index = 0; index < NumItems; index++)
        {
            VariantClear(&pvDataValues[index]);
        }

        delete phServer;
        delete pftTimeStamps;
        delete pvDataValues;
        delete pdwQualities;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncDeleteRaw(
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;
		
    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            OPCHANDLE* phServer = NULL;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_SyncUpdate->DeleteRaw(
                &htStartTime,
                &htEndTime,
                NumItems,
                phServer,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL == *ppErrors)
            {
                hr = E_FAIL;
            }

            if (SUCCEEDED(hr))
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncDeleteAtTime(
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppErrors)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHANDLE* phServer = NULL;
        FILETIME* pftTimeStamps = NULL;
        HRESULT* pErrors = NULL;

        phServer = new OPCHANDLE[NumItems];
        pftTimeStamps = new FILETIME[NumItems];

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        hr = m_pOPCHDA_SyncUpdate->DeleteAtTime(
            NumItems,
            phServer,
            pftTimeStamps,
            &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        delete phServer;
        delete pftTimeStamps;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncReadAnnotations(
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppAnnotationValues,
    SAFEARRAY ** ppErrors)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppAnnotationValues == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppAnnotationValues = NULL;
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncAnnotations)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        OPCHDA_ANNOTATION* pAnnotationValues = NULL;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            OPCHANDLE* phServer = NULL;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_SyncAnnotations->Read(
                &htStartTime,
                &htEndTime,
                NumItems,
                phServer,
                &pAnnotationValues,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppAnnotationValues = SafeArrayCreateVector(VT_VARIANT, 1, NumItems);

            if (NULL == *ppAnnotationValues)
            {
                hr = E_FAIL;
            }
            else
            {
                *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

                if (NULL == *ppErrors)
                {
                    hr = E_FAIL;

                    SafeArrayDestroy(*ppAnnotationValues);

                    *ppAnnotationValues = NULL;
                }
            }

            if (SUCCEEDED(hr))
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                CComObject<COPCHDAHistory>* pHistory;
                OPCHDAHistory* pOPCHDAHistory;
                HRESULT hr2;
                VARIANT v;

                VariantInit(&v);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    if (SUCCEEDED(pErrors[index]))
                    {
                        pHistory = NULL;
                        pOPCHDAHistory = NULL;

                        hr2 = CComObject<COPCHDAHistory>::CreateInstance(&pHistory);
                        _ASSERTE(SUCCEEDED(hr2));

                        pHistory->Initialize(&pAnnotationValues[index]);
                    
                        pHistory->QueryInterface(IID_OPCHDAHistory, reinterpret_cast<void**>(&pOPCHDAHistory));
                        _ASSERTE(pOPCHDAHistory);

                        v.vt = VT_DISPATCH;
                        v.pdispVal = pOPCHDAHistory;
                    }

                    SafeArrayPutElement(*ppAnnotationValues, &vbIndex, &v);
                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);

                    VariantClear(&v);
                }
            }

            for (index = 0; index < NumItems; index++)
            {
                for (vbIndex = 0; vbIndex < pAnnotationValues[index].dwNumValues; vbIndex++)
                {
                    CoTaskMemFree(&pAnnotationValues[index].szAnnotation[vbIndex]);
                    CoTaskMemFree(&pAnnotationValues[index].szUser[vbIndex]);
                }

                CoTaskMemFree(pAnnotationValues[index].ftTimeStamps);
                CoTaskMemFree(pAnnotationValues[index].szAnnotation);
                CoTaskMemFree(pAnnotationValues[index].ftAnnotationTime);
                CoTaskMemFree(pAnnotationValues[index].szUser);
            }

            CoTaskMemFree(pAnnotationValues);

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::SyncInsertAnnotations(
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppAnnotationValues,
    SAFEARRAY ** ppErrors)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppAnnotationValues == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppAnnotationValues, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppAnnotationValues, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_SyncAnnotations)
    {
        // TODO: something is screwy in the spec
    }
		
	return E_NOTIMPL;
}

STDMETHODIMP COPCHDAAutoServer::AsyncReadRaw(
    LONG TransactionID,
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumValues,
    BOOL Bounds,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncRead)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            OPCHANDLE* phServer = NULL;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_AsyncRead->ReadRaw(
                TransactionID,
                &htStartTime,
                &htEndTime,
                NumValues,
                Bounds,
                NumItems,
                phServer,
                &dwCancelID,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncAdviseRaw(
    LONG TransactionID,
    VARIANT * pStartTime,
    DATE UpdateInterval,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncRead)
    {
        OPCHDA_TIME htStartTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            ULONGLONG ulUpdateInterval;
            OPCHANDLE* phServer = NULL;

            // convert days to 100ns intervals
            ulUpdateInterval = UpdateInterval * 24.0 * 60.0 * 60.0 / 100e-9;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_AsyncRead->AdviseRaw(
                TransactionID,
                &htStartTime,
                *reinterpret_cast<FILETIME*>(&ulUpdateInterval),
                NumItems,
                phServer,
                &dwCancelID,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                HDATimeToVariant(&htStartTime, pStartTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncReadProcessed(
    LONG TransactionID,
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    DATE ResampleInterval,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppAggregates,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppAggregates == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppAggregates, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppAggregates, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncRead)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            ULONGLONG ulResampleInterval;
            OPCHANDLE* phServer = NULL;
            OPCHDA_AGGREGATE* haAggregate = NULL;

            // convert days to 100ns intervals
            ulResampleInterval = ResampleInterval * 24.0 * 60.0 * 60.0 / 100e-9;

            phServer = new OPCHANDLE[NumItems];
            haAggregate = new OPCHDA_AGGREGATE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
                SafeArrayGetElement(*ppAggregates, &vbIndex, reinterpret_cast<void*>(&haAggregate[index]));
            }

            hr = m_pOPCHDA_AsyncRead->ReadProcessed(
                TransactionID,
                &htStartTime,
                &htEndTime,
                *reinterpret_cast<FILETIME*>(&ulResampleInterval),
                NumItems,
                phServer,
                (DWORD*) haAggregate,
                &dwCancelID,
                &pErrors);

            delete phServer;
            delete haAggregate;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncAdviseProcessed(
    LONG TransactionID,
    VARIANT * pStartTime,
    DATE ResampleInterval,
    LONG NumIntervals,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppAggregates,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppAggregates == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppAggregates, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppAggregates, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncRead)
    {
        OPCHDA_TIME htStartTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            ULONGLONG ulResampleInterval;
            OPCHANDLE* phServer = NULL;
            OPCHDA_AGGREGATE* haAggregate = NULL;

            // convert days to 100ns intervals
            ulResampleInterval = ResampleInterval * 24.0 * 60.0 * 60.0 / 100e-9;

            phServer = new OPCHANDLE[NumItems];
            haAggregate = new OPCHDA_AGGREGATE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
                SafeArrayGetElement(*ppAggregates, &vbIndex, reinterpret_cast<void*>(&haAggregate[index]));
            }

            hr = m_pOPCHDA_AsyncRead->AdviseProcessed(
                TransactionID,
                &htStartTime,
                *reinterpret_cast<FILETIME*>(&ulResampleInterval),
                NumItems,
                phServer,
                (DWORD*) haAggregate,
                NumIntervals,
                &dwCancelID,
                &pErrors);

            delete phServer;
            delete haAggregate;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                HDATimeToVariant(&htStartTime, pStartTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncReadAtTime(
    LONG TransactionID,
    LONG NumTimeStamps,
    SAFEARRAY ** ppTimeStamps,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumTimeStamps < 1)
    {
        return E_INVALIDARG;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumTimeStamps))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncRead)
    {
        FILETIME* pftTimeStamps = NULL;
        OPCHANDLE* phServer = NULL;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        pftTimeStamps = new FILETIME[NumTimeStamps];

        for (index = 0; index < NumTimeStamps; index++)
        {
            vbIndex = index + 1;

            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        phServer = new OPCHANDLE[NumItems];

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
        }

        hr = m_pOPCHDA_AsyncRead->ReadAtTime(
            TransactionID,
            NumTimeStamps,
            pftTimeStamps,
            NumItems,
            phServer,
            &dwCancelID,
            &pErrors);

        delete pftTimeStamps;

        delete phServer;

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncReadModified(
    LONG TransactionID,
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumValues,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncRead)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            OPCHANDLE* phServer = NULL;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_AsyncRead->ReadModified(
                TransactionID,
                &htStartTime,
                &htEndTime,
                NumValues,
                NumItems,
                phServer,
                &dwCancelID,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncReadAttribute(
    LONG TransactionID,
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG ServerHandle,
    LONG NumAttributes,
    SAFEARRAY ** ppAttributeIDs,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppAttributeIDs == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumAttributes < 1)
    {
        return E_INVALIDARG;
    }
		
    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppAttributeIDs, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppAttributeIDs, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumAttributes))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncRead)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            DWORD* pdwAttributeIDs = NULL;

            pdwAttributeIDs = new DWORD[NumAttributes];

            for (index = 0; index < NumAttributes; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppAttributeIDs, &vbIndex, reinterpret_cast<void*>(&pdwAttributeIDs[index]));
            }

            hr = m_pOPCHDA_AsyncRead->ReadAttribute(
                TransactionID,
                &htStartTime,
                &htEndTime,
                ServerHandle,
                NumAttributes,
                pdwAttributeIDs,
                &dwCancelID,
                &pErrors);

            delete pdwAttributeIDs;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumAttributes);

            if (NULL != *ppErrors)
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                for (index = 0; index < NumAttributes; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncCancelRead(
    LONG CancelID)
{
    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_AsyncRead)
    {
        hr = m_pOPCHDA_AsyncRead->Cancel(CancelID);
    }

	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncInsert(
    LONG TransactionID,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppDataValues,
    SAFEARRAY ** ppQualities,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }

	if (*ppDataValues == NULL)
    {
		return E_POINTER;
    }

	if (*ppQualities == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppDataValues, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppDataValues, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppQualities, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppQualities, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHANDLE* phServer = NULL;
        FILETIME* pftTimeStamps = NULL;
        VARIANT* pvDataValues = NULL;
        DWORD* pdwQualities = NULL;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        phServer = new OPCHANDLE[NumItems];
        pftTimeStamps = new FILETIME[NumItems];
        pvDataValues = new VARIANT[NumItems];
        pdwQualities = new DWORD[NumItems];

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            VariantInit(&pvDataValues[index]);

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));
            SafeArrayGetElement(*ppDataValues, &vbIndex, reinterpret_cast<void*>(&pvDataValues[index]));
            SafeArrayGetElement(*ppQualities, &vbIndex, reinterpret_cast<void*>(&pdwQualities[index]));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        hr = m_pOPCHDA_AsyncUpdate->Insert(
            TransactionID,
            NumItems,
            phServer,
            pftTimeStamps,
            pvDataValues,
            pdwQualities,
            &dwCancelID,
            &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        for (index = 0; index < NumItems; index++)
        {
            VariantClear(&pvDataValues[index]);
        }

        delete phServer;
        delete pftTimeStamps;
        delete pvDataValues;
        delete pdwQualities;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncReplace(
    LONG TransactionID,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppDataValues,
    SAFEARRAY ** ppQualities,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }

	if (*ppDataValues == NULL)
    {
		return E_POINTER;
    }

	if (*ppQualities == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppDataValues, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppDataValues, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppQualities, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppQualities, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHANDLE* phServer = NULL;
        FILETIME* pftTimeStamps = NULL;
        VARIANT* pvDataValues = NULL;
        DWORD* pdwQualities = NULL;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        phServer = new OPCHANDLE[NumItems];
        pftTimeStamps = new FILETIME[NumItems];
        pvDataValues = new VARIANT[NumItems];
        pdwQualities = new DWORD[NumItems];

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            VariantInit(&pvDataValues[index]);

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));
            SafeArrayGetElement(*ppDataValues, &vbIndex, reinterpret_cast<void*>(&pvDataValues[index]));
            SafeArrayGetElement(*ppQualities, &vbIndex, reinterpret_cast<void*>(&pdwQualities[index]));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        hr = m_pOPCHDA_AsyncUpdate->Replace(
            TransactionID,
            NumItems,
            phServer,
            pftTimeStamps,
            pvDataValues,
            pdwQualities,
            &dwCancelID,
            &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        for (index = 0; index < NumItems; index++)
        {
            VariantClear(&pvDataValues[index]);
        }

        delete phServer;
        delete pftTimeStamps;
        delete pvDataValues;
        delete pdwQualities;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncInsertReplace(
    LONG TransactionID,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppDataValues,
    SAFEARRAY ** ppQualities,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }

	if (*ppDataValues == NULL)
    {
		return E_POINTER;
    }

	if (*ppQualities == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppDataValues, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppDataValues, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppQualities, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppQualities, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHANDLE* phServer = NULL;
        FILETIME* pftTimeStamps = NULL;
        VARIANT* pvDataValues = NULL;
        DWORD* pdwQualities = NULL;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        phServer = new OPCHANDLE[NumItems];
        pftTimeStamps = new FILETIME[NumItems];
        pvDataValues = new VARIANT[NumItems];
        pdwQualities = new DWORD[NumItems];

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            VariantInit(&pvDataValues[index]);

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));
            SafeArrayGetElement(*ppDataValues, &vbIndex, reinterpret_cast<void*>(&pvDataValues[index]));
            SafeArrayGetElement(*ppQualities, &vbIndex, reinterpret_cast<void*>(&pdwQualities[index]));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        hr = m_pOPCHDA_AsyncUpdate->InsertReplace(
            TransactionID,
            NumItems,
            phServer,
            pftTimeStamps,
            pvDataValues,
            pdwQualities,
            &dwCancelID,
            &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        for (index = 0; index < NumItems; index++)
        {
            VariantClear(&pvDataValues[index]);
        }

        delete phServer;
        delete pftTimeStamps;
        delete pvDataValues;
        delete pdwQualities;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncDeleteRaw(
    LONG TransactionID,
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;
		
    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            OPCHANDLE* phServer = NULL;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_AsyncUpdate->DeleteRaw(
                TransactionID,
                &htStartTime,
                &htEndTime,
                NumItems,
                phServer,
                &dwCancelID,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL == *ppErrors)
            {
                hr = E_FAIL;
            }

            if (SUCCEEDED(hr))
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncDeleteAtTime(
    LONG TransactionID,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }

	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }

	if (ppErrors == NULL)
    {
		return E_POINTER;
    }

	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHANDLE* phServer = NULL;
        FILETIME* pftTimeStamps = NULL;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        phServer = new OPCHANDLE[NumItems];
        pftTimeStamps = new FILETIME[NumItems];

        LONG index, vbIndex;
        SYSTEMTIME st;
        DATE date;

        for (index = 0; index < NumItems; index++)
        {
            vbIndex = index + 1;

            SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            SafeArrayGetElement(*ppTimeStamps, &vbIndex, reinterpret_cast<void*>(&date));

            VariantTimeToSystemTime(date, &st);
            SystemTimeToFileTime(&st, &pftTimeStamps[index]);
            LocalFileTimeToFileTime(&pftTimeStamps[index], &pftTimeStamps[index]);
        }

        hr = m_pOPCHDA_AsyncUpdate->DeleteAtTime(
            TransactionID,
            NumItems,
            phServer,
            pftTimeStamps,
            &dwCancelID,
            &pErrors);

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        delete phServer;
        delete pftTimeStamps;
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncCancelUpdate(
    LONG CancelID)
{
    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_AsyncUpdate)
    {
        hr = m_pOPCHDA_AsyncUpdate->Cancel(CancelID);
    }

	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncReadAnnotations(
    LONG TransactionID,
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncAnnotations)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            OPCHANDLE* phServer = NULL;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_AsyncAnnotations->Read(
                TransactionID,
                &htStartTime,
                &htEndTime,
                NumItems,
                phServer,
                &dwCancelID,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncInsertAnnotations(
    LONG TransactionID,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppTimeStamps,
    SAFEARRAY ** ppAnnotationValues,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppTimeStamps == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppAnnotationValues == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppTimeStamps, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppTimeStamps, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppAnnotationValues, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppAnnotationValues, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_AsyncAnnotations)
    {
        // TODO: something is screwy in the spec
    }
		
	return E_NOTIMPL;
}

STDMETHODIMP COPCHDAAutoServer::AsyncCancelAnnotations(
    LONG CancelID)
{
    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_AsyncAnnotations)
    {
        hr = m_pOPCHDA_AsyncAnnotations->Cancel(CancelID);
    }

	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncPlaybackRaw(
    LONG TransactionID,
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumValues,
    DATE UpdateDuration,
    DATE UpdateInterval,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_Playback)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            ULONGLONG ulUpdateDuration;
            ULONGLONG ulUpdateInterval;
            OPCHANDLE* phServer = NULL;

            // convert days to 100ns intervals
            ulUpdateDuration = UpdateDuration * 24.0 * 60.0 * 60.0 / 100e-9;
            ulUpdateInterval = UpdateInterval * 24.0 * 60.0 * 60.0 / 100e-9;

            phServer = new OPCHANDLE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
            }

            hr = m_pOPCHDA_Playback->ReadRawWithUpdate(
                TransactionID,
                &htStartTime,
                &htEndTime,
                NumValues,
                *reinterpret_cast<FILETIME*>(&ulUpdateDuration),
                *reinterpret_cast<FILETIME*>(&ulUpdateInterval),
                NumItems,
                phServer,
                &dwCancelID,
                &pErrors);

            delete phServer;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncPlaybackProcessed(
    LONG TransactionID,
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    DATE ResampleInterval,
    LONG NumIntervals,
    DATE UpdateInterval,
    LONG NumItems,
    SAFEARRAY ** ppServerHandles,
    SAFEARRAY ** ppAggregates,
    SAFEARRAY ** ppErrors,
    LONG * pCancelID)
{
	if (pStartTime == NULL)
    {
		return E_POINTER;
    }
		
	if (pEndTime == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppServerHandles == NULL)
    {
		return E_POINTER;
    }
		
	if (*ppAggregates == NULL)
    {
		return E_POINTER;
    }
		
	if (ppErrors == NULL)
    {
		return E_POINTER;
    }
		
	if (pCancelID == NULL)
    {
		return E_POINTER;
    }
		
    if (NumItems < 1)
    {
        return E_INVALIDARG;
    }

    *ppErrors = NULL;

    HRESULT hr;

    LONG LBound = 0;
    LONG UBound = 0;

    hr = SafeArrayGetLBound(*ppServerHandles, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppServerHandles, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = SafeArrayGetLBound(*ppAggregates, 1, &LBound);

    if (FAILED(hr))
    {
        return hr;
    }

    hr = SafeArrayGetUBound(*ppAggregates, 1, &UBound);

    if (FAILED(hr))
    {
        return hr;
    }

    if ((LBound > 1) || (UBound < NumItems))
    {
        return E_INVALIDARG;
    }

    hr = E_FAIL;

    if (m_pOPCHDA_Playback)
    {
        OPCHDA_TIME htStartTime;
        OPCHDA_TIME htEndTime;
        DWORD dwCancelID = 0;
        HRESULT* pErrors = NULL;

        memset(&htStartTime, 0, sizeof(htStartTime));
        memset(&htEndTime, 0, sizeof(htEndTime));

        hr = VariantToHDATime(pStartTime, &htStartTime);

        if (SUCCEEDED(hr))
        {
            hr = VariantToHDATime(pEndTime, &htEndTime);
        }

        LONG index, vbIndex;

        if (SUCCEEDED(hr))
        {
            ULONGLONG ulResampleInterval;
            ULONGLONG ulUpdateInterval;
            OPCHANDLE* phServer = NULL;
            OPCHDA_AGGREGATE* haAggregate = NULL;

            // convert days to 100ns intervals
            ulResampleInterval = ResampleInterval * 24.0 * 60.0 * 60.0 / 100e-9;
            ulUpdateInterval = UpdateInterval * 24.0 * 60.0 * 60.0 / 100e-9;

            phServer = new OPCHANDLE[NumItems];
            haAggregate = new OPCHDA_AGGREGATE[NumItems];

            for (index = 0; index < NumItems; index++)
            {
                vbIndex = index + 1;

                SafeArrayGetElement(*ppServerHandles, &vbIndex, reinterpret_cast<void*>(&phServer[index]));
                SafeArrayGetElement(*ppAggregates, &vbIndex, reinterpret_cast<void*>(&haAggregate[index]));
            }

            hr = m_pOPCHDA_Playback->ReadProcessedWithUpdate(
                TransactionID,
                &htStartTime,
                &htEndTime,
                *reinterpret_cast<FILETIME*>(&ulResampleInterval),
                NumIntervals,
                *reinterpret_cast<FILETIME*>(&ulUpdateInterval),
                NumItems,
                phServer,
                (DWORD*) haAggregate,
                &dwCancelID,
                &pErrors);

            delete phServer;
            delete haAggregate;
        }

        if (SUCCEEDED(hr))
        {
            *ppErrors = SafeArrayCreateVector(VT_I4, 1, NumItems);

            if (NULL != *ppErrors)
            {
                HDATimeToVariant(&htStartTime, pStartTime);
                HDATimeToVariant(&htEndTime, pEndTime);

                for (index = 0; index < NumItems; index++)
                {
                    vbIndex = index + 1;

                    SafeArrayPutElement(*ppErrors, &vbIndex, &pErrors[index]);
                }

                *pCancelID = dwCancelID;
            }
            else
            {
                hr = E_FAIL;
            }

            CoTaskMemFree(pErrors);
        }

        if (NULL != htStartTime.szTime) CoTaskMemFree(htStartTime.szTime);
        if (NULL != htEndTime.szTime) CoTaskMemFree(htEndTime.szTime);
    }
		
	return hr;
}

STDMETHODIMP COPCHDAAutoServer::AsyncCancelPlayback(LONG CancelID)
{
    HRESULT hr = E_FAIL;

    if (m_pOPCHDA_Playback)
    {
        hr = m_pOPCHDA_Playback->Cancel(CancelID);
    }

	return hr;
}
