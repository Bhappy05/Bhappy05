/*  ____________________________________________________________________________

    OPCHDAAutoServer.h

    COPCHDAAutoServer class definition.
    ____________________________________________________________________________

    Copyright © 2000 The OPC Foundation

    #292, 20423 State Road 7
    Bacon Raton, FL
    United States 33498
    (561) 477-1375 Phone
    (561) 477-0520 Fax
    www.opcfoundation.org
    opc@powerinternet.com
    ____________________________________________________________________________

    Disclaimer

    This sample code is provided by the OPC Foundation solely to assist
    in understanding the OPC Specifications and may be used
    as set forth in the License Grant section of the OPC Specification.
    This code is provided as-is and without warranty or support of any sort
    and is subject to the Warranty and Liability Disclaimers which appear
    in the printed OPC Specification.
    ____________________________________________________________________________

    Credits

    This code was generously provided to the OPC Foundation by
    Jeff Caulfield, Matrikon Consulting Inc.
    ____________________________________________________________________________

    revision history

    2000-11-15 Jeff Caulfield
    ____________________________________________________________________________
*/
#ifndef OPCHDAAutoServer_h
#define OPCHDAAutoServer_h

#include "OPCHDAAutoCP.h"
#include "OPCHDAItemEvents.h"

class ATL_NO_VTABLE COPCHDAAutoServer : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<COPCHDAAutoServer, &CLSID_OPCHDAServer>,
	public IConnectionPointContainerImpl<COPCHDAAutoServer>,
	public IDispatchImpl<IOPCHDAAutoServer, &IID_IOPCHDAAutoServer, &LIBID_OPCHDAAutomation>,
    public IDispatchImpl<IOPCHDAItems, &IID_IOPCHDAItems, &LIBID_OPCHDAAutomation>,
    public CProxy_IOPCHDAAutoServerEvents<COPCHDAAutoServer>,
    public CProxy_IOPCHDAItemEvents<COPCHDAAutoServer>,
	public ISupportErrorInfo,
    public IOPCShutdown,
    public IOPCHDA_DataCallback
{
public:
DECLARE_REGISTRY_RESOURCEID(IDR_OPCHDAAUTOSERVER)
DECLARE_NOT_AGGREGATABLE(COPCHDAAutoServer)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COPCHDAAutoServer)
    COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY2(IDispatch, IOPCHDAAutoServer)
	COM_INTERFACE_ENTRY(IOPCHDAAutoServer)
    COM_INTERFACE_ENTRY(IOPCHDAItems)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(IOPCShutdown)
    COM_INTERFACE_ENTRY(IOPCHDA_DataCallback)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(COPCHDAAutoServer)
    CONNECTION_POINT_ENTRY(DIID__IOPCHDAAutoServerEvents)
    CONNECTION_POINT_ENTRY(DIID__IOPCHDAItemEvents)
END_CONNECTION_POINT_MAP()

	COPCHDAAutoServer();
	~COPCHDAAutoServer();

    STDMETHOD(VariantToHDATime)(
        const VARIANT* pvTime,
        OPCHDA_TIME* phtTime);

    void HDATimeToVariant(
        const OPCHDA_TIME* phtTime,
        VARIANT* pvTime);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(
        REFIID riid);

// IOPCShutdown
    STDMETHOD(ShutdownRequest)(
        LPCWSTR szReason);

