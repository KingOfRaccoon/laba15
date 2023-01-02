typedef char telem;        //тип информационной части элемента стека
struct stek {
    telem data;            //поле данных
    stek *link;            //поле адреса
};


//Объявления (прототипы) функций
stek *initStek();                //инициализация стека
int isEmptyStek(stek *);                //проверка стека на пустоту
stek *pushStek(telem, stek *);        //добавление элемента в стек
stek *popStek(stek *, telem&);        //извлечение элемента из стека
void printStek(stek *);            //вывод содержимого стека
void printInFile(const char *, stek *);