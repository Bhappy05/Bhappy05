// OPCBABatchSummary.h
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
//  It contains the definition of OPCBABatchSummary object.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//

#ifndef __OPCBABATCHSUMMARY_H_
#define __OPCBABATCHSUMMARY_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COPCBABatchSummary
class ATL_NO_VTABLE COPCBABatchSummary : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COPCBABatchSummary, &CLSID_OPCBABatchSummary>,
	public IDispatchImpl<IOPCBABatchSummary, &IID_IOPCBABatchSummary, &LIBID_OPCBatchAutomation>
{
friend class COPCBABatchSummaryCollection;
public:
	COPCBABatchSummary();
	~COPCBABatchSummary();

DECLARE_REGISTRY_RESOURCEID(IDR_OPCBABATCHSUMMARY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COPCBABatchSummary)
	COM_INTERFACE_ENTRY(IOPCBABatchSummary)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IOPCBABatchSummary
public:
	STDMETHOD(get_ActualEndTime)(/*[out, retval]*/ DATE *pVal);
	STDMETHOD(get_ActualStartTime)(/*[out, retval]*/ DATE *pVal);
	STDMETHOD(get_ExecutionMode)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ExecutionState)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_EU)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_BatchSize)(/*[out, retval]*/ float *pVal);
	STDMETHOD(get_MasterRecipeID)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_OPCItemID)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Description)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ID)(/*[out, retval]*/ BSTR *pVal);

// Implementation
private:
	CComBSTR	m_ID;
	CComBSTR	m_Description;
	CComBSTR	m_OPCItemID;
	CComBSTR	m_MasterRecipeID;
	float		m_BatchSize;
	CComBSTR	m_EU;
	CComBSTR	m_ExecutionState;
	CComBSTR	m_ExecutionMode;
	DATE		m_ActualStartTime;
	DATE		m_ActualEndTime;
};

#endif //__OPCBABATCHSUMMARY_H_