// IOPCHDA_DataCallback
    STDMETHOD(OnDataChange)( 
        DWORD dwTransactionID,
        HRESULT hrStatus,
        DWORD dwNumItems,
        OPCHDA_ITEM * pItemValues,
        HRESULT * phrErrors);
    
    STDMETHOD(OnReadComplete)( 
        DWORD dwTransactionID,
        HRESULT hrStatus,
        DWORD dwNumItems,
        OPCHDA_ITEM * pItemValues,
        HRESULT * phrErrors);
    
    STDMETHOD(OnReadModifiedComplete)( 
        DWORD dwTransactionID,
        HRESULT hrStatus,
        DWORD dwNumItems,
        OPCHDA_MODIFIEDITEM * pItemValues,
        HRESULT * phrErrors);
    
    STDMETHOD(OnReadAttributeComplete)( 
        DWORD dwTransactionID,
        HRESULT hrStatus,
        OPCHANDLE hClient,
        DWORD dwNumItems,
        OPCHDA_ATTRIBUTE * pAttributeValues,
        HRESULT * phrErrors);
    
    STDMETHOD(OnReadAnnotations)( 
        DWORD dwTransactionID,
        HRESULT hrStatus,
        DWORD dwNumItems,
        OPCHDA_ANNOTATION * pAnnotationValues,
        HRESULT * phrErrors);
    
    STDMETHOD(OnInsertAnnotations)( 
        DWORD dwTransactionID,
        HRESULT hrStatus,
        DWORD dwCount,
        OPCHANDLE * phClients,
        HRESULT * phrErrors);
    
    STDMETHOD(OnPlayback)( 
        DWORD dwTransactionID,
        HRESULT hrStatus,
        DWORD dwNumItems,
        OPCHDA_ITEM ** ppItemValues,
        HRESULT * phrErrors);
    
    STDMETHOD(OnUpdateComplete)( 
        DWORD dwTransactionID,
        HRESULT hrStatus,
        DWORD dwCount,
        OPCHANDLE * phClients,
        HRESULT * phrErrors);
    
    STDMETHOD(OnCancelComplete)( 
        DWORD dwCancelID);

// IOPCHDAAutoServer
    STDMETHOD(get_StartTime)(DATE * pStartTime);
    STDMETHOD(get_CurrentTime)(DATE * pCurrentTime);
    STDMETHOD(get_MaxReturnValues)(LONG * pMaxReturnValues);
    STDMETHOD(get_MajorVersion)(short * pMajorVersion);
    STDMETHOD(get_MinorVersion)(short * pMinorVersion);
    STDMETHOD(get_BuildNumber)(short * pBuildNumber);
    STDMETHOD(get_VendorInfo)(BSTR * pVendorInfo);
    STDMETHOD(get_HistorianStatus)(LONG * pHistorianStatus);
    STDMETHOD(get_StatusString)(BSTR * pStatusString);
    STDMETHOD(get_ServerName)(BSTR * pServerName);
    STDMETHOD(get_ServerNode)(BSTR * pServerNode);
    STDMETHOD(get_ClientName)(BSTR * pClientName);
    STDMETHOD(put_ClientName)(BSTR ClientName);
    STDMETHOD(get_LocaleID)(LONG * pLocaleID);
    STDMETHOD(put_LocaleID)(LONG LocaleID);
	STDMETHOD(get_CanSyncInsert)(BOOL * pCanSyncInsert);
	STDMETHOD(get_CanSyncReplace)(BOOL * pCanSyncReplace);
	STDMETHOD(get_CanSyncInsertReplace)(BOOL * pCanSyncInsertReplace);
	STDMETHOD(get_CanSyncDeleteRaw)(BOOL * pCanSyncDeleteRaw);
	STDMETHOD(get_CanSyncDeleteAtTime)(BOOL * pCanSyncDeleteAtTime);
	STDMETHOD(get_CanSyncReadAnnotations)(BOOL * pCanSyncReadAnnotations);
	STDMETHOD(get_CanSyncInsertAnnotations)(BOOL * pCanSyncInsertAnnotations);
	STDMETHOD(get_CanAsyncInsert)(BOOL * pCanAsyncInsert);
	STDMETHOD(get_CanAsyncReplace)(BOOL * pCanAsyncReplace);
	STDMETHOD(get_CanAsyncInsertReplace)(BOOL * pCanAsyncInsertReplace);
	STDMETHOD(get_CanAsyncDeleteRaw)(BOOL * pCanAsyncDeleteRaw);
	STDMETHOD(get_CanAsyncDeleteAtTime)(BOOL * pCanAsyncDeleteAtTime);
	STDMETHOD(get_CanAsyncReadAnnotations)(BOOL * pCanAsyncReadAnnotations);
	STDMETHOD(get_CanAsyncInsertAnnotations)(BOOL * pCanAsyncInsertAnnotations);
    STDMETHOD(get_OPCHDAItems)(IOPCHDAItems ** ppOPCHDAItems);

    STDMETHOD(GetOPCHDAServers)(
        VARIANT Node,
        VARIANT * pOPCHDAServers);

    STDMETHOD(Connect)(
        BSTR ProgID,
        VARIANT Node);

    STDMETHOD(Disconnect)();

    STDMETHOD(GetErrorString)(
        LONG ErrorCode,
        BSTR *pErrorString);

    STDMETHOD(QueryAvailableLocaleIDs)(
        VARIANT * pLocaleIDs);
    
    STDMETHOD(GetItemAttributes)( 
        LONG * pCount,
        SAFEARRAY ** ppAttributeIDs,
        SAFEARRAY ** ppNames,
        SAFEARRAY ** ppDescriptions,
        SAFEARRAY ** ppDataTypes);
    
    STDMETHOD(GetAggregates)( 
        LONG * pCount,
        SAFEARRAY ** ppAggregateIDs,
        SAFEARRAY ** ppNames,
        SAFEARRAY ** ppDescriptions);
    
    STDMETHOD(CreateBrowser)( 
        LONG NumCriteria,
        VARIANT AttributeIDs,
        VARIANT OperatorCodes,
        VARIANT Filters,
        VARIANT * pErrors,
        OPCHDABrowser ** ppOPCHDABrowser);

