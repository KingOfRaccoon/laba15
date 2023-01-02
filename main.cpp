#include "moduleStek.h"
#include <string>
#include<fstream>
#include <cstring>
#include "iostream"

#define FileNameInput "D:\\input.txt\0"    //имя исх. файла задано константной строкой
#define FileNameOutput "D:\\output.txt\0"
const int RAZ = 50;            //максимальная длина строки
const char PR_R[] = "r";        //признак открытия файла на чтение
int checkFile(char *, const char *);    //проверка наличия файла
void printFile(char *);    //вывод содержимого файла на печать

using namespace std;

int main() {
    FILE *in;
    stek *stack;
    int length;
    char filenameInput[] = FileNameInput;
    char filenameOutput[] = FileNameOutput;
    char st_in[RAZ];
    setlocale(LC_ALL, "Russian");

    cout << "Программа формирует текстовый файл, который" << endl;
    cout << " символы соответствующей строки исходного файла, записанные в обратном порядке." << endl;

    if (!checkFile(filenameInput, PR_R)) {
        cout << " Ошибка открытия файла " << filenameInput << " на чтение" << endl;
        cout << " Нажмите <Enter>" << endl;
        getchar();
        return 1;            //если исходный файл не создан
    }
    cout << "Содержимое исходного файла:" << endl;
    printFile(filenameInput);

    ifstream out(filenameInput);
    while (out.getline(st_in, RAZ)) {
        stack = initStek();
        length = strlen(st_in);
        for (int i = 0; i < length; i++) {
            stack = pushStek(st_in[i], stack);
        }
        printInFile(filenameOutput, stack);
    }
    out.close();
    cout << "Содержимое финального файла:" << endl;
    printFile(filenameOutput);
    return 0;
}

int checkFile(char *fileName, const char *pr) {
    if (!(fopen(fileName, pr)))    //если файл не существует
        return (0);
    return (1);
}

void printFile(char *fileName) {
    ifstream out(fileName);
    char st_in[RAZ];
    while (!out.eof()) {
        out.getline(st_in, RAZ);
        cout << st_in << endl;
    }
    out.close();
}