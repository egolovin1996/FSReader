#include "pch.h"
#include <iostream> 
#include <windows.h>
#include "NTFSReader.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster[1];
	BYTE Padding2[23];
	long TotalSectors; 

} NTFSBootRecord;

using namespace std;

NTFSReader::NTFSReader(HANDLE fileHandle): BaseReader(fileHandle)
{
	LARGE_INTEGER position = { 0 };
	BOOL ok = SetFilePointerEx(fileHandle, position, nullptr, FILE_BEGIN);

	NTFSBootRecord *ntfsBootRecord;
	int bufferSize = 1024;
	BYTE buffer[1024];
	DWORD read;
	ok = ReadFile(fileHandle, buffer, bufferSize, &read, nullptr);

	ntfsBootRecord = (NTFSBootRecord*)buffer;

	BytesPerSector = *(unsigned short*)ntfsBootRecord->BytesPerSector;
	int sectorsPerCluster = *(unsigned short*)ntfsBootRecord->SectorsPerCluster;
	BytesPerCluster = BytesPerSector * sectorsPerCluster;
	TotalSectors = ntfsBootRecord->TotalSectors;
	TotalClusters = TotalSectors / sectorsPerCluster;
	TotalBytes = BytesPerSector * TotalSectors;
}

string NTFSReader::GetFileSystemName()
{
	return "NTFS";
}

void NTFSReader::ShowClusterByNumber(int clusterNumber)
{
	LARGE_INTEGER position = { (clusterNumber - 1)*BytesPerCluster };
	BOOL ok = SetFilePointerEx(FileHandle, position, nullptr, FILE_BEGIN);
	BYTE *buffer = new BYTE[BytesPerCluster];
	DWORD read;
	ok = ReadFile(FileHandle, buffer, BytesPerCluster, &read, nullptr);

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

NTFSReader::~NTFSReader()
{
}