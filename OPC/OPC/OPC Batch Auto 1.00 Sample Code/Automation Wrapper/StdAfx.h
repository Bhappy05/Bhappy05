// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently
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
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//
#if !defined(AFX_STDAFX_H__01253836_212E_11D4_9015_00C04FA36AD7__INCLUDED_)
#define AFX_STDAFX_H__01253836_212E_11D4_9015_00C04FA36AD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>

// _variant_t support
#include <comdef.h>

// OPC Batch Custom Server
#include "opcbc.h"

// OPCBatch Automation Server
#include "OPCBatchAuto.h"

// The reset is required for OPC Data Access support
#include <List>
using namespace std; // for STL
#include "OPCDA.h"
#include "OPCComn.h"
//#include "OPCAuto.h"
#include "resource.h"
#include "OPCAutoServer.h"

// Functions to convert variants to Automation compatible types
HRESULT VariantToAutomation( VARIANT* );
HRESULT ArrayToAutomation( VARIANT*, VARTYPE );

extern LPWSTR empty;
extern CComBSTR emptyString;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__01253836_212E_11D4_9015_00C04FA36AD7__INCLUDED)
