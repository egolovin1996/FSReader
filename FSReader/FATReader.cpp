#include "pch.h"
#include "FATReader.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster;
	BYTE Padding2[5];
	BYTE TotalSectorsSmall[2];
	BYTE Padding3[11];
	long TotalSectorsBig;

} FATBootRecord;

FATReader::FATReader(FileReader* fileReader) : BaseReader(fileReader)
{
	FATBootRecord *fatBootRecord = (FATBootRecord*)_FileDataReader->ReadData(0, 1024);

	_BytesPerSector = *(unsigned short*)fatBootRecord->BytesPerSector;
	int sectorsPerCluster = (unsigned short)fatBootRecord->SectorsPerCluster;
	_BytesPerCluster = _BytesPerSector * sectorsPerCluster;
	int totalSectorsSmall = *(unsigned short*)fatBootRecord->TotalSectorsSmall;
	int fatSectorsDiff = 578;
	_TotalSectors = totalSectorsSmall != 0 
		? totalSectorsSmall 
		: fatBootRecord->TotalSectorsBig - fatSectorsDiff;
	_TotalClusters = _TotalSectors / sectorsPerCluster;
	_TotalBytes = _BytesPerSector * _TotalSectors;
}

string FATReader::GetFileSystemName()
{
	return "FAT";
}

FATReader::~FATReader() { }
