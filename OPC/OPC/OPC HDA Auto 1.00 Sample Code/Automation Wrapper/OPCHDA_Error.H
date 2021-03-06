/*++
Module Name:
 OpcHDAError.h
Author:
Ayana Craven, OSI Software, Inc.

Revision History:

--*/

/*
Code Assignments:
  0000 to 0200 are reserved for Microsoft use 
  (although some were inadverdantly used for OPC 1.0 errors). 
  0200 to 8000 are reserved for future OPC use. 
  8000 to FFFF can be vendor specific.

*/

#ifndef __OPCHDAERROR_H
#define __OPCHDAERROR_H

//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//

//
// MessageId: OPC_S_NODATA
//
// MessageText:
//
//  There is no data within the specified parameters
//

#define OPC_S_NODATA	 	            ((HRESULT)0x40041002L)


//
// MessageId: OPC_S_MOREDATA
//
// MessageText:
//
// There is more data satisfying the query than was returned
//

#define OPC_S_MOREDATA	             ((HRESULT)0x40041003L)


//
// MessageId: OPC_S_CURRENTVALUE
//
// MessageText:
//
//  The server only returns current values for the requested item attributes.
//

#define OPC_S_CURRENTVALUE		((HRESULT)0x40041005L)


//
// MessageId: OPC_S_EXTRADATA
//
// MessageText:
//
//  Additional data satisfying the query was found.
//

#define OPC_S_EXTRADATA		((HRESULT)0x40041006L)


//
// MessageId: OPC_S_INSERTED
//
// MessageText:
//
//  The requested insert occurred.
//

#define OPC_S_INSERTED			((HRESULT)0x4004100EL)


//
// MessageId: OPC_S_REPLACED
//
// MessageText:
//
//  The requested replace occurred.
//

#define OPC_S_REPLACED			((HRESULT)0x4004100FL)


//
// MessageId: OPC_W_NOFILTER
//
// MessageText:
//
//  The server does not support this filter.
//


#define OPC_W_NOFILTER			((HRESULT)0x80041007L)


//
// MessageId: OPC_E_MAXEXCEEDED
//
// MessageText:
//
//  The maximum number of values requested exceeds the server's limit.
//

#define OPC_E_MAXEXCEEDED           ((HRESULT)0xC0041001L)


//
// MessageId: OPC_E_NODATAEXISTS
//
// MessageText:
//
//  The server has no value for the specified time and item ID.
//

#define OPC_E_NODATAEXISTS           ((HRESULT)0xC0041007L)

//
// MessageId: OPC_E_UNKNOWNATTRID
//
// MessageText:
//
//  The server does not support this attribute.
//

#define OPC_E_UNKNOWNATTRID         ((HRESULT)0xC0041008L)


//
// MessageId: OPC_E_NOT_AVAIL
//
// MessageText:
//
//  The requested aggregate is not available for the specified item.
//

#define OPC_E_NOT_AVAIL		((HRESULT)0xC0041009L)


//
// MessageId: OPC_E_INVALIDDATATYPE
//
// MessageText:
//
//  The supplied value for the attribute is not a correct data type.
//

#define OPC_E_INVALIDDATATYPE       ((HRESULT)0xC004100AL)


//
// MessageId: OPC_E_DATAEXISTS
//
// MessageText:
//
//  Unable to insert - data already present.
//
#define OPC_E_DATAEXISTS		((HRESULT)0xC004100BL)


//
// MessageId: OPC_E_INVALIDATTRID
//
// MessageText:
//
//  The supplied attribute ID is not valid.
//
#define OPC_E_INVALIDATTRID        ((HRESULT)0xC004100CL)


//
// MessageId: OPC_E_INVALIDAGGREGATE
//
// MessageText:
//
//  The aggregate requested is not valid.
//

#define OPC_E_INVALIDAGGREGATE	((HRESULT)0xC0041004L)


#endif // OpcHDAError
