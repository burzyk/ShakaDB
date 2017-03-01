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

#ifndef SRC_UTILS_ALLOCATOR_H_
#define SRC_UTILS_ALLOCATOR_H_

#include <cstdlib>

#include "src/fatal-exception.h"
#include "src/log.h"
#include "src/utils/rw-lock-scope.h"
#include "src/utils/rw-lock.h"

namespace shakadb {

class Allocator {
 public:
  template<typename T>
  static T *New(int count = 1) {
    return static_cast<T *>(calloc(count, sizeof(T)));
  }

  static void Delete(void *pointer);
};

}  // namespace shakadb

#endif  // SRC_UTILS_ALLOCATOR_H_
