#include "pch.h"
#include "BaseReader.h"

#include <string> 
#include <iostream> 
#include <windows.h>

using namespace std;

BaseReader::BaseReader(HANDLE fileHandle)
{
	FileHandle = fileHandle;
}

void BaseReader::ShowInfo()
{
	cout << "File system name: " << GetFileSystemName() << endl;
	cout << "Bytes per sector: " << BytesPerSector << endl;
	cout << "Bytes per cluster: " << BytesPerCluster << endl;
	cout << "Total sectors: " << TotalSectors << endl;
	cout << "Total clusters: " << TotalClusters << endl;
	cout << "Total bytes: " << TotalBytes << endl;
}

BaseReader::~BaseReader()
{

}
