#pragma once

#include "tape.h"

class TapeSort {
public:
  TapeSort(const std::string &outFileName, Tape *tapeIn, int maxCountElemSave);
  ~TapeSort() { delete tapeInput_; }
  void readElemntForTempFile();
  void sortElement();
  const std::string fileNameTemp{"/tmp/tempTape/tempTape"};

private:
  Tape *tapeInput_; 
  Tape *tapeOutput_;

  std::string outFileName_;
  int maxCountElemSave_ = 2;
  int countTempFile_ = 0;
};