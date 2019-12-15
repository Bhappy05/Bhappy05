/*  ____________________________________________________________________________

    OPCHDAHistory.h

    COPCHDAHistory class definition.
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
#ifndef OPCHDAHistory_h
#define OPCHDAHistory_h

class ATL_NO_VTABLE COPCHDAHistory : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IDispatchImpl<OPCHDAHistory, &IID_OPCHDAHistory, &LIBID_OPCHDAAutomation>
{
public:
BEGIN_COM_MAP(COPCHDAHistory)
	COM_INTERFACE_ENTRY(OPCHDAHistory)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(COPCHDAHistory)

	COPCHDAHistory();
	~COPCHDAHistory();

    STDMETHOD(Initialize)(OPCHDA_ITEM* pItemValue);
    STDMETHOD(Initialize)(OPCHDA_ATTRIBUTE* pAttributeValue);
    STDMETHOD(Initialize)(OPCHDA_MODIFIEDITEM* pItemValue);
    STDMETHOD(Initialize)(OPCHDA_ANNOTATION* pAnnotationValue);

// OPCHDAHistory
    STDMETHOD(get_Count)(LONG * pCount);
    STDMETHOD(get__NewEnum)(IUnknown ** ppUnk);

	STDMETHOD(Item)(
        VARIANT ItemSpecifier,
        OPCHDAValue ** ppValue);

private:
    DWORD           m_dwCount;
    bool            m_entries;
                    
    FILETIME*       m_pftTimeStamps;
    CComVariant*    m_pvDataValues;
    DWORD*          m_pdwQualities;
                    
    FILETIME*       m_pftEntryTimes;
    DWORD*          m_pdwEntryTypes;
    CComBSTR*       m_pszUsers;

}; // class COPCHDAHistory

#endif // OPCHDAHistory_h
