// OPCBABatchSummary.cpp
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
//  It contains the implementation of OPCBABatchSummary object.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//

#include "stdafx.h"
#include "Globals.h"
#include "OPCBABatchSummary.h"

/////////////////////////////////////////////////////////////////////////////
// Construction/Destruction

COPCBABatchSummary::COPCBABatchSummary()
{
	m_ID = m_Description = m_OPCItemID = m_MasterRecipeID = "";
	m_BatchSize = 0.0f;
	m_EU = m_ExecutionState = m_ExecutionMode = "";
}

COPCBABatchSummary::~COPCBABatchSummary()
{
}

/////////////////////////////////////////////////////////////////////////////
// Implementation

STDMETHODIMP COPCBABatchSummary::get_ID(BSTR *pVal)
{
	m_ID.CopyTo(pVal);
	return S_OK;
}

STDMETHODIMP COPCBABatchSummary::get_Description(BSTR *pVal)
{
	m_Description.CopyTo(pVal);
	return S_OK;
}

STDMETHODIMP COPCBABatchSummary::get_OPCItemID(BSTR *pVal)
{
	m_OPCItemID.CopyTo(pVal);
	return S_OK;
}

STDMETHODIMP COPCBABatchSummary::get_MasterRecipeID(BSTR *pVal)
{
	m_MasterRecipeID.CopyTo(pVal);
	return S_OK;
}

STDMETHODIMP COPCBABatchSummary::get_BatchSize(float *pVal)
{
	*pVal = m_BatchSize;
	return S_OK;
}

STDMETHODIMP COPCBABatchSummary::get_EU(BSTR *pVal)
{
	m_EU.CopyTo(pVal);
	return S_OK;
}

STDMETHODIMP COPCBABatchSummary::get_ExecutionState(BSTR *pVal)
{
	m_ExecutionState.CopyTo(pVal);
	return S_OK;
}

STDMETHODIMP COPCBABatchSummary::get_ExecutionMode(BSTR *pVal)
{
	m_ExecutionMode.CopyTo(pVal);
	return S_OK;
}

STDMETHODIMP COPCBABatchSummary::get_ActualStartTime(DATE *pVal)
{
	*pVal = m_ActualStartTime;
	return S_OK;
}

STDMETHODIMP COPCBABatchSummary::get_ActualEndTime(DATE *pVal)
{
	*pVal = m_ActualEndTime;
	return S_OK;
}
