#include "tapesort.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>



TapeSort::TapeSort(const std::string &outFileName, Tape *tapeIn, int maxCountElemSave)
{
    outFileName_ = outFileName;
    tape_ = tapeIn;
    maxCountElemSave_ = maxCountElemSave;
};

void TapeSort::readElemntForTempFile()
{
    std::ifstream inputTapeNameFile(tape_->fileName);
    if (inputTapeNameFile.is_open()) {

        while (!inputTapeNameFile.eof()) {
            ++countTempFile_;
            std::vector<int> tempVectorElements; 
            tempVectorElements.reserve(maxCountElemSave_);
            for(int i=0; i<maxCountElemSave_; ++i)
            {
                int number;
	            inputTapeNameFile >> number;
                tempVectorElements.push_back(number);	
            }
            std::sort(tempVectorElements.begin(), tempVectorElements.end());
            
            std::string tempFileName = fileNameTemp + std::to_string(countTempFile_) + ".txt";
            Tape *tape  = new Tape(tempFileName);
            tape->write(tempVectorElements);
        }
        inputTapeNameFile.close();
    }
    else {
        std::cerr<< "File temp no open";
    }
};

void TapeSort::sortElement() {
    /*Алгоритм + доп обработка при первом элементе
    считываем первый элемент, сравниваем с минимальным текущем элементом
    если подходит записываем элемент + имя временного файла
    когда перебрали все временные элементы, перезаписываем временный элемент, но без первого числа

    // + если вектор стал пустым у временного файла, то исключаем его из обработки/ удаляем файл или бежим вектору с индексами временных файлов 
    --- другой вариант - плохой
    Считываем элементы в вектор из временных файлов
    и сравниваем элементы с минимальным и текущем
    если элемент находится между, то записываем его в текущий, но если это не самый первый элемент
    если все временные файлы кончились, тогда записываем текущий в выходную ленту
    При этом подумать:
    после записи элемента в файл, возможно стоит удалить его из временного
    а если во временном кончились элементы, тогда удалить временный файл (или удалить из рассмотрения, тогда хранить все в map и бежаться по map)

    */

}
