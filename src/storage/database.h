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
// Created by Pawel Burzynski on 15/02/2017.
//

#ifndef SRC_STORAGE_DATABASE_H_
#define SRC_STORAGE_DATABASE_H_

#include <string>

#include "src/storage/data-points-reader.h"

namespace shakadb {

class Database {
 public:
  virtual ~Database() {}
  virtual DataPointsReader *Read(data_series_id_t series_id, timestamp_t begin, timestamp_t end, int max_points) = 0;
  virtual void Write(data_series_id_t series_id, data_point_t *points, int count) = 0;
  virtual void Truncate(data_series_id_t series_id) = 0;
};

}  // namespace shakadb

#endif  // SRC_STORAGE_DATABASE_H_
