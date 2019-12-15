// Globals.cpp
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
//  This file defines global variables.
//
// Modification Log:
// Vers    Date       By    Notes
// ----  ----------- ----   -----
// 1.00  Sep 15,2000  GK    First Release
//

#include "stdafx.h"
#include "Globals.h"

// Memory allocator
IMalloc*	gpIMalloc;

// OPC Batch Custom Server
CComPtr<IOPCBatchServer> gpOPCBatchCustomServer;

// Used in OPC Data Access Auto Server
UINT OPCSTMFORMATDATATIME = 0;
UINT OPCSTMFORMATWRITECOMPLETE = 0;
