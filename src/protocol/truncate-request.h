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
// Created by Pawel Burzynski on 08/03/2017.
//

#ifndef SRC_PROTOCOL_TRUNCATE_REQUEST_H_
#define SRC_PROTOCOL_TRUNCATE_REQUEST_H_

#include <string>
#include <vector>

#include "src/data-point.h"
#include "src/protocol/data-packet.h"

namespace shakadb {

class TruncateRequest : public DataPacket {
 public:
  TruncateRequest();
  explicit TruncateRequest(std::string series_name);

  PacketType GetType();
  std::string GetSeriesName();

 protected:
  bool Deserialize(Buffer *payload);
  std::vector<Buffer *> Serialize();

 private:
  struct truncate_request_t {
    char series_name[SHAKADB_SERIES_NAME_MAX_LENGTH + 1];
  };

  std::string series_name;
};

}  // namespace shakadb

#endif  // SRC_PROTOCOL_TRUNCATE_REQUEST_H_
