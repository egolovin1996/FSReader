#pragma once
#include "BaseReader.h"

using namespace std;

class FileReaderWithClusterIteration
{
protected:
	int _CurrentClusterNumber;
	BaseReader* _Reader;

public:
	FileReaderWithClusterIteration(BaseReader* reader);

	void ShowCluster();
	bool HasMore();

	~FileReaderWithClusterIteration();
};

