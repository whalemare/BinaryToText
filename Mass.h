/*
 * Developed with love
 * by @whalemare on 2016.
 */

#ifndef OLGA_MASS_H
#define OLGA_MASS_H


#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Mass {
public:
    string *buf; // указатель на элемент массива
    int sz; // размер массива
    Mass *Next; // указатель на следующий элемент

    Mass(); // конструктор по умолчанию
    Mass(int); // конструктор с параметром
    Mass(Mass &); // конструкто копирования
    ~Mass(); // деструктор

    friend istream &operator>>(istream&, Mass&); //перегруженный оператор для ввода массива
    friend ostream &operator<<(ostream&, const Mass&); //перегруженный оператор для вывода массива

    Mass operator=(const Mass&); //перегруженный оператор присваивания
    string operator[](int); //для возможности удобно обращаться к элементам массива. Например mas[2];

    int getSize(); // получить размер массива
    void del(int); // удалить элемент по индексу
    void ins(int, string); // вставка
    void rep(int, string); // замена
};


#endif //OLGA_MASS_H
