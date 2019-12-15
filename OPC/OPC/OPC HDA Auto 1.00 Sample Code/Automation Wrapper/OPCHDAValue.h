/*  ____________________________________________________________________________

    OPCHDAValue.h

    COPCHDAValue class definition.
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
#ifndef OPCHDAValue_h
#define OPCHDAValue_h

class ATL_NO_VTABLE COPCHDAValue : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IDispatchImpl<OPCHDAValue, &IID_OPCHDAValue, &LIBID_OPCHDAAutomation>
{
public:
BEGIN_COM_MAP(COPCHDAValue)
	COM_INTERFACE_ENTRY(OPCHDAValue)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(COPCHDAValue)

	COPCHDAValue()
    {
        m_timeStamp = 0.0;
        m_quality = 0;
    }

    STDMETHOD(Initialize)(
        DATE TimeStamp,
        const CComVariant& DataValue,
        DWORD Quality)
    {
        m_timeStamp = TimeStamp;
        m_dataValue = DataValue;
        m_quality = Quality;

        return S_OK;
    }

// OPCHDAValue
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

private:
    DATE        m_timeStamp;
    CComVariant m_dataValue;
    DWORD       m_quality;

}; // class COPCHDAValue

#endif // OPCHDAValue_h
