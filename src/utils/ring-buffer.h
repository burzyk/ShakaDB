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

#ifndef SHAKADB_STORAGE_RINGBUFFER_H
#define SHAKADB_STORAGE_RINGBUFFER_H

#include <cstdint>
#include "stream.h"

namespace shakadb {

class RingBuffer : public Stream {
 public:
  RingBuffer(int grow_increment);
  ~RingBuffer();

  int Read(byte_t *buffer, int buffer_size);
  int Peek(byte_t *buffer, int buffer_size);
  int Write(byte_t *buffer, int buffer_size);
  int GetSize();
 private:
  void EnsureBufferSize(int new_size);

  byte_t *data;
  int size;
  int capacity;
  int begin;
  int grow_increment;
};

}

#endif //SHAKADB_STORAGE_RINGBUFFER_H
