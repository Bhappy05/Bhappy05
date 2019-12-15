/*  ____________________________________________________________________________

    OPCHDAEntry.h

    COPCHDAEntry class definition.
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
#ifndef OPCHDAEntry_h
#define OPCHDAEntry_h

class ATL_NO_VTABLE COPCHDAEntry : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IDispatchImpl<OPCHDAEntry, &IID_OPCHDAEntry, &LIBID_OPCHDAAutomation>
{
public:
BEGIN_COM_MAP(COPCHDAEntry)
	COM_INTERFACE_ENTRY(OPCHDAEntry)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(COPCHDAEntry)

	COPCHDAEntry()
    {
        m_timeStamp = 0.0;
        m_quality = 0;
        m_entryTime = 0.0;
        m_entryType = 0;
    }

    STDMETHOD(Initialize)(
        DATE TimeStamp,
        const CComVariant& DataValue,
        DWORD Quality,
        DATE EntryTime,
        DWORD EntryType,
        const CComBSTR& User)
    {
        m_timeStamp = TimeStamp;
        m_dataValue = DataValue;
        m_quality = Quality;
        m_entryTime = EntryTime;
        m_entryType = EntryType;
        m_user = User;

        return S_OK;
    }

// OPCHDAEntry
    STDMETHOD(get_TimeStamp)(DATE * pTimeStamp)
    {
        if (NULL == pTimeStamp)
        {
            return E_POINTER;
        }

        *pTimeStamp = m_timeStamp;

        return S_OK;
    }

    STDMETHOD(get_DataValue)(VARIANT * pDataValue)
    {
        if (NULL == pDataValue)
        {
            return E_POINTER;
        }

        HRESULT hr = E_FAIL;

        VariantClear(pDataValue);

        hr = VariantCopy(pDataValue, &m_dataValue);

        return hr;
    }

    STDMETHOD(get_Quality)(LONG * pQuality)
    {
        if (NULL == pQuality)
        {
            return E_POINTER;
        }

        *pQuality = m_quality;

        return S_OK;
    }

    STDMETHOD(get_EntryTime)(DATE * pEntryTime)
    {
        if (NULL == pEntryTime)
        {
            return E_POINTER;
        }

        *pEntryTime = m_entryTime;

        return S_OK;
    }

    STDMETHOD(get_EntryType)(LONG * pEntryType)
    {
        if (NULL == pEntryType)
        {
            return E_POINTER;
        }

        *pEntryType = m_entryType;

        return S_OK;
    }

    STDMETHOD(get_User)(BSTR * pUser)
    {
        if (NULL == pUser)
        {
            return E_POINTER;
        }

        *pUser = m_user.Copy();

        return S_OK;
    }

private:
    DATE        m_timeStamp;
    CComVariant m_dataValue;
    DWORD       m_quality;
    DATE        m_entryTime;
    DWORD       m_entryType;
    CComBSTR    m_user;

}; // class COPCHDAEntry

#endif // OPCHDAEntry_h
