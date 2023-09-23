#include "config.cpp"
#include "tapesort.h"
#include <fstream>
#include <iostream>
#include <list>
#include <string>

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cout << " Недостаточно входных аргуметов!";
    return -1;
  }

  ConfigTest::readConfig();

  Tape *inTape = new Tape(argv[1]);

  std::ifstream inputTapeNameFile(inTape->fileName);
  if (inputTapeNameFile.is_open()) {
    std::cout << " файл открылся \n";
  } else {
    std::cout << " файл не открылся \n";
  }
  inputTapeNameFile.close();
  std::string outNameFileTape = argv[2];
  TapeSort ts(outNameFileTape, inTape, 2);
  ts.readElemntForTempFile();
  ts.sortElement();
  return 0;
}