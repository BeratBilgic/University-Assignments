#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function to calculate simple checksum
uint8_t calculateChecksum(const char *data) {
    size_t size = strlen(data);
    uint8_t checksum = 0;
    for (size_t i = 0; i < size; ++i) {
        checksum += (uint8_t)data[i];
    }
    return checksum;
}

// Function to calculate CRC using polynomial 0x8C (binary: 10001100)
uint8_t calculateCRC(const char *data) {
    size_t size = strlen(data);
    uint8_t crc = 0;
    const uint8_t polynomial = 0x8C;

    for (size_t i = 0; i < size; ++i) {
        crc ^= (uint8_t)data[i];
        for (int j = 0; j < 8; ++j) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ polynomial;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}
