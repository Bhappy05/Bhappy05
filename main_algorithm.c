#include <open62541.h>

void write_detector_value(UA_UInt16 value) {
	
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
				for(int i = 0; i < 16; ++i){
					ref%2 == 1 ? : 0 ;
					ref >>= 1;
				}
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
				for(int i = 0; i < 16; ++i){
					ref%2 == 1 ? : 0 ;
					ref >>= 1;
				}
				/*EVENT*/
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
				for(int i = 0; i < 16; ++i){
					ref%2 == 1 ? : 0 ;
					ref >>= 1;
				}
				/*EVENT*/
			}
		}
			break;
		case 3:{
			ref = 0x2800;
			ref ^= value;
			if(ref == 0){
				cycle = 0;
				/*EVENT_OK*/
			}else{
				cycle = 0;
				for(int i = 0; i < 16; ++i){
					ref%2 == 1 ? : 0 ;
					ref >>= 1;
				}
				/*EVENT*/
			}
		}
			break;
	}
}

