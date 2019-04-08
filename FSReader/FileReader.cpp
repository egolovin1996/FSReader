#include "pch.h"
#include "FileReader.h"

using namespace std;

FileReader::FileReader()
{
}

FileReader::FileReader(string fileName)
{
	wstring wFileName(fileName.begin(), fileName.end());
	_fileHandle = CreateFileW(
		wFileName.c_str(),
		GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (_fileHandle == INVALID_HANDLE_VALUE)
	{
		throw runtime_error("Error open file");
	}
}

BYTE* FileReader::ReadData(int startPosition, int bufferSize)
{
	LARGE_INTEGER position = { startPosition };
	BOOL ok = SetFilePointerEx(_fileHandle, position, nullptr, FILE_BEGIN);
	BYTE *buffer = new BYTE[bufferSize];
	DWORD read;
	ok = ReadFile(_fileHandle, buffer, bufferSize, &read, nullptr);

	return buffer;
}

FileReader::~FileReader()
{
	CloseHandle(_fileHandle);
}
