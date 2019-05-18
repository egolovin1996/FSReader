#pragma once

#include <string> 
#include <iostream> 
#include <windows.h>

#include "FileReader.h"

using namespace std;

class BaseReader
{
protected:
	FileReader* _FileDataReader;
	int _BytesPerSector;
	int _BytesPerCluster;
	int _TotalSectors;
	int _TotalClusters;
	int _TotalBytes;

public:
	BaseReader(FileReader* fileReader);

	BYTE* GetClusterByNumber(int clusterNumber);
	int GetTotalClustersCount();
	void ShowClusterByNumber(int clusterNumber);
	void ShowInfo();

	virtual string GetFileSystemName() = 0;

	~BaseReader();
private:
	void ShowHexData(BYTE *buffer);
};

