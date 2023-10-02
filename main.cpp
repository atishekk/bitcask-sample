#include "engine.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    cerr << "Error: No log file provided for the database\n";
    exit(1);
  }

  Engine e{fs::path(argv[1])};

  cout << e.version();
}
