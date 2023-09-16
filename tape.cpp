#include "tape.h"
#include <iostream>
#include <fstream>
#include <iterator>

void Tape::write(const std::vector<int> &vectorElements) {
    std::ofstream outputFile(fileName);
    std::copy(vectorElements.begin(), vectorElements.end(), std::ostream_iterator<int>(outputFile, " "));
    outputFile.close();
};