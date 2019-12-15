// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__2F69807F_B1B1_11D4_9E6F_00B0D060205F__INCLUDED_)
#define AFX_STDAFX_H__2F69807F_B1B1_11D4_9E6F_00B0D060205F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#pragma warning( disable : 4786 )  // "identifier truncated" warning

#define _ATL_STATIC_REGISTRY
#define _WIN32_WINNT 0x0400
#define _ATL_DEBUG_QI

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>

#ifdef _ATL_STATIC_REGISTRY
#include <statreg.h>
#endif

#include <list>

#include "opccomn.h"
#include "opcda.h"
#include "opchda.h"

EXTERN_C const CLSID CLSID_OPCServerList;
EXTERN_C const GUID CATID_OPCHDAServer10;

#include "opcdefs.h"
#include "opcprops.h"

#include "OPCError.h"
#include "OPCHDA_Error.h"

#include "resource.h"
#include "OPCHDAAuto.h"

#define NEXT_COUNT 100

typedef CComQIPtr<IOPCCommon, &IID_IOPCCommon> IOPCCommonPtr;
typedef CComQIPtr<IOPCHDA_Server, &IID_IOPCHDA_Server> IOPCHDA_ServerPtr;
typedef CComQIPtr<IOPCHDA_Browser, &IID_IOPCHDA_Browser> IOPCHDA_BrowserPtr;
typedef CComQIPtr<IOPCHDA_SyncRead, &IID_IOPCHDA_SyncRead> IOPCHDA_SyncReadPtr;
typedef CComQIPtr<IOPCHDA_SyncUpdate, &IID_IOPCHDA_SyncUpdate> IOPCHDA_SyncUpdatePtr;
typedef CComQIPtr<IOPCHDA_SyncAnnotations, &IID_IOPCHDA_SyncAnnotations> IOPCHDA_SyncAnnotationsPtr;
typedef CComQIPtr<IOPCHDA_AsyncRead, &IID_IOPCHDA_AsyncRead> IOPCHDA_AsyncReadPtr;
typedef CComQIPtr<IOPCHDA_AsyncUpdate, &IID_IOPCHDA_AsyncUpdate> IOPCHDA_AsyncUpdatePtr;
typedef CComQIPtr<IOPCHDA_AsyncAnnotations, &IID_IOPCHDA_AsyncAnnotations> IOPCHDA_AsyncAnnotationsPtr;
typedef CComQIPtr<IOPCHDA_Playback, &IID_IOPCHDA_Playback> IOPCHDA_PlaybackPtr;

class COPCHDAAutoServer;
class COPCHDABrowser;
class COPCHDAItem;
class COPCHDAHistory;
class COPCHDAEnumHistory;
class COPCHDAValue;
class COPCHDAEntry;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__2F69807F_B1B1_11D4_9E6F_00B0D060205F__INCLUDED)
