
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __OPCAuto_h__
#define __OPCAuto_h__

/* Forward Declarations */ 

#ifndef __IOPCServerEvent_FWD_DEFINED__
#define __IOPCServerEvent_FWD_DEFINED__
typedef interface IOPCServerEvent IOPCServerEvent;
#endif 	/* __IOPCServerEvent_FWD_DEFINED__ */


#ifndef __IOPCGroupsEvent_FWD_DEFINED__
#define __IOPCGroupsEvent_FWD_DEFINED__
typedef interface IOPCGroupsEvent IOPCGroupsEvent;
#endif 	/* __IOPCGroupsEvent_FWD_DEFINED__ */


#ifndef __IOPCGroupEvent_FWD_DEFINED__
#define __IOPCGroupEvent_FWD_DEFINED__
typedef interface IOPCGroupEvent IOPCGroupEvent;
#endif 	/* __IOPCGroupEvent_FWD_DEFINED__ */


#ifndef __IOPCAutoServer_FWD_DEFINED__
#define __IOPCAutoServer_FWD_DEFINED__
typedef interface IOPCAutoServer IOPCAutoServer;
#endif 	/* __IOPCAutoServer_FWD_DEFINED__ */


#ifndef __DIOPCServerEvent_FWD_DEFINED__
#define __DIOPCServerEvent_FWD_DEFINED__
typedef interface DIOPCServerEvent DIOPCServerEvent;
#endif 	/* __DIOPCServerEvent_FWD_DEFINED__ */


#ifndef __OPCBrowser_FWD_DEFINED__
#define __OPCBrowser_FWD_DEFINED__
typedef interface OPCBrowser OPCBrowser;
#endif 	/* __OPCBrowser_FWD_DEFINED__ */


#ifndef __IOPCGroups_FWD_DEFINED__
#define __IOPCGroups_FWD_DEFINED__
typedef interface IOPCGroups IOPCGroups;
#endif 	/* __IOPCGroups_FWD_DEFINED__ */


#ifndef __DIOPCGroupsEvent_FWD_DEFINED__
#define __DIOPCGroupsEvent_FWD_DEFINED__
typedef interface DIOPCGroupsEvent DIOPCGroupsEvent;
#endif 	/* __DIOPCGroupsEvent_FWD_DEFINED__ */


#ifndef __IOPCGroup_FWD_DEFINED__
#define __IOPCGroup_FWD_DEFINED__
typedef interface IOPCGroup IOPCGroup;
#endif 	/* __IOPCGroup_FWD_DEFINED__ */


#ifndef __DIOPCGroupEvent_FWD_DEFINED__
#define __DIOPCGroupEvent_FWD_DEFINED__
typedef interface DIOPCGroupEvent DIOPCGroupEvent;
#endif 	/* __DIOPCGroupEvent_FWD_DEFINED__ */


#ifndef __OPCItems_FWD_DEFINED__
#define __OPCItems_FWD_DEFINED__
typedef interface OPCItems OPCItems;
#endif 	/* __OPCItems_FWD_DEFINED__ */


#ifndef __OPCItem_FWD_DEFINED__
#define __OPCItem_FWD_DEFINED__
typedef interface OPCItem OPCItem;
#endif 	/* __OPCItem_FWD_DEFINED__ */


#ifndef __OPCGroups_FWD_DEFINED__
#define __OPCGroups_FWD_DEFINED__

#ifdef __cplusplus
typedef class OPCGroups OPCGroups;
#else
typedef struct OPCGroups OPCGroups;
#endif /* __cplusplus */

#endif 	/* __OPCGroups_FWD_DEFINED__ */


#ifndef __OPCGroup_FWD_DEFINED__
#define __OPCGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class OPCGroup OPCGroup;
#else
typedef struct OPCGroup OPCGroup;
#endif /* __cplusplus */

#endif 	/* __OPCGroup_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_OPCAuto_0000 */
/* [local] */ 








extern RPC_IF_HANDLE __MIDL_itf_OPCAuto_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_OPCAuto_0000_v0_0_s_ifspec;

#ifndef __IOPCServerEvent_INTERFACE_DEFINED__
#define __IOPCServerEvent_INTERFACE_DEFINED__

/* interface IOPCServerEvent */
/* [oleautomation][unique][helpstring][uuid][dual][object] */ 


