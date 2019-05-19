#pragma once
#include "BaseReader.h"
#include "FileReader.h"

using namespace std;

class NTFSReader :
	public BaseReader
{
public:
	NTFSReader(FileReader* fileHandle);

	string GetFileSystemName() override;

	~NTFSReader();
};

