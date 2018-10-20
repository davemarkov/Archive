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

    // receive bytes to write, put them in bits container 
    // and then at certain ammount(chunks) of bytes
    // write them to the output file

    // puts a strig in bits container buffer
    void write(char*);

    // puts 1 byte in bits container buffer
    void write(char);

    // puts a maximum if 1 byte with given number of bits
    // in bits container buffer
    //void write(char, int);

    // puts a maximum if 2 byte with given number of bits
    // in bits container buffer
    void write(short, int);

    // puts a maximum if 4 byte with given numbre of bits
    // in bits container buffer
    void write(int, int);

    // puts an integer in bits container buffer
    void write(int);

    void putEOF();


private:
    // writes the buffer in the opened file
    void writeToFile(int);

};

#endif//_WRITE_TO_BINARY_H_