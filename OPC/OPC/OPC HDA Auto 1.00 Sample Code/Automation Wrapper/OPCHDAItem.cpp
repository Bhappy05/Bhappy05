/*  ____________________________________________________________________________

    OPCHDAItem.cpp

    COPCHDAItem class implementation.
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
#include "OPCHDAItem.h"

#include "OPCHDAAutoServer.h"

COPCHDAItem::COPCHDAItem()
{
    m_client = NULL;
    m_server = NULL;
    m_pParent = NULL;
}

COPCHDAItem::~COPCHDAItem()
{
}

STDMETHODIMP COPCHDAItem::Initialize( 
    BSTR szItemID,
    OPCHANDLE hClient,
    OPCHANDLE hServer,
    COPCHDAAutoServer* pParent)
{
    m_pParent = pParent;
    m_itemID = szItemID;
    m_client = hClient;
    m_server = hServer;

    return S_OK;
}

STDMETHODIMP COPCHDAItem::get_Parent(IOPCHDAAutoServer ** ppParent)
{
    if (NULL == ppParent)
    {
        return E_POINTER;
    }

    *ppParent = NULL;

    HRESULT hr;

    hr = ((CComObject<COPCHDAAutoServer>*)m_pParent)->QueryInterface(
        IID_IOPCHDAAutoServer,
        reinterpret_cast<void**>(ppParent));
    _ASSERTE(*ppParent);

    return hr;
}

STDMETHODIMP COPCHDAItem::get_ClientHandle(LONG * pClientHandle)
{
    if (NULL == pClientHandle)
    {
        return E_POINTER;
    }

    *pClientHandle = m_client;

    return S_OK;
}

STDMETHODIMP COPCHDAItem::get_ServerHandle(LONG * pServerHandle)
{
    if (NULL == pServerHandle)
    {
        return E_POINTER;
    }

    *pServerHandle = m_server;

    return S_OK;
}

STDMETHODIMP COPCHDAItem::get_ItemID(BSTR * pItemID)
{
    if (NULL == pItemID)
    {
        return E_POINTER;
    }

    *pItemID = m_itemID.Copy();

    return S_OK;
}

STDMETHODIMP COPCHDAItem::ReadRaw( 
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    LONG NumValues,
    BOOL Bounds,
    VARIANT * pItemValues)
{
    if (NULL == pItemValues)
    {
        return E_POINTER;
    }

    HRESULT hr = E_FAIL;
    
    if (m_pParent)
    {
        SAFEARRAY* pServerHandles = SafeArrayCreateVector(VT_I4, 1, 1);
        SAFEARRAY* pItemValues2 = NULL;
        SAFEARRAY* pErrors = NULL;

        LONG vbIndex = 1;

        SafeArrayPutElement(pServerHandles, &vbIndex, &m_server);

        hr = m_pParent->SyncReadRaw(
            pStartTime,
            pEndTime,
            NumValues,
            Bounds,
            1,
            &pServerHandles,
            &pItemValues2,
            &pErrors);

        SafeArrayDestroy(pServerHandles);

        if (SUCCEEDED(hr))
        {
            SafeArrayGetElement(pErrors, &vbIndex, &hr);

            if (SUCCEEDED(hr))
            {
                SafeArrayGetElement(pItemValues2, &vbIndex, pItemValues);
            }

            SafeArrayDestroy(pItemValues2);
            SafeArrayDestroy(pErrors);
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAItem::ReadProcessed( 
    VARIANT * pStartTime,
    VARIANT * pEndTime,
    DATE ResampleInterval,
    LONG Aggregate,
    VARIANT * pItemValues)
{
    if (NULL == pItemValues)
    {
        return E_POINTER;
    }

    HRESULT hr = E_FAIL;
    
    if (m_pParent)
    {
        SAFEARRAY* pServerHandles = SafeArrayCreateVector(VT_I4, 1, 1);
        SAFEARRAY* pAggregates = SafeArrayCreateVector(VT_I4, 1, 1);
        SAFEARRAY* pItemValues2 = NULL;
        SAFEARRAY* pErrors = NULL;

        LONG vbIndex = 1;

        SafeArrayPutElement(pServerHandles, &vbIndex, &m_server);
        SafeArrayPutElement(pAggregates, &vbIndex, &Aggregate);

        hr = m_pParent->SyncReadProcessed(
            pStartTime,
            pEndTime,
            ResampleInterval,
            1,
            &pServerHandles,
            &pAggregates,
            &pItemValues2,
            &pErrors);

        SafeArrayDestroy(pServerHandles);
        SafeArrayDestroy(pAggregates);

        if (SUCCEEDED(hr))
        {
            SafeArrayGetElement(pErrors, &vbIndex, &hr);

            if (SUCCEEDED(hr))
            {
                SafeArrayGetElement(pItemValues2, &vbIndex, pItemValues);
            }

            SafeArrayDestroy(pItemValues2);
            SafeArrayDestroy(pErrors);
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAItem::ReadAtTime( 
    LONG NumTimeStamps,
    SAFEARRAY ** ppTimeStamps,
    VARIANT * pItemValues)
{
    if (NULL == pItemValues)
    {
        return E_POINTER;
    }

    HRESULT hr = E_FAIL;
    
    if (m_pParent)
    {
        SAFEARRAY* pServerHandles = SafeArrayCreateVector(VT_I4, 1, 1);
        SAFEARRAY* pItemValues2 = NULL;
        SAFEARRAY* pErrors = NULL;

        LONG vbIndex = 1;

        SafeArrayPutElement(pServerHandles, &vbIndex, &m_server);

        hr = m_pParent->SyncReadAtTime(
            NumTimeStamps,
            ppTimeStamps,
            1,
            &pServerHandles,
            &pItemValues2,
            &pErrors);

        SafeArrayDestroy(pServerHandles);

        if (SUCCEEDED(hr))
        {
            SafeArrayGetElement(pErrors, &vbIndex, &hr);

            if (SUCCEEDED(hr))
            {
                SafeArrayGetElement(pItemValues2, &vbIndex, pItemValues);
            }

            SafeArrayDestroy(pItemValues2);
            SafeArrayDestroy(pErrors);
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAItem::Update( 
    DATE TimeStamp,
    VARIANT DataValue,
    LONG Quality,
    LONG EditType)
{
    HRESULT hr = E_FAIL;
    
    if (m_pParent)
    {
        SAFEARRAY* pServerHandles = SafeArrayCreateVector(VT_I4, 1, 1);
        SAFEARRAY* pTimeStamps = SafeArrayCreateVector(VT_DATE, 1, 1);
        SAFEARRAY* pDataValues = SafeArrayCreateVector(VT_VARIANT, 1, 1);
        SAFEARRAY* pQualities = SafeArrayCreateVector(VT_I4, 1, 1);
        SAFEARRAY* pErrors = NULL;

        LONG vbIndex = 1;

        SafeArrayPutElement(pServerHandles, &vbIndex, &m_server);
        SafeArrayPutElement(pTimeStamps, &vbIndex, &TimeStamp);
        SafeArrayPutElement(pDataValues, &vbIndex, &DataValue);
        SafeArrayPutElement(pQualities, &vbIndex, &Quality);

        switch (EditType)
        {
        case OPCHDAInsert:
            hr = m_pParent->SyncInsert(
                1,
                &pServerHandles,
                &pTimeStamps,
                &pDataValues,
                &pQualities,
                &pErrors);
            break;

        case OPCHDAReplace:
            hr = m_pParent->SyncReplace(
                1,
                &pServerHandles,
                &pTimeStamps,
                &pDataValues,
                &pQualities,
                &pErrors);
            break;

        case OPCHDAInsertReplace:
            hr = m_pParent->SyncInsertReplace(
                1,
                &pServerHandles,
                &pTimeStamps,
                &pDataValues,
                &pQualities,
                &pErrors);
            break;

        case OPCHDADelete:
            hr = m_pParent->SyncDeleteAtTime(
                1,
                &pServerHandles,
                &pTimeStamps,
                &pErrors);
            break;

        case OPCHDAAnnotate:
            hr = m_pParent->SyncInsertAnnotations(
                1,
                &pServerHandles,
                &pTimeStamps,
                &pDataValues,
                &pErrors);
            break;

        default:
            hr = E_INVALIDARG;
        }

        SafeArrayDestroy(pServerHandles);
        SafeArrayDestroy(pTimeStamps);
        SafeArrayDestroy(pDataValues);
        SafeArrayDestroy(pQualities);

        if (SUCCEEDED(hr))
        {
            SafeArrayGetElement(pErrors, &vbIndex, &hr);

            SafeArrayDestroy(pErrors);
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAItem::DeleteRaw( 
    VARIANT * pStartTime,
    VARIANT * pEndTime)
{
    HRESULT hr = E_FAIL;
    
    if (m_pParent)
    {
        SAFEARRAY* pServerHandles = SafeArrayCreateVector(VT_I4, 1, 1);
        SAFEARRAY* pErrors = NULL;

        LONG vbIndex = 1;

        SafeArrayPutElement(pServerHandles, &vbIndex, &m_server);

        hr = m_pParent->SyncDeleteRaw(
            pStartTime,
            pEndTime,
            1,
            &pServerHandles,
            &pErrors);

        SafeArrayDestroy(pServerHandles);

        if (SUCCEEDED(hr))
        {
            SafeArrayGetElement(pErrors, &vbIndex, &hr);

            SafeArrayDestroy(pErrors);
        }
    }

    return hr;
}
