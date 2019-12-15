// OPCBABatchServer.cpp
//
// (c) Copyright 2000 The OPC Foundation
// ALL RIGHTS RESERVED.
//
// DISCLAIMER:
//  This sample code is provided by the OPC Foundation solely to assist
//  in understanding the OPC Specifications and may be used
//  as set forth in the License Grant section of the OPC Specification.
//  This code is provided as-is and without warranty or support of any sort
//  and is subject to the Warranty and Liability Disclaimers which appear
//  in the printed OPC Specification.
//
// CREDITS:
//  This code was generously provided to the OPC Foundation by
//  Gregory Khrapunovich, ABB Automation
//
// CONTENTS:
//  This file is part of the OPC Batch Automation wrapper dll.
//  It contains the implementation of OPCBABatchServer object.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//

#include "stdafx.h"

// OPC Automation Batch Server
#include "OPCBABatchServer.h"

// OPCBatch Data Access
#include "Globals.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor/Destructor
COPCBABatchServer::COPCBABatchServer()
{
	// Store memory allocator in a global variable 
	CoGetMalloc(MEMCTX_TASK, &gpIMalloc);

	// Initialize OPCBatch Custom server
	gpOPCBatchCustomServer = NULL;
}

COPCBABatchServer::~COPCBABatchServer()
{
	if (gpOPCBatchCustomServer)
		gpOPCBatchCustomServer.Release();
}

/////////////////////////////////////////////////////////////////////////////
// Interface

STDMETHODIMP COPCBABatchServer::get_Delimiter(BSTR *pVal)
{
	HRESULT hr;
	LPWSTR  szDelimiter;
	CComBSTR bstrDelimiter("");

	if (pVal==NULL) return E_INVALIDARG;
	if (gpOPCBatchCustomServer == NULL) return E_FAIL;

	hr = gpOPCBatchCustomServer->GetDelimiter(&szDelimiter);
	if (SUCCEEDED(hr)) {
		bstrDelimiter = szDelimiter;
		gpIMalloc->Free(szDelimiter);
	}
	bstrDelimiter.CopyTo(pVal);
	return hr;
}

STDMETHODIMP COPCBABatchServer::GetOPCServer(IOPCAutoServer **ppOPCServer)
{
	if( ppOPCServer == NULL ) return E_INVALIDARG;

	// Note: we cannot use CoCreateInstance because it will create a separate COM object
	// OPCServer must share global variables with OPCBatch objects
	CComObject<COPCAutoServer>* pOPCServer;
	HRESULT hr = CComObject<COPCAutoServer>::CreateInstance(&pOPCServer);
	hr = pOPCServer->QueryInterface(IID_IOPCAutoServer, (LPVOID*)ppOPCServer);
	return hr;
}

STDMETHODIMP COPCBABatchServer::GetOPCBABatchSummaryCollection(IOPCBABatchSummaryCollection **ppOPCBABatchSummaryCollection)
{
	if(ppOPCBABatchSummaryCollection==NULL) return E_INVALIDARG;
	if (gpOPCBatchCustomServer == NULL) return E_FAIL;

	// Create OPCBatchSummaryCollection object
	HRESULT hr;
	*ppOPCBABatchSummaryCollection = NULL;

	hr = CoCreateInstance(CLSID_OPCBABatchSummaryCollection, NULL, CLSCTX_INPROC_SERVER,
		IID_IOPCBABatchSummaryCollection, (LPVOID*) ppOPCBABatchSummaryCollection);

	if (FAILED(hr)) {
		*ppOPCBABatchSummaryCollection = NULL;
		return hr;
	}
	return S_OK;
}

STDMETHODIMP COPCBABatchServer::GetOPCBAEnumerationSets(IOPCBAEnumerationSets **ppOPCBAEnumerationSets)
{
	if(ppOPCBAEnumerationSets==NULL) return E_INVALIDARG;
	if (gpOPCBatchCustomServer == NULL) return E_FAIL;

	// Create OPCEnumerationSets object
	HRESULT hr;
	*ppOPCBAEnumerationSets = NULL;

	hr = CoCreateInstance(CLSID_OPCBAEnumerationSets, NULL, CLSCTX_INPROC_SERVER,
		IID_IOPCBAEnumerationSets, (LPVOID*) ppOPCBAEnumerationSets);

	if (FAILED(hr)) {
		*ppOPCBAEnumerationSets = NULL;
		return hr;
	}
	return S_OK;
}

