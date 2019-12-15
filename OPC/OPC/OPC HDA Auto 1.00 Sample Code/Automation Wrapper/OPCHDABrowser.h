/*  ____________________________________________________________________________

    OPCHDABrowser.h

    COPCHDABrowser class definition.
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
#ifndef OPCHDABrowser_h
#define OPCHDABrowser_h

class ATL_NO_VTABLE COPCHDABrowser : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IDispatchImpl<OPCHDABrowser, &IID_OPCHDABrowser, &LIBID_OPCHDAAutomation>
{
public:
BEGIN_COM_MAP(COPCHDABrowser)
	COM_INTERFACE_ENTRY(OPCHDABrowser)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(COPCHDABrowser)

	COPCHDABrowser();
	~COPCHDABrowser();

    STDMETHOD(Initialize)(
        IOPCHDA_Browser* pOPCHDA_Browser);

// OPCHDABrowser
    STDMETHOD(get_CurrentPosition)(BSTR * pCurrentPosition);
    STDMETHOD(get_OPCHDABranches)(VARIANT * pOPCHDABranches);
    STDMETHOD(get_OPCHDALeaves)(VARIANT * pOPCHDALeaves);
    STDMETHOD(get_OPCHDAItems)(VARIANT * pOPCHDAItems);
    
    STDMETHOD(MoveUp)();
    
    STDMETHOD(MoveToRoot)();
    
    STDMETHOD(MoveDown)(
        BSTR BranchName);
    
    STDMETHOD(MoveTo)(
        BSTR NewPosition);
    
    STDMETHOD(GetItemID)(
        BSTR ItemName,
        BSTR * pItemID);

private:
    IOPCHDA_BrowserPtr  m_pOPCHDA_Browser;

}; // class COPCHDABrowser

#endif // OPCHDABrowser_h
