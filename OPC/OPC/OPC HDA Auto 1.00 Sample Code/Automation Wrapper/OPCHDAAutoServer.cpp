/*  ____________________________________________________________________________

    OPCHDAAutoServer.cpp

    COPCHDAAutoServer class implementation.
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

#include "OPCHDABrowser.h"

COPCHDAAutoServer::COPCHDAAutoServer()
{
    HRESULT hr;

    m_ShutdownConnection = 0;
    m_DataConnection = 0;
    
    hr = CoInitializeSecurity(
        NULL,
        -1,
        NULL,
        NULL,
        RPC_C_AUTHN_LEVEL_NONE,
        RPC_C_IMP_LEVEL_IDENTIFY,
        NULL,
        EOAC_NONE,
        NULL);
}

COPCHDAAutoServer::~COPCHDAAutoServer()
{
    Disconnect();
}

STDMETHODIMP COPCHDAAutoServer::VariantToHDATime(
    const VARIANT* pvTime,
    OPCHDA_TIME* phtTime)
{
    HRESULT hr = S_OK;

    if (NULL != phtTime->szTime)
    {
        CoTaskMemFree(phtTime->szTime);

        phtTime->szTime = NULL;
    }

    if (VT_BSTR == pvTime->vt)
    {
        phtTime->bString = TRUE;

        if (NULL != pvTime->bstrVal)
        {
            phtTime->szTime = (LPWSTR)CoTaskMemAlloc(SysStringByteLen(pvTime->bstrVal) + sizeof(WCHAR));

            wcscpy(phtTime->szTime, pvTime->bstrVal);
        }
        else
        {
            phtTime->szTime = (LPWSTR)CoTaskMemAlloc(sizeof(WCHAR));

            phtTime->szTime[0] = 0;
        }
    }
    else
    {
        phtTime->bString = FALSE;

        VARIANT v;

        VariantInit(&v);

        hr = VariantChangeType(&v, const_cast<VARIANTARG*>(pvTime), 0, VT_DATE);

        if (SUCCEEDED(hr))
        {
            SYSTEMTIME st;

            if ((FALSE != VariantTimeToSystemTime(v.date, &st)) &&
                (FALSE != SystemTimeToFileTime(&st, &phtTime->ftTime)) &&
                (FALSE != LocalFileTimeToFileTime(&phtTime->ftTime, &phtTime->ftTime)))
            {
                phtTime->szTime = (LPWSTR)CoTaskMemAlloc(sizeof(WCHAR));

                phtTime->szTime[0] = 0;
            }
            else
            {
                hr = E_FAIL;
            }
        }

        VariantClear(&v);
    }

    return hr;
}

void COPCHDAAutoServer::HDATimeToVariant(
    const OPCHDA_TIME* phtTime,
    VARIANT* pvTime)
{
    VariantClear(pvTime);

    FILETIME ft;
    SYSTEMTIME st;
    DATE date;

    if ((FALSE != FileTimeToLocalFileTime(&phtTime->ftTime, &ft)) &&
        (FALSE != FileTimeToSystemTime(&ft, &st)) &&
        (FALSE != SystemTimeToVariantTime(&st, &date)))
    {
        pvTime->vt = VT_DATE;

        pvTime->date = date;
    }
    else
    {
        pvTime->vt = VT_ERROR;

        pvTime->scode = E_FAIL;
    }
}

STDMETHODIMP COPCHDAAutoServer::InterfaceSupportsErrorInfo(
    REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IOPCHDAAutoServer
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
        if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP COPCHDAAutoServer::ShutdownRequest(
    LPCWSTR szReason)
{
    CComBSTR Reason(szReason);
    Fire_HDAServerShutDown(Reason);
    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_StartTime(DATE * pStartTime)
{
    if (pStartTime == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCHDAServer)
    {
        return E_FAIL;
    }

    HRESULT hr;
    OPCHDA_SERVERSTATUS dwStatus;
    FILETIME* pftCurrentTime;
    FILETIME* pftStartTime;
    WORD wMajorVersion;
    WORD wMinorVersion;
    WORD wBuildNumber;
    DWORD dwMaxReturnValues;
    LPWSTR szStatusString;
    LPWSTR szVendorInfo;
    
    hr = m_pOPCHDAServer->GetHistorianStatus(
        &dwStatus,
        &pftCurrentTime,
        &pftStartTime,
        &wMajorVersion,
        &wMinorVersion,
        &wBuildNumber,
        &dwMaxReturnValues,
        &szStatusString,
        &szVendorInfo);

    if (FAILED(hr))
    {
        return hr;
    }

    *pStartTime = 0;

    FILETIME ft;

    if (0 != FileTimeToLocalFileTime(pftStartTime, &ft))
    {
        SYSTEMTIME st;

        if (0 != FileTimeToSystemTime(&ft, &st))
        {
            SystemTimeToVariantTime(&st, pStartTime);
        }
    }

    CoTaskMemFree(pftCurrentTime);
    CoTaskMemFree(pftStartTime);
    CoTaskMemFree(szStatusString);
    CoTaskMemFree(szVendorInfo);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_CurrentTime(DATE * pCurrentTime)
{
    if (pCurrentTime == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCHDAServer)
    {
        return E_FAIL;
    }

    HRESULT hr;
    OPCHDA_SERVERSTATUS dwStatus;
    FILETIME* pftCurrentTime;
    FILETIME* pftStartTime;
    WORD wMajorVersion;
    WORD wMinorVersion;
    WORD wBuildNumber;
    DWORD dwMaxReturnValues;
    LPWSTR szStatusString;
    LPWSTR szVendorInfo;
    
    hr = m_pOPCHDAServer->GetHistorianStatus(
        &dwStatus,
        &pftCurrentTime,
        &pftStartTime,
        &wMajorVersion,
        &wMinorVersion,
        &wBuildNumber,
        &dwMaxReturnValues,
        &szStatusString,
        &szVendorInfo);

    if (FAILED(hr))
    {
        return hr;
    }

    *pCurrentTime = 0;

    FILETIME ft;

    if (0 != FileTimeToLocalFileTime(pftStartTime, &ft))
    {
        SYSTEMTIME st;

        if (0 != FileTimeToSystemTime(&ft, &st))
        {
            SystemTimeToVariantTime(&st, pCurrentTime);
        }
    }

    CoTaskMemFree(pftCurrentTime);
    CoTaskMemFree(pftStartTime);
    CoTaskMemFree(szStatusString);
    CoTaskMemFree(szVendorInfo);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_MaxReturnValues(LONG * pMaxReturnValues)
{
    if (pMaxReturnValues == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCHDAServer)
    {
        return E_FAIL;
    }

    HRESULT hr;
    OPCHDA_SERVERSTATUS dwStatus;
    FILETIME* pftCurrentTime;
    FILETIME* pftStartTime;
    WORD wMajorVersion;
    WORD wMinorVersion;
    WORD wBuildNumber;
    DWORD dwMaxReturnValues;
    LPWSTR szStatusString;
    LPWSTR szVendorInfo;
    
    hr = m_pOPCHDAServer->GetHistorianStatus(
        &dwStatus,
        &pftCurrentTime,
        &pftStartTime,
        &wMajorVersion,
        &wMinorVersion,
        &wBuildNumber,
        &dwMaxReturnValues,
        &szStatusString,
        &szVendorInfo);

    if (FAILED(hr))
    {
        return hr;
    }

    *pMaxReturnValues = dwMaxReturnValues;

    CoTaskMemFree(pftCurrentTime);
    CoTaskMemFree(pftStartTime);
    CoTaskMemFree(szStatusString);
    CoTaskMemFree(szVendorInfo);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_MajorVersion(short * pMajorVersion)
{
    if (pMajorVersion == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCHDAServer)
    {
        return E_FAIL;
    }

    HRESULT hr;
    OPCHDA_SERVERSTATUS dwStatus;
    FILETIME* pftCurrentTime;
    FILETIME* pftStartTime;
    WORD wMajorVersion;
    WORD wMinorVersion;
    WORD wBuildNumber;
    DWORD dwMaxReturnValues;
    LPWSTR szStatusString;
    LPWSTR szVendorInfo;
    
    hr = m_pOPCHDAServer->GetHistorianStatus(
        &dwStatus,
        &pftCurrentTime,
        &pftStartTime,
        &wMajorVersion,
        &wMinorVersion,
        &wBuildNumber,
        &dwMaxReturnValues,
        &szStatusString,
        &szVendorInfo);

    if (FAILED(hr))
    {
        return hr;
    }

    *pMajorVersion = wMajorVersion;

    CoTaskMemFree(pftCurrentTime);
    CoTaskMemFree(pftStartTime);
    CoTaskMemFree(szStatusString);
    CoTaskMemFree(szVendorInfo);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_MinorVersion(short * pMinorVersion)
{
    if (pMinorVersion == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCHDAServer)
    {
        return E_FAIL;
    }

    HRESULT hr;
    OPCHDA_SERVERSTATUS dwStatus;
    FILETIME* pftCurrentTime;
    FILETIME* pftStartTime;
    WORD wMajorVersion;
    WORD wMinorVersion;
    WORD wBuildNumber;
    DWORD dwMaxReturnValues;
    LPWSTR szStatusString;
    LPWSTR szVendorInfo;
    
    hr = m_pOPCHDAServer->GetHistorianStatus(
        &dwStatus,
        &pftCurrentTime,
        &pftStartTime,
        &wMajorVersion,
        &wMinorVersion,
        &wBuildNumber,
        &dwMaxReturnValues,
        &szStatusString,
        &szVendorInfo);

    if (FAILED(hr))
    {
        return hr;
    }

    *pMinorVersion = wMinorVersion;

    CoTaskMemFree(pftCurrentTime);
    CoTaskMemFree(pftStartTime);
    CoTaskMemFree(szStatusString);
    CoTaskMemFree(szVendorInfo);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_BuildNumber(short * pBuildNumber)
{
    if (pBuildNumber == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCHDAServer)
    {
        return E_FAIL;
    }

    HRESULT hr;
    OPCHDA_SERVERSTATUS dwStatus;
    FILETIME* pftCurrentTime;
    FILETIME* pftStartTime;
    WORD wMajorVersion;
    WORD wMinorVersion;
    WORD wBuildNumber;
    DWORD dwMaxReturnValues;
    LPWSTR szStatusString;
    LPWSTR szVendorInfo;
    
    hr = m_pOPCHDAServer->GetHistorianStatus(
        &dwStatus,
        &pftCurrentTime,
        &pftStartTime,
        &wMajorVersion,
        &wMinorVersion,
        &wBuildNumber,
        &dwMaxReturnValues,
        &szStatusString,
        &szVendorInfo);

    if (FAILED(hr))
    {
        return hr;
    }

    *pBuildNumber = wBuildNumber;

    CoTaskMemFree(pftCurrentTime);
    CoTaskMemFree(pftStartTime);
    CoTaskMemFree(szStatusString);
    CoTaskMemFree(szVendorInfo);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_VendorInfo(BSTR * pVendorInfo)
{
    if (pVendorInfo == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCHDAServer)
    {
        return E_FAIL;
    }

    HRESULT hr;
    OPCHDA_SERVERSTATUS dwStatus;
    FILETIME* pftCurrentTime;
    FILETIME* pftStartTime;
    WORD wMajorVersion;
    WORD wMinorVersion;
    WORD wBuildNumber;
    DWORD dwMaxReturnValues;
    LPWSTR szStatusString;
    LPWSTR szVendorInfo;
    
    hr = m_pOPCHDAServer->GetHistorianStatus(
        &dwStatus,
        &pftCurrentTime,
        &pftStartTime,
        &wMajorVersion,
        &wMinorVersion,
        &wBuildNumber,
        &dwMaxReturnValues,
        &szStatusString,
        &szVendorInfo);

    if (FAILED(hr))
    {
        return hr;
    }

    *pVendorInfo = SysAllocString(szVendorInfo);

    CoTaskMemFree(pftCurrentTime);
    CoTaskMemFree(pftStartTime);
    CoTaskMemFree(szStatusString);
    CoTaskMemFree(szVendorInfo);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_HistorianStatus(LONG * pHistorianStatus)
{
    if (pHistorianStatus == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCHDAServer)
    {
        return E_FAIL;
    }

    HRESULT hr;
    OPCHDA_SERVERSTATUS dwStatus;
    FILETIME* pftCurrentTime;
    FILETIME* pftStartTime;
    WORD wMajorVersion;
    WORD wMinorVersion;
    WORD wBuildNumber;
    DWORD dwMaxReturnValues;
    LPWSTR szStatusString;
    LPWSTR szVendorInfo;
    
    hr = m_pOPCHDAServer->GetHistorianStatus(
        &dwStatus,
        &pftCurrentTime,
        &pftStartTime,
        &wMajorVersion,
        &wMinorVersion,
        &wBuildNumber,
        &dwMaxReturnValues,
        &szStatusString,
        &szVendorInfo);

    if (FAILED(hr))
    {
        return hr;
    }

    *pHistorianStatus = dwStatus;

    CoTaskMemFree(pftCurrentTime);
    CoTaskMemFree(pftStartTime);
    CoTaskMemFree(szStatusString);
    CoTaskMemFree(szVendorInfo);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_StatusString(BSTR * pStatusString)
{
    if (pStatusString == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCHDAServer)
    {
        return E_FAIL;
    }

    HRESULT hr;
    OPCHDA_SERVERSTATUS dwStatus;
    FILETIME* pftCurrentTime;
    FILETIME* pftStartTime;
    WORD wMajorVersion;
    WORD wMinorVersion;
    WORD wBuildNumber;
    DWORD dwMaxReturnValues;
    LPWSTR szStatusString;
    LPWSTR szVendorInfo;
    
    hr = m_pOPCHDAServer->GetHistorianStatus(
        &dwStatus,
        &pftCurrentTime,
        &pftStartTime,
        &wMajorVersion,
        &wMinorVersion,
        &wBuildNumber,
        &dwMaxReturnValues,
        &szStatusString,
        &szVendorInfo);

    if (FAILED(hr))
    {
        return hr;
    }

    *pStatusString = SysAllocString(szStatusString);

    CoTaskMemFree(pftCurrentTime);
    CoTaskMemFree(pftStartTime);
    CoTaskMemFree(szStatusString);
    CoTaskMemFree(szVendorInfo);

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_ServerName(BSTR * pServerName)
{
    if (pServerName == NULL)
    {
        return E_POINTER;
    }

    *pServerName = m_name.Copy();

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_ServerNode(BSTR * pServerNode)
{
    if (pServerNode == NULL)
    {
        return E_POINTER;
    }

    *pServerNode = m_node.Copy();

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::get_ClientName(BSTR * pClientName)
{
    if (pClientName == NULL)
    {
        return E_POINTER;
    }

    *pClientName = m_client.Copy();

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::put_ClientName(BSTR ClientName)
{
    HRESULT hr = S_OK;

    m_client = ClientName;

    if (m_pOPCCommon)
    {
        hr = m_pOPCCommon->SetClientName(m_client);
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_LocaleID(LONG * pLocaleID)
{
    if (pLocaleID == NULL)
    {
        return E_POINTER;
    }

    if (!m_pOPCCommon)
    {
        return E_FAIL;
    }

    HRESULT hr;

    hr = m_pOPCCommon->GetLocaleID((LCID*)pLocaleID);

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::put_LocaleID(LONG LocaleID)
{
    if (!m_pOPCCommon)
    {
        return E_FAIL;
    }

    HRESULT hr;

    hr = m_pOPCCommon->SetLocaleID(LocaleID);

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanSyncInsert(BOOL * pCanSyncInsert)
{
    if (pCanSyncInsert == NULL)
    {
        return E_POINTER;
    }

    *pCanSyncInsert = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_SyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_INSERTCAP))
        {
            *pCanSyncInsert = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanSyncReplace(BOOL * pCanSyncReplace)
{
    if (pCanSyncReplace == NULL)
    {
        return E_POINTER;
    }

    *pCanSyncReplace = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_SyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_REPLACECAP))
        {
            *pCanSyncReplace = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanSyncInsertReplace(BOOL * pCanSyncInsertReplace)
{
    if (pCanSyncInsertReplace == NULL)
    {
        return E_POINTER;
    }

    *pCanSyncInsertReplace = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_SyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_INSERTREPLACECAP))
        {
            *pCanSyncInsertReplace = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanSyncDeleteRaw(BOOL * pCanSyncDeleteRaw)
{
    if (pCanSyncDeleteRaw == NULL)
    {
        return E_POINTER;
    }

    *pCanSyncDeleteRaw = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_SyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_DELETERAWCAP))
        {
            *pCanSyncDeleteRaw = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanSyncDeleteAtTime(BOOL * pCanSyncDeleteAtTime)
{
    if (pCanSyncDeleteAtTime == NULL)
    {
        return E_POINTER;
    }

    *pCanSyncDeleteAtTime = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_SyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_SyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_DELETEATTIMECAP))
        {
            *pCanSyncDeleteAtTime = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanSyncReadAnnotations(BOOL * pCanSyncReadAnnotations)
{
    if (pCanSyncReadAnnotations == NULL)
    {
        return E_POINTER;
    }

    *pCanSyncReadAnnotations = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_SyncAnnotations)
    {
        OPCHDA_ANNOTATIONCAPABILITIES dwCapabilities = (OPCHDA_ANNOTATIONCAPABILITIES)0;

        hr = m_pOPCHDA_SyncAnnotations->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_READANNOTATIONCAP))
        {
            *pCanSyncReadAnnotations = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanSyncInsertAnnotations(BOOL * pCanSyncInsertAnnotations)
{
    if (pCanSyncInsertAnnotations == NULL)
    {
        return E_POINTER;
    }

    *pCanSyncInsertAnnotations = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_SyncAnnotations)
    {
        OPCHDA_ANNOTATIONCAPABILITIES dwCapabilities = (OPCHDA_ANNOTATIONCAPABILITIES)0;

        hr = m_pOPCHDA_SyncAnnotations->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_INSERTANNOTATIONCAP))
        {
            *pCanSyncInsertAnnotations = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanAsyncInsert(BOOL * pCanAsyncInsert)
{
    if (pCanAsyncInsert == NULL)
    {
        return E_POINTER;
    }

    *pCanAsyncInsert = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_AsyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_INSERTCAP))
        {
            *pCanAsyncInsert = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanAsyncReplace(BOOL * pCanAsyncReplace)
{
    if (pCanAsyncReplace == NULL)
    {
        return E_POINTER;
    }

    *pCanAsyncReplace = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_AsyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_REPLACECAP))
        {
            *pCanAsyncReplace = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanAsyncInsertReplace(BOOL * pCanAsyncInsertReplace)
{
    if (pCanAsyncInsertReplace == NULL)
    {
        return E_POINTER;
    }

    *pCanAsyncInsertReplace = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_AsyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_INSERTREPLACECAP))
        {
            *pCanAsyncInsertReplace = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanAsyncDeleteRaw(BOOL * pCanAsyncDeleteRaw)
{
    if (pCanAsyncDeleteRaw == NULL)
    {
        return E_POINTER;
    }

    *pCanAsyncDeleteRaw = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_AsyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_DELETERAWCAP))
        {
            *pCanAsyncDeleteRaw = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanAsyncDeleteAtTime(BOOL * pCanAsyncDeleteAtTime)
{
    if (pCanAsyncDeleteAtTime == NULL)
    {
        return E_POINTER;
    }

    *pCanAsyncDeleteAtTime = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_AsyncUpdate)
    {
        OPCHDA_UPDATECAPABILITIES dwCapabilities = (OPCHDA_UPDATECAPABILITIES)0;

        hr = m_pOPCHDA_AsyncUpdate->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_DELETEATTIMECAP))
        {
            *pCanAsyncDeleteAtTime = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanAsyncReadAnnotations(BOOL * pCanAsyncReadAnnotations)
{
    if (pCanAsyncReadAnnotations == NULL)
    {
        return E_POINTER;
    }

    *pCanAsyncReadAnnotations = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_AsyncAnnotations)
    {
        OPCHDA_ANNOTATIONCAPABILITIES dwCapabilities = (OPCHDA_ANNOTATIONCAPABILITIES)0;

        hr = m_pOPCHDA_AsyncAnnotations->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_READANNOTATIONCAP))
        {
            *pCanAsyncReadAnnotations = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_CanAsyncInsertAnnotations(BOOL * pCanAsyncInsertAnnotations)
{
    if (pCanAsyncInsertAnnotations == NULL)
    {
        return E_POINTER;
    }

    *pCanAsyncInsertAnnotations = FALSE;

    HRESULT hr = S_OK;

    if (m_pOPCHDA_AsyncAnnotations)
    {
        OPCHDA_ANNOTATIONCAPABILITIES dwCapabilities = (OPCHDA_ANNOTATIONCAPABILITIES)0;

        hr = m_pOPCHDA_AsyncAnnotations->QueryCapabilities(&dwCapabilities);

        if (SUCCEEDED(hr) && (dwCapabilities & OPCHDA_INSERTANNOTATIONCAP))
        {
            *pCanAsyncInsertAnnotations = TRUE;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::get_OPCHDAItems(IOPCHDAItems ** ppOPCHDAItems)
{
    if (ppOPCHDAItems == NULL)
    {
        return E_POINTER;
    }

    *ppOPCHDAItems = NULL;

    HRESULT hr;

    hr = ((CComObject<COPCHDAAutoServer>*)this)->QueryInterface(
        IID_IOPCHDAItems,
        reinterpret_cast<void**>(ppOPCHDAItems));

   _ASSERTE(*ppOPCHDAItems);

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::GetOPCHDAServers(
    VARIANT Node,
    VARIANT * pOPCHDAServers)
{
    USES_CONVERSION;

    if (pOPCHDAServers == NULL)
    {
        return E_POINTER;
    }

    HRESULT hr = E_FAIL;
    DWORD dwClsCtx = CLSCTX_ALL;
    COSERVERINFO ServerInfo;
    MULTI_QI Result;

    memset(&ServerInfo, 0, sizeof(ServerInfo));
    memset(&Result, 0, sizeof(Result));

    if ((VT_BSTR == Node.vt) &&
        (DISP_E_PARAMNOTFOUND != Node.scode) &&
        (NULL != Node.bstrVal) &&
        (0 != Node.bstrVal[0]) &&
        (0 != wcsicmp(L"localhost", Node.bstrVal)) &&
        (0 != wcsicmp(L"127.0.0.1", Node.bstrVal)))
    {
        TCHAR szLocalHost[MAX_COMPUTERNAME_LENGTH + 1];

        DWORD dwSize = sizeof(szLocalHost) / sizeof(szLocalHost[0]);

        if ((0 == GetComputerName(szLocalHost, &dwSize)) || (0 != wcsicmp(T2W(szLocalHost), Node.bstrVal)))
        {
            dwClsCtx = CLSCTX_REMOTE_SERVER;

            ServerInfo.pwszName = Node.bstrVal;
        }
    }

    Result.pIID = &IID_IOPCServerList;

    if (CLSCTX_REMOTE_SERVER == dwClsCtx)
    {
        hr = CoCreateInstanceEx(
            CLSID_OPCServerList,
            NULL,
            dwClsCtx,
            &ServerInfo,
            1,
            &Result);
    }
    else
    {
        hr = CoCreateInstance(
            CLSID_OPCServerList,
            NULL,
            dwClsCtx,
            *Result.pIID,
            reinterpret_cast<void**>(&Result.pItf));
    }

    if (SUCCEEDED(hr))
    {
        hr = Result.hr;
    }

    if (SUCCEEDED(hr))
    {
        IOPCServerList* pOPCServerList = reinterpret_cast<IOPCServerList*>(Result.pItf);

        IEnumGUID* pEnumGUID = NULL;

        CATID rgcatidImpl[1];

        rgcatidImpl[0] = CATID_OPCHDAServer10;

        hr = pOPCServerList->EnumClassesOfCategories(
            1,
            rgcatidImpl,
            0,
            NULL,
            &pEnumGUID);

        if (SUCCEEDED(hr))
        {
            ULONG count, index;
            LPOLESTR szProgID;
            LPOLESTR szUserType;
            CLSID clsid[NEXT_COUNT];

            std::list<LPOLESTR> ProgIDs;
            std::list<LPOLESTR>::iterator it;

            do
            {
                count = 0;

                hr = pEnumGUID->Next(NEXT_COUNT, clsid, &count);

                for (index = 0; index < count; index++)
                {
                    HRESULT hr2;

                    hr2 = pOPCServerList->GetClassDetails(clsid[index], &szProgID, &szUserType);

                    if (SUCCEEDED(hr2))
                    {
                        ProgIDs.push_back(szProgID);

                        CoTaskMemFree(szUserType);
                    }
                }
            }
            while (S_OK == hr);

            if (SUCCEEDED(hr))
            {
                SAFEARRAY* parray = SafeArrayCreateVector(VT_BSTR, 1, ProgIDs.size());

                if (NULL != parray)
                {
                    LONG lIndex = 0;
                    BSTR bstr;

                    for (it = ProgIDs.begin(); ProgIDs.end() != it; it++)
                    {
                        lIndex++;

                        szProgID = *it;

                        bstr = SysAllocString(szProgID);

                        CoTaskMemFree(szProgID);

                        SafeArrayPutElement(parray, &lIndex, reinterpret_cast<void*>(bstr));
                    }

                    VariantClear(pOPCHDAServers);

                    pOPCHDAServers->vt = VT_ARRAY | VT_BSTR;
                    pOPCHDAServers->parray = parray;
                }
                else
                {
                    hr = E_FAIL;
                }
            }

            if (FAILED(hr))
            {
                for (it = ProgIDs.begin(); ProgIDs.end() != it; it++)
                {
                    szProgID = *it;

                    CoTaskMemFree(szProgID);
                }
            }

            pEnumGUID->Release();
        }

        pOPCServerList->Release();
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::Connect(
    BSTR ProgID,
    VARIANT Node)
{
    USES_CONVERSION;

    HRESULT hr = E_FAIL;
    DWORD dwClsCtx = CLSCTX_ALL;
    COSERVERINFO ServerInfo;
    MULTI_QI Result;
    CLSID clsid = CLSID_NULL;

    memset(&ServerInfo, 0, sizeof(ServerInfo));
    memset(&Result, 0, sizeof(Result));

    Disconnect();

    if ((VT_BSTR == Node.vt) &&
        (DISP_E_PARAMNOTFOUND != Node.scode) &&
        (NULL != Node.bstrVal) &&
        (0 != Node.bstrVal[0]) &&
        (0 != wcsicmp(L"localhost", Node.bstrVal)) &&
        (0 != wcsicmp(L"127.0.0.1", Node.bstrVal)))
    {
        TCHAR szLocalHost[MAX_COMPUTERNAME_LENGTH + 1];

        DWORD dwSize = sizeof(szLocalHost) / sizeof(szLocalHost[0]);

        if ((0 == GetComputerName(szLocalHost, &dwSize)) || (0 != wcsicmp(T2W(szLocalHost), Node.bstrVal)))
        {
            dwClsCtx = CLSCTX_REMOTE_SERVER;

            ServerInfo.pwszName = Node.bstrVal;
        }
    }

    // get class information

    Result.pIID = &IID_IOPCServerList;

    if (CLSCTX_REMOTE_SERVER == dwClsCtx)
    {
        hr = CoCreateInstanceEx(
            CLSID_OPCServerList,
            NULL,
            dwClsCtx,
            &ServerInfo,
            1,
            &Result);
    }
    else
    {
        hr = CoCreateInstance(
            CLSID_OPCServerList,
            NULL,
            dwClsCtx,
            *Result.pIID,
            reinterpret_cast<void**>(&Result.pItf));
    }

    if (SUCCEEDED(hr))
    {
        hr = Result.hr;
    }

    if (SUCCEEDED(hr))
    {
        IOPCServerList* pOPCServerList = reinterpret_cast<IOPCServerList*>(Result.pItf);

        hr = pOPCServerList->CLSIDFromProgID(ProgID, &clsid);

        pOPCServerList->Release();
    }

    if (FAILED(hr))
    {
        hr = CLSIDFromProgID(ProgID, &clsid);
    }

    if (FAILED(hr))
    {
        hr = CLSIDFromString(ProgID, &clsid);
    }

    // connect to server

	if (SUCCEEDED(hr))
	{
        memset(&Result, 0, sizeof(Result));

        Result.pIID = &IID_IOPCHDA_Server;

        if (CLSCTX_REMOTE_SERVER == dwClsCtx)
        {
            hr = CoCreateInstanceEx(
                clsid,
                NULL,
                dwClsCtx,
                &ServerInfo,
                1,
                &Result);
        }
        else
        {
            hr = CoCreateInstance(
                clsid,
                NULL,
                dwClsCtx,
                *Result.pIID,
                reinterpret_cast<void**>(&Result.pItf));
        }

		if (SUCCEEDED(hr))
		{
            m_pOPCHDAServer.Attach(reinterpret_cast<IOPCHDA_Server*>(Result.pItf));

            m_name = ProgID;
            m_node = ServerInfo.pwszName;

            m_pOPCHDA_SyncRead = m_pOPCHDAServer;
            m_pOPCHDA_SyncUpdate = m_pOPCHDAServer;
            m_pOPCHDA_SyncAnnotations = m_pOPCHDAServer;
            m_pOPCHDA_AsyncRead = m_pOPCHDAServer;
            m_pOPCHDA_AsyncUpdate = m_pOPCHDAServer;
            m_pOPCHDA_AsyncAnnotations = m_pOPCHDAServer;
            m_pOPCHDA_Playback = m_pOPCHDAServer;
            m_pOPCCommon = m_pOPCHDAServer;

            IUnknown* pUnk = NULL;

            ((CComObject<COPCHDAAutoServer>*)this)->QueryInterface(
                IID_IUnknown,
                reinterpret_cast<void**>(&pUnk));

            if (!m_pOPCCommon)
            {
                AtlAdvise(m_pOPCCommon, pUnk, IID_IOPCShutdown, &m_ShutdownConnection);
            }

            AtlAdvise(m_pOPCHDAServer, pUnk, IID_IOPCHDA_DataCallback, &m_DataConnection);

            pUnk->Release();
		}
	}

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::Disconnect()
{
    RemoveAll();

    if (m_pOPCCommon)
    {
        AtlUnadvise(m_pOPCCommon, IID_IOPCShutdown, m_ShutdownConnection);
    }

    if (m_pOPCHDAServer)
    {
        AtlUnadvise(m_pOPCHDAServer, IID_IOPCHDA_DataCallback, m_DataConnection);
    }

    m_ShutdownConnection = 0;
    m_DataConnection = 0;

    m_pOPCCommon.Release();
    m_pOPCHDAServer.Release();
    m_pOPCHDA_SyncRead.Release();
    m_pOPCHDA_SyncUpdate.Release();
    m_pOPCHDA_SyncAnnotations.Release();
    m_pOPCHDA_AsyncRead.Release();
    m_pOPCHDA_AsyncUpdate.Release();
    m_pOPCHDA_AsyncAnnotations.Release();
    m_pOPCHDA_Playback.Release();

    m_name.Empty();
    m_node.Empty();
    m_client.Empty();

    return S_OK;
}

STDMETHODIMP COPCHDAAutoServer::GetErrorString(
    LONG ErrorCode,
    BSTR *pErrorString)
{
    if (pErrorString == NULL)
    {
        return E_POINTER;
    }

    HRESULT hr = E_FAIL;

    if (m_pOPCCommon)
    {
        LPWSTR szString = NULL;

        hr = m_pOPCCommon->GetErrorString(ErrorCode, &szString);

        if (SUCCEEDED(hr))
        {
            *pErrorString = SysAllocString(szString);

            CoTaskMemFree(szString);
        }
    }

    if (FAILED(hr))
    {
        LPVOID lpBuffer = NULL;
        DWORD dwLength = 0;

        dwLength = FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            ErrorCode,
            LOCALE_SYSTEM_DEFAULT,
            reinterpret_cast<LPTSTR>(&lpBuffer),
            0,
            NULL);

        if (dwLength > 0)
        {
            CComBSTR temp(reinterpret_cast<LPCTSTR>(lpBuffer));
            LocalFree(lpBuffer);
            *pErrorString = temp.Copy();
            hr = S_OK;
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::QueryAvailableLocaleIDs(
    VARIANT * pLocaleIDs)
{
    if (pLocaleIDs == NULL)
    {
        return E_POINTER;
    }

    HRESULT hr = E_FAIL;

    if (m_pOPCCommon)
    {
        DWORD dwCount = 0;
        LCID* pLocales = NULL;

        hr = m_pOPCCommon->QueryAvailableLocaleIDs(&dwCount, &pLocales);

        if (SUCCEEDED(hr))
        {
            SAFEARRAY* parray = SafeArrayCreateVector(VT_I4, 1, dwCount);

            if (NULL != parray)
            {
                LONG lIndex;

                for (DWORD dwIndex = 0; dwIndex < dwCount; dwIndex++)
                {
                    lIndex = dwIndex + 1;

                    SafeArrayPutElement(parray, &lIndex, reinterpret_cast<void*>(&pLocales[dwIndex]));
                }

                VariantClear(pLocaleIDs);

                pLocaleIDs->vt = VT_ARRAY | VT_I4;
                pLocaleIDs->parray = parray;
            }
            else
            {
                hr = E_FAIL;
            }

            if (NULL != pLocales) CoTaskMemFree(pLocales);
        }
    }

    return hr;
}
    
STDMETHODIMP COPCHDAAutoServer::GetItemAttributes( 
    LONG * pCount,
    SAFEARRAY ** ppAttributeIDs,
    SAFEARRAY ** ppNames,
    SAFEARRAY ** ppDescriptions,
    SAFEARRAY ** ppDataTypes)
{
    if (pCount == NULL)
    {
        return E_POINTER;
    }

    if (ppAttributeIDs == NULL)
    {
        return E_POINTER;
    }

    if (ppNames == NULL)
    {
        return E_POINTER;
    }

    if (ppDescriptions == NULL)
    {
        return E_POINTER;
    }

    if (ppDataTypes == NULL)
    {
        return E_POINTER;
    }

    *ppAttributeIDs = NULL;
    *ppNames = NULL;
    *ppDescriptions = NULL;
    *ppDataTypes = NULL;

    HRESULT hr = E_FAIL;

    if (m_pOPCHDAServer)
    {
        DWORD dwCount = 0;
        DWORD* pdwAttrID = NULL;
        LPWSTR* pAttrName = NULL;
        LPWSTR* pAttrDesc = NULL;
        VARTYPE* pvtAttrDataType;

        hr = m_pOPCHDAServer->GetItemAttributes(
            &dwCount,
            &pdwAttrID,
            &pAttrName,
            &pAttrDesc,
            &pvtAttrDataType);

        if (SUCCEEDED(hr))
        {
            DWORD dwIndex;

            SAFEARRAY* pAttributeIDs = SafeArrayCreateVector(VT_I4, 1, dwCount);
            SAFEARRAY* pNames = SafeArrayCreateVector(VT_BSTR, 1, dwCount);
            SAFEARRAY* pDescriptions = SafeArrayCreateVector(VT_BSTR, 1, dwCount);
            SAFEARRAY* pDataTypes = SafeArrayCreateVector(VT_I2, 1, dwCount);

            if ((NULL != pAttributeIDs) &&
                (NULL != pNames) &&
                (NULL != pDescriptions) &&
                (NULL != pDataTypes))
            {
                LONG lIndex = 0;
                BSTR bstrName;
                BSTR bstrDesc;

                for (dwIndex = 0; dwIndex < dwCount; dwIndex++)
                {
                    lIndex = dwIndex + 1;

                    bstrName = SysAllocString(pAttrName[dwIndex]);
                    bstrDesc = SysAllocString(pAttrDesc[dwIndex]);

                    CoTaskMemFree(pAttrName[dwIndex]);
                    CoTaskMemFree(pAttrDesc[dwIndex]);

                    SafeArrayPutElement(pAttributeIDs, &lIndex, reinterpret_cast<void*>(&pdwAttrID[dwIndex]));
                    SafeArrayPutElement(pNames, &lIndex, reinterpret_cast<void*>(bstrName));
                    SafeArrayPutElement(pDescriptions, &lIndex, reinterpret_cast<void*>(bstrDesc));
                    SafeArrayPutElement(pDataTypes, &lIndex, reinterpret_cast<void*>(&pvtAttrDataType[dwIndex]));
                }

                *pCount = dwCount;
                *ppAttributeIDs = pAttributeIDs;
                *ppNames = pNames;
                *ppDescriptions = pDescriptions;
                *ppDataTypes = pDataTypes;
            }
            else
            {
                if (NULL != pAttributeIDs) SafeArrayDestroy(pAttributeIDs);
                if (NULL != pNames) SafeArrayDestroy(pNames);
                if (NULL != pDescriptions) SafeArrayDestroy(pDescriptions);
                if (NULL != pDataTypes) SafeArrayDestroy(pDataTypes);

                for (dwIndex = 0; dwIndex < dwCount; dwIndex++)
                {
                    CoTaskMemFree(pAttrName[dwIndex]);
                    CoTaskMemFree(pAttrDesc[dwIndex]);
                }
            }

            CoTaskMemFree(pdwAttrID);
            CoTaskMemFree(pAttrName);
            CoTaskMemFree(pAttrDesc);
            CoTaskMemFree(pvtAttrDataType);
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::GetAggregates( 
    LONG * pCount,
    SAFEARRAY ** ppAggregateIDs,
    SAFEARRAY ** ppNames,
    SAFEARRAY ** ppDescriptions)
{
    if (pCount == NULL)
    {
        return E_POINTER;
    }

    if (ppAggregateIDs == NULL)
    {
        return E_POINTER;
    }

    if (ppNames == NULL)
    {
        return E_POINTER;
    }

    if (ppDescriptions == NULL)
    {
        return E_POINTER;
    }


    *ppAggregateIDs = NULL;
    *ppNames = NULL;
    *ppDescriptions = NULL;

    HRESULT hr = E_FAIL;

    if (m_pOPCHDAServer)
    {
        DWORD dwCount = 0;
        DWORD* pdwAggrID = NULL;
        LPWSTR* pAggrName = NULL;
        LPWSTR* pAggrDesc = NULL;

        hr = m_pOPCHDAServer->GetAggregates(
            &dwCount,
            &pdwAggrID,
            &pAggrName,
            &pAggrDesc);

        if (SUCCEEDED(hr))
        {
            DWORD dwIndex;

            SAFEARRAY* pAggregateIDs = SafeArrayCreateVector(VT_I4, 1, dwCount);
            SAFEARRAY* pNames = SafeArrayCreateVector(VT_BSTR, 1, dwCount);
            SAFEARRAY* pDescriptions = SafeArrayCreateVector(VT_BSTR, 1, dwCount);

            if ((NULL != pAggregateIDs) &&
                (NULL != pNames) &&
                (NULL != pDescriptions))
            {
                LONG lIndex = 0;
                BSTR bstrName;
                BSTR bstrDesc;

                for (dwIndex = 0; dwIndex < dwCount; dwIndex++)
                {
                    lIndex = dwIndex + 1;

                    bstrName = SysAllocString(pAggrName[dwIndex]);
                    bstrDesc = SysAllocString(pAggrDesc[dwIndex]);

                    CoTaskMemFree(pAggrName[dwIndex]);
                    CoTaskMemFree(pAggrDesc[dwIndex]);

                    SafeArrayPutElement(pAggregateIDs, &lIndex, reinterpret_cast<void*>(&pdwAggrID[dwIndex]));
                    SafeArrayPutElement(pNames, &lIndex, reinterpret_cast<void*>(bstrName));
                    SafeArrayPutElement(pDescriptions, &lIndex, reinterpret_cast<void*>(bstrDesc));
                }

                *pCount = dwCount;
                *ppAggregateIDs = pAggregateIDs;
                *ppNames = pNames;
                *ppDescriptions = pDescriptions;
            }
            else
            {
                if (NULL != pAggregateIDs) SafeArrayDestroy(pAggregateIDs);
                if (NULL != pNames) SafeArrayDestroy(pNames);
                if (NULL != pDescriptions) SafeArrayDestroy(pDescriptions);

                for (dwIndex = 0; dwIndex < dwCount; dwIndex++)
                {
                    CoTaskMemFree(pAggrName[dwIndex]);
                    CoTaskMemFree(pAggrDesc[dwIndex]);
                }
            }

            CoTaskMemFree(pdwAggrID);
            CoTaskMemFree(pAggrName);
            CoTaskMemFree(pAggrDesc);
        }
    }

    return hr;
}

STDMETHODIMP COPCHDAAutoServer::CreateBrowser( 
    LONG NumCriteria,
    VARIANT AttributeIDs,
    VARIANT OperatorCodes,
    VARIANT Filters,
    VARIANT * pErrors,
    OPCHDABrowser ** ppOPCHDABrowser)
{
    if (ppOPCHDABrowser == NULL)
    {
        return E_POINTER;
    }

    *ppOPCHDABrowser = NULL;

    HRESULT hr;

    if (NumCriteria > 0)
    {
        if (((VT_ARRAY | VT_I4) != AttributeIDs.vt) ||
            ((VT_ARRAY | VT_I4) != OperatorCodes.vt) ||
            ((VT_ARRAY | VT_VARIANT) != Filters.vt) ||
            (DISP_E_PARAMNOTFOUND == AttributeIDs.scode) ||
            (DISP_E_PARAMNOTFOUND == OperatorCodes.scode) ||
            (DISP_E_PARAMNOTFOUND == Filters.scode) ||
            (NULL == AttributeIDs.parray) ||
            (NULL == OperatorCodes.parray) ||
            (NULL == Filters.parray))
        {
            return E_INVALIDARG;
        }

        LONG LBound = 0;
        LONG UBound = 0;

        hr = SafeArrayGetLBound(AttributeIDs.parray, 1, &LBound);

        if (FAILED(hr))
        {
            return hr;
        }

        hr = SafeArrayGetUBound(AttributeIDs.parray, 1, &UBound);

        if (FAILED(hr))
        {
            return hr;
        }

        if ((LBound > 1) || (UBound < NumCriteria))
        {
            return E_INVALIDARG;
        }

        hr = SafeArrayGetLBound(OperatorCodes.parray, 1, &LBound);

        if (FAILED(hr))
        {
            return hr;
        }

        hr = SafeArrayGetUBound(OperatorCodes.parray, 1, &UBound);

        if (FAILED(hr))
        {
            return hr;
        }

        if ((LBound > 1) || (UBound < NumCriteria))
        {
            return E_INVALIDARG;
        }

        hr = SafeArrayGetLBound(Filters.parray, 1, &LBound);

        if (FAILED(hr))
        {
            return hr;
        }

        hr = SafeArrayGetUBound(Filters.parray, 1, &UBound);

        if (FAILED(hr))
        {
            return hr;
        }

        if ((LBound > 1) || (UBound < NumCriteria))
        {
            return E_INVALIDARG;
        }
    }

    hr = E_FAIL;

    if (m_pOPCHDAServer)
    {
        DWORD* pdwAttrID = NULL;
        OPCHDA_OPERATORCODES* pOperator = NULL;
        VARIANT* vFilter = NULL;
        IOPCHDA_Browser* pOPCHDA_Browser = NULL;
        HRESULT* pErrors2 = NULL;

        LONG index, vbIndex;

        if (NumCriteria > 0)
        {
            pdwAttrID = new DWORD[NumCriteria];
            pOperator = new OPCHDA_OPERATORCODES[NumCriteria];
            vFilter = new VARIANT[NumCriteria];

            for (index = 0; index < NumCriteria; index++)
            {
                vbIndex = index + 1;

                VariantInit(&vFilter[index]);

                SafeArrayGetElement(AttributeIDs.parray, &vbIndex, reinterpret_cast<void*>(&pdwAttrID[index]));
                SafeArrayGetElement(OperatorCodes.parray, &vbIndex, reinterpret_cast<void*>(&pOperator[index]));
                SafeArrayGetElement(Filters.parray, &vbIndex, reinterpret_cast<void*>(&vFilter[index]));
            }
        }
        else
        {
            NumCriteria = 1;

            pdwAttrID = new DWORD[NumCriteria];
            pOperator = new OPCHDA_OPERATORCODES[NumCriteria];
            vFilter = new VARIANT[NumCriteria];

            pdwAttrID[0] = OPCHDA_ITEMID;
            pOperator[0] = OPCHDA_EQUAL;
            vFilter[0].vt = VT_BSTR;
            vFilter[0].bstrVal = SysAllocString(L"*");
        }

        hr = m_pOPCHDAServer->CreateBrowse(
            NumCriteria,
            pdwAttrID,
            pOperator,
            vFilter,
            &pOPCHDA_Browser,
            &pErrors2);

        for (index = 0; index < NumCriteria; index++)
        {
            VariantClear(&vFilter[index]);
        }

        delete pdwAttrID;
        
        delete pOperator;

        delete vFilter;

        if (SUCCEEDED(hr))
        {
            CComObject<COPCHDABrowser>* pBrowser = NULL;

            hr = CComObject<COPCHDABrowser>::CreateInstance(&pBrowser);

            if (SUCCEEDED(hr))
            {
                pBrowser->Initialize(pOPCHDA_Browser);

                hr = pBrowser->QueryInterface(IID_OPCHDABrowser, reinterpret_cast<void**>(ppOPCHDABrowser));
                _ASSERTE(*ppOPCHDABrowser);
            }

            pOPCHDA_Browser->Release();

            if ((NumCriteria > 0) &&
                (NULL != pErrors2) &&
                (NULL != pErrors) &&
                (DISP_E_PARAMNOTFOUND != pErrors->scode))
            {
                VariantClear(pErrors);

                SAFEARRAY* parray = SafeArrayCreateVector(VT_I4, 1, NumCriteria);

                if (NULL != parray)
                {
                    for (index = 0; index < NumCriteria; index++)
                    {
                        vbIndex = index + 1;

                        SafeArrayPutElement(parray, &vbIndex, &pErrors2[index]);
                    }

                    pErrors->vt = VT_ARRAY | VT_I4;
                    pErrors->parray = parray;
                }
            }

            if (NULL != pErrors2) CoTaskMemFree(pErrors2);
        }
    }

    return hr;
}
