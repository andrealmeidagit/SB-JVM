#include "conversions.h"

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
