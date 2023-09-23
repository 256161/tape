#include "tape.h"
#include "tapesort.h"
#include <list>

int Tape::readFirst() {
  int element = -1;
  std::ifstream inputTapeNameFile(fileName);
  if (inputTapeNameFile.is_open()) {

    if (!inputTapeNameFile.eof()) {
      inputTapeNameFile >> element;
    }
    inputTapeNameFile.close();
    return element;
  } else {
    std::cerr << "File temp no open";
  }
  return element;
}

void Tape::deleteFirstElement() {

  std::list<int> fullElement = readFull<std::list<int>>();
  fullElement.erase(fullElement.begin());
  write<std::list<int>>(fullElement);
};

void Tape::writeNextElement(int element) {

  std::ofstream outputFile(fileName, std::ios::app);
  if (outputFile.is_open()) {
    outputFile << element;
    outputFile << " ";
    outputFile.close();
  } else {
    std::cout << " Файл для записи следующего элемента не открылся";
  }
}
