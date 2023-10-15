#ifndef BITCASK_OP
#define BITCASK_OP

#include "base.hpp"

enum class Operation {
    GET, SET, REMOVE
};

namespace OP {
    Operation get_operation(const std::string &str_repr);

// O(n) BUT WON'T MATTER as number of operations are small
    std::string get_str(Operation op);
} // namespace OP
#endif