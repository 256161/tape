#include "tapesort.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>

TapeSort::TapeSort(const std::string &outFileName, Tape *tapeIn,
                   int maxCountElemSave) {
  outFileName_ = outFileName;
  tape_ = tapeIn;
  maxCountElemSave_ = maxCountElemSave;
};

// Передалать, с учетом что эта лента! + добавить позицию головки
void TapeSort::readElemntForTempFile() {
  std::ifstream inputTapeNameFile(tape_->fileName);
  if (inputTapeNameFile.is_open()) {

    while (!inputTapeNameFile.eof()) {
      ++countTempFile_;
      std::vector<int> tempVectorElements;
      tempVectorElements.reserve(maxCountElemSave_);
      for (int i = 0; i < maxCountElemSave_; ++i) {
        int number;
        inputTapeNameFile >> number;
        tempVectorElements.push_back(number);
      }
      std::sort(tempVectorElements.begin(), tempVectorElements.end());

      std::string tempFileName =
          fileNameTemp + std::to_string(countTempFile_) + ".txt";
      Tape *tape = new Tape(tempFileName);
      tape->write(tempVectorElements);
    }
    inputTapeNameFile.close();
  } else {
    std::cerr << "File temp no open";
  }
};

void TapeSort::sortElement() {

  std::list<int> remainTempFiles;
  // Заполняется при первом проходе по всем файлам
  for (int i = 0; i < countTempFile_; ++i) {
    remainTempFiles.push_back(i);
  }

  int minNumber = -1;
  int currentElement;
  int numberTempFile = -1;
  while (remainTempFiles.size()) {
    for (auto numberTempFiles : remainTempFiles) {
      Tape *tape =
          new Tape(fileNameTemp + std::to_string(numberTempFiles) + ".txt");
      currentElement = tape->readFirst();

      if (!currentElement) {
        remainTempFiles.remove(numberTempFiles);
        continue;
      } else {
        if (!minNumber || minNumber > currentElement) {
          minNumber = std::move(currentElement);
          numberTempFile = numberTempFiles;
        }
      }
    }
    // Выбрали минимальный элемент
    if (numberTempFile) {
      Tape *tape =
          new Tape(fileNameTemp + std::to_string(numberTempFile) + ".txt");
      // переписываем все значения кроме первого
      tape->deleteFirstElement();
      // Записываем элемент в выходной массив
      tape_->writeNextElement(minNumber);
    } else { // передлать под исключения
      std::cout << " Sort stopped";
      return;
    }
  }
}
/*Алгоритм + доп обработка при первом элементе
считываем первый элемент, сравниваем с минимальным текущем элементом
если подходит записываем элемент + имя временного файла
когда перебрали все временные элементы, перезаписываем временный элемент, но без
первого числа

// + если вектор стал пустым у временного файла, то исключаем его из обработки/
удаляем файл или бежим вектору с индексами временных файлов
--- другой вариант - плохой
Считываем элементы в вектор из временных файлов
и сравниваем элементы с минимальным и текущем
если элемент находится между, то записываем его в текущий, но если это не самый
первый элемент если все временные файлы кончились, тогда записываем текущий в
выходную ленту При этом подумать: после записи элемента в файл, возможно стоит
удалить его из временного а если во временном кончились элементы, тогда удалить
временный файл (или удалить из рассмотрения, тогда хранить все в map и бежаться
по map)

*/
