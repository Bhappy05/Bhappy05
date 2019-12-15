// OPCBAEnumerationSets.h
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
//  It contains the definition of OPCBAEnumerationSets object.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//


#ifndef __OPCBAENUMERATIONSETS_H_
#define __OPCBAENUMERATIONSETS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COPCBAEnumerationSets
class ATL_NO_VTABLE COPCBAEnumerationSets : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COPCBAEnumerationSets, &CLSID_OPCBAEnumerationSets>,
	public IDispatchImpl<IOPCBAEnumerationSets, &IID_IOPCBAEnumerationSets, &LIBID_OPCBatchAutomation>
{
public:
	COPCBAEnumerationSets();
	~COPCBAEnumerationSets();

DECLARE_REGISTRY_RESOURCEID(IDR_OPCBAENUMERATIONSETS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COPCBAEnumerationSets)
	COM_INTERFACE_ENTRY(IOPCBAEnumerationSets)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IOPCBAEnumerationSets
public:
	STDMETHOD(QueryEnumerationList)(/*[in]*/ long EnumSetID, /*[out]*/ long* Count, /*[out]*/ SAFEARRAY/*(long)*/ **EnumValue, /*[out]*/ SAFEARRAY/*(BSTR)*/ **EnumName);
	STDMETHOD(QueryEnumerationSets)(/*[out]*/ LONG* Count, /*[out]*/ SAFEARRAY/*(LONG)*/ **EnumSetID, /*[out]*/ SAFEARRAY/*(BSTR)*/**EnumSetName);
	STDMETHOD(QueryEnumeration)(/*[in]*/ long EnumSetID, /*[in]*/ long EnumValue, /*[out, retval]*/ BSTR *EnumName);

// Implementation
private:
	CComQIPtr<IOPCEnumerationSets, &IID_IOPCEnumerationSets> m_pEnumSets;
};

#endif //__OPCBAENUMERATIONSETS_H_
