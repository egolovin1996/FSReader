#include "pch.h"
#include "FileReaderWithClusterIteration.h"


FileReaderWithClusterIteration::FileReaderWithClusterIteration(BaseReader* reader)
{
	_CurrentClusterNumber = 0;
	_Reader = reader;
}

void FileReaderWithClusterIteration::ShowCluster() {
	_CurrentClusterNumber++;
	_Reader->ShowClusterByNumber(_CurrentClusterNumber);
}

bool FileReaderWithClusterIteration::HasMore() {
	int nextClusterNumber = _CurrentClusterNumber++;
	return nextClusterNumber < _Reader->GetTotalClustersCount();
}

FileReaderWithClusterIteration::~FileReaderWithClusterIteration()
{
}
