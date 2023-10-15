#ifndef BITCASK_ENTRY
#define BITCASK_ENTRY

#include "base.hpp"

typedef std::string Key;
typedef std::string Value;

class entry {
public:
    Key key;
    Value value;

    entry(const Key &key, const Value &value) {
        this->key = key;
        this->value = value;
    }
};

#endif