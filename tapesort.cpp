#include "tapesort.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <unordered_map>

TapeSort::TapeSort(const std::string &outFileName, Tape *tapeIn,
                   int maxCountElemSave) {
  outFileName_ = outFileName;
  tapeInput_ = tapeIn;
  maxCountElemSave_ = maxCountElemSave;
  tapeOutput_ = new Tape(outFileName);
};

void TapeSort::readElemntForTempFile() {
  std::ifstream inputTapeNameFile(tapeInput_->fileName);
  if (inputTapeNameFile.is_open()) {

    while (!inputTapeNameFile.eof()) {
      if (inputTapeNameFile.eof())
        break;
      ++countTempFile_;
      std::vector<int> tempVectorElements;
      tempVectorElements.reserve(maxCountElemSave_);
      for (int i = 0; i < maxCountElemSave_; ++i) {
        std::string str;
        inputTapeNameFile >> str;
        if (str != "" || str != "\n") {
          try {
            tempVectorElements.push_back(std::stoi(str));
          } catch (...) {
            std::cout << "Invalid input. Please try again!\n";
          }
        }
      }

      std::sort(tempVectorElements.begin(), tempVectorElements.end());

      std::string tempFileName =
          fileNameTemp + std::to_string(countTempFile_) + ".txt";

      Tape *tape = new Tape(tempFileName);
      tape->write(tempVectorElements);
    }
    inputTapeNameFile.close();
  } else {
    std::cerr << "\n File temp inputTape NameFile no open \n";
  }
};

void TapeSort::sortElement() {

  std::list<int> remainTempFiles;
  for (int i = 0; i < countTempFile_; ++i) {
    remainTempFiles.push_back(i + 1);
  }
  int minNumber = -1;
  int currentElement = -1;
  int numberTempFile = -1;
  bool isFirst = true;
  while (remainTempFiles.size()) {
    isFirst = true;
    currentElement = -1;
    numberTempFile = -1;
    std::list<int>::iterator iter = remainTempFiles.begin();
    while (iter != remainTempFiles.end()) {

      Tape *tape = new Tape(fileNameTemp + std::to_string(*iter) + ".txt");
      currentElement = tape->readFirst();

      if (currentElement == -1) {
        iter = remainTempFiles.erase(iter);
      } else {
        if (isFirst) {

          minNumber = currentElement;
          numberTempFile = *iter;
          isFirst = false;
        } else if (minNumber == -1 || minNumber >= currentElement) {
          minNumber = currentElement;
          numberTempFile = *iter;
        }
        iter++;
      }
    }
    if (numberTempFile != -1) {

      Tape *tapeSave =
          new Tape(fileNameTemp + std::to_string(numberTempFile) + ".txt");

      tapeSave->deleteFirstElement();

      tapeOutput_->writeNextElement(minNumber);

    } else {
      return;
    }
  }
}
