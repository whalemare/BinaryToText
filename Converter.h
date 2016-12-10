/*
 * Developed with love
 * by @whalemare on 2016.
 */

#ifndef MAP_CONVERTER_CONVERTER_H
#define MAP_CONVERTER_CONVERTER_H
#include<string.h>
using namespace std;

class Converter {
public:

    Converter(); // just. Functions below can used how static

    int convertToText(char *inp, char *out); // convert binary to text

    int convertToBinary(char *inp, char *out); // convert text to binary; return -1 if error, otherwise 0a
};

#endif
