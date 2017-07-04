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
