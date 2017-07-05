#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

#include <string.h>
#include <stdint.h>

int64_t toInt64(uint64_t num);
int32_t toInt32(uint32_t num);
int16_t toInt16(uint16_t num);
int8_t toInt8(uint8_t num);

uint64_t fromInt64(int64_t num);
uint32_t fromInt32(int32_t num);
uint16_t fromInt16(int16_t num);
uint8_t fromInt8(int8_t num);

float toFloat(uint32_t num);
double toDouble(uint64_t num);

uint32_t fromFloat(float num);
uint64_t fromDouble(double num);

uint32_t* toPointer(uint32_t address);
uint32_t fromPointer(uint32_t* pointer);

#endif /* CONVERSIONS_H_ */
