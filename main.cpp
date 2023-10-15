#include "engine.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        cerr << "Error: No log file provided for the database\n";
        exit(1);
    }

    Engine e{fs::path(argv[1])};
    e.set(entry("Hello", "world"));
    e.set(entry("Hello1", "world1"));
    cout << e.get("Hello2").value_or("lol");
}
