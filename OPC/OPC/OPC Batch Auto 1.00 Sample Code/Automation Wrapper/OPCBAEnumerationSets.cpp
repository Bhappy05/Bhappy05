// OPCBAEnumerationSets.cpp
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
//  It contains the implementation of OPCBAEnumerationSets object.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//

#include "stdafx.h"

#include "Globals.h"
#include "OPCBAEnumerationSets.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor/Destructor

COPCBAEnumerationSets::COPCBAEnumerationSets()
{
	// Query Interface (implicitly)
	if (gpOPCBatchCustomServer)
		m_pEnumSets = gpOPCBatchCustomServer;
}

COPCBAEnumerationSets::~COPCBAEnumerationSets()
{
	if (m_pEnumSets)
		m_pEnumSets.Release();
}

/////////////////////////////////////////////////////////////////////////////
// Interface

STDMETHODIMP COPCBAEnumerationSets::QueryEnumeration(long EnumSetID, long EnumValue, BSTR *EnumName)
{
	if (EnumName==NULL) return E_INVALIDARG;
	if (!m_pEnumSets) return E_FAIL;

	LPWSTR szEnumName;
	CComBSTR bstrEnumName;
	HRESULT hr;

	hr = m_pEnumSets->QueryEnumeration(EnumSetID, EnumValue, &szEnumName);
	if (SUCCEEDED(hr)) {
		bstrEnumName = szEnumName; // Change format from LPWSTR to BSTR
		bstrEnumName.CopyTo(EnumName);
		gpIMalloc->Free(szEnumName);
	}
	return hr;
}

STDMETHODIMP COPCBAEnumerationSets::QueryEnumerationSets(/*[out]*/ long* Count, /*[out]*/ SAFEARRAY/*(LONG)*/ **EnumSetID, /*[out]*/ SAFEARRAY/*(BSTR)*/**EnumSetName)
{
	if ((Count==NULL)||(EnumSetID==NULL)||(EnumSetName==NULL))
		return E_INVALIDARG;
	if (!m_pEnumSets) return E_FAIL;

	ULONG cnt;
	ULONG *setID;
	LPWSTR *setName;
	HRESULT hr;

	// Initialize returned data
	*Count = 0;
	*EnumSetID = NULL;
	*EnumSetName = NULL;

	hr = m_pEnumSets->QueryEnumerationSets(&cnt, &setID, &setName);

	if (SUCCEEDED(hr)) {
		*Count = cnt;
		CComBSTR bsName;
		SAFEARRAYBOUND bound;
		bound.lLbound = 1;
		bound.cElements = cnt;
		*EnumSetID = SafeArrayCreate(VT_I4, 1, &bound);
		*EnumSetName = SafeArrayCreate(VT_BSTR, 1, &bound);
		for (long i=1; i<=*Count; i++) {
			hr = SafeArrayPutElement(*EnumSetID, &i, &setID[i-1]);
			bsName = setName[i-1]; // translate LPWSTR to BSTR
			gpIMalloc->Free(setName[i-1]); // memory was allocated by Custom Batch Server
			hr = SafeArrayPutElement(*EnumSetName, &i, bsName);
		}
		gpIMalloc->Free(setID);
		gpIMalloc->Free(setName);
	}
	return hr;
}

STDMETHODIMP COPCBAEnumerationSets::QueryEnumerationList(/*[in]*/ long EnumSetID, /*[out]*/ long* Count, /*[out]*/ SAFEARRAY/*(long)*/ **EnumValue, /*[out]*/ SAFEARRAY/*(BSTR)*/ **EnumName)
{
	if ((Count==NULL)||(EnumValue==NULL)||(EnumName==NULL))
		return E_INVALIDARG;
	if (!m_pEnumSets) return E_FAIL;

	ULONG cnt;
	ULONG *value;
	LPWSTR *name;
	HRESULT hr;

	// Initialize returned data
	*Count = 0;
	*EnumValue = NULL;
	*EnumName = NULL;

	hr = m_pEnumSets->QueryEnumerationList(EnumSetID, &cnt, &value, &name);

	if (SUCCEEDED(hr)) {
		*Count = cnt;
		CComBSTR bsName;
		SAFEARRAYBOUND bound;
		bound.lLbound = 1;
		bound.cElements = cnt;
		*EnumValue = SafeArrayCreate(VT_I4, 1, &bound);
		*EnumName = SafeArrayCreate(VT_BSTR, 1, &bound);
		for (long i=1; i<=*Count; i++) {
			hr = SafeArrayPutElement(*EnumValue, &i, &value[i-1]);
			bsName = name[i-1]; // translate LPWSTR to BSTR
			gpIMalloc->Free(name[i-1]); // memory was allocated by Custom Batch Server
			hr = SafeArrayPutElement(*EnumName, &i, bsName);
		}
		gpIMalloc->Free(value);
		gpIMalloc->Free(name);
	}
	return hr;
}
