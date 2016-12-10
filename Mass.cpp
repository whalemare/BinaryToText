/*
 * Developed with love
 * by @whalemare on 2016.
 */

#include "Mass.h"
#include <ostream>
#include <iostream>
using std::ostream;
using namespace std;


Mass::Mass(){sz = 0; buf = new string[0];}

Mass::Mass(int a) { //создает пустой массив с a элементами
    buf = new string[a];
    Mass::sz = a;
    sz = a;
}

Mass::Mass(Mass &a) { //конструктор копирования.
    buf = new string[a.sz];
    sz = a.sz;
    for (int i = 0; i < sz; ++i)
        buf[i] = a.buf[i];
    /* Пример.
    Есть некий массив A
    Мы хотим создать его копию - массив B
    Благодаря этому конструктору достаточно сделать так:
    Mas B = A;
    */
}

Mass::~Mass() {
//	delete buf; // очищаем память
}

istream& operator>>(istream &in, Mass &a) {
    for (int i = 0; i < a.sz; ++i)
        in >> a.buf[i]; // вводим элементы массива
    return in;
}

ostream& operator<<(ostream &out, const Mass &a) {
    if ((a.sz <= 0) || (a.sz==NULL)) // если массив пуст
        out << "Массив пуст";
    else
        for (int i = 0; i < a.sz; ++i)
            out << a.buf[i]; // выводим элементы массива
    return out;
}

Mass Mass::operator=(const Mass&a) {
    if (&a != this) {
        if (sz != a.sz) { //если размеры разные, то уравниваем
            delete buf;
            sz = a.sz;
            buf = new string [sz];
        }

        for (int i = 0; i < sz; ++i)
            buf[i] = a.buf[i]; //копируем элементы
    }
    return *this; // разрешает множественное присваивание (a = b = c)
}

string Mass::operator[](int a) {
    if (a >= 0 && a < sz)
        return buf[a]; // возвращает элемент по индексу (для a[i])
    else
        cout << "Неверный индекс" << endl;
}

int Mass::getSize() {
    return sz; // размер массива
}

void Mass::del(int a) {
    Mass t = *this; // создаем новый массив с размером на 1 меньше
    delete buf; --sz;
    buf = new string[sz];
    int j = 0;
    for (int i =0; i < sz + 1; ++i)
        if (i != a) {
            buf[j] = t.buf[i]; // заносим туда все старые элементы, кроме удаляемого
            j++;
        }
}

void Mass::ins(int n, string a) {
    Mass t = *this;

    delete buf; sz++; // создаем новый массив с размером на 1 больше
    buf = new string [sz];

    int j = 0;
    for (int i = 0; i < sz; ++i) { // заносим туда все старые элементы и +1 новый добавленный
        if (i!=n) {
            buf[i] = t.buf[j];
            j++;
        }
        else buf[i] = a;
    }
}

void Mass::rep(int n, string a) {
    for (int i = 0; i < sz; ++i) {
        if (i == n)
            buf[i] = a; // заменяем элемент под индексом n на a
    }
}
