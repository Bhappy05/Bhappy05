// OPCBABatchSummaryCollection.h
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
//  It contains the definition of OPCBABatchSummaryCollection object.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//

#ifndef __OPCBABATCHSUMMARYCOLLECTION_H_
#define __OPCBABATCHSUMMARYCOLLECTION_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COPCBABatchSummaryCollection
class ATL_NO_VTABLE COPCBABatchSummaryCollection : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COPCBABatchSummaryCollection, &CLSID_OPCBABatchSummaryCollection>,
	public IDispatchImpl<IOPCBABatchSummaryCollection, &IID_IOPCBABatchSummaryCollection, &LIBID_OPCBatchAutomation>
{
public:
	COPCBABatchSummaryCollection();
	~COPCBABatchSummaryCollection();

DECLARE_REGISTRY_RESOURCEID(IDR_OPCBABATCHSUMMARYCOLLECTION)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COPCBABatchSummaryCollection)
	COM_INTERFACE_ENTRY(IOPCBABatchSummaryCollection)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IOPCBABatchSummaryCollection
public:
	STDMETHOD(Item)(/*[in]*/ VARIANT ItemSpecifier, /*[out, retval]*/ IOPCBABatchSummary** ppBatchSummary);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);

// Implementation
private:
	void ReleaseMemory(OPCBATCHSUMMARY* pBS);
	HRESULT CreateBatchSummaryObject(IOPCBABatchSummary** ppIBS, OPCBATCHSUMMARY* pBS);
	CComPtr<IEnumOPCBatchSummary> m_pEnumBatchSum;
};

#endif //__OPCBABATCHSUMMARYCOLLECTION_H_
