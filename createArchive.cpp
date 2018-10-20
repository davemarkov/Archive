#include <iostream>
#include <fstream>
#include "createArchive.h"
#include <string.h>
//#include "vector.hpp"

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

	WriteToBinary out("myTest.darc");
		// compressed file header
		int len = strlen(fileName);
		out.write(len);
		out.write(fileName);
		out.write(dictionaryLength);

		//insert dictionary (for each encoding)
		while (!arr.isEmpty())
		{
			Data* current = arr.pop();

			out.write(current->elem);
			out.write(current->codeLength);
			out.write(current->encoded,current->codeLength);
						
			bucket.insert(current->elem,current);
		}

		//go through each byte and write the corresponding encoded value from bytebucket
		BinaryFileReader file(fileName);
		while (!file.isEOF())
		{
			Data* temp = bucket.get(file.get());
			out.write(temp->encoded, temp->codeLength);
		}
		out.putEOF();
//
		//BinaryFileReader file(fileName);
//
		//while (!file.isEOF())
		//{
		//	Data* temp = dictionary.search(file.get());
		//	bitsContainer.addCustom(temp->encoded, temp->codeLength);
		//}
		//bitsContainer.setEnd();
//
		//out.write(bitsContainer.allBits, (sizeof(char))*bitsContainer.size + 1);
//
		//out.close();
}
