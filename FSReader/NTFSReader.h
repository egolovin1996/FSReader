#pragma once
#include "BaseReader.h"

using namespace std;

class NTFSReader :
	public BaseReader
{
public:
	NTFSReader(HANDLE fileHandle);

	string GetFileSystemName() override;
	void ShowClusterByNumber(int clusterNumber) override;

	~NTFSReader();
};

