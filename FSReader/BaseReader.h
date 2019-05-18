#pragma once

#include <string> 
#include <iostream> 
#include <windows.h>

#include "FileReader.h"
#include "Cluster.h"

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

	Cluster* GetClusterByNumber(int clusterNumber);
	int GetTotalClustersCount();
	void ShowInfo();

	virtual string GetFileSystemName() = 0;

	~BaseReader();
};