EXTERN_C const IID IID_IOPCServerEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28E68F90-8D75-11d1-8DC3-3C302A000000")
    IOPCServerEvent : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ServerShutDown( 
            /* [string][in] */ BSTR Reason) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOPCServerEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOPCServerEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOPCServerEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOPCServerEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOPCServerEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOPCServerEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOPCServerEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOPCServerEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ServerShutDown )( 
            IOPCServerEvent __RPC_FAR * This,
            /* [string][in] */ BSTR Reason);
        
        END_INTERFACE
    } IOPCServerEventVtbl;

    interface IOPCServerEvent
    {
        CONST_VTBL struct IOPCServerEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPCServerEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOPCServerEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOPCServerEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOPCServerEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOPCServerEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOPCServerEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOPCServerEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOPCServerEvent_ServerShutDown(This,Reason)	\
    (This)->lpVtbl -> ServerShutDown(This,Reason)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IOPCServerEvent_ServerShutDown_Proxy( 
    IOPCServerEvent __RPC_FAR * This,
    /* [string][in] */ BSTR Reason);


void __RPC_STUB IOPCServerEvent_ServerShutDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOPCServerEvent_INTERFACE_DEFINED__ */


#ifndef __IOPCGroupsEvent_INTERFACE_DEFINED__
#define __IOPCGroupsEvent_INTERFACE_DEFINED__

/* interface IOPCGroupsEvent */
/* [oleautomation][unique][helpstring][uuid][dual][object] */ 


EXTERN_C const IID IID_IOPCGroupsEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28E68F9C-8D75-11d1-8DC3-3C302A000000")
    IOPCGroupsEvent : public IDispatch
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GlobalDataChange( 
            /* [in] */ LONG TransactionID,
            /* [in] */ LONG GroupHandle,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemValues,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Qualities,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TimeStamps) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOPCGroupsEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOPCGroupsEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOPCGroupsEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOPCGroupsEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOPCGroupsEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOPCGroupsEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOPCGroupsEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOPCGroupsEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GlobalDataChange )( 
            IOPCGroupsEvent __RPC_FAR * This,
            /* [in] */ LONG TransactionID,
            /* [in] */ LONG GroupHandle,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemValues,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Qualities,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TimeStamps);
        
        END_INTERFACE
    } IOPCGroupsEventVtbl;

    interface IOPCGroupsEvent
    {
        CONST_VTBL struct IOPCGroupsEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPCGroupsEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOPCGroupsEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOPCGroupsEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOPCGroupsEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOPCGroupsEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOPCGroupsEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOPCGroupsEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOPCGroupsEvent_GlobalDataChange(This,TransactionID,GroupHandle,NumItems,ClientHandles,ItemValues,Qualities,TimeStamps)	\
    (This)->lpVtbl -> GlobalDataChange(This,TransactionID,GroupHandle,NumItems,ClientHandles,ItemValues,Qualities,TimeStamps)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroupsEvent_GlobalDataChange_Proxy( 
    IOPCGroupsEvent __RPC_FAR * This,
    /* [in] */ LONG TransactionID,
    /* [in] */ LONG GroupHandle,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemValues,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Qualities,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TimeStamps);


void __RPC_STUB IOPCGroupsEvent_GlobalDataChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOPCGroupsEvent_INTERFACE_DEFINED__ */


#ifndef __IOPCGroupEvent_INTERFACE_DEFINED__
#define __IOPCGroupEvent_INTERFACE_DEFINED__

/* interface IOPCGroupEvent */
/* [oleautomation][unique][helpstring][uuid][dual][object] */ 


EXTERN_C const IID IID_IOPCGroupEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28E68F90-8D75-11d1-8DC3-3C302A000001")
    IOPCGroupEvent : public IDispatch
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DataChange( 
            /* [in] */ LONG TransactionID,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemValues,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Qualities,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TimeStamps) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AsyncReadComplete( 
            /* [in] */ LONG TransactionID,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemValues,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Qualities,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TimeStamps,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AsyncWriteComplete( 
            /* [in] */ LONG TransactionID,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AsyncCancelComplete( 
            /* [in] */ LONG TransactionID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOPCGroupEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOPCGroupEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOPCGroupEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOPCGroupEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOPCGroupEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOPCGroupEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOPCGroupEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOPCGroupEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DataChange )( 
            IOPCGroupEvent __RPC_FAR * This,
            /* [in] */ LONG TransactionID,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemValues,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Qualities,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TimeStamps);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncReadComplete )( 
            IOPCGroupEvent __RPC_FAR * This,
            /* [in] */ LONG TransactionID,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemValues,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Qualities,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TimeStamps,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncWriteComplete )( 
            IOPCGroupEvent __RPC_FAR * This,
            /* [in] */ LONG TransactionID,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncCancelComplete )( 
            IOPCGroupEvent __RPC_FAR * This,
            /* [in] */ LONG TransactionID);
        
        END_INTERFACE
    } IOPCGroupEventVtbl;

    interface IOPCGroupEvent
    {
        CONST_VTBL struct IOPCGroupEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPCGroupEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOPCGroupEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOPCGroupEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOPCGroupEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOPCGroupEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOPCGroupEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOPCGroupEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOPCGroupEvent_DataChange(This,TransactionID,NumItems,ClientHandles,ItemValues,Qualities,TimeStamps)	\
    (This)->lpVtbl -> DataChange(This,TransactionID,NumItems,ClientHandles,ItemValues,Qualities,TimeStamps)

#define IOPCGroupEvent_AsyncReadComplete(This,TransactionID,NumItems,ClientHandles,ItemValues,Qualities,TimeStamps,Errors)	\
    (This)->lpVtbl -> AsyncReadComplete(This,TransactionID,NumItems,ClientHandles,ItemValues,Qualities,TimeStamps,Errors)

#define IOPCGroupEvent_AsyncWriteComplete(This,TransactionID,NumItems,ClientHandles,Errors)	\
    (This)->lpVtbl -> AsyncWriteComplete(This,TransactionID,NumItems,ClientHandles,Errors)

#define IOPCGroupEvent_AsyncCancelComplete(This,TransactionID)	\
    (This)->lpVtbl -> AsyncCancelComplete(This,TransactionID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroupEvent_DataChange_Proxy( 
    IOPCGroupEvent __RPC_FAR * This,
    /* [in] */ LONG TransactionID,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemValues,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Qualities,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TimeStamps);


void __RPC_STUB IOPCGroupEvent_DataChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroupEvent_AsyncReadComplete_Proxy( 
    IOPCGroupEvent __RPC_FAR * This,
    /* [in] */ LONG TransactionID,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemValues,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Qualities,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TimeStamps,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);


void __RPC_STUB IOPCGroupEvent_AsyncReadComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroupEvent_AsyncWriteComplete_Proxy( 
    IOPCGroupEvent __RPC_FAR * This,
    /* [in] */ LONG TransactionID,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);


void __RPC_STUB IOPCGroupEvent_AsyncWriteComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroupEvent_AsyncCancelComplete_Proxy( 
    IOPCGroupEvent __RPC_FAR * This,
    /* [in] */ LONG TransactionID);


void __RPC_STUB IOPCGroupEvent_AsyncCancelComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOPCGroupEvent_INTERFACE_DEFINED__ */



#ifndef __OPCAutomation_LIBRARY_DEFINED__
#define __OPCAutomation_LIBRARY_DEFINED__

/* library OPCAutomation */
/* [helpstring][version][uuid] */ 


enum OPCNamespaceTypes
    {	OPCHierarchical	= 1,
	OPCFlat	= OPCHierarchical + 1
    };

enum OPCDataSource
    {	OPCCache	= 1,
	OPCDevice	= OPCCache + 1
    };

enum OPCAccessRights
    {	OPCReadable	= 1,
	OPCWritable	= OPCReadable + 1
    };

enum OPCServerState
    {	OPCRunning	= 1,
	OPCFailed	= OPCRunning + 1,
	OPCNoconfig	= OPCFailed + 1,
	OPCSuspended	= OPCNoconfig + 1,
	OPCTest	= OPCSuspended + 1,
	OPCDisconnected	= OPCTest + 1
    };

enum OPCErrors
    {	OPCInvalidHandle	= 0xc0040001L,
	OPCBadType	= 0xc0040004L,
	OPCPublic	= 0xc0040005L,
	OPCBadRights	= 0xc0040006L,
	OPCUnknownItemID	= 0xc0040007L,
	OPCInvalidItemID	= 0xc0040008L,
	OPCInvalidFilter	= 0xc0040009L,
	OPCUnknownPath	= 0xc004000aL,
	OPCRange	= 0xc004000bL,
	OPCDuplicateName	= 0xc004000cL,
	OPCUnsupportedRate	= 0x4000dL,
	OPCClamp	= 0x4000eL,
	OPCInuse	= 0x4000fL,
	OPCInvalidConfig	= 0xc0040010L,
	OPCNotFound	= 0xc0040011L,
	OPCInvalidPID	= 0xc0040203L
    };

enum OPCQuality
    {	OPCQualityMask	= 0xc0,
	OPCQualityBad	= 0,
	OPCQualityUncertain	= 0x40,
	OPCQualityGood	= 0xc0
    };

enum OPCQualityStatus
    {	OPCStatusMask	= 0xfc,
	OPCStatusConfigError	= 0x4,
	OPCStatusNotConnected	= 0x8,
	OPCStatusDeviceFailure	= 0xc,
	OPCStatusSensorFailure	= 0x10,
	OPCStatusLastKnown	= 0x14,
	OPCStatusCommFailure	= 0x18,
	OPCStatusOutOfService	= 0x1c,
	OPCStatusLastUsable	= 0x44,
	OPCStatusSensorCal	= 0x50,
	OPCStatusEGUExceeded	= 0x54,
	OPCStatusSubNormal	= 0x58,
	OPCStatusLocalOverride	= 0xd8
    };

enum OPCQualityLimits
    {	OPCLimitMask	= 0x3,
	OPCLimitOk	= 0,
	OPCLimitLow	= 0x1,
	OPCLimitHigh	= 0x2,
	OPCLimitConst	= 0x3
    };

EXTERN_C const IID LIBID_OPCAutomation;

#ifndef __IOPCAutoServer_INTERFACE_DEFINED__
#define __IOPCAutoServer_INTERFACE_DEFINED__

/* interface IOPCAutoServer */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IOPCAutoServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28E68F92-8D75-11d1-8DC3-3C302A000000")
    IOPCAutoServer : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_StartTime( 
            /* [retval][out] */ DATE __RPC_FAR *StartTime) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentTime( 
            /* [retval][out] */ DATE __RPC_FAR *CurrentTime) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LastUpdateTime( 
            /* [retval][out] */ DATE __RPC_FAR *LastUpdateTime) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_MajorVersion( 
            /* [retval][out] */ short __RPC_FAR *MajorVersion) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_MinorVersion( 
            /* [retval][out] */ short __RPC_FAR *MinorVersion) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_BuildNumber( 
            /* [retval][out] */ short __RPC_FAR *BuildNumber) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VendorInfo( 
            /* [retval][out] */ BSTR __RPC_FAR *VendorInfo) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ServerState( 
            /* [retval][out] */ LONG __RPC_FAR *ServerState) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ServerName( 
            /* [retval][out] */ BSTR __RPC_FAR *ServerName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ServerNode( 
            /* [retval][out] */ BSTR __RPC_FAR *ServerNode) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientName( 
            /* [retval][out] */ BSTR __RPC_FAR *ClientName) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_ClientName( 
            /* [in] */ BSTR ClientName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LocaleID( 
            /* [retval][out] */ LONG __RPC_FAR *LocaleID) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_LocaleID( 
            /* [in] */ LONG LocaleID) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Bandwidth( 
            /* [retval][out] */ LONG __RPC_FAR *Bandwidth) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OPCGroups( 
            /* [retval][out] */ OPCGroups	__RPC_FAR *__RPC_FAR *ppGroups) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PublicGroupNames( 
            /* [retval][out] */ VARIANT __RPC_FAR *PublicGroups) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetOPCServers( 
            /* [optional][in] */ VARIANT Node,
            /* [retval][out] */ VARIANT __RPC_FAR *OPCServers) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [string][in] */ BSTR ProgID,
            /* [optional][in] */ VARIANT Node) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateBrowser( 
            /* [retval][out] */ OPCBrowser __RPC_FAR *__RPC_FAR *ppBrowser) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetErrorString( 
            /* [in] */ LONG ErrorCode,
            /* [retval][out] */ BSTR __RPC_FAR *ErrorString) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryAvailableLocaleIDs( 
            /* [retval][out] */ VARIANT __RPC_FAR *LocaleIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryAvailableProperties( 
            /* [string][in] */ BSTR ItemID,
            /* [out] */ LONG __RPC_FAR *Count,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Descriptions,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *DataTypes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemProperties( 
            /* [string][in] */ BSTR ItemID,
            /* [in] */ LONG Count,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyValues,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LookupItemIDs( 
            /* [string][in] */ BSTR ItemID,
            /* [in] */ LONG Count,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *NewItemIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOPCAutoServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOPCAutoServer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOPCAutoServer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StartTime )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ DATE __RPC_FAR *StartTime);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CurrentTime )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ DATE __RPC_FAR *CurrentTime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LastUpdateTime )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ DATE __RPC_FAR *LastUpdateTime);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MajorVersion )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *MajorVersion);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MinorVersion )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *MinorVersion);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BuildNumber )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *BuildNumber);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VendorInfo )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *VendorInfo);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServerState )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ServerState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServerName )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ServerName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServerNode )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ServerNode);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClientName )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ClientName);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ClientName )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [in] */ BSTR ClientName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LocaleID )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *LocaleID);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LocaleID )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [in] */ LONG LocaleID);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Bandwidth )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *Bandwidth);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OPCGroups )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ OPCGroups	__RPC_FAR *__RPC_FAR *ppGroups);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublicGroupNames )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *PublicGroups);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOPCServers )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [optional][in] */ VARIANT Node,
            /* [retval][out] */ VARIANT __RPC_FAR *OPCServers);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [string][in] */ BSTR ProgID,
            /* [optional][in] */ VARIANT Node);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IOPCAutoServer __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateBrowser )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ OPCBrowser __RPC_FAR *__RPC_FAR *ppBrowser);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorString )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [in] */ LONG ErrorCode,
            /* [retval][out] */ BSTR __RPC_FAR *ErrorString);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryAvailableLocaleIDs )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *LocaleIDs);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryAvailableProperties )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [string][in] */ BSTR ItemID,
            /* [out] */ LONG __RPC_FAR *Count,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Descriptions,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *DataTypes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemProperties )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [string][in] */ BSTR ItemID,
            /* [in] */ LONG Count,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyValues,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LookupItemIDs )( 
            IOPCAutoServer __RPC_FAR * This,
            /* [string][in] */ BSTR ItemID,
            /* [in] */ LONG Count,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *NewItemIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);
        
        END_INTERFACE
    } IOPCAutoServerVtbl;

    interface IOPCAutoServer
    {
        CONST_VTBL struct IOPCAutoServerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPCAutoServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOPCAutoServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOPCAutoServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOPCAutoServer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOPCAutoServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOPCAutoServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOPCAutoServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOPCAutoServer_get_StartTime(This,StartTime)	\
    (This)->lpVtbl -> get_StartTime(This,StartTime)

#define IOPCAutoServer_get_CurrentTime(This,CurrentTime)	\
    (This)->lpVtbl -> get_CurrentTime(This,CurrentTime)

#define IOPCAutoServer_get_LastUpdateTime(This,LastUpdateTime)	\
    (This)->lpVtbl -> get_LastUpdateTime(This,LastUpdateTime)

#define IOPCAutoServer_get_MajorVersion(This,MajorVersion)	\
    (This)->lpVtbl -> get_MajorVersion(This,MajorVersion)

#define IOPCAutoServer_get_MinorVersion(This,MinorVersion)	\
    (This)->lpVtbl -> get_MinorVersion(This,MinorVersion)

#define IOPCAutoServer_get_BuildNumber(This,BuildNumber)	\
    (This)->lpVtbl -> get_BuildNumber(This,BuildNumber)

#define IOPCAutoServer_get_VendorInfo(This,VendorInfo)	\
    (This)->lpVtbl -> get_VendorInfo(This,VendorInfo)

#define IOPCAutoServer_get_ServerState(This,ServerState)	\
    (This)->lpVtbl -> get_ServerState(This,ServerState)

#define IOPCAutoServer_get_ServerName(This,ServerName)	\
    (This)->lpVtbl -> get_ServerName(This,ServerName)

#define IOPCAutoServer_get_ServerNode(This,ServerNode)	\
    (This)->lpVtbl -> get_ServerNode(This,ServerNode)

#define IOPCAutoServer_get_ClientName(This,ClientName)	\
    (This)->lpVtbl -> get_ClientName(This,ClientName)

#define IOPCAutoServer_put_ClientName(This,ClientName)	\
    (This)->lpVtbl -> put_ClientName(This,ClientName)

#define IOPCAutoServer_get_LocaleID(This,LocaleID)	\
    (This)->lpVtbl -> get_LocaleID(This,LocaleID)

#define IOPCAutoServer_put_LocaleID(This,LocaleID)	\
    (This)->lpVtbl -> put_LocaleID(This,LocaleID)

#define IOPCAutoServer_get_Bandwidth(This,Bandwidth)	\
    (This)->lpVtbl -> get_Bandwidth(This,Bandwidth)

#define IOPCAutoServer_get_OPCGroups(This,ppGroups)	\
    (This)->lpVtbl -> get_OPCGroups(This,ppGroups)

#define IOPCAutoServer_get_PublicGroupNames(This,PublicGroups)	\
    (This)->lpVtbl -> get_PublicGroupNames(This,PublicGroups)

#define IOPCAutoServer_GetOPCServers(This,Node,OPCServers)	\
    (This)->lpVtbl -> GetOPCServers(This,Node,OPCServers)

#define IOPCAutoServer_Connect(This,ProgID,Node)	\
    (This)->lpVtbl -> Connect(This,ProgID,Node)

#define IOPCAutoServer_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IOPCAutoServer_CreateBrowser(This,ppBrowser)	\
    (This)->lpVtbl -> CreateBrowser(This,ppBrowser)

#define IOPCAutoServer_GetErrorString(This,ErrorCode,ErrorString)	\
    (This)->lpVtbl -> GetErrorString(This,ErrorCode,ErrorString)

#define IOPCAutoServer_QueryAvailableLocaleIDs(This,LocaleIDs)	\
    (This)->lpVtbl -> QueryAvailableLocaleIDs(This,LocaleIDs)

#define IOPCAutoServer_QueryAvailableProperties(This,ItemID,Count,PropertyIDs,Descriptions,DataTypes)	\
    (This)->lpVtbl -> QueryAvailableProperties(This,ItemID,Count,PropertyIDs,Descriptions,DataTypes)

#define IOPCAutoServer_GetItemProperties(This,ItemID,Count,PropertyIDs,PropertyValues,Errors)	\
    (This)->lpVtbl -> GetItemProperties(This,ItemID,Count,PropertyIDs,PropertyValues,Errors)

#define IOPCAutoServer_LookupItemIDs(This,ItemID,Count,PropertyIDs,NewItemIDs,Errors)	\
    (This)->lpVtbl -> LookupItemIDs(This,ItemID,Count,PropertyIDs,NewItemIDs,Errors)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_StartTime_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ DATE __RPC_FAR *StartTime);


