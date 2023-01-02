#include<fstream>
#include <iostream>
#include "moduleStek.h"

using namespace std;
//Просмотр содержимого стека
void printStek(stek *stack) {
    stek *tec = stack;
    while (!isEmptyStek(tec)) {
        cout << tec->data;
        tec = tec->link;
    }
    cout << endl;
}

//Занесение нового элемента в стек
stek *pushStek(telem ch, stek *stack) {
    stek *nov = new(stek);    //выделяем память под элемент стека
    nov->data = ch;         //заполняем поля
    nov->link = stack;
    stack = nov;            //указатель на начало стека
    return stack;
}

//Извлечение элемента из стека
stek *popStek(stek *stack, telem &ch) {
    stek *tec = stack->link;
    ch = stack->data;    //копируем информационную часть головного элемента
    delete (stack);        //освобождаем память
    return tec;
}

//Инициализация стека
stek *initStek() {
    return nullptr;    //в исходном состоянии стек пуст
}

//Проверка стека на пустоту
int isEmptyStek(stek *stack) {
    return stack == nullptr;    //стек пуст - 0
}

void printInFile(const char *fileName, stek *stack){
    ofstream in;
    in.open(fileName, ios_base::app);
    char *str = new char[50];
    int i = 0;
    telem ch;
    while (!isEmptyStek(stack)){
        stack = popStek(stack, ch);
        str[i] = ch;
        i++;
    }
    in << str << endl;
    in.close();
}