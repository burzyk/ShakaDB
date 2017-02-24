//
// Created by Pawel Burzynski on 15/02/2017.
//

#ifndef SHAKADB_DATA_POINTS_READER_H
#define SHAKADB_DATA_POINTS_READER_H

#include <src/data-point.h>

namespace shakadb {

class DataPointsReader {
 public:
  virtual ~DataPointsReader() {};

  virtual data_point_t *GetDataPoints() = 0;
  virtual int GetDataPointsCount() = 0;
};

}

#endif //SHAKADB_DATA_POINTS_READER_H
