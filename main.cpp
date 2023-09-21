#include "config.cpp"
#include "tapesort.h"
#include <fstream>
#include <iostream>
#include <list>
#include <string>
// Файл конфигурации хранит информацию
/* задержки по записи/чтению элемента с ленты, перемотки
ленты, и сдвига ленты на одну позицию.*/

int main(int argc, char const *argv[]) {
  /*if (argc != 3) {
     std::cout << " Недостаточно входных аргуметов!";
     return -1;
 }*/

  // TapeSort ts(argv[1], argv[2]);

  ConfigTest::readConfig();

  Tape *inTape = new Tape("/tmp/tempTape/inputTape.txt");

  std::ifstream inputTapeNameFile(inTape->fileName);
  if (inputTapeNameFile.is_open()) {
    std::cout << " файл открылся \n";
  } else {
    std::cout << " файл не открылся \n";
  }
  inputTapeNameFile.close();
  std::string outNameFileTape = "/tmp/tempTape/outTape.txt";
  TapeSort ts(outNameFileTape, inTape, 2);
  ts.readElemntForTempFile();
  ts.sortElement();
  return 0;
}