#include "utils.hpp"

std::tuple<Operation, Key, Value> deserialize_row(const std::string &line) {
    std::stringstream lineStream(line);
    std::string cell;

    std::getline(lineStream, cell, ',');
    Operation op = OP::get_operation(cell);

    std::getline(lineStream, cell, ',');
    Key key = cell;

    Value value;
    if (op == Operation::SET) {
        std::getline(lineStream, cell, ',');
        value = cell;
    }

    return {op, key, value};
}