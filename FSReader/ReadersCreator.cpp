#include "pch.h"
#include <iostream> 
#include "ReadersCreator.h"


using namespace std;

typedef struct
{
	BYTE Padding1[3];
	char OEMName[8];
} OEMName;

ReadersCreator::ReadersCreator() { }

BaseReader* ReadersCreator::CreateReader(FileReader* fileReader)
{
	// Todo понять почему не работает с маленькими числами
	OEMName *oemName = (OEMName*)fileReader->ReadData(0, 1024);
	
	if (strcmp(oemName->OEMName, "NTFS    ") == 0) {
		return new NTFSReader(fileReader);
	}
	if (strcmp(oemName->OEMName, "MSDOS5.0") == 0) {
		return new FATReader(fileReader);
	}
	if (strcmp(oemName->OEMName, "EXFAT   ") == 0) {
		return new EXFATReader(fileReader);
	}

	// Можно написать readerы для других файловых систем, досточно реализовать BaseReader

	throw runtime_error("Unsupported file system or file type");
}

ReadersCreator::~ReadersCreator() { }