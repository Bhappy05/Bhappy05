/*  ____________________________________________________________________________

    OPCHDAItem.h

    COPCHDAItem class definition.
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
#ifndef OPCHDAItem_h
#define OPCHDAItem_h

class ATL_NO_VTABLE COPCHDAItem : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IDispatchImpl<OPCHDAItem, &IID_OPCHDAItem, &LIBID_OPCHDAAutomation>
{
public:
BEGIN_COM_MAP(COPCHDAItem)
	COM_INTERFACE_ENTRY(OPCHDAItem)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(COPCHDAItem)

	COPCHDAItem();
	~COPCHDAItem();

    STDMETHOD(Initialize)(
        BSTR szItemID,
        OPCHANDLE hClient,
        OPCHANDLE hServer,
        COPCHDAAutoServer* pParent);

    const BSTR GetItemID() const {return m_itemID;}
    const OPCHANDLE GetClientHandle() const {return m_client;}
    const OPCHANDLE GetServerHandle() const {return m_server;}

// OPCHDAItem
    STDMETHOD(get_Parent)(IOPCHDAAutoServer ** ppParent);
    STDMETHOD(get_ClientHandle)(LONG * pClientHandle);
    STDMETHOD(get_ServerHandle)(LONG * pServerHandle);
    STDMETHOD(get_ItemID)(BSTR * pItemID);
    
    STDMETHOD(ReadRaw)( 
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        LONG NumValues,
        BOOL Bounds,
        VARIANT * pItemValues);
    
    STDMETHOD(ReadProcessed)( 
        VARIANT * pStartTime,
        VARIANT * pEndTime,
        DATE ResampleInterval,
        LONG Aggregate,
        VARIANT * pItemValues);
    
    STDMETHOD(ReadAtTime)( 
        LONG NumTimeStamps,
        SAFEARRAY ** ppTimeStamps,
        VARIANT * pItemValues);
    
    STDMETHOD(Update)( 
        DATE TimeStamp,
        VARIANT DataValue,
        LONG Quality,
        LONG EditType = OPCHDAInsertReplace);
    
    STDMETHOD(DeleteRaw)( 
        VARIANT * pStartTime,
        VARIANT * pEndTime);

private:
    CComBSTR            m_itemID;
    OPCHANDLE           m_client;
    OPCHANDLE           m_server;

    COPCHDAAutoServer*  m_pParent;                                                            

}; // class COPCHDAItem

#endif // OPCHDAItem_h
