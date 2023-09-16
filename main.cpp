#include <fstream>
#include <iostream>
#include "tapesort.h"
// Файл конфигурации хранит информацию
/* задержки по записи/чтению элемента с ленты, перемотки
ленты, и сдвига ленты на одну позицию.*/


int main(int argc, char const *argv[])
{
     /*if (argc != 3) {
        std::cout << " Недостаточно входных аргуметов!";
        return -1;
    }*/

    //TapeSort ts(argv[1], argv[2]);

    Tape *inTape = new Tape("/tmp/tempTape/inputTape.txt");
    std::string outNameFileTape = "/tmp/tempTape/outTape.txt";
    TapeSort ts(outNameFileTape, inTape, 2);
    ts.readElemntForTempFile();
    return 0;
}