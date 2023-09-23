#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

class Tape {
public:
  Tape(const std::string &fileNameTape) { fileName = fileNameTape; }

  template <typename T> T readFull() {
    T elements;
    std::ifstream inputTapeNameFile(fileName);

    if (inputTapeNameFile.is_open()) {

      int number;
      while (inputTapeNameFile >> number) {
        elements.push_back(number);
      }
      inputTapeNameFile.close();
    } else {
      std::cerr << "File temp no open";
    }
    return elements;
  }

  int readFirst();

  template <typename T> void write(const T &vectorElements) {
    std::ofstream outputFile(fileName);
    std::copy(vectorElements.begin(), vectorElements.end(),
              std::ostream_iterator<int>(outputFile, " "));
    outputFile.close();
  }

  void writeNextElement(int element);
  void moveToLeft();
  void moveToRight();
  void deleteFirstElement();
  std::string fileName;
};