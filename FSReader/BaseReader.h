#pragma once

#include <string> 
#include <iostream> 
#include <windows.h>

#include "FileReader.h"

using namespace std;

class BaseReader
{
protected:
	FileReader* FileDataReader;
	int BytesPerSector;
	int BytesPerCluster;
	int TotalSectors;
	int TotalClusters;
	int TotalBytes;

public:
	BaseReader(FileReader* fileReader);

	void ShowInfo();
	void ShowClusterByNumber(int clusterNumber);

	virtual string GetFileSystemName() = 0;

	~BaseReader();
private:
	void ShowHexData(BYTE *buffer);
};

