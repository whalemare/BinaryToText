/*
 * Developed with love
 * by @whalemare on 2016.
 */

#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Converter.h"
using namespace::std;
#include <fstream>
#include <stdio.h>
#include<stdlib.h>

#define STR_LEN 255


int Converter::convertToText(char *inp, char *out) {
/*variables*/
    long int count;
    char string[STR_LEN];
    unsigned int i;
    unsigned int integer;
    unsigned int length;

    /*file pointers*/
    FILE *fp;
    FILE *fo;

    /*input/output files error check*/
    if((fp = fopen(inp, "r")) == NULL)
    {
        printf("Input file could not be opened\n");
        return 0;
    }

    if((fo = fopen(out, "w")) == NULL)
    {
        printf("Output file could not be opened\n");
        return 0;
    }

    /*to store the size of file*/
    fseek(fp, 0, SEEK_END);
    count = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /*loop until EOF*/
    while((ftell(fp)) != count)
    {
        /*take the first character--length of string*/
        fscanf(fp, "%c", &string[0]);

        /*convert character into an unsigned int*/
        length = string[0];

        i = 0;
        /*scans in characters with string length as counter*/
        while(length > 0)
        {
            fscanf(fp, "%c", &string[i]);
            i++;
            length--;
        }

        /*adds null terminator*/
        string[i] = '\0';

        /*read the integer*/
        fread((void *)&integer, sizeof(unsigned int), 1, fp);

        /*prints string to output*/
        fprintf(fo, "%s", string);

        /*prints tab to output*/
        fprintf(fo, "\t");

        /*prints integer to output*/
        fprintf(fo, "%d", integer);

        /*avoid newline at end of last line*/
        if((count - (ftell(fp)) != 0))
        {
            /*print new line*/
            fprintf(fo, "\n");
        }
    }

    /*close files*/
    fclose(fp);
    fclose(fo);
}

int Converter::convertToBinary(char *inp, char *out) {
    /*variables*/
    long int count;
    unsigned int i;
    char string[STR_LEN];
    unsigned int integer;
    unsigned char length;

    /*file pointers*/
    ifstream in;
    ofstream ofs;

    FILE *fp;
    FILE *fo;

    /*input/output files error check*/
    if((fp = fopen(inp, "r")) == NULL)
    {
        fprintf(stderr, "Input file could not be opened\n");
        return -1;
    }

    if((fo = fopen(out, "w")) == NULL)
    {
        fprintf(stderr, "Output file could not be opened\n");
        return -1;
    }

    /*to store the size of file*/
    fseek(fp, 0, SEEK_END);
    count = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /*loop until EOF*/
    while((ftell(fp)) != count)
    {
        /*scans in one line*/
        fscanf(fp, "%s \t %d", string, &integer);

        /*finds length of string*/
        length = strlen(string);

        /*writes the integer in 1 byte*/
        fwrite((void *)&length, sizeof(char), 1, fo);

        /*writes string without null character*/
        for(i = 0; i < length; i++)
        {
            fwrite((void *)&string[i], sizeof(char), 1, fo);
        }

        /*writes integer in 4 bytes*/
        fwrite((void *)&integer, sizeof(int), 1, fo);
    }

    /*close files*/
    fclose(fp);
    fclose(fo);
    return 0;
}

Converter::Converter() {
    // empty constructor
}