void __RPC_STUB IOPCAutoServer_get_StartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_CurrentTime_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ DATE __RPC_FAR *CurrentTime);


void __RPC_STUB IOPCAutoServer_get_CurrentTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_LastUpdateTime_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ DATE __RPC_FAR *LastUpdateTime);


void __RPC_STUB IOPCAutoServer_get_LastUpdateTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_MajorVersion_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *MajorVersion);


void __RPC_STUB IOPCAutoServer_get_MajorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_MinorVersion_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *MinorVersion);


void __RPC_STUB IOPCAutoServer_get_MinorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_BuildNumber_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *BuildNumber);


void __RPC_STUB IOPCAutoServer_get_BuildNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_VendorInfo_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *VendorInfo);


void __RPC_STUB IOPCAutoServer_get_VendorInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_ServerState_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ServerState);


void __RPC_STUB IOPCAutoServer_get_ServerState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_ServerName_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ServerName);


void __RPC_STUB IOPCAutoServer_get_ServerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_ServerNode_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ServerNode);


void __RPC_STUB IOPCAutoServer_get_ServerNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_ClientName_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ClientName);


void __RPC_STUB IOPCAutoServer_get_ClientName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_put_ClientName_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [in] */ BSTR ClientName);


void __RPC_STUB IOPCAutoServer_put_ClientName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_LocaleID_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *LocaleID);


void __RPC_STUB IOPCAutoServer_get_LocaleID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_put_LocaleID_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [in] */ LONG LocaleID);


void __RPC_STUB IOPCAutoServer_put_LocaleID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_Bandwidth_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *Bandwidth);


void __RPC_STUB IOPCAutoServer_get_Bandwidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_OPCGroups_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ OPCGroups	__RPC_FAR *__RPC_FAR *ppGroups);


void __RPC_STUB IOPCAutoServer_get_OPCGroups_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_get_PublicGroupNames_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *PublicGroups);


void __RPC_STUB IOPCAutoServer_get_PublicGroupNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_GetOPCServers_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [optional][in] */ VARIANT Node,
    /* [retval][out] */ VARIANT __RPC_FAR *OPCServers);


void __RPC_STUB IOPCAutoServer_GetOPCServers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_Connect_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [string][in] */ BSTR ProgID,
    /* [optional][in] */ VARIANT Node);


void __RPC_STUB IOPCAutoServer_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_Disconnect_Proxy( 
    IOPCAutoServer __RPC_FAR * This);


void __RPC_STUB IOPCAutoServer_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_CreateBrowser_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ OPCBrowser __RPC_FAR *__RPC_FAR *ppBrowser);


void __RPC_STUB IOPCAutoServer_CreateBrowser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_GetErrorString_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [in] */ LONG ErrorCode,
    /* [retval][out] */ BSTR __RPC_FAR *ErrorString);


void __RPC_STUB IOPCAutoServer_GetErrorString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCAutoServer_QueryAvailableLocaleIDs_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *LocaleIDs);


void __RPC_STUB IOPCAutoServer_QueryAvailableLocaleIDs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IOPCAutoServer_QueryAvailableProperties_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [string][in] */ BSTR ItemID,
    /* [out] */ LONG __RPC_FAR *Count,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyIDs,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Descriptions,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *DataTypes);


void __RPC_STUB IOPCAutoServer_QueryAvailableProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IOPCAutoServer_GetItemProperties_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [string][in] */ BSTR ItemID,
    /* [in] */ LONG Count,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyIDs,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyValues,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);


void __RPC_STUB IOPCAutoServer_GetItemProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IOPCAutoServer_LookupItemIDs_Proxy( 
    IOPCAutoServer __RPC_FAR * This,
    /* [string][in] */ BSTR ItemID,
    /* [in] */ LONG Count,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *PropertyIDs,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *NewItemIDs,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);


void __RPC_STUB IOPCAutoServer_LookupItemIDs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOPCAutoServer_INTERFACE_DEFINED__ */


#ifndef __DIOPCServerEvent_DISPINTERFACE_DEFINED__
#define __DIOPCServerEvent_DISPINTERFACE_DEFINED__

/* dispinterface DIOPCServerEvent */
/* [helpstring][nonextensible][uuid] */ 


EXTERN_C const IID DIID_DIOPCServerEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("28E68F93-8D75-11d1-8DC3-3C302A000000")
    DIOPCServerEvent : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct DIOPCServerEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            DIOPCServerEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            DIOPCServerEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            DIOPCServerEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            DIOPCServerEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            DIOPCServerEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            DIOPCServerEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            DIOPCServerEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } DIOPCServerEventVtbl;

    interface DIOPCServerEvent
    {
        CONST_VTBL struct DIOPCServerEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define DIOPCServerEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define DIOPCServerEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define DIOPCServerEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define DIOPCServerEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define DIOPCServerEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define DIOPCServerEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define DIOPCServerEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __DIOPCServerEvent_DISPINTERFACE_DEFINED__ */


#ifndef __OPCBrowser_INTERFACE_DEFINED__
#define __OPCBrowser_INTERFACE_DEFINED__

/* interface OPCBrowser */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_OPCBrowser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28E68F94-8D75-11d1-8DC3-3C302A000000")
    OPCBrowser : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Organization( 
            /* [retval][out] */ LONG __RPC_FAR *Organization) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Filter( 
            /* [retval][out] */ BSTR __RPC_FAR *Filter) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Filter( 
            /* [in] */ BSTR Filter) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DataType( 
            /* [retval][out] */ SHORT __RPC_FAR *DataType) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DataType( 
            /* [in] */ SHORT DataType) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AccessRights( 
            /* [retval][out] */ LONG __RPC_FAR *AccessRights) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_AccessRights( 
            /* [in] */ LONG AccessRights) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentPosition( 
            /* [retval][out] */ BSTR __RPC_FAR *CurrentPosition) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG __RPC_FAR *Count) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT ItemSpecifier,
            /* [retval][out] */ BSTR __RPC_FAR *Item) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ShowBranches( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ShowLeafs( 
            /* [optional][in] */ VARIANT Flat) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MoveUp( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MoveToRoot( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MoveDown( 
            /* [string][in] */ BSTR Branch) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MoveTo( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Branches) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetItemID( 
            /* [string][in] */ BSTR Leaf,
            /* [retval][out] */ BSTR __RPC_FAR *ItemID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAccessPaths( 
            /* [string][in] */ BSTR ItemID,
            /* [retval][out] */ VARIANT __RPC_FAR *AccessPaths) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct OPCBrowserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            OPCBrowser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            OPCBrowser __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            OPCBrowser __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            OPCBrowser __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            OPCBrowser __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            OPCBrowser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            OPCBrowser __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Organization )( 
            OPCBrowser __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *Organization);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Filter )( 
            OPCBrowser __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Filter);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Filter )( 
            OPCBrowser __RPC_FAR * This,
            /* [in] */ BSTR Filter);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DataType )( 
            OPCBrowser __RPC_FAR * This,
            /* [retval][out] */ SHORT __RPC_FAR *DataType);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DataType )( 
            OPCBrowser __RPC_FAR * This,
            /* [in] */ SHORT DataType);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AccessRights )( 
            OPCBrowser __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *AccessRights);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AccessRights )( 
            OPCBrowser __RPC_FAR * This,
            /* [in] */ LONG AccessRights);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CurrentPosition )( 
            OPCBrowser __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *CurrentPosition);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            OPCBrowser __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *Count);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            OPCBrowser __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item )( 
            OPCBrowser __RPC_FAR * This,
            /* [in] */ VARIANT ItemSpecifier,
            /* [retval][out] */ BSTR __RPC_FAR *Item);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowBranches )( 
            OPCBrowser __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowLeafs )( 
            OPCBrowser __RPC_FAR * This,
            /* [optional][in] */ VARIANT Flat);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveUp )( 
            OPCBrowser __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveToRoot )( 
            OPCBrowser __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveDown )( 
            OPCBrowser __RPC_FAR * This,
            /* [string][in] */ BSTR Branch);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            OPCBrowser __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Branches);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemID )( 
            OPCBrowser __RPC_FAR * This,
            /* [string][in] */ BSTR Leaf,
            /* [retval][out] */ BSTR __RPC_FAR *ItemID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAccessPaths )( 
            OPCBrowser __RPC_FAR * This,
            /* [string][in] */ BSTR ItemID,
            /* [retval][out] */ VARIANT __RPC_FAR *AccessPaths);
        
        END_INTERFACE
    } OPCBrowserVtbl;

    interface OPCBrowser
    {
        CONST_VTBL struct OPCBrowserVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define OPCBrowser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define OPCBrowser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define OPCBrowser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define OPCBrowser_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define OPCBrowser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define OPCBrowser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define OPCBrowser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define OPCBrowser_get_Organization(This,Organization)	\
    (This)->lpVtbl -> get_Organization(This,Organization)

#define OPCBrowser_get_Filter(This,Filter)	\
    (This)->lpVtbl -> get_Filter(This,Filter)

#define OPCBrowser_put_Filter(This,Filter)	\
    (This)->lpVtbl -> put_Filter(This,Filter)

#define OPCBrowser_get_DataType(This,DataType)	\
    (This)->lpVtbl -> get_DataType(This,DataType)

#define OPCBrowser_put_DataType(This,DataType)	\
    (This)->lpVtbl -> put_DataType(This,DataType)

#define OPCBrowser_get_AccessRights(This,AccessRights)	\
    (This)->lpVtbl -> get_AccessRights(This,AccessRights)

#define OPCBrowser_put_AccessRights(This,AccessRights)	\
    (This)->lpVtbl -> put_AccessRights(This,AccessRights)

#define OPCBrowser_get_CurrentPosition(This,CurrentPosition)	\
    (This)->lpVtbl -> get_CurrentPosition(This,CurrentPosition)

#define OPCBrowser_get_Count(This,Count)	\
    (This)->lpVtbl -> get_Count(This,Count)

#define OPCBrowser_get__NewEnum(This,ppUnk)	\
    (This)->lpVtbl -> get__NewEnum(This,ppUnk)

#define OPCBrowser_Item(This,ItemSpecifier,Item)	\
    (This)->lpVtbl -> Item(This,ItemSpecifier,Item)

#define OPCBrowser_ShowBranches(This)	\
    (This)->lpVtbl -> ShowBranches(This)

#define OPCBrowser_ShowLeafs(This,Flat)	\
    (This)->lpVtbl -> ShowLeafs(This,Flat)

#define OPCBrowser_MoveUp(This)	\
    (This)->lpVtbl -> MoveUp(This)

#define OPCBrowser_MoveToRoot(This)	\
    (This)->lpVtbl -> MoveToRoot(This)

#define OPCBrowser_MoveDown(This,Branch)	\
    (This)->lpVtbl -> MoveDown(This,Branch)

#define OPCBrowser_MoveTo(This,Branches)	\
    (This)->lpVtbl -> MoveTo(This,Branches)

#define OPCBrowser_GetItemID(This,Leaf,ItemID)	\
    (This)->lpVtbl -> GetItemID(This,Leaf,ItemID)

#define OPCBrowser_GetAccessPaths(This,ItemID,AccessPaths)	\
    (This)->lpVtbl -> GetAccessPaths(This,ItemID,AccessPaths)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE OPCBrowser_get_Organization_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *Organization);


void __RPC_STUB OPCBrowser_get_Organization_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE OPCBrowser_get_Filter_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Filter);


void __RPC_STUB OPCBrowser_get_Filter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE OPCBrowser_put_Filter_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [in] */ BSTR Filter);


void __RPC_STUB OPCBrowser_put_Filter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE OPCBrowser_get_DataType_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [retval][out] */ SHORT __RPC_FAR *DataType);


void __RPC_STUB OPCBrowser_get_DataType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE OPCBrowser_put_DataType_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [in] */ SHORT DataType);


void __RPC_STUB OPCBrowser_put_DataType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE OPCBrowser_get_AccessRights_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *AccessRights);


void __RPC_STUB OPCBrowser_get_AccessRights_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE OPCBrowser_put_AccessRights_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [in] */ LONG AccessRights);


void __RPC_STUB OPCBrowser_put_AccessRights_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE OPCBrowser_get_CurrentPosition_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *CurrentPosition);


void __RPC_STUB OPCBrowser_get_CurrentPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE OPCBrowser_get_Count_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *Count);


void __RPC_STUB OPCBrowser_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE OPCBrowser_get__NewEnum_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);


void __RPC_STUB OPCBrowser_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OPCBrowser_Item_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [in] */ VARIANT ItemSpecifier,
    /* [retval][out] */ BSTR __RPC_FAR *Item);


void __RPC_STUB OPCBrowser_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCBrowser_ShowBranches_Proxy( 
    OPCBrowser __RPC_FAR * This);


void __RPC_STUB OPCBrowser_ShowBranches_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCBrowser_ShowLeafs_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [optional][in] */ VARIANT Flat);


void __RPC_STUB OPCBrowser_ShowLeafs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCBrowser_MoveUp_Proxy( 
    OPCBrowser __RPC_FAR * This);


void __RPC_STUB OPCBrowser_MoveUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCBrowser_MoveToRoot_Proxy( 
    OPCBrowser __RPC_FAR * This);


void __RPC_STUB OPCBrowser_MoveToRoot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCBrowser_MoveDown_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [string][in] */ BSTR Branch);


void __RPC_STUB OPCBrowser_MoveDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCBrowser_MoveTo_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Branches);


void __RPC_STUB OPCBrowser_MoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCBrowser_GetItemID_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [string][in] */ BSTR Leaf,
    /* [retval][out] */ BSTR __RPC_FAR *ItemID);


void __RPC_STUB OPCBrowser_GetItemID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCBrowser_GetAccessPaths_Proxy( 
    OPCBrowser __RPC_FAR * This,
    /* [string][in] */ BSTR ItemID,
    /* [retval][out] */ VARIANT __RPC_FAR *AccessPaths);


void __RPC_STUB OPCBrowser_GetAccessPaths_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __OPCBrowser_INTERFACE_DEFINED__ */


#ifndef __IOPCGroups_INTERFACE_DEFINED__
#define __IOPCGroups_INTERFACE_DEFINED__

