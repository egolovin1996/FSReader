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

BYTE * BaseReader::GetClusterByNumber(int clusterNumber)
{
	if (clusterNumber < 1 || clusterNumber > _TotalClusters)
	{
		throw runtime_error("Wrong cluster number");
	}

	int clusterPosition = (clusterNumber - 1)*_BytesPerCluster;
	BYTE *result = _FileDataReader->ReadData(clusterPosition, _BytesPerCluster);

	return result;
}

void BaseReader::ShowClusterByNumber(int clusterNumber)
{
	BYTE *buffer = GetClusterByNumber(clusterNumber);
	ShowHexData(buffer);
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

void BaseReader::ShowHexData(BYTE * buffer)
{
	for (int i = 1; i < _BytesPerCluster + 1; i++) {
		printf("%02x ", buffer[i - 1]);

		if (i % 16 == 0) {
			cout << endl;
		}
		else if (i % 8 == 0)
		{
			cout << "  ";
		}
	}
}
