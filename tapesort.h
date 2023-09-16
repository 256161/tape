#pragma once

#include "tape.h"

class TapeSort 
{
public: 
    TapeSort(const std::string &outFileName, Tape *tapeIn, int maxCountElemSave);
    ~TapeSort(){delete tape_;}
    void readElemntForTempFile();
    void sortElement();
    const std::string fileNameTemp{"/tmp/tempTape/tempTape"};

private:
    Tape *tape_; 
    std::string outFileName_; 
    int maxCountElemSave_ = 2;
    int countTempFile_ = 0;
};