#include "pch.h"
#include <iostream> 
#include "ReadersCreator.h"
#include "NTFSReader.h"

using namespace std;

typedef struct
{
	BYTE Padding1[3];
	char OEMName[8];
} OEMName;

ReadersCreator::ReadersCreator() { }

BaseReader* ReadersCreator::CreateReader(FileReader* fileReader)
{
	// Todo ������ ������ �� �������� � ���������� �������
	OEMName *oemName = (OEMName*)fileReader->ReadData(0, 1024);
	
	if (strcmp(oemName->OEMName, "NTFS    ") == 0) {
		return new NTFSReader(fileReader);
	}

	// ����� �������� reader� ��� ������ �������� ������, �������� ����������� BaseReader

	throw runtime_error("Unsupported file system or file type");
}

ReadersCreator::~ReadersCreator() { }