/* interface IOPCGroups */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IOPCGroups;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28E68F95-8D75-11d1-8DC3-3C302A000000")
    IOPCGroups : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IOPCAutoServer __RPC_FAR *__RPC_FAR *ppParent) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DefaultGroupIsActive( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *DefaultGroupIsActive) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DefaultGroupIsActive( 
            /* [in] */ VARIANT_BOOL DefaultGroupIsActive) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DefaultGroupUpdateRate( 
            /* [retval][out] */ LONG __RPC_FAR *DefaultGroupUpdateRate) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DefaultGroupUpdateRate( 
            /* [in] */ LONG DefaultGroupUpdateRate) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DefaultGroupDeadband( 
            /* [retval][out] */ float __RPC_FAR *DefaultGroupDeadband) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DefaultGroupDeadband( 
            /* [in] */ float DefaultGroupDeadband) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DefaultGroupLocaleID( 
            /* [retval][out] */ LONG __RPC_FAR *DefaultGroupLocaleID) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DefaultGroupLocaleID( 
            /* [in] */ LONG DefaultGroupLocaleID) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DefaultGroupTimeBias( 
            /* [retval][out] */ LONG __RPC_FAR *DefaultGroupTimeBias) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DefaultGroupTimeBias( 
            /* [in] */ LONG DefaultGroupTimeBias) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG __RPC_FAR *Count) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT ItemSpecifier,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [optional][in] */ VARIANT Name,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetOPCGroup( 
            /* [in] */ VARIANT ItemSpecifier,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT ItemSpecifier) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ConnectPublicGroup( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemovePublicGroup( 
            /* [in] */ VARIANT ItemSpecifier) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOPCGroupsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOPCGroups __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOPCGroups __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOPCGroups __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Parent )( 
            IOPCGroups __RPC_FAR * This,
            /* [retval][out] */ IOPCAutoServer __RPC_FAR *__RPC_FAR *ppParent);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultGroupIsActive )( 
            IOPCGroups __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *DefaultGroupIsActive);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultGroupIsActive )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL DefaultGroupIsActive);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultGroupUpdateRate )( 
            IOPCGroups __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *DefaultGroupUpdateRate);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultGroupUpdateRate )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ LONG DefaultGroupUpdateRate);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultGroupDeadband )( 
            IOPCGroups __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *DefaultGroupDeadband);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultGroupDeadband )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ float DefaultGroupDeadband);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultGroupLocaleID )( 
            IOPCGroups __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *DefaultGroupLocaleID);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultGroupLocaleID )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ LONG DefaultGroupLocaleID);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultGroupTimeBias )( 
            IOPCGroups __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *DefaultGroupTimeBias);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultGroupTimeBias )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ LONG DefaultGroupTimeBias);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IOPCGroups __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *Count);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IOPCGroups __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ VARIANT ItemSpecifier,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IOPCGroups __RPC_FAR * This,
            /* [optional][in] */ VARIANT Name,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOPCGroup )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ VARIANT ItemSpecifier,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll )( 
            IOPCGroups __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ VARIANT ItemSpecifier);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConnectPublicGroup )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemovePublicGroup )( 
            IOPCGroups __RPC_FAR * This,
            /* [in] */ VARIANT ItemSpecifier);
        
        END_INTERFACE
    } IOPCGroupsVtbl;

    interface IOPCGroups
    {
        CONST_VTBL struct IOPCGroupsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPCGroups_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOPCGroups_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOPCGroups_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOPCGroups_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOPCGroups_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOPCGroups_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOPCGroups_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOPCGroups_get_Parent(This,ppParent)	\
    (This)->lpVtbl -> get_Parent(This,ppParent)

#define IOPCGroups_get_DefaultGroupIsActive(This,DefaultGroupIsActive)	\
    (This)->lpVtbl -> get_DefaultGroupIsActive(This,DefaultGroupIsActive)

#define IOPCGroups_put_DefaultGroupIsActive(This,DefaultGroupIsActive)	\
    (This)->lpVtbl -> put_DefaultGroupIsActive(This,DefaultGroupIsActive)

#define IOPCGroups_get_DefaultGroupUpdateRate(This,DefaultGroupUpdateRate)	\
    (This)->lpVtbl -> get_DefaultGroupUpdateRate(This,DefaultGroupUpdateRate)

#define IOPCGroups_put_DefaultGroupUpdateRate(This,DefaultGroupUpdateRate)	\
    (This)->lpVtbl -> put_DefaultGroupUpdateRate(This,DefaultGroupUpdateRate)

#define IOPCGroups_get_DefaultGroupDeadband(This,DefaultGroupDeadband)	\
    (This)->lpVtbl -> get_DefaultGroupDeadband(This,DefaultGroupDeadband)

#define IOPCGroups_put_DefaultGroupDeadband(This,DefaultGroupDeadband)	\
    (This)->lpVtbl -> put_DefaultGroupDeadband(This,DefaultGroupDeadband)

#define IOPCGroups_get_DefaultGroupLocaleID(This,DefaultGroupLocaleID)	\
    (This)->lpVtbl -> get_DefaultGroupLocaleID(This,DefaultGroupLocaleID)

#define IOPCGroups_put_DefaultGroupLocaleID(This,DefaultGroupLocaleID)	\
    (This)->lpVtbl -> put_DefaultGroupLocaleID(This,DefaultGroupLocaleID)

#define IOPCGroups_get_DefaultGroupTimeBias(This,DefaultGroupTimeBias)	\
    (This)->lpVtbl -> get_DefaultGroupTimeBias(This,DefaultGroupTimeBias)

#define IOPCGroups_put_DefaultGroupTimeBias(This,DefaultGroupTimeBias)	\
    (This)->lpVtbl -> put_DefaultGroupTimeBias(This,DefaultGroupTimeBias)

#define IOPCGroups_get_Count(This,Count)	\
    (This)->lpVtbl -> get_Count(This,Count)

#define IOPCGroups_get__NewEnum(This,ppUnk)	\
    (This)->lpVtbl -> get__NewEnum(This,ppUnk)

#define IOPCGroups_Item(This,ItemSpecifier,ppGroup)	\
    (This)->lpVtbl -> Item(This,ItemSpecifier,ppGroup)

#define IOPCGroups_Add(This,Name,ppGroup)	\
    (This)->lpVtbl -> Add(This,Name,ppGroup)

#define IOPCGroups_GetOPCGroup(This,ItemSpecifier,ppGroup)	\
    (This)->lpVtbl -> GetOPCGroup(This,ItemSpecifier,ppGroup)

#define IOPCGroups_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)

#define IOPCGroups_Remove(This,ItemSpecifier)	\
    (This)->lpVtbl -> Remove(This,ItemSpecifier)

#define IOPCGroups_ConnectPublicGroup(This,Name,ppGroup)	\
    (This)->lpVtbl -> ConnectPublicGroup(This,Name,ppGroup)

#define IOPCGroups_RemovePublicGroup(This,ItemSpecifier)	\
    (This)->lpVtbl -> RemovePublicGroup(This,ItemSpecifier)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCGroups_get_Parent_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [retval][out] */ IOPCAutoServer __RPC_FAR *__RPC_FAR *ppParent);


void __RPC_STUB IOPCGroups_get_Parent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroups_get_DefaultGroupIsActive_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *DefaultGroupIsActive);


void __RPC_STUB IOPCGroups_get_DefaultGroupIsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroups_put_DefaultGroupIsActive_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL DefaultGroupIsActive);


void __RPC_STUB IOPCGroups_put_DefaultGroupIsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroups_get_DefaultGroupUpdateRate_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *DefaultGroupUpdateRate);


void __RPC_STUB IOPCGroups_get_DefaultGroupUpdateRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroups_put_DefaultGroupUpdateRate_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ LONG DefaultGroupUpdateRate);


void __RPC_STUB IOPCGroups_put_DefaultGroupUpdateRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroups_get_DefaultGroupDeadband_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *DefaultGroupDeadband);


void __RPC_STUB IOPCGroups_get_DefaultGroupDeadband_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroups_put_DefaultGroupDeadband_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ float DefaultGroupDeadband);


void __RPC_STUB IOPCGroups_put_DefaultGroupDeadband_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroups_get_DefaultGroupLocaleID_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *DefaultGroupLocaleID);


void __RPC_STUB IOPCGroups_get_DefaultGroupLocaleID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroups_put_DefaultGroupLocaleID_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ LONG DefaultGroupLocaleID);


void __RPC_STUB IOPCGroups_put_DefaultGroupLocaleID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroups_get_DefaultGroupTimeBias_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *DefaultGroupTimeBias);


void __RPC_STUB IOPCGroups_get_DefaultGroupTimeBias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroups_put_DefaultGroupTimeBias_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ LONG DefaultGroupTimeBias);


void __RPC_STUB IOPCGroups_put_DefaultGroupTimeBias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCGroups_get_Count_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *Count);


void __RPC_STUB IOPCGroups_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE IOPCGroups_get__NewEnum_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);


void __RPC_STUB IOPCGroups_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOPCGroups_Item_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ VARIANT ItemSpecifier,
    /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IOPCGroups_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroups_Add_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [optional][in] */ VARIANT Name,
    /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IOPCGroups_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroups_GetOPCGroup_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ VARIANT ItemSpecifier,
    /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IOPCGroups_GetOPCGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroups_RemoveAll_Proxy( 
    IOPCGroups __RPC_FAR * This);


void __RPC_STUB IOPCGroups_RemoveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroups_Remove_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ VARIANT ItemSpecifier);


void __RPC_STUB IOPCGroups_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroups_ConnectPublicGroup_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IOPCGroups_ConnectPublicGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IOPCGroups_RemovePublicGroup_Proxy( 
    IOPCGroups __RPC_FAR * This,
    /* [in] */ VARIANT ItemSpecifier);


void __RPC_STUB IOPCGroups_RemovePublicGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOPCGroups_INTERFACE_DEFINED__ */


#ifndef __DIOPCGroupsEvent_DISPINTERFACE_DEFINED__
#define __DIOPCGroupsEvent_DISPINTERFACE_DEFINED__

/* dispinterface DIOPCGroupsEvent */
/* [helpstring][nonextensible][uuid] */ 


EXTERN_C const IID DIID_DIOPCGroupsEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("28E68F9D-8D75-11d1-8DC3-3C302A000000")
    DIOPCGroupsEvent : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct DIOPCGroupsEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            DIOPCGroupsEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            DIOPCGroupsEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            DIOPCGroupsEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            DIOPCGroupsEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            DIOPCGroupsEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            DIOPCGroupsEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            DIOPCGroupsEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } DIOPCGroupsEventVtbl;

    interface DIOPCGroupsEvent
    {
        CONST_VTBL struct DIOPCGroupsEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define DIOPCGroupsEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define DIOPCGroupsEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define DIOPCGroupsEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define DIOPCGroupsEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define DIOPCGroupsEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define DIOPCGroupsEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define DIOPCGroupsEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __DIOPCGroupsEvent_DISPINTERFACE_DEFINED__ */


#ifndef __IOPCGroup_INTERFACE_DEFINED__
#define __IOPCGroup_INTERFACE_DEFINED__

/* interface IOPCGroup */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IOPCGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28E68F96-8D75-11d1-8DC3-3C302A000000")
    IOPCGroup : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IOPCAutoServer __RPC_FAR *__RPC_FAR *ppParent) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *Name) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsPublic( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsPublic) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsActive( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsActive) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_IsActive( 
            /* [in] */ VARIANT_BOOL IsActive) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsSubscribed( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsSubscribed) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_IsSubscribed( 
            /* [in] */ VARIANT_BOOL IsSubscribed) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ClientHandle( 
            /* [retval][out] */ LONG __RPC_FAR *ClientHandle) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_ClientHandle( 
            /* [in] */ LONG ClientHandle) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ServerHandle( 
            /* [retval][out] */ LONG __RPC_FAR *ServerHandle) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LocaleID( 
            /* [retval][out] */ LONG __RPC_FAR *LocaleID) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_LocaleID( 
            /* [in] */ LONG LocaleID) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_TimeBias( 
            /* [retval][out] */ LONG __RPC_FAR *TimeBias) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_TimeBias( 
            /* [in] */ LONG TimeBias) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DeadBand( 
            /* [retval][out] */ FLOAT __RPC_FAR *DeadBand) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DeadBand( 
            /* [in] */ FLOAT DeadBand) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UpdateRate( 
            /* [retval][out] */ LONG __RPC_FAR *UpdateRate) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_UpdateRate( 
            /* [in] */ LONG UpdateRate) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OPCItems( 
            /* [retval][out] */ OPCItems __RPC_FAR *__RPC_FAR *ppItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncRead( 
            /* [in] */ SHORT Source,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Values,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [optional][out] */ VARIANT __RPC_FAR *Qualities,
            /* [optional][out] */ VARIANT __RPC_FAR *TimeStamps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncWrite( 
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Values,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncRead( 
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [in] */ LONG TransactionID,
            /* [out] */ LONG __RPC_FAR *CancelID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncWrite( 
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Values,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [in] */ LONG TransactionID,
            /* [out] */ LONG __RPC_FAR *CancelID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncRefresh( 
            /* [in] */ SHORT Source,
            /* [in] */ LONG TransactionID,
            /* [out] */ LONG __RPC_FAR *CancelID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncCancel( 
            /* [in] */ LONG CancelID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOPCGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOPCGroup __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOPCGroup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOPCGroup __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Parent )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ IOPCAutoServer __RPC_FAR *__RPC_FAR *ppParent);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsPublic )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsPublic);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsActive )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsActive);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IsActive )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL IsActive);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsSubscribed )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsSubscribed);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IsSubscribed )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL IsSubscribed);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClientHandle )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ClientHandle);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ClientHandle )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ LONG ClientHandle);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServerHandle )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ServerHandle);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LocaleID )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *LocaleID);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LocaleID )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ LONG LocaleID);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TimeBias )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *TimeBias);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TimeBias )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ LONG TimeBias);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DeadBand )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ FLOAT __RPC_FAR *DeadBand);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DeadBand )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ FLOAT DeadBand);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UpdateRate )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *UpdateRate);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UpdateRate )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ LONG UpdateRate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OPCItems )( 
            IOPCGroup __RPC_FAR * This,
            /* [retval][out] */ OPCItems __RPC_FAR *__RPC_FAR *ppItems);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncRead )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ SHORT Source,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Values,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [optional][out] */ VARIANT __RPC_FAR *Qualities,
            /* [optional][out] */ VARIANT __RPC_FAR *TimeStamps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncWrite )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Values,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncRead )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [in] */ LONG TransactionID,
            /* [out] */ LONG __RPC_FAR *CancelID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncWrite )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Values,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [in] */ LONG TransactionID,
            /* [out] */ LONG __RPC_FAR *CancelID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncRefresh )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ SHORT Source,
            /* [in] */ LONG TransactionID,
            /* [out] */ LONG __RPC_FAR *CancelID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncCancel )( 
            IOPCGroup __RPC_FAR * This,
            /* [in] */ LONG CancelID);
        
        END_INTERFACE
    } IOPCGroupVtbl;

    interface IOPCGroup
    {
        CONST_VTBL struct IOPCGroupVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOPCGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOPCGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOPCGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOPCGroup_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOPCGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOPCGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOPCGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOPCGroup_get_Parent(This,ppParent)	\
    (This)->lpVtbl -> get_Parent(This,ppParent)

#define IOPCGroup_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)

#define IOPCGroup_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IOPCGroup_get_IsPublic(This,IsPublic)	\
    (This)->lpVtbl -> get_IsPublic(This,IsPublic)

#define IOPCGroup_get_IsActive(This,IsActive)	\
    (This)->lpVtbl -> get_IsActive(This,IsActive)

#define IOPCGroup_put_IsActive(This,IsActive)	\
    (This)->lpVtbl -> put_IsActive(This,IsActive)

#define IOPCGroup_get_IsSubscribed(This,IsSubscribed)	\
    (This)->lpVtbl -> get_IsSubscribed(This,IsSubscribed)

#define IOPCGroup_put_IsSubscribed(This,IsSubscribed)	\
    (This)->lpVtbl -> put_IsSubscribed(This,IsSubscribed)

#define IOPCGroup_get_ClientHandle(This,ClientHandle)	\
    (This)->lpVtbl -> get_ClientHandle(This,ClientHandle)

#define IOPCGroup_put_ClientHandle(This,ClientHandle)	\
    (This)->lpVtbl -> put_ClientHandle(This,ClientHandle)

#define IOPCGroup_get_ServerHandle(This,ServerHandle)	\
    (This)->lpVtbl -> get_ServerHandle(This,ServerHandle)

#define IOPCGroup_get_LocaleID(This,LocaleID)	\
    (This)->lpVtbl -> get_LocaleID(This,LocaleID)

#define IOPCGroup_put_LocaleID(This,LocaleID)	\
    (This)->lpVtbl -> put_LocaleID(This,LocaleID)

#define IOPCGroup_get_TimeBias(This,TimeBias)	\
    (This)->lpVtbl -> get_TimeBias(This,TimeBias)

#define IOPCGroup_put_TimeBias(This,TimeBias)	\
    (This)->lpVtbl -> put_TimeBias(This,TimeBias)

#define IOPCGroup_get_DeadBand(This,DeadBand)	\
    (This)->lpVtbl -> get_DeadBand(This,DeadBand)

#define IOPCGroup_put_DeadBand(This,DeadBand)	\
    (This)->lpVtbl -> put_DeadBand(This,DeadBand)

#define IOPCGroup_get_UpdateRate(This,UpdateRate)	\
    (This)->lpVtbl -> get_UpdateRate(This,UpdateRate)

#define IOPCGroup_put_UpdateRate(This,UpdateRate)	\
    (This)->lpVtbl -> put_UpdateRate(This,UpdateRate)

#define IOPCGroup_get_OPCItems(This,ppItems)	\
    (This)->lpVtbl -> get_OPCItems(This,ppItems)

#define IOPCGroup_SyncRead(This,Source,NumItems,ServerHandles,Values,Errors,Qualities,TimeStamps)	\
    (This)->lpVtbl -> SyncRead(This,Source,NumItems,ServerHandles,Values,Errors,Qualities,TimeStamps)

#define IOPCGroup_SyncWrite(This,NumItems,ServerHandles,Values,Errors)	\
    (This)->lpVtbl -> SyncWrite(This,NumItems,ServerHandles,Values,Errors)

#define IOPCGroup_AsyncRead(This,NumItems,ServerHandles,Errors,TransactionID,CancelID)	\
    (This)->lpVtbl -> AsyncRead(This,NumItems,ServerHandles,Errors,TransactionID,CancelID)

#define IOPCGroup_AsyncWrite(This,NumItems,ServerHandles,Values,Errors,TransactionID,CancelID)	\
    (This)->lpVtbl -> AsyncWrite(This,NumItems,ServerHandles,Values,Errors,TransactionID,CancelID)

#define IOPCGroup_AsyncRefresh(This,Source,TransactionID,CancelID)	\
    (This)->lpVtbl -> AsyncRefresh(This,Source,TransactionID,CancelID)

#define IOPCGroup_AsyncCancel(This,CancelID)	\
    (This)->lpVtbl -> AsyncCancel(This,CancelID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_Parent_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ IOPCAutoServer __RPC_FAR *__RPC_FAR *ppParent);


void __RPC_STUB IOPCGroup_get_Parent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_Name_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Name);


void __RPC_STUB IOPCGroup_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroup_put_Name_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IOPCGroup_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_IsPublic_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsPublic);


void __RPC_STUB IOPCGroup_get_IsPublic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_IsActive_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsActive);


void __RPC_STUB IOPCGroup_get_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroup_put_IsActive_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL IsActive);


void __RPC_STUB IOPCGroup_put_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_IsSubscribed_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsSubscribed);


void __RPC_STUB IOPCGroup_get_IsSubscribed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroup_put_IsSubscribed_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL IsSubscribed);


void __RPC_STUB IOPCGroup_put_IsSubscribed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_ClientHandle_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ClientHandle);


void __RPC_STUB IOPCGroup_get_ClientHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroup_put_ClientHandle_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ LONG ClientHandle);


void __RPC_STUB IOPCGroup_put_ClientHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_ServerHandle_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ServerHandle);


void __RPC_STUB IOPCGroup_get_ServerHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_LocaleID_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *LocaleID);


void __RPC_STUB IOPCGroup_get_LocaleID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroup_put_LocaleID_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ LONG LocaleID);


void __RPC_STUB IOPCGroup_put_LocaleID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_TimeBias_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *TimeBias);


void __RPC_STUB IOPCGroup_get_TimeBias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroup_put_TimeBias_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ LONG TimeBias);


void __RPC_STUB IOPCGroup_put_TimeBias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_DeadBand_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ FLOAT __RPC_FAR *DeadBand);


void __RPC_STUB IOPCGroup_get_DeadBand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroup_put_DeadBand_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ FLOAT DeadBand);


void __RPC_STUB IOPCGroup_put_DeadBand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_UpdateRate_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *UpdateRate);


void __RPC_STUB IOPCGroup_get_UpdateRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IOPCGroup_put_UpdateRate_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ LONG UpdateRate);


void __RPC_STUB IOPCGroup_put_UpdateRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IOPCGroup_get_OPCItems_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [retval][out] */ OPCItems __RPC_FAR *__RPC_FAR *ppItems);


void __RPC_STUB IOPCGroup_get_OPCItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IOPCGroup_SyncRead_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ SHORT Source,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Values,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
    /* [optional][out] */ VARIANT __RPC_FAR *Qualities,
    /* [optional][out] */ VARIANT __RPC_FAR *TimeStamps);


void __RPC_STUB IOPCGroup_SyncRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IOPCGroup_SyncWrite_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Values,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);


void __RPC_STUB IOPCGroup_SyncWrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IOPCGroup_AsyncRead_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
    /* [in] */ LONG TransactionID,
    /* [out] */ LONG __RPC_FAR *CancelID);


void __RPC_STUB IOPCGroup_AsyncRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IOPCGroup_AsyncWrite_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Values,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
    /* [in] */ LONG TransactionID,
    /* [out] */ LONG __RPC_FAR *CancelID);


void __RPC_STUB IOPCGroup_AsyncWrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IOPCGroup_AsyncRefresh_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ SHORT Source,
    /* [in] */ LONG TransactionID,
    /* [out] */ LONG __RPC_FAR *CancelID);


void __RPC_STUB IOPCGroup_AsyncRefresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IOPCGroup_AsyncCancel_Proxy( 
    IOPCGroup __RPC_FAR * This,
    /* [in] */ LONG CancelID);


void __RPC_STUB IOPCGroup_AsyncCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOPCGroup_INTERFACE_DEFINED__ */


#ifndef __DIOPCGroupEvent_DISPINTERFACE_DEFINED__
#define __DIOPCGroupEvent_DISPINTERFACE_DEFINED__

/* dispinterface DIOPCGroupEvent */
/* [helpstring][nonextensible][uuid] */ 


EXTERN_C const IID DIID_DIOPCGroupEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("28E68F97-8D75-11d1-8DC3-3C302A000000")
    DIOPCGroupEvent : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct DIOPCGroupEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            DIOPCGroupEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            DIOPCGroupEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            DIOPCGroupEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            DIOPCGroupEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            DIOPCGroupEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            DIOPCGroupEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            DIOPCGroupEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } DIOPCGroupEventVtbl;

    interface DIOPCGroupEvent
    {
        CONST_VTBL struct DIOPCGroupEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define DIOPCGroupEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define DIOPCGroupEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define DIOPCGroupEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define DIOPCGroupEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define DIOPCGroupEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define DIOPCGroupEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define DIOPCGroupEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __DIOPCGroupEvent_DISPINTERFACE_DEFINED__ */


#ifndef __OPCItems_INTERFACE_DEFINED__
#define __OPCItems_INTERFACE_DEFINED__

/* interface OPCItems */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_OPCItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28E68F98-8D75-11d1-8DC3-3C302A000000")
    OPCItems : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppParent) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DefaultRequestedDataType( 
            /* [retval][out] */ SHORT __RPC_FAR *DefaultRequestedDataType) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DefaultRequestedDataType( 
            /* [in] */ SHORT DefaultRequestedDataType) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DefaultAccessPath( 
            /* [retval][out] */ BSTR __RPC_FAR *DefaultAccessPath) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DefaultAccessPath( 
            /* [string][in] */ BSTR DefaultAccessPath) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DefaultIsActive( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *DefaultIsActive) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DefaultIsActive( 
            /* [in] */ VARIANT_BOOL DefaultIsActive) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG __RPC_FAR *Count) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT ItemSpecifier,
            /* [retval][out] */ OPCItem __RPC_FAR *__RPC_FAR *ppItem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetOPCItem( 
            /* [in] */ LONG ServerHandle,
            /* [retval][out] */ OPCItem __RPC_FAR *__RPC_FAR *ppItem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddItem( 
            /* [string][in] */ BSTR ItemID,
            /* [in] */ LONG ClientHandle,
            /* [retval][out] */ OPCItem __RPC_FAR *__RPC_FAR *ppItem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddItems( 
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemIDs,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [optional][in] */ VARIANT RequestedDataTypes,
            /* [optional][in] */ VARIANT AccessPaths) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Validate( 
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [optional][in] */ VARIANT RequestedDataTypes,
            /* [optional][in] */ VARIANT AccessPaths) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetActive( 
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ VARIANT_BOOL ActiveState,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetClientHandles( 
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetDataTypes( 
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *RequestedDataTypes,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct OPCItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            OPCItems __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            OPCItems __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            OPCItems __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Parent )( 
            OPCItems __RPC_FAR * This,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppParent);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultRequestedDataType )( 
            OPCItems __RPC_FAR * This,
            /* [retval][out] */ SHORT __RPC_FAR *DefaultRequestedDataType);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultRequestedDataType )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ SHORT DefaultRequestedDataType);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultAccessPath )( 
            OPCItems __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *DefaultAccessPath);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultAccessPath )( 
            OPCItems __RPC_FAR * This,
            /* [string][in] */ BSTR DefaultAccessPath);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultIsActive )( 
            OPCItems __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *DefaultIsActive);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultIsActive )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL DefaultIsActive);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            OPCItems __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *Count);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            OPCItems __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ VARIANT ItemSpecifier,
            /* [retval][out] */ OPCItem __RPC_FAR *__RPC_FAR *ppItem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOPCItem )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ LONG ServerHandle,
            /* [retval][out] */ OPCItem __RPC_FAR *__RPC_FAR *ppItem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddItem )( 
            OPCItems __RPC_FAR * This,
            /* [string][in] */ BSTR ItemID,
            /* [in] */ LONG ClientHandle,
            /* [retval][out] */ OPCItem __RPC_FAR *__RPC_FAR *ppItem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddItems )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemIDs,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [optional][in] */ VARIANT RequestedDataTypes,
            /* [optional][in] */ VARIANT AccessPaths);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemIDs,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
            /* [optional][in] */ VARIANT RequestedDataTypes,
            /* [optional][in] */ VARIANT AccessPaths);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetActive )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ VARIANT_BOOL ActiveState,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClientHandles )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDataTypes )( 
            OPCItems __RPC_FAR * This,
            /* [in] */ LONG NumItems,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *RequestedDataTypes,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);
        
        END_INTERFACE
    } OPCItemsVtbl;

    interface OPCItems
    {
        CONST_VTBL struct OPCItemsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define OPCItems_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define OPCItems_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define OPCItems_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define OPCItems_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define OPCItems_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define OPCItems_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define OPCItems_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define OPCItems_get_Parent(This,ppParent)	\
    (This)->lpVtbl -> get_Parent(This,ppParent)

#define OPCItems_get_DefaultRequestedDataType(This,DefaultRequestedDataType)	\
    (This)->lpVtbl -> get_DefaultRequestedDataType(This,DefaultRequestedDataType)

#define OPCItems_put_DefaultRequestedDataType(This,DefaultRequestedDataType)	\
    (This)->lpVtbl -> put_DefaultRequestedDataType(This,DefaultRequestedDataType)

#define OPCItems_get_DefaultAccessPath(This,DefaultAccessPath)	\
    (This)->lpVtbl -> get_DefaultAccessPath(This,DefaultAccessPath)

#define OPCItems_put_DefaultAccessPath(This,DefaultAccessPath)	\
    (This)->lpVtbl -> put_DefaultAccessPath(This,DefaultAccessPath)

#define OPCItems_get_DefaultIsActive(This,DefaultIsActive)	\
    (This)->lpVtbl -> get_DefaultIsActive(This,DefaultIsActive)

#define OPCItems_put_DefaultIsActive(This,DefaultIsActive)	\
    (This)->lpVtbl -> put_DefaultIsActive(This,DefaultIsActive)

#define OPCItems_get_Count(This,Count)	\
    (This)->lpVtbl -> get_Count(This,Count)

#define OPCItems_get__NewEnum(This,ppUnk)	\
    (This)->lpVtbl -> get__NewEnum(This,ppUnk)

#define OPCItems_Item(This,ItemSpecifier,ppItem)	\
    (This)->lpVtbl -> Item(This,ItemSpecifier,ppItem)

#define OPCItems_GetOPCItem(This,ServerHandle,ppItem)	\
    (This)->lpVtbl -> GetOPCItem(This,ServerHandle,ppItem)

#define OPCItems_AddItem(This,ItemID,ClientHandle,ppItem)	\
    (This)->lpVtbl -> AddItem(This,ItemID,ClientHandle,ppItem)

#define OPCItems_AddItems(This,NumItems,ItemIDs,ClientHandles,ServerHandles,Errors,RequestedDataTypes,AccessPaths)	\
    (This)->lpVtbl -> AddItems(This,NumItems,ItemIDs,ClientHandles,ServerHandles,Errors,RequestedDataTypes,AccessPaths)

#define OPCItems_Remove(This,NumItems,ServerHandles,Errors)	\
    (This)->lpVtbl -> Remove(This,NumItems,ServerHandles,Errors)

#define OPCItems_Validate(This,NumItems,ItemIDs,Errors,RequestedDataTypes,AccessPaths)	\
    (This)->lpVtbl -> Validate(This,NumItems,ItemIDs,Errors,RequestedDataTypes,AccessPaths)

#define OPCItems_SetActive(This,NumItems,ServerHandles,ActiveState,Errors)	\
    (This)->lpVtbl -> SetActive(This,NumItems,ServerHandles,ActiveState,Errors)

#define OPCItems_SetClientHandles(This,NumItems,ServerHandles,ClientHandles,Errors)	\
    (This)->lpVtbl -> SetClientHandles(This,NumItems,ServerHandles,ClientHandles,Errors)

#define OPCItems_SetDataTypes(This,NumItems,ServerHandles,RequestedDataTypes,Errors)	\
    (This)->lpVtbl -> SetDataTypes(This,NumItems,ServerHandles,RequestedDataTypes,Errors)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE OPCItems_get_Parent_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *ppParent);


void __RPC_STUB OPCItems_get_Parent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItems_get_DefaultRequestedDataType_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [retval][out] */ SHORT __RPC_FAR *DefaultRequestedDataType);


void __RPC_STUB OPCItems_get_DefaultRequestedDataType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE OPCItems_put_DefaultRequestedDataType_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ SHORT DefaultRequestedDataType);


void __RPC_STUB OPCItems_put_DefaultRequestedDataType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItems_get_DefaultAccessPath_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *DefaultAccessPath);


void __RPC_STUB OPCItems_get_DefaultAccessPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE OPCItems_put_DefaultAccessPath_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [string][in] */ BSTR DefaultAccessPath);


void __RPC_STUB OPCItems_put_DefaultAccessPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItems_get_DefaultIsActive_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *DefaultIsActive);


void __RPC_STUB OPCItems_get_DefaultIsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE OPCItems_put_DefaultIsActive_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL DefaultIsActive);


void __RPC_STUB OPCItems_put_DefaultIsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE OPCItems_get_Count_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *Count);


void __RPC_STUB OPCItems_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE OPCItems_get__NewEnum_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);


void __RPC_STUB OPCItems_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OPCItems_Item_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ VARIANT ItemSpecifier,
    /* [retval][out] */ OPCItem __RPC_FAR *__RPC_FAR *ppItem);


void __RPC_STUB OPCItems_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCItems_GetOPCItem_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ LONG ServerHandle,
    /* [retval][out] */ OPCItem __RPC_FAR *__RPC_FAR *ppItem);


void __RPC_STUB OPCItems_GetOPCItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCItems_AddItem_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [string][in] */ BSTR ItemID,
    /* [in] */ LONG ClientHandle,
    /* [retval][out] */ OPCItem __RPC_FAR *__RPC_FAR *ppItem);


void __RPC_STUB OPCItems_AddItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCItems_AddItems_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemIDs,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
    /* [optional][in] */ VARIANT RequestedDataTypes,
    /* [optional][in] */ VARIANT AccessPaths);


