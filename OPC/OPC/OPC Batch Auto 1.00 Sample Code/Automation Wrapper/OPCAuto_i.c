
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 5.03.0280 */
/* at Wed Jun 14 09:17:30 2000
 */
/* Compiler settings for D:\Standards\OPC Sample code\OPCBatchAuto\OPCAuto\OPCAuto.idl:
    Os (OptLev=s), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AXP64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IOPCServerEvent,0x28E68F90,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCGroupsEvent,0x28E68F9C,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCGroupEvent,0x28E68F90,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x01);


MIDL_DEFINE_GUID(IID, LIBID_OPCAutomation,0x28E68F91,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCAutoServer,0x28E68F92,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, DIID_DIOPCServerEvent,0x28E68F93,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_OPCBrowser,0x28E68F94,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCGroups,0x28E68F95,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, DIID_DIOPCGroupsEvent,0x28E68F9D,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCGroup,0x28E68F96,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, DIID_DIOPCGroupEvent,0x28E68F97,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_OPCItems,0x28E68F98,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_OPCItem,0x28E68F99,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_OPCGroups,0x28E68F9E,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_OPCGroup,0x28E68F9B,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AXP64)*/


#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 5.03.0280 */
/* at Wed Jun 14 09:17:30 2000
 */
/* Compiler settings for D:\Standards\OPC Sample code\OPCBatchAuto\OPCAuto\OPCAuto.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win64 (32b run,appending), ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AXP64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IOPCServerEvent,0x28E68F90,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCGroupsEvent,0x28E68F9C,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCGroupEvent,0x28E68F90,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x01);


MIDL_DEFINE_GUID(IID, LIBID_OPCAutomation,0x28E68F91,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCAutoServer,0x28E68F92,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, DIID_DIOPCServerEvent,0x28E68F93,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_OPCBrowser,0x28E68F94,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCGroups,0x28E68F95,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, DIID_DIOPCGroupsEvent,0x28E68F9D,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IOPCGroup,0x28E68F96,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, DIID_DIOPCGroupEvent,0x28E68F97,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_OPCItems,0x28E68F98,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_OPCItem,0x28E68F99,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_OPCGroups,0x28E68F9E,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_OPCGroup,0x28E68F9B,0x8D75,0x11d1,0x8D,0xC3,0x3C,0x30,0x2A,0x00,0x00,0x00);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AXP64)*/

