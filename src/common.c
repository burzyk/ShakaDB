/*
 * Copyright (c) 2016 Pawel Burzynski. All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
//
// Created by Pawel Burzynski on 14/04/2017.
//

#include "src/common.h"

#include <stdlib.h>

inline void *sdb_alloc(size_t size) {
  return calloc(1, size);
}

inline void sdb_free(void *buffer) {
  free(buffer);
}

inline uint64_t sdb_min(uint64_t a, uint64_t b) {
  return a < b ? a : b;
}

inline uint64_t sdb_max(uint64_t a, uint64_t b) {
  return a < b ? b : a;
}

void die_internal(const char *message, const char *file, int line_number) {
  fprintf(stderr, "PANIC: %s:%d -> %s\n", file, line_number, message);
  fflush(stderr);
  exit(-1);
}

void assert_internal(int status, const char *message, const char *file, int line_number) {
  if (!status) {
    char line[SDB_STR_MAX_LEN] = {0};
    sprintf(line, "ASSERT: %s:%d -> %s", file, line_number, message);
    die(line);
  }
}
