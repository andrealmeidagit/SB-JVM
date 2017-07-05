#include "conversions.h"

int64_t toInt64(uint64_t num) {
    int64_t result;
    memcpy(&result, &num, sizeof(int64_t));
    return result;
}

int32_t toInt32(uint32_t num) {
    int32_t result;
    memcpy(&result, &num, sizeof(int32_t));
    return result;
}

int16_t toInt16(uint16_t num) {
    int16_t result;
    memcpy(&result, &num, sizeof(int16_t));
    return result;
}

int8_t toInt8(uint8_t num) {
    int8_t result;
    memcpy(&result, &num, sizeof(int8_t));
    return result;
}

uint64_t fromInt64(int64_t num) {
    uint64_t result;
    memcpy(&result, &num, sizeof(uint64_t));
    return result;
}

uint32_t fromInt32(int32_t num) {
    uint32_t result;
    memcpy(&result, &num, sizeof(uint32_t));
    return result;
}

uint16_t fromInt16(int16_t num) {
    uint16_t result;
    memcpy(&result, &num, sizeof(uint16_t));
    return result;
}

uint8_t fromInt8(int8_t num) {
    uint8_t result;
    memcpy(&result, &num, sizeof(uint8_t));
    return result;
}

float toFloat(uint32_t num) {
    float result;
    memcpy(&result, &num, sizeof(float));
    return result;
}

double toDouble(uint64_t num) {
    double result;
    memcpy(&result, &num, sizeof(double));
    return result;
}

uint32_t fromFloat(float num) {
    uint32_t result;
    memcpy(&result, &num, sizeof(uint32_t));
    return result;
}

uint64_t fromDouble(double num) {
    uint64_t result;
    memcpy(&result, &num, sizeof(uint64_t));
    return result;
}

uint64_t* toPointerUI64(uint32_t address) {
    uint64_t* pointer;
    memcpy(&pointer, &address, sizeof(uint64_t*));
    return pointer;
}

uint32_t fromPointerUI64(uint64_t* pointer) {
    uint32_t address;
    memcpy(&address, &pointer, sizeof(uint32_t));
    return address;
}

uint32_t* toPointerUI32(uint32_t address) {
    uint32_t* pointer;
    memcpy(&pointer, &address, sizeof(uint32_t*));
    return pointer;
}

uint32_t fromPointerUI32(uint32_t* pointer) {
    uint32_t address;
    memcpy(&address, &pointer, sizeof(uint32_t));
    return address;
}

uint16_t* toPointerUI16(uint32_t address) {
    uint16_t* pointer;
    memcpy(&pointer, &address, sizeof(uint16_t*));
    return pointer;
}

uint32_t fromPointerUI16(uint16_t* pointer) {
    uint32_t address;
    memcpy(&address, &pointer, sizeof(uint32_t));
    return address;
}

uint8_t* toPointerUI8(uint32_t address) {
    uint8_t* pointer;
    memcpy(&pointer, &address, sizeof(uint8_t*));
    return pointer;
}

uint32_t fromPointerUI8(uint8_t* pointer) {
    uint32_t address;
    memcpy(&address, &pointer, sizeof(uint32_t));
    return address;
}
