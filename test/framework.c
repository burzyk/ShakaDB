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
// Created by Pawel Burzynski on 15/04/2017.
//

#include "test/framework.h"

#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>

int sdb_directory_create(const char *directory_name) {
  int status = mkdir(directory_name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  return status && errno != EEXIST;
}

test_session_t *test_session_create(const char *root_directory) {
  test_session_t *session = (test_session_t *)sdb_alloc(sizeof(test_session_t));
  snprintf(session->directory, SDB_STR_MAX_LEN, "%s/%lu", root_directory, time(NULL));
  session->tests_failed = 0;
  session->tests_success = 0;

  if (sdb_directory_create(session->directory)) {
    die("Unable to create directory for tests");
  }

  return session;
}

void test_session_destroy(test_session_t *session) {
  sdb_free(session);
}

int test_session_run(test_session_t *session, const char *name, sdb_test_function_t test_function) {
  printf("Running: %s ...", name);

  char test_directory[SDB_STR_MAX_LEN] = {0};
  snprintf(test_directory, SDB_STR_MAX_LEN, "%s/%s", session->directory, name);

  if (sdb_directory_create(test_directory)) {
    die("Unable to create test directory");
  }

  for (uint32_t i = 12; i < 24; i += 4) {
    char working_directory[SDB_STR_MAX_LEN] = {0};
    snprintf(working_directory, SDB_STR_MAX_LEN, "%s/%s/%d", session->directory, name, i);

    if (sdb_directory_create(working_directory)) {
      die("Unable to create working directory");
    }

    test_context_t context = {};
    strncpy(context.working_directory, working_directory, SDB_STR_MAX_LEN);
    context.session = session;

    printf(" %d,", i);
    context.point_size = i;
    test_function(context);
  }

  printf(ANSI_COLOR_GREEN " [ OK ]\n" ANSI_COLOR_RESET);
  session->tests_success++;

  return 0;
}

void test_session_print_summary(test_session_t *session) {
  printf("Test run: %d, failed: %d\n", session->tests_success + session->tests_failed, session->tests_failed);
}