#include "engine.hpp"

void Engine::set(const entry &_entry) {
    Operation curr_op = Operation::SET;
    std::string out = std::format("{},{},{}", OP::get_str(curr_op), _entry.key, _entry.value);

    log_stream.seekg(0, std::ios::end);
    log_stream << out << std::endl;

    index.update_index(curr_op, _entry.key, num_bytes);
    num_bytes += out.size() + 1;
}

std::optional<Value> Engine::get(const Key &key) {
    Operation curr_op = Operation::GET;
    std::string out = std::format("{},{}", OP::get_str(curr_op), key);

    log_stream.seekg(0, std::ios::end);
    log_stream << out << std::endl;
    num_bytes += out.size() + 1;

    auto pos = index.find(key);
    if (pos.has_value()) {
        // get the position from the index and seek it
        std::size_t loc = pos.value();
        log_stream.seekg(loc, std::ios::beg);
        // read the line
        std::string line;
        std::getline(log_stream, line);
        auto [op, _key, _value] = deserialize_row(line);
        if (_key != key) throw std::runtime_error("Internal error: keys don't match");
        return _value;
    }
    return std::nullopt;
}

std::optional<Value> Engine::remove(const Key &Key) {
    return std::nullopt;
}