void __RPC_STUB OPCItems_AddItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCItems_Remove_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);


void __RPC_STUB OPCItems_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCItems_Validate_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ItemIDs,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors,
    /* [optional][in] */ VARIANT RequestedDataTypes,
    /* [optional][in] */ VARIANT AccessPaths);


void __RPC_STUB OPCItems_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCItems_SetActive_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
    /* [in] */ VARIANT_BOOL ActiveState,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);


void __RPC_STUB OPCItems_SetActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCItems_SetClientHandles_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ClientHandles,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);


void __RPC_STUB OPCItems_SetClientHandles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE OPCItems_SetDataTypes_Proxy( 
    OPCItems __RPC_FAR * This,
    /* [in] */ LONG NumItems,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ServerHandles,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *RequestedDataTypes,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Errors);


void __RPC_STUB OPCItems_SetDataTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __OPCItems_INTERFACE_DEFINED__ */


#ifndef __OPCItem_INTERFACE_DEFINED__
#define __OPCItem_INTERFACE_DEFINED__

/* interface OPCItem */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_OPCItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28E68F99-8D75-11d1-8DC3-3C302A000000")
    OPCItem : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *Parent) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ClientHandle( 
            /* [retval][out] */ LONG __RPC_FAR *ClientHandle) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_ClientHandle( 
            /* [in] */ LONG ClientHandle) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ServerHandle( 
            /* [retval][out] */ LONG __RPC_FAR *ServerHandle) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_AccessPath( 
            /* [retval][out] */ BSTR __RPC_FAR *AccessPath) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_AccessRights( 
            /* [retval][out] */ LONG __RPC_FAR *AccessRights) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ItemID( 
            /* [retval][out] */ BSTR __RPC_FAR *ItemID) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsActive( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsActive) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_IsActive( 
            /* [in] */ VARIANT_BOOL IsActive) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RequestedDataType( 
            /* [retval][out] */ SHORT __RPC_FAR *RequestedDataType) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_RequestedDataType( 
            /* [in] */ SHORT RequestedDataType) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT __RPC_FAR *CurrentValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Quality( 
            /* [retval][out] */ LONG __RPC_FAR *Quality) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_TimeStamp( 
            /* [retval][out] */ DATE __RPC_FAR *TimeStamp) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CanonicalDataType( 
            /* [retval][out] */ SHORT __RPC_FAR *CanonicalDataType) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_EUType( 
            /* [retval][out] */ SHORT __RPC_FAR *EUType) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_EUInfo( 
            /* [retval][out] */ VARIANT __RPC_FAR *EUInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Read( 
            /* [in] */ SHORT Source,
            /* [optional][out] */ VARIANT __RPC_FAR *Value,
            /* [optional][out] */ VARIANT __RPC_FAR *Quality,
            /* [optional][out] */ VARIANT __RPC_FAR *TimeStamp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ VARIANT Value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct OPCItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            OPCItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            OPCItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            OPCItem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            OPCItem __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            OPCItem __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            OPCItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            OPCItem __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Parent )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *Parent);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClientHandle )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ClientHandle);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ClientHandle )( 
            OPCItem __RPC_FAR * This,
            /* [in] */ LONG ClientHandle);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServerHandle )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *ServerHandle);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AccessPath )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *AccessPath);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AccessRights )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *AccessRights);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ItemID )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ItemID);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsActive )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsActive);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IsActive )( 
            OPCItem __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL IsActive);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RequestedDataType )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ SHORT __RPC_FAR *RequestedDataType);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RequestedDataType )( 
            OPCItem __RPC_FAR * This,
            /* [in] */ SHORT RequestedDataType);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *CurrentValue);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Quality )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *Quality);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TimeStamp )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ DATE __RPC_FAR *TimeStamp);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CanonicalDataType )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ SHORT __RPC_FAR *CanonicalDataType);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EUType )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ SHORT __RPC_FAR *EUType);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EUInfo )( 
            OPCItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *EUInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Read )( 
            OPCItem __RPC_FAR * This,
            /* [in] */ SHORT Source,
            /* [optional][out] */ VARIANT __RPC_FAR *Value,
            /* [optional][out] */ VARIANT __RPC_FAR *Quality,
            /* [optional][out] */ VARIANT __RPC_FAR *TimeStamp);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Write )( 
            OPCItem __RPC_FAR * This,
            /* [in] */ VARIANT Value);
        
        END_INTERFACE
    } OPCItemVtbl;

    interface OPCItem
    {
        CONST_VTBL struct OPCItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define OPCItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define OPCItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define OPCItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define OPCItem_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define OPCItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define OPCItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define OPCItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define OPCItem_get_Parent(This,Parent)	\
    (This)->lpVtbl -> get_Parent(This,Parent)

#define OPCItem_get_ClientHandle(This,ClientHandle)	\
    (This)->lpVtbl -> get_ClientHandle(This,ClientHandle)

#define OPCItem_put_ClientHandle(This,ClientHandle)	\
    (This)->lpVtbl -> put_ClientHandle(This,ClientHandle)

#define OPCItem_get_ServerHandle(This,ServerHandle)	\
    (This)->lpVtbl -> get_ServerHandle(This,ServerHandle)

#define OPCItem_get_AccessPath(This,AccessPath)	\
    (This)->lpVtbl -> get_AccessPath(This,AccessPath)

#define OPCItem_get_AccessRights(This,AccessRights)	\
    (This)->lpVtbl -> get_AccessRights(This,AccessRights)

#define OPCItem_get_ItemID(This,ItemID)	\
    (This)->lpVtbl -> get_ItemID(This,ItemID)

#define OPCItem_get_IsActive(This,IsActive)	\
    (This)->lpVtbl -> get_IsActive(This,IsActive)

#define OPCItem_put_IsActive(This,IsActive)	\
    (This)->lpVtbl -> put_IsActive(This,IsActive)

#define OPCItem_get_RequestedDataType(This,RequestedDataType)	\
    (This)->lpVtbl -> get_RequestedDataType(This,RequestedDataType)

#define OPCItem_put_RequestedDataType(This,RequestedDataType)	\
    (This)->lpVtbl -> put_RequestedDataType(This,RequestedDataType)

#define OPCItem_get_Value(This,CurrentValue)	\
    (This)->lpVtbl -> get_Value(This,CurrentValue)

#define OPCItem_get_Quality(This,Quality)	\
    (This)->lpVtbl -> get_Quality(This,Quality)

#define OPCItem_get_TimeStamp(This,TimeStamp)	\
    (This)->lpVtbl -> get_TimeStamp(This,TimeStamp)

#define OPCItem_get_CanonicalDataType(This,CanonicalDataType)	\
    (This)->lpVtbl -> get_CanonicalDataType(This,CanonicalDataType)

#define OPCItem_get_EUType(This,EUType)	\
    (This)->lpVtbl -> get_EUType(This,EUType)

#define OPCItem_get_EUInfo(This,EUInfo)	\
    (This)->lpVtbl -> get_EUInfo(This,EUInfo)

#define OPCItem_Read(This,Source,Value,Quality,TimeStamp)	\
    (This)->lpVtbl -> Read(This,Source,Value,Quality,TimeStamp)

#define OPCItem_Write(This,Value)	\
    (This)->lpVtbl -> Write(This,Value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_Parent_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ OPCGroup	__RPC_FAR *__RPC_FAR *Parent);


void __RPC_STUB OPCItem_get_Parent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_ClientHandle_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ClientHandle);


void __RPC_STUB OPCItem_get_ClientHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE OPCItem_put_ClientHandle_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [in] */ LONG ClientHandle);


void __RPC_STUB OPCItem_put_ClientHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_ServerHandle_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *ServerHandle);


void __RPC_STUB OPCItem_get_ServerHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_AccessPath_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *AccessPath);


void __RPC_STUB OPCItem_get_AccessPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_AccessRights_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *AccessRights);


void __RPC_STUB OPCItem_get_AccessRights_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_ItemID_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ItemID);


void __RPC_STUB OPCItem_get_ItemID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_IsActive_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *IsActive);


void __RPC_STUB OPCItem_get_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE OPCItem_put_IsActive_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL IsActive);


void __RPC_STUB OPCItem_put_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_RequestedDataType_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ SHORT __RPC_FAR *RequestedDataType);


void __RPC_STUB OPCItem_get_RequestedDataType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE OPCItem_put_RequestedDataType_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [in] */ SHORT RequestedDataType);


void __RPC_STUB OPCItem_put_RequestedDataType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE OPCItem_get_Value_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *CurrentValue);


void __RPC_STUB OPCItem_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_Quality_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *Quality);


void __RPC_STUB OPCItem_get_Quality_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_TimeStamp_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ DATE __RPC_FAR *TimeStamp);


void __RPC_STUB OPCItem_get_TimeStamp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_CanonicalDataType_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ SHORT __RPC_FAR *CanonicalDataType);


void __RPC_STUB OPCItem_get_CanonicalDataType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_EUType_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ SHORT __RPC_FAR *EUType);


void __RPC_STUB OPCItem_get_EUType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE OPCItem_get_EUInfo_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *EUInfo);


void __RPC_STUB OPCItem_get_EUInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OPCItem_Read_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [in] */ SHORT Source,
    /* [optional][out] */ VARIANT __RPC_FAR *Value,
    /* [optional][out] */ VARIANT __RPC_FAR *Quality,
    /* [optional][out] */ VARIANT __RPC_FAR *TimeStamp);


void __RPC_STUB OPCItem_Read_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE OPCItem_Write_Proxy( 
    OPCItem __RPC_FAR * This,
    /* [in] */ VARIANT Value);


void __RPC_STUB OPCItem_Write_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __OPCItem_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OPCGroups;

#ifdef __cplusplus

class DECLSPEC_UUID("28E68F9E-8D75-11d1-8DC3-3C302A000000")
OPCGroups;
#endif

EXTERN_C const CLSID CLSID_OPCGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("28E68F9B-8D75-11d1-8DC3-3C302A000000")
OPCGroup;
#endif
#endif /* __OPCAutomation_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long __RPC_FAR *, unsigned long            , LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


