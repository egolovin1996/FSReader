#include "pch.h"
#include "BaseReader.h"
#include "FileReader.h"

using namespace std;

BaseReader::BaseReader(FileReader* fileReader) 
{
	FileDataReader = fileReader;
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

void BaseReader::ShowClusterByNumber(int clusterNumber)
{
	if (clusterNumber < 1 || clusterNumber > TotalClusters) 
	{
		throw runtime_error("Wrong cluster number");
	}

	int clusterPosition = (clusterNumber - 1)*BytesPerCluster;
	BYTE *buffer = FileDataReader->ReadData(clusterPosition, BytesPerCluster);

	ShowHexData(buffer);
}

BaseReader::~BaseReader() { }

void BaseReader::ShowHexData(BYTE * buffer)
{
	for (int i = 1; i < BytesPerCluster + 1; i++) {
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
