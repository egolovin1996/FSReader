#include "pch.h"
#include "BaseClusterIterator.h"
#include "BaseReader.h"

BaseClusterIterator::BaseClusterIterator(BaseReader* reader)
{
	_Reader = reader;
}

void BaseClusterIterator::ShowCluster() {	
	_CurrentClusterNumber++;
	_Reader->ShowClusterByNumber(_CurrentClusterNumber);
}

bool BaseClusterIterator::HasMore() {
	int nextClusterNumber = _CurrentClusterNumber + 1;
	return nextClusterNumber < _Reader->GetTotalClustersCount();
}

BaseClusterIterator::~BaseClusterIterator() { }
