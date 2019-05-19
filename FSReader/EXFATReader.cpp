#include "pch.h"
#include "EXFATReader.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster[1];
	BYTE Padding2[23];
	long TotalSectors;

} EXFATBootRecord;

EXFATReader::EXFATReader(FileReader* fileReader) : BaseReader(fileReader)
{
	EXFATBootRecord *exfatBootRecord = (EXFATBootRecord*)_FileDataReader->ReadData(0, 1024);

	_BytesPerSector = *(unsigned short*)exfatBootRecord->BytesPerSector;
	int sectorsPerCluster = *(unsigned short*)exfatBootRecord->SectorsPerCluster;
	_BytesPerCluster = _BytesPerSector * sectorsPerCluster;
	_TotalSectors = exfatBootRecord->TotalSectors;
	_TotalClusters = _TotalSectors / sectorsPerCluster;
	_TotalBytes = _BytesPerSector * _TotalSectors;
}

string EXFATReader::GetFileSystemName()
{
	return "exFat";
}

EXFATReader::~EXFATReader() { }