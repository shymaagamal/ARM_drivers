


#ifndef _ESP_INTERFACE_H
#define _ESP_INTERFACE_H

#include "StdTypes.h"

void ESP_Init(void);
u8 ESP_ValidateCmd(void);
void ESP_connectWifi(void);
void ESP_connectServer(void);
void ESP_ReciveHTTPRequest(u8 *Ptr_u8Data);

#endif
