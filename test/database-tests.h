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
// Created by Pawel Burzynski on 19/01/2017.
//

#ifndef TEST_DATABASE_TESTS_H_
#define TEST_DATABASE_TESTS_H_

#include "test/framework.h"

void test_database_simple_initialization_test(test_context_t ctx);
void test_database_write_and_read_all(test_context_t ctx);
void test_database_write_database_in_one_big_batch(test_context_t ctx);
void test_database_write_database_in_multiple_small_batches(test_context_t ctx);
void test_database_multi_write_and_read_all(test_context_t ctx);
void test_database_write_history(test_context_t ctx);
void test_database_write_close_and_write_more(test_context_t ctx);
void test_database_continuous_write(test_context_t ctx);
void test_database_continuous_write_with_pickup(test_context_t ctx);
void test_database_write_close_read(test_context_t ctx);
void test_database_write_batch_size_equal_to_page_capacity(test_context_t ctx);
void test_database_write_batch_size_greater_than_page_capacity(test_context_t ctx);
void test_database_read_inside_single_chunk(test_context_t ctx);
void test_database_read_span_two_chunks(test_context_t ctx);
void test_database_read_span_three_chunks(test_context_t ctx);
void test_database_read_chunk_edges(test_context_t ctx);
void test_database_read_duplicated_values(test_context_t ctx);
void test_database_read_with_limit(test_context_t ctx);
void test_database_truncate(test_context_t ctx);
void test_database_truncate_multiple(test_context_t ctx);
void test_database_truncate_write_again(test_context_t ctx);
void test_database_failed_write(test_context_t ctx);
void test_database_read_latest_no_data(test_context_t ctx);
void test_database_read_latest(test_context_t ctx);

#endif  // TEST_DATABASE_TESTS_H_
