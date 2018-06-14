#include <iostream>
#include <fstream>
#include "createArchive.h"
#include <string.h>
#include "vector.hpp"

void Archive::archiveFile(char* fileName)
{

	// analyze text and load huffnam 
	// store encoded data in bucket
		// use bitsContainer!!! 
	// write file header 
	// write deictionary
		// write them during encoding each elem and inserting them in bucket
	// write file with encoded bytes
	// done 

	std::ofstream out("myTest.darc", std::ios::binary);
	if (out.is_open())
	{
		int len = strlen(fileName);
		bitsContainer.addNumber(len);
		bitsContainer.addString(fileName);
		bitsContainer.addNumber(dictionaryLength);

		// huffmanIterator// intsert in file// intsert in vector(sorted)
		CompressionIterator iter = begin();

		Dictionary dictionary;
		while (!iter.endOfIterator())
		{
			bitsContainer.addChar(iter->elem);
			bitsContainer.addNumber(iter->codeLength);
			bitsContainer.addNumber(iter->encoded);
						
			dictionary.insert(iter.operator->);
			
		}

		//generate encoded file with vector;
		BinaryFileReader file(fileName);

		while (!file.isEOF())
		{
			Data* temp = dictionary.search(file.get());
			bitsContainer.addCustom(temp->encoded, temp->codeLength);
		}
		bitsContainer.setEnd();

		out.write(bitsContainer.allBits, (sizeof(char))*bitsContainer.size + 1);

		out.close();
	}
	else
		std::cout << "couldnt create file :( " << std::endl;
}
