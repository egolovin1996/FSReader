#include "pch.h"
#include <iostream> 
#include "ReadersFactory.h"
#include "NTFSReader.h"

using namespace std;

typedef struct
{
	BYTE Padding1[3];
	char OEMName[8];
} OEMName;

ReadersFactory::ReadersFactory() { }

BaseReader* ReadersFactory::CreateReader(FileReader* fileReader)
{
	// Todo ������ ������ �� �������� � ���������� �������
	OEMName *oemName = (OEMName*)fileReader->ReadData(0, 1024);
	
	if (strcmp(oemName->OEMName, "NTFS    ") == 0) {
		return new NTFSReader(fileReader);
	}

	// ����� �������� reader� ��� ������ �������� ������, �������� ����������� BaseReader

	throw runtime_error("Unsupported file system or file type");
}

ReadersFactory::~ReadersFactory() { }