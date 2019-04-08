#include "pch.h"
#include <windows.h>
#include <iostream> 
#include "ReadersFactory.h"
#include "NTFSReader.h"

using namespace std;

typedef struct
{
	BYTE Padding1[3];
	char OEMName[8];
} OEMName;

ReadersFactory::ReadersFactory()
{
}

BaseReader* ReadersFactory::CreateReader(HANDLE fileHandle)
{
	LARGE_INTEGER position = { 0 };
	BOOL ok = SetFilePointerEx(fileHandle, position, nullptr, FILE_BEGIN);

	OEMName *oemName;
	const int bufferSize = 1024;
	BYTE buffer[bufferSize];
	DWORD read;
	ok = ReadFile(fileHandle, buffer, bufferSize, &read, nullptr);

	oemName = (OEMName*)buffer;
	
	if (strcmp(oemName->OEMName, "NTFS    ") == 0) {
		return new NTFSReader(fileHandle);
	}

	// Other file systems

	throw runtime_error("Unsupported file system or file type");
}

ReadersFactory::~ReadersFactory()
{
}
