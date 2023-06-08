#pragma once
#ifndef MYUSART2USB_H
/// Include guard even though \#pragma once
#define MYUSART2USB_H
#include "MyStorage.h"
#include <stdint.h>

void usart2USB_Init(void);
void usart2_Deinitialise(void);

void transmit2toUSB(const uint16_t data);
void transmit1toUSB(const uint8_t data);

void transmitAllToUSB(const int16_t time_Diff);

#endif // MYUSART2USB_H
