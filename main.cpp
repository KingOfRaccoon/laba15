#include "moduleStek.h"
#include <string>
#include<fstream>
#include <cstring>
#include "iostream"

#define FileNameInput "D:\\input.txt\0"    //��� ���. ����� ������ ����������� �������
#define FileNameOutput "D:\\output.txt\0"
const int RAZ = 50;            //������������ ����� ������
const char PR_R[] = "r";        //������� �������� ����� �� ������
int checkFile(char *, const char *);    //�������� ������� �����
void printFile(char *);    //����� ����������� ����� �� ������

using namespace std;

int main() {
    FILE *in;
    stek *stack;
    int length;
    char filenameInput[] = FileNameInput;
    char filenameOutput[] = FileNameOutput;
    char st_in[RAZ];
    setlocale(LC_ALL, "Russian");

    cout << "��������� ��������� ��������� ����, �������" << endl;
    cout << " ������� ��������������� ������ ��������� �����, ���������� � �������� �������." << endl;

    if (!checkFile(filenameInput, PR_R)) {
        cout << " ������ �������� ����� " << filenameInput << " �� ������" << endl;
        cout << " ������� <Enter>" << endl;
        getchar();
        return 1;            //���� �������� ���� �� ������
    }
    cout << "���������� ��������� �����:" << endl;
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
    cout << "���������� ���������� �����:" << endl;
    printFile(filenameOutput);
    return 0;
}

int checkFile(char *fileName, const char *pr) {
    if (!(fopen(fileName, pr)))    //���� ���� �� ����������
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