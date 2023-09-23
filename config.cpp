#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class ConfigTest {
public:
  static void readConfig() {
    std::ifstream f("config.json");
    json data = json::parse(f);

    std::cout << " " << data["RecordingTime"] << std::endl;
    std::cout << " " << data["ReadingTime"] << std::endl;
    std::cout << " " << data["RewindTime"] << std::endl;
    std::cout << " " << data["MoveTime"] << std::endl;
  }
};