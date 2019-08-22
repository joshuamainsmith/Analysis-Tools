#include <iostream>
#include <fstream>

using namespace std;


struct PEHeader
{
	int signautre; // offset to signature indicated at 0x3c
	bool PE = false;
	// COFF File Header (Object and Image)
	short machine;
	short numberOfSections;
	int timeDateStamp;
	int pointerToSymbolTable;
	int numberOfSymbols;
	short sizeOfOptionalHeader;
	short characteristics;
};

int main()
{
	PEHeader header;
	string fileName = "PhoneSort.exe";
	ifstream file(fileName, ios::in | ios::binary);




	file.seekg(0x3c, ios::beg);

	int offset;

	file.read((char*)& offset, sizeof(offset));

	cout << offset << endl;

	file.seekg(offset, ios::beg);

	/*char re;
	file.read((char*)& re, sizeof(re));*/


	file.read((char *)&header.signautre, sizeof(header.signautre));

	cout << header.signautre << endl;

	return 0;
}