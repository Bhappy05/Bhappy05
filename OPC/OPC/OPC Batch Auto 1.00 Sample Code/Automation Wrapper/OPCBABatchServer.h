// OPCBABatchServer.h
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
//  It contains the definition of OPCBABatchServer object.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//

#ifndef __OPCBABATCHSERVER_H_
#define __OPCBABATCHSERVER_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COPCBABatchServer
class ATL_NO_VTABLE COPCBABatchServer : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COPCBABatchServer, &CLSID_OPCBABatchServer>,
	public IDispatchImpl<IOPCBABatchServer, &IID_IOPCBABatchServer, &LIBID_OPCBatchAutomation>
{
public:
	COPCBABatchServer();
	~COPCBABatchServer();

DECLARE_REGISTRY_RESOURCEID(IDR_OPCBABATCHSERVER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COPCBABatchServer)
	COM_INTERFACE_ENTRY(IOPCBABatchServer)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IOPCBABatchServer
public:
	STDMETHOD(GetOPCBAEnumerationSets)(/*[out, retval]*/ IOPCBAEnumerationSets** ppOPCBAEnumerationSets);
	STDMETHOD(GetOPCBABatchSummaryCollection)(/*[out, retval]*/ IOPCBABatchSummaryCollection** ppOPCBABatchSummaryCollection);
	STDMETHOD(GetOPCServer)(/*[out, retval]*/ IOPCAutoServer** ppOPCServer);
	STDMETHOD(get_Delimiter)(/*[out, retval]*/ BSTR *pVal);

// Implementation
};


#endif //__OPCBABATCHSERVER_H_
