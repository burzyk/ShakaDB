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
// Created by Pawel Burzynski on 11/02/2017.
//

#ifndef SHAKADB_STORAGE_ALLOCATOR_H
#define SHAKADB_STORAGE_ALLOCATOR_H

#include <string>
#include <map>
#include <cstdlib>
#include <src/fatal-exception.h>
#include "src/log.h"
#include "rw-lock-scope.h"
#include "rw-lock.h"

namespace shakadb {

class Allocator {
 public:
  template<typename T>
  static T *New(int count = 1, const char *context = nullptr) {
    auto scope = lock.LockWrite();

    T *data = (T *)calloc(count, sizeof(T));
    memory[data] = std::string(context != nullptr ? context : "");

    return data;
  }

  static void Delete(void *pointer) {
    auto scope = lock.LockWrite();

    if (memory.find(pointer) == memory.end()) {
      throw FatalException("Deleting unknown pointer");
    }

    memory.erase(pointer);
    free(pointer);
  }

  static void AssertAllDeleted() {
    auto scope = lock.LockWrite();

    if (memory.size() != 0) {
      throw FatalException("Not all memory allocations have been deleted");
    }
  }

 private:
  static RwLock lock;
  static std::map<void *, std::string> memory;
};

}

#endif //SHAKADB_STORAGE_ALLOCATOR_H
