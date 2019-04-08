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

NTFSReader::NTFSReader(FileReader* fileReader): BaseReader(fileReader)
{
	BYTE *buffer = FileDataReader->ReadData(0, 1024);
	NTFSBootRecord *ntfsBootRecord;
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

NTFSReader::~NTFSReader() { }