#include <open62541.h>
#include <stdlib.h>
#include <string.h>

static UA_NodeId eventType;
char *out;

static UA_StatusCode
addNewEventType(UA_Server *server);

static UA_StatusCode
setUpEvent(UA_Server *server, UA_NodeId *outId);

void write_detector_value(UA_UInt16 value, UA_Server *server) {
	
	addNewEventType(server);
	static char tetrad = 0;
	UA_UInt16 norm;

	switch(tetrad){
		case 0:{
			norm = 0x1802;
			norm ^= value;
			if(norm == 0)
                        {
				tetrad++;
			}
                        else
                        {
				tetrad = 0;
				char err[17];
				for(int i = 0; i < 16; ++i)
                                {
                                        if (norm % 2 == 0) {err[15 - i] = 48;}
                                        else {err[15 - i] = 49;}
					norm >>= 1;
				}
				err[16] = '\0';
				free(out);
				out = (char*)malloc(30 * sizeof(char));
				strcpy(out, "1 Tetrad: ");
				strcat(out, err);
				UA_NodeId eventNodeId;
				setUpEvent(server, &eventNodeId);
				UA_Server_triggerEvent(server, eventNodeId,
                                    UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
			}
		}
			break;
		case 1:{
			norm = 0x7113;
			norm ^= value;
			if(norm == 0)
                        {
				tetrad++;
			}
                        else
                        {
				tetrad = 0;
				char err[17];
				for(int i = 0; i < 16; ++i)
                                {
					if (norm % 2 == 0) {err[15 - i] = 48;}
                                        else {err[15 - i] = 49;}
                                        norm>>=1;
				}
				err[16] = '\0';
				free(out);
				out = (char*)malloc(30 * sizeof(char));
				strcpy(out, "2 Tetrad: ");
				strcat(out, err);
				UA_NodeId eventNodeId;
				setUpEvent(server, &eventNodeId);
				UA_Server_triggerEvent(server, eventNodeId,
                                    UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
			}
		}
			break;
		case 2:{
			norm = 0x5440;
			norm ^= value;
			if(norm == 0)
                        {
				tetrad++;
			}
                        else
                        {
				tetrad = 0;
				char err[17];
				for(int i = 0; i < 16; ++i)
                                {
					if (norm % 2 == 0) {err[15 - i] = 48;}
                                        else {err[15 - i] = 49;}
					norm >>= 1;
				}
				err[16] = '\0';
				free(out);
				out = (char*)malloc(30 * sizeof(char));
				strcpy(out, "3 Tetrad: ");
				strcat(out, err);
				UA_NodeId eventNodeId;
				setUpEvent(server, &eventNodeId);
				UA_Server_triggerEvent(server, eventNodeId,
                                    UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
			}
		}
			break;
		case 3:{
			norm = 0x0000;
			norm ^= value;
			if(norm == 0)
                        {
				tetrad = 0;
				free(out);
				out = (char*)malloc(8 * sizeof(char));
				strcpy(out, "Success");
				UA_NodeId eventNodeId;
				setUpEvent(server, &eventNodeId);
				UA_Server_triggerEvent(server, eventNodeId,
                                    UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
			}
                        else
                        {
				tetrad = 0;
				char err[17];
				for(int i = 0; i < 16; ++i)
                                {
					if (norm % 2 == 0) {err[15 - i] = 48;}
                                        else {err[15 - i] = 49;}
					norm >>= 1;
				}
				err[16] = '\0';
				free(out);
				out = (char*)malloc(30 * sizeof(char));
				strcpy(out, "4 Tetrad: ");
				strcat(out, err);
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

    UA_LocalizedText eventMessage = UA_LOCALIZEDTEXT("en-US", out);
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(0, "Message"),
                                         &eventMessage, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT]);

    UA_String eventSourceName = UA_STRING("Server");
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(0, "SourceName"),
                                         &eventSourceName, &UA_TYPES[UA_TYPES_STRING]);

    return UA_STATUSCODE_GOOD;
}
