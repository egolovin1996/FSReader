#include "pch.h"
#include "EXFATReader.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE Padding2[61];
	ULONGLONG TotalSectors;
	DWORD FATStartSector;
	DWORD FATSizeInSectors;
	DWORD FirstDataSector;
	DWORD TotalClusters;
	DWORD RootDirCluster;
	BYTE Padding3[8];
	BYTE SectorFactor;
	BYTE ClusterFactor;

} EXFATBootRecord;

EXFATReader::EXFATReader(FileReader* fileReader) : BaseReader(fileReader)
{
	EXFATBootRecord *exfatBootRecord = (EXFATBootRecord*)_FileDataReader->ReadData(0, 1024);

	_BytesPerSector = pow(2, exfatBootRecord->SectorFactor);
	int sectorsPerCluster = pow(2, exfatBootRecord->ClusterFactor);
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