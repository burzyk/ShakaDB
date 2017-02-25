//
// Created by Pawel Burzynski on 18/01/2017.
//

#ifndef SHAKADB_STORAGE_COMMON_H
#define SHAKADB_STORAGE_COMMON_H

#include <cstdint>

namespace shakadb {

#define SHAKADB_SERIES_NAME_MAX_LENGTH 255

typedef uint8_t byte_t;

uint64_t max(uint64_t a, uint64_t b);
uint64_t min(uint64_t a, uint64_t b);
int min(int a, int b);

}

#endif //SHAKADB_STORAGE_COMMON_H
