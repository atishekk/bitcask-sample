#include "operation.hpp"

static const std::unordered_map<std::string, Operation> repr = {
        {"GET",    Operation::GET},
        {"SET",    Operation::SET},
        {"REMOVE", Operation::REMOVE},
};

Operation OP::get_operation(const std::string &str_repr) {
    auto it = repr.find(str_repr);
    if (it == repr.end()) {
        throw std::runtime_error("Invalid string representation for Operation");
    }
    return it->second;
}

std::string OP::get_str(Operation op) {
    auto it = std::find_if(repr.begin(), repr.end(),
                           [&op](auto &&p) { return p.second == op; });
    if (it == repr.end()) {
        throw std::runtime_error(
                "The representation couldn't be deduced.(lib-error)");
    }
    return it->first;
}
