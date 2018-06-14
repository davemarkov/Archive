#ifndef _WRITE_TO_BINARY_H_
#define _WRITE_TO_BINARY_H_

#include "bitsContainer.h"
#include <fstream>

class WriteToBinary 
{
    BitsContainer buffer;
    std::ofstream out;

public:
    WriteToBinary(char* filename)
        : out(filename, std::ios::binary) {}

    void write(char*, int);
    void write(char, int);
    void write(int, int);
    void write(short, int);

};

#endif//_WRITE_TO_BINARY_H_