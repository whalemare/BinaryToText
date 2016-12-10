#include <iostream>
#include "Converter.h"

using namespace std;

int main() {
    Converter *converter = new Converter();
    char *inp = (char *) "binaryOutput.bin";
    char *out = (char *) "textOutput.txt";

    return converter->convertToText(inp, out);
}