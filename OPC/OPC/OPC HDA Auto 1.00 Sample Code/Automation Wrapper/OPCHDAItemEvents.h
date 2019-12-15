#ifndef OPCHDAItemEvents_h
#define OPCHDAItemEvents_h

template <class T>
class CProxy_IOPCHDAItemEvents : 
    public IConnectionPointImpl<T, &DIID__IOPCHDAItemEvents, CComDynamicUnkArray>
{
public:
	HRESULT Fire_DataChange(
        LONG TransactionID,
        LONG Status,
        LONG NumItems,
        SAFEARRAY * pClientHandles,
        SAFEARRAY * pAggregates,
        SAFEARRAY * pItemValues,
        SAFEARRAY * pErrors)
	{
        VARIANTARG* pvars = new VARIANTARG[7];
        for (int i = 0; i < 7; i++)
            VariantInit(&pvars[i]);
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[6].vt = VT_I4;
				pvars[6].lVal = TransactionID;
				pvars[5].vt = VT_I4;
				pvars[5].lVal = Status;
				pvars[4].vt = VT_I4;
				pvars[4].lVal = NumItems;
				pvars[3].vt = VT_ARRAY | VT_I4;
				pvars[3].parray = pClientHandles;
				pvars[2].vt = VT_ARRAY | VT_I4;
				pvars[2].parray = pAggregates;
				pvars[1].vt = VT_ARRAY | VT_VARIANT;
				pvars[1].parray = pItemValues;
				pvars[0].vt = VT_ARRAY | VT_I4;
				pvars[0].parray = pErrors;
				DISPPARAMS disp = { pvars, NULL, 7, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	}

	HRESULT Fire_AsyncReadComplete(
        LONG TransactionID,
        LONG Status,
        LONG NumItems,
        SAFEARRAY * pClientHandles,
        SAFEARRAY * pAggregates,
        SAFEARRAY * pItemValues,
        SAFEARRAY * pErrors)
	{
        VARIANTARG* pvars = new VARIANTARG[7];
        for (int i = 0; i < 7; i++)
            VariantInit(&pvars[i]);
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[6].vt = VT_I4;
				pvars[6].lVal = TransactionID;
				pvars[5].vt = VT_I4;
				pvars[5].lVal = Status;
				pvars[4].vt = VT_I4;
				pvars[4].lVal = NumItems;
				pvars[3].vt = VT_ARRAY | VT_I4;
				pvars[3].parray = pClientHandles;
				pvars[2].vt = VT_ARRAY | VT_I4;
				pvars[2].parray = pAggregates;
				pvars[1].vt = VT_ARRAY | VT_VARIANT;
				pvars[1].parray = pItemValues;
				pvars[0].vt = VT_ARRAY | VT_I4;
				pvars[0].parray = pErrors;
				DISPPARAMS disp = { pvars, NULL, 7, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	}

	HRESULT Fire_AsyncReadModifiedComplete(
        LONG TransactionID,
        LONG Status,
        LONG NumItems,
        SAFEARRAY * pClientHandles,
        SAFEARRAY * pItemValues,
        SAFEARRAY * pErrors)
	{
        VARIANTARG* pvars = new VARIANTARG[6];
        for (int i = 0; i < 6; i++)
            VariantInit(&pvars[i]);
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[5].vt = VT_I4;
				pvars[5].lVal = TransactionID;
				pvars[4].vt = VT_I4;
				pvars[4].lVal = Status;
				pvars[3].vt = VT_I4;
				pvars[3].lVal = NumItems;
				pvars[2].vt = VT_ARRAY | VT_I4;
				pvars[2].parray = pClientHandles;
				pvars[1].vt = VT_ARRAY | VT_VARIANT;
				pvars[1].parray = pItemValues;
				pvars[0].vt = VT_ARRAY | VT_I4;
				pvars[0].parray = pErrors;
				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				pDispatch->Invoke(0x3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	}

	HRESULT Fire_AsyncReadAttributesComplete(
        LONG TransactionID,
        LONG Status,
        LONG ClientHandle,
        LONG NumAttributes,
        SAFEARRAY * pAttributesIDs,
        SAFEARRAY * pAttributeValues,
        SAFEARRAY * pErrors)
	{
        VARIANTARG* pvars = new VARIANTARG[7];
        for (int i = 0; i < 7; i++)
            VariantInit(&pvars[i]);
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[6].vt = VT_I4;
				pvars[6].lVal = TransactionID;
				pvars[5].vt = VT_I4;
				pvars[5].lVal = Status;
				pvars[4].vt = VT_I4;
				pvars[4].lVal = ClientHandle;
				pvars[3].vt = VT_I4;
				pvars[3].lVal = NumAttributes;
				pvars[2].vt = VT_ARRAY | VT_I4;
				pvars[2].parray = pAttributesIDs;
				pvars[1].vt = VT_ARRAY | VT_VARIANT;
				pvars[1].parray = pAttributeValues;
				pvars[0].vt = VT_ARRAY | VT_I4;
				pvars[0].parray = pErrors;
				DISPPARAMS disp = { pvars, NULL, 7, 0 };
				pDispatch->Invoke(0x4, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	}

	HRESULT Fire_AsyncReadAnnotationsComplete(
        LONG TransactionID,
        LONG Status,
        LONG NumItems,
        SAFEARRAY * pClientHandles,
        SAFEARRAY * pAnnotationValues,
        SAFEARRAY * pErrors)
	{
        VARIANTARG* pvars = new VARIANTARG[6];
        for (int i = 0; i < 6; i++)
            VariantInit(&pvars[i]);
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[5].vt = VT_I4;
				pvars[5].lVal = TransactionID;
				pvars[4].vt = VT_I4;
				pvars[4].lVal = Status;
				pvars[3].vt = VT_I4;
				pvars[3].lVal = NumItems;
				pvars[2].vt = VT_ARRAY | VT_I4;
				pvars[2].parray = pClientHandles;
				pvars[1].vt = VT_ARRAY | VT_VARIANT;
				pvars[1].parray = pAnnotationValues;
				pvars[0].vt = VT_ARRAY | VT_I4;
				pvars[0].parray = pErrors;
				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				pDispatch->Invoke(0x5, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	}

	HRESULT Fire_AsyncInsertAnnotationsComplete(
        LONG TransactionID,
        LONG Status,
        LONG NumItems,
        SAFEARRAY * pClientHandles,
        SAFEARRAY * pErrors)
	{
        VARIANTARG* pvars = new VARIANTARG[5];
        for (int i = 0; i < 5; i++)
            VariantInit(&pvars[i]);
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[4].vt = VT_I4;
				pvars[4].lVal = TransactionID;
				pvars[3].vt = VT_I4;
				pvars[3].lVal = Status;
				pvars[2].vt = VT_I4;
				pvars[2].lVal = NumItems;
				pvars[1].vt = VT_ARRAY | VT_I4;
				pvars[1].parray = pClientHandles;
				pvars[0].vt = VT_ARRAY | VT_I4;
				pvars[0].parray = pErrors;
				DISPPARAMS disp = { pvars, NULL, 5, 0 };
				pDispatch->Invoke(0x6, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	}

	HRESULT Fire_Playback(
        LONG TransactionID,
        LONG Status,
        LONG NumItems,
        SAFEARRAY * pClientHandles,
        SAFEARRAY * pAggregates,
        SAFEARRAY * pItemValues,
        SAFEARRAY * pErrors)
	{
        VARIANTARG* pvars = new VARIANTARG[7];
        for (int i = 0; i < 7; i++)
            VariantInit(&pvars[i]);
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[6].vt = VT_I4;
				pvars[6].lVal = TransactionID;
				pvars[5].vt = VT_I4;
				pvars[5].lVal = Status;
				pvars[4].vt = VT_I4;
				pvars[4].lVal = NumItems;
				pvars[3].vt = VT_ARRAY | VT_I4;
				pvars[3].parray = pClientHandles;
				pvars[2].vt = VT_ARRAY | VT_I4;
				pvars[2].parray = pAggregates;
				pvars[1].vt = VT_ARRAY | VT_VARIANT;
				pvars[1].parray = pItemValues;
				pvars[0].vt = VT_ARRAY | VT_I4;
				pvars[0].parray = pErrors;
				DISPPARAMS disp = { pvars, NULL, 7, 0 };
				pDispatch->Invoke(0x7, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	}

	HRESULT Fire_AsyncUpdateComplete(
        LONG TransactionID,
        LONG Status,
        LONG NumItems,
        SAFEARRAY * pClientHandles,
        SAFEARRAY * pErrors)
	{
        VARIANTARG* pvars = new VARIANTARG[5];
        for (int i = 0; i < 5; i++)
            VariantInit(&pvars[i]);
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[4].vt = VT_I4;
				pvars[4].lVal = TransactionID;
				pvars[3].vt = VT_I4;
				pvars[3].lVal = Status;
				pvars[2].vt = VT_I4;
				pvars[2].lVal = NumItems;
				pvars[1].vt = VT_ARRAY | VT_I4;
				pvars[1].parray = pClientHandles;
				pvars[0].vt = VT_ARRAY | VT_I4;
				pvars[0].parray = pErrors;
				DISPPARAMS disp = { pvars, NULL, 5, 0 };
				pDispatch->Invoke(0x8, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	}

	HRESULT Fire_AsyncCancelComplete(
        LONG TransactionID)
	{
        VARIANTARG* pvars = new VARIANTARG[1];
        for (int i = 0; i < 1; i++)
            VariantInit(&pvars[i]);
		CComVariant varResult;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				VariantClear(&varResult);
				pvars[0].vt = VT_I4;
				pvars[0].lVal = TransactionID;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x9, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, &varResult, NULL, NULL);
			}
		}
		delete[] pvars;
		return varResult.scode;
	}

}; // class CProxy_IOPCHDAItemEvents

#endif
