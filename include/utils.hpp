#ifndef BITCASK_UTILS
#define BITCASK_UTILS

#include "base.hpp"
#include "operation.hpp"
#include "entry.hpp"


std::tuple<Operation, Key, Value> deserialize_row(const std::string &line);

#endif //BITCASK_UTILS
