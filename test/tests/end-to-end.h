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
// Created by Pawel Burzynski on 21/02/2017.
//

#ifndef TEST_TESTS_END_TO_END_H_
#define TEST_TESTS_END_TO_END_H_

#include <string>

#include "src/utils/stopwatch.h"
#include "src/bootstrapper.h"
#include "src/client/client.h"
#include "test/framework/test-context.h"

namespace shakadb {
namespace test {

class EndToEnd {
 public:
  void empty_read(TestContext ctx);
  void write_small(TestContext ctx);
  void write_multiple(TestContext ctx);
  void write_stop_read(TestContext ctx);

 private:
  Bootstrapper *BootstrapInit(TestContext ctx);
  void ValidateRead(data_series_id_t series_id, int expected_points_count);
  void WriteSequencialPoints(data_series_id_t series_id, int batch_size, int count);
  void WritePoints(data_series_id_t series_id, data_point_t *points, int points_count);
};

}  // namespace test
}  // namespace shakadb

#endif  // TEST_TESTS_END_TO_END_H_
