#include <iostream>
#include "writeToBinary.h"

// puts a strig in bits container buffer
void WriteToBinary::write(char* string)
{
    buffer.addString(string);
    if (buffer.isReady())
    {
        writeToFile(MAX_SIZE);
    }
}

// puts 1 byte in bits container buffer
void WriteToBinary::write(char byte)
{
    buffer.addChar(byte);
    if (buffer.isReady())
    {
        writeToFile(MAX_SIZE);
    }
}

// puts a maximum if 1 byte with given number of bits
// in bits container buffer
//void WriteToBinary::write(char byte, int lenght)
//{
//    buffer.addCustom(byte, lenght);
//}

// puts a maximum if 2 byte with given number of bits
// in bits container buffer
void WriteToBinary::write(short bytes, int lenght)
{
    buffer.addCustom(bytes, lenght);
    if (buffer.isReady())
    {
        writeToFile(MAX_SIZE);
    }
}

// puts a maximum if 4 byte with given numbre of bits
// in bits container buffer
void WriteToBinary::write(int bytes, int lenght)
{
    buffer.addCustom(bytes, lenght);
    if (buffer.isReady())
    {
        writeToFile(MAX_SIZE);
    }
}

// puts an integer in bits container buffer
void WriteToBinary::write(int number)
{
    buffer.addNumber(number);
    if (buffer.isReady())
    {
        writeToFile(MAX_SIZE);
    }
}

void WriteToBinary::putEOF()
{
    buffer.setEnd();
    writeToFile(buffer.getSize());
}

// writes the buffer in the opened file
void WriteToBinary::writeToFile(int numberOfBytes)
{
    out.write(buffer.getBlockToWrite(), numberOfBytes);
    buffer.setDoneWritting();

}
