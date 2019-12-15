// Globals.h
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
//  This file declares global variables.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//

#ifndef __OPCABATCH_GLOBALS_H_
#define __OPCABATCH_GLOBALS_H_

////////////////////////////////////////////////////////////
// Global variables

// OPC Custom server
extern CComPtr<IOPCBatchServer> gpOPCBatchCustomServer;

// Memory allocator
extern IMalloc*	gpIMalloc;

// Used in OPC Data Access Auto Server
extern UINT OPCSTMFORMATDATATIME;
extern UINT OPCSTMFORMATWRITECOMPLETE;

#endif //__OPCABATCH_GLOBALS_H_