// IOPCHDAItems
	STDMETHOD(get_Parent)(IOPCHDAAutoServer ** ppParent);
	STDMETHOD(get_Count)(LONG * pCount);
	STDMETHOD(get__NewEnum)(IUnknown ** ppUnk);

	STDMETHOD(Item)(
        VARIANT ItemSpecifier,
        OPCHDAItem ** ppItem);

	STDMETHOD(GetOPCHDAItem)(
        LONG ServerHandle,
        OPCHDAItem ** ppItem);

	STDMETHOD(AddItem)(
        BSTR ItemID,
        LONG ClientHandle,
        OPCHDAItem ** ppItem);

	STDMETHOD(AddItems)(
        LONG NumItems,
        SAFEARRAY ** ppItemIDs,
        SAFEARRAY ** ppClientHandles,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors);

	STDMETHOD(Remove)(
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors);

	STDMETHOD(RemoveAll)();

	STDMETHOD(Validate)(
        LONG NumItems,
        SAFEARRAY ** ppItemIDs,
        SAFEARRAY ** ppErrors);

	STDMETHOD(SyncReadRaw)(
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG NumValues,
        BOOL Bounds,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppItemValues,
        SAFEARRAY ** ppErrors);

	STDMETHOD(SyncReadProcessed)(
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        DATE ResampleInterval,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppAggregates,
        SAFEARRAY ** ppItemValues,
        SAFEARRAY ** ppErrors);

	STDMETHOD(SyncReadAtTime)(
        LONG NumTimeStamps,
        SAFEARRAY ** ppTimeStamps,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppItemValues,
        SAFEARRAY ** ppErrors);

	STDMETHOD(SyncReadModified)(
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG NumValues,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppItemValues,
        SAFEARRAY ** ppErrors);

	STDMETHOD(SyncReadAttribute)(
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG ServerHandle,
        LONG NumAttributes,
        SAFEARRAY ** ppAttributeIDs,
        SAFEARRAY ** ppAttributeValues,
        SAFEARRAY ** ppErrors);
	
    STDMETHOD(SyncInsert)(
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppDataValues,
        SAFEARRAY ** ppQualities,
        SAFEARRAY ** ppErrors);

	STDMETHOD(SyncReplace)(
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppDataValues,
        SAFEARRAY ** ppQualities,
        SAFEARRAY ** ppErrors);

	STDMETHOD(SyncInsertReplace)(
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppDataValues,
        SAFEARRAY ** ppQualities,
        SAFEARRAY ** ppErrors);

	STDMETHOD(SyncDeleteRaw)(
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors);

	STDMETHOD(SyncDeleteAtTime)(
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppErrors);
	
    STDMETHOD(SyncReadAnnotations)(
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppAnnotationValues,
        SAFEARRAY ** ppErrors);
	
    STDMETHOD(SyncInsertAnnotations)(
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppAnnotationValues,
        SAFEARRAY ** ppErrors);
	
    STDMETHOD(AsyncReadRaw)(
        LONG TransactionID,
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG NumValues,
        BOOL Bounds,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncAdviseRaw)(
        LONG TransactionID,
        VARIANT * pStartTime,
        DATE UpdateInterval,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncReadProcessed)(
        LONG TransactionID,
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        DATE ResampleInterval,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppAggregates,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncAdviseProcessed)(
        LONG TransactionID,
        VARIANT * pStartTime,
        DATE ResampleInterval,
        LONG NumIntervals,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppAggregates,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncReadAtTime)(
        LONG TransactionID,
        LONG NumTimeStamps,
        SAFEARRAY ** ppTimeStamps,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncReadModified)(
        LONG TransactionID,
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG NumValues,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncReadAttribute)(
        LONG TransactionID,
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG ServerHandle,
        LONG NumAttributes,
        SAFEARRAY ** pAttributeIDs,
        SAFEARRAY ** pErrors,
        LONG * pCancelID);
	
    STDMETHOD(AsyncCancelRead)(
        LONG CancelID);
	
    STDMETHOD(AsyncInsert)(
        LONG TransactionID,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppDataValues,
        SAFEARRAY ** ppQualities,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncReplace)(
        LONG TransactionID,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppDataValues,
        SAFEARRAY ** ppQualities,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncInsertReplace)(
        LONG TransactionID,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppDataValues,
        SAFEARRAY ** ppQualities,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncDeleteRaw)(
        LONG TransactionID,
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncDeleteAtTime)(
        LONG TransactionID,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);
	
    STDMETHOD(AsyncCancelUpdate)(
        LONG CancelID);
	
    STDMETHOD(AsyncReadAnnotations)(
        LONG TransactionID,
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncInsertAnnotations)(
        LONG TransactionID,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppTimeStamps,
        SAFEARRAY ** ppAnnotationValues,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);
	
    STDMETHOD(AsyncCancelAnnotations)(
        LONG CancelID);
	
    STDMETHOD(AsyncPlaybackRaw)(
        LONG TransactionID,
        VARIANT * ppStartTime,
        VARIANT * ppEndTime,
        LONG NumValues,
        DATE UpdateDuration,
        DATE UpdateInterval,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);

	STDMETHOD(AsyncPlaybackProcessed)(
        LONG TransactionID,
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        DATE ResampleInterval,
        LONG NumIntervals,
        DATE UpdateInterval,
        LONG NumItems,
        SAFEARRAY ** ppServerHandles,
        SAFEARRAY ** ppAggregates,
        SAFEARRAY ** ppErrors,
        LONG * pCancelID);
	
    STDMETHOD(AsyncCancelPlayback)(
        LONG CancelID);

private:
    typedef std::list<COPCHDAItem*>     TOPCHDAItemCollection;

    CComBSTR                            m_name;
    CComBSTR                            m_node;
    CComBSTR                            m_client;
                                                            
    IOPCCommonPtr                       m_pOPCCommon;
    IOPCHDA_ServerPtr                   m_pOPCHDAServer;
    IOPCHDA_SyncReadPtr                 m_pOPCHDA_SyncRead;
    IOPCHDA_SyncUpdatePtr               m_pOPCHDA_SyncUpdate;
    IOPCHDA_SyncAnnotationsPtr          m_pOPCHDA_SyncAnnotations;
    IOPCHDA_AsyncReadPtr                m_pOPCHDA_AsyncRead;
    IOPCHDA_AsyncUpdatePtr              m_pOPCHDA_AsyncUpdate;
    IOPCHDA_AsyncAnnotationsPtr         m_pOPCHDA_AsyncAnnotations;
    IOPCHDA_PlaybackPtr                 m_pOPCHDA_Playback;
                                                            
    DWORD                               m_ShutdownConnection;
    DWORD                               m_DataConnection;

    TOPCHDAItemCollection               m_items;

}; // class COPCHDAAutoServer

#endif // OPCHDAAutoServer_h
