/*  ____________________________________________________________________________

    OPCHDAEnumHistory.h

    COPCHDAEnumHistory class definition.
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
#ifndef OPCHDAEnumHistory_h
#define OPCHDAEnumHistory_h

class ATL_NO_VTABLE COPCHDAEnumHistory : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IEnumVARIANT
{
public:
BEGIN_COM_MAP(COPCHDAEnumHistory)
	COM_INTERFACE_ENTRY(IEnumVARIANT)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(COPCHDAEnumHistory)

	COPCHDAEnumHistory();
	~COPCHDAEnumHistory();

    STDMETHOD(Initialize)(
        COPCHDAHistory* pHistory,
        LONG index = 1);

// IEnumVARIANT
    STDMETHOD(Next)( 
        ULONG celt,
        VARIANT * rgVar,
        ULONG * pCeltFetched);
    
    STDMETHOD(Skip)( 
        ULONG celt);
    
    STDMETHOD(Reset)();
    
    STDMETHOD(Clone)( 
        IEnumVARIANT ** ppEnum);

private:
    LONG            m_index;
    COPCHDAHistory* m_pHistory;

}; // class COPCHDAEnumHistory

#endif // OPCHDAEnumHistory_h
