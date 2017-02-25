//
// Created by Pawel Burzynski on 19/02/2017.
//

#ifndef SHAKADB_READREQUEST_H
#define SHAKADB_READREQUEST_H

#include <string>
#include <src/data-point.h>
#include "data-packet.h"

namespace shakadb {

class ReadRequest : public DataPacket {
 public:
  friend DataPacket *DataPacket::Load(Stream *stream);
  ReadRequest(std::string series_name, timestamp_t begin, timestamp_t end);

  PacketType GetType();
  std::string GetSeriesName();
  timestamp_t GetBegin();
  timestamp_t GetEnd();
 private:
  ReadRequest(Buffer *packet);
  int GetSeriesNameSize();
};

}

#endif //SHAKADB_READREQUEST_H
