#include "pch.h"
#include "BaseReader.h"
#include "FileReader.h"

using namespace std;

BaseReader::BaseReader(FileReader* fileReader) 
{
	_FileDataReader = fileReader;
}

int BaseReader::GetTotalClustersCount()
{
	return _TotalClusters;
}

Cluster * BaseReader::GetClusterByNumber(int clusterNumber)
{
	if (clusterNumber < 1 || clusterNumber > _TotalClusters)
	{
		throw runtime_error("Wrong cluster number");
	}

	int clusterPosition = (clusterNumber - 1)*_BytesPerCluster;
	BYTE *data = _FileDataReader->ReadData(clusterPosition, _BytesPerCluster);
	Cluster *result = new Cluster(data, _BytesPerCluster);

	return result;
}

void BaseReader::ShowInfo()
{
	cout << "File system name: " << GetFileSystemName() << endl;
	cout << "Bytes per sector: " << _BytesPerSector << endl;
	cout << "Bytes per cluster: " << _BytesPerCluster << endl;
	cout << "Total sectors: " << _TotalSectors << endl;
	cout << "Total clusters: " << _TotalClusters << endl;
	cout << "Total bytes: " << _TotalBytes << endl;
}

BaseReader::~BaseReader() { }