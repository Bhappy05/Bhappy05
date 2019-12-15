// OPCBABatchSummaryCollection.cpp
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
//  It contains the implementation of OPCBABatchSummaryCollection object.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//

#include "stdafx.h"

#include "Globals.h"

#include "OPCBABatchServer.h"
#include "OPCBABatchSummary.h"
#include "OPCBABatchSummaryCollection.h"

/////////////////////////////////////////////////////////////////////////////
// Construction/Destruction

COPCBABatchSummaryCollection::COPCBABatchSummaryCollection()
{
	IUnknown* pUnk;
	HRESULT hr;

	// Initialize interface pointer
	m_pEnumBatchSum = NULL;

	if (gpOPCBatchCustomServer == NULL)
		return;
	
	// Create batch list
	hr = gpOPCBatchCustomServer->CreateEnumerator(IID_IEnumOPCBatchSummary, &pUnk);
	if (SUCCEEDED(hr)) {
		pUnk->QueryInterface(IID_IEnumOPCBatchSummary, (LPVOID*)&m_pEnumBatchSum);
		pUnk->Release();
	}
}

COPCBABatchSummaryCollection::~COPCBABatchSummaryCollection()
{
	if (m_pEnumBatchSum)
		m_pEnumBatchSum.Release();
}

/////////////////////////////////////////////////////////////////////////////
// Interface

STDMETHODIMP COPCBABatchSummaryCollection::get_Count(long *pVal)
{
	HRESULT hr;
	if (pVal==NULL) return E_INVALIDARG;
	if (m_pEnumBatchSum==NULL) return E_FAIL;
	hr = m_pEnumBatchSum->Count((ULONG*)pVal);
	return hr;
}

STDMETHODIMP COPCBABatchSummaryCollection::Item(VARIANT ItemSpecifier, IOPCBABatchSummary **ppBatchSummary)
{
	OPCBATCHSUMMARY* pBS;
	ULONG ulFetched;
	long lCount;
	HRESULT hr;

	if (ppBatchSummary==NULL) return E_INVALIDARG;
	if (m_pEnumBatchSum==NULL) return E_FAIL;

	*ppBatchSummary = NULL;
	pBS = NULL;

	if (ItemSpecifier.vt == VT_BSTR) { // Find item by ID
		CComBSTR ItemName = ItemSpecifier.bstrVal;

		hr = m_pEnumBatchSum->Reset();
		if (FAILED(hr)) return E_FAIL;
		hr = get_Count(&lCount);
		if (FAILED(hr)) return E_FAIL;

		for (long i=0; i<lCount; i++) {
			hr = m_pEnumBatchSum->Next(1, &pBS, &ulFetched);
			if (FAILED(hr)) return E_FAIL;
			// Compare ID of the retrieved Batch Summary with required ID
			CComBSTR batchID(pBS[0].szID);
			if (ItemName == batchID) { // Match
				hr = CreateBatchSummaryObject(ppBatchSummary, pBS);
				ReleaseMemory(pBS);
				return hr;
			}
			// Release memory allocated by the OPCBatchServer::Next()
			ReleaseMemory(pBS);
		}
	}
	else { // Find item by number
		long i = (long)_variant_t(ItemSpecifier);
		if (i < 1) return E_INVALIDARG;
		hr = m_pEnumBatchSum->Reset();
		hr = m_pEnumBatchSum->Skip(i-1);
		// only S_OK is acceptable, S_FALSE means that no item is availale 
		if (hr != S_OK) return E_FAIL;
		hr = m_pEnumBatchSum->Next(1, &pBS, &ulFetched);
		if (hr != S_OK) return E_FAIL;
		hr = CreateBatchSummaryObject(ppBatchSummary, pBS);
		// Release memory allocated by the OPCBatchServer::Next()
		ReleaseMemory(pBS);
	}
	return hr;
}

HRESULT COPCBABatchSummaryCollection::CreateBatchSummaryObject(IOPCBABatchSummary** ppIBS, OPCBATCHSUMMARY* pBS)
{
	// Create object, initialize its data and return IOPCBABatchSummary interface
	HRESULT hr;
	CComObject<COPCBABatchSummary>* pBSNew;
	hr = CComObject<COPCBABatchSummary>::CreateInstance(&pBSNew);

	pBSNew->m_ID			= pBS->szID;
	pBSNew->m_Description	= pBS->szDescription;
	pBSNew->m_OPCItemID		= pBS->szOPCItemID;
	pBSNew->m_MasterRecipeID= pBS->szMasterRecipeID;
	pBSNew->m_BatchSize		= pBS->fBatchSize;
	pBSNew->m_EU			= pBS->szEU;
	pBSNew->m_ExecutionState= pBS->szExecutionState;
	pBSNew->m_ExecutionMode	= pBS->szExecutionMode;

	// Translate FILETIME to DATE format
	SYSTEMTIME sysTime;

	FileTimeToSystemTime(&pBS->ftActualStartTime, &sysTime);
	SystemTimeToVariantTime(&sysTime, &pBSNew->m_ActualStartTime);

	FileTimeToSystemTime(&pBS->ftActualEndTime, &sysTime);
	SystemTimeToVariantTime(&sysTime, &pBSNew->m_ActualEndTime);

	// Return the interface pointer
	hr = pBSNew->QueryInterface(IID_IOPCBABatchSummary, (LPVOID*)ppIBS);
	return hr;
}

void COPCBABatchSummaryCollection::ReleaseMemory(OPCBATCHSUMMARY* pBS)
{
	// Release memory allocated by OPC Batch Custom Server for Batch Summmary
	gpIMalloc->Free(pBS->szID);
	gpIMalloc->Free(pBS->szDescription);
	gpIMalloc->Free(pBS->szOPCItemID);
	gpIMalloc->Free(pBS->szMasterRecipeID);
	gpIMalloc->Free(pBS->szEU);
	gpIMalloc->Free(pBS->szExecutionState);
	gpIMalloc->Free(pBS->szExecutionMode);
	gpIMalloc->Free(pBS);
}
