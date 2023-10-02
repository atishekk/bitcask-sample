#ifndef BITCASK_ENGINE
#define BITCASK_ENGINE
#include "base.hpp"

/**
 * Implementation of the log-structured databases' storage engine
 */
class Engine {
private:
  fs::path log_path;

public:
  Engine(fs::path log) {
    this->log_path = log;
    // open the log file
    if (!fs::exists(this->log_path)) {
      throw std::runtime_error("File: " + log_path.generic_string() +
                               " doesn't exist");
    }
  }

  ~Engine() {}

  /**
   * Get the current version of the storage engine
   */
  std::string version();
};

#endif