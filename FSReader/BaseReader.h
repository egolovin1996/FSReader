#pragma once

#include <string> 
#include <iostream> 
#include <windows.h>

using namespace std;

class BaseReader
{
protected:
	HANDLE FileHandle;
	int BytesPerSector;
	int BytesPerCluster;
	int TotalSectors;
	int TotalClusters;
	int TotalBytes;

public:
	BaseReader(HANDLE fileHandle);

	void ShowInfo();

	virtual string GetFileSystemName() = 0;
	virtual void ShowClusterByNumber(int clusterNumber) = 0;

	~BaseReader();
};

