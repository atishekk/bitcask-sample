#ifndef BITCASK_ENGINE
#define BITCASK_ENGINE

#include <utility>

#include "base.hpp"
#include "entry.hpp"
#include "index.hpp"

/**
 * Implementation of the log-structured databases' storage engine
 */
class Engine {
private:
    fs::path log_path;
    std::fstream log_stream;
    std::size_t num_bytes;
    Index index;

public:
    explicit Engine(const fs::path &log) : log_path(log), index(Index(log)) {
        // create the necessary directory structure
        if (log.has_parent_path() && !fs::exists(log_path.parent_path())) {
            std::cout << "Creating the directory structure for the log file: "
                      << log_path << std::endl;
            fs::create_directories(log_path.parent_path());
        }
        // open the read and write streams for the log file
        log_stream = std::fstream(log_path, std::ios::app | std::ios::in);
        log_stream.seekg(0, std::ios::end);
        num_bytes = log_stream.tellg();
    }

    ~Engine() {
        log_stream.close();
    }

    // TODO: Move to an entry class with binary data
    void set(const entry &_entry);

    std::optional<Value> get(const Key &key);

    std::optional<Value> remove(const Key &Key);

    /**
     * Get the current version of the storage engine
     */
    static std::string version() { return "0.0.1"; }
};

#endif
