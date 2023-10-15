#ifndef BITCASK_INDEX
#define BITCASK_INDEX

#include <utility>

#include "base.hpp"
#include "utils.hpp"

/**
 * Index implementation for the storage engine
 */
class Index {
private:

    std::unordered_map<Key, std::size_t> _index;


    void build(const fs::path &log_path) {
        if (!fs::exists(log_path) || fs::is_empty(log_path)) return;

        std::ifstream log(log_path, std::ios::in);
        std::size_t num_bytes = 0;
        std::string line;

        // Build out the index from the file
        while (!log.eof()) {
            line.clear();
            std::getline(log, line);
            if (line.empty()) break;
            auto [op, key, value] = deserialize_row(line);
            update_index(op, key, num_bytes);
            num_bytes += line.size() + 1;
        }
    }

public:
    void update_index(Operation operation, const Key &key, std::size_t n) {
        switch (operation) {
            case Operation::GET:
                break;
            case Operation::SET:
                _index[key] = n;
                break;
            case Operation::REMOVE:
                _index.erase(key);
                break;
        }
    }

    explicit Index(const fs::path &log) {
        build(log);
    }

    ~Index() { _index.clear(); }

    std::optional<std::size_t> find(const Key &key) {
        auto it = _index.find(key);
        if (it == _index.end()) return std::nullopt;
        return it->second;
    }
};

#endif