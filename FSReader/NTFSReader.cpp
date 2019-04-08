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
	NTFSBootRecord *ntfsBootRecord = (NTFSBootRecord*)_FileDataReader->ReadData(0, 1024);

	_BytesPerSector = *(unsigned short*)ntfsBootRecord->BytesPerSector;
	int sectorsPerCluster = *(unsigned short*)ntfsBootRecord->SectorsPerCluster;
	_BytesPerCluster = _BytesPerSector * sectorsPerCluster;
	_TotalSectors = ntfsBootRecord->TotalSectors;
	_TotalClusters = _TotalSectors / sectorsPerCluster;
	_TotalBytes = _BytesPerSector * _TotalSectors;
}

string NTFSReader::GetFileSystemName()
{
	return "NTFS";
}

NTFSReader::~NTFSReader() { }