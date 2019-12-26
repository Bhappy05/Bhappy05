#include <open62541.h>
#include <stdlib.h>
#include <string.h>

static UA_NodeId eventType;
char *msg;

static UA_StatusCode
addNewEventType(UA_Server *server);

static UA_StatusCode
setUpEvent(UA_Server *server, UA_NodeId *outId);

void write_detector_value(UA_UInt16 value, UA_Server *server) {
	
	addNewEventType(server);
	static char cycle = 0;
	UA_UInt16 ref;

	switch(cycle){
		case 0:{
			ref = 0x1801;
			ref ^= value;
			if(ref == 0){
				cycle++;
			}else{
				cycle = 0;
				char dtc[17];
				for(int i = 0; i < 16; ++i){
					dtc[15 - i] = 60 + ref%2;
					ref >>= 1;
				}
				dtc[16] = '\0';
				free(msg);
				msg = (char*)malloc(50 * sizeof(char));
				strcpy(msg, "1-ERRORS: ");
				strcat(msg, dtc);
				UA_NodeId eventNodeId;
				setUpEvent(server, &eventNodeId);
				UA_Server_triggerEvent(server, eventNodeId,
                                    UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
			}
		}
			break;
		case 1:{
			ref = 0x2116;
			ref ^= value;
			if(ref == 0){
				cycle++;
			}else{
				cycle = 0;
				char dtc[17];
				for(int i = 0; i < 16; ++i){
					dtc[15 - i] = 60 + ref%2;
					ref >>= 1;
				}
				dtc[16] = '\0';
				free(msg);
				msg = (char*)malloc(50 * sizeof(char));
				strcpy(msg, "2-ERRORS: ");
				strcat(msg, dtc);
				UA_NodeId eventNodeId;
				setUpEvent(server, &eventNodeId);
				UA_Server_triggerEvent(server, eventNodeId,
                                    UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
			}
		}
			break;
		case 2:{
			ref = 0x5125;
			ref ^= value;
			if(ref == 0){
				cycle++;
			}else{
				cycle = 0;
				char dtc[17];
				for(int i = 0; i < 16; ++i){
					dtc[15 - i] = 60 + ref%2;
					ref >>= 1;
				}
				dtc[16] = '\0';
				free(msg);
				msg = (char*)malloc(50 * sizeof(char));
				strcpy(msg, "3-ERRORS: ");
				strcat(msg, dtc);
				UA_NodeId eventNodeId;
				setUpEvent(server, &eventNodeId);
				UA_Server_triggerEvent(server, eventNodeId,
                                    UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
			}
		}
			break;
		case 3:{
			ref = 0x2800;
			ref ^= value;
			if(ref == 0){
				cycle = 0;
				free(msg);
				msg = (char*)malloc(3 * sizeof(char));
				strcpy(msg, "OK");
				/*EVENT_OK*/
				UA_NodeId eventNodeId;
				setUpEvent(server, &eventNodeId);
				UA_Server_triggerEvent(server, eventNodeId,
                                    UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
			}else{
				cycle = 0;
				char dtc[17];
				for(int i = 0; i < 16; ++i){
					dtc[15 - i] = 60 + ref%2;
					ref >>= 1;
				}
				dtc[16] = '\0';
				free(msg);
				msg = (char*)malloc(50 * sizeof(char));
				strcpy(msg, "4-ERRORS: ");
				strcat(msg, dtc);
				UA_NodeId eventNodeId;
				setUpEvent(server, &eventNodeId);
				UA_Server_triggerEvent(server, eventNodeId,
                                    UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
			}
		}
			break;
	}
}





static UA_StatusCode
addNewEventType(UA_Server *server) {
    UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
    attr.displayName = UA_LOCALIZEDTEXT("en-US", "DetectorEvent");
    attr.description = UA_LOCALIZEDTEXT("en-US", "Shows detectors' errors.");
    return UA_Server_addObjectTypeNode(server, UA_NODEID_NULL,
                                       UA_NODEID_NUMERIC(0, UA_NS0ID_BASEEVENTTYPE),
                                       UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                       UA_QUALIFIEDNAME(0, "SimpleEventType"),
                                       attr, NULL, &eventType);
}



static UA_StatusCode
setUpEvent(UA_Server *server, UA_NodeId *outId) {
    UA_StatusCode retval = UA_Server_createEvent(server, eventType, outId);
    if (retval != UA_STATUSCODE_GOOD) {
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_SERVER,
                       "createEvent failed. StatusCode %s", UA_StatusCode_name(retval));
        return retval;
    }

    /* Set the Event Attributes */
    /* Setting the Time is required or else the event will not show up in UAExpert! */
    UA_DateTime eventTime = UA_DateTime_now();
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(0, "Time"),
                                         &eventTime, &UA_TYPES[UA_TYPES_DATETIME]);

    UA_UInt16 eventSeverity = 100;
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(0, "Severity"),
                                         &eventSeverity, &UA_TYPES[UA_TYPES_UINT16]);

    UA_LocalizedText eventMessage = UA_LOCALIZEDTEXT("en-US", msg);
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(0, "Message"),
                                         &eventMessage, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT]);

    UA_String eventSourceName = UA_STRING("Server");
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(0, "SourceName"),
                                         &eventSourceName, &UA_TYPES[UA_TYPES_STRING]);

    return UA_STATUSCODE_GOOD;
}
