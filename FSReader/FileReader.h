#pragma once

#include <iostream>
#include <string> 
#include <windows.h> 

using namespace std;

class FileReader
{
private:
	HANDLE _fileHandle;
public:
	FileReader();
	FileReader(string fileName);

	BYTE* ReadData(int startPosition, int bufferSize);

	~FileReader();
};

