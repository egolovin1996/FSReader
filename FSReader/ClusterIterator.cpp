#include "pch.h"
#include "ClusterIterator.h"
#include "BaseReader.h"

ClusterIterator::ClusterIterator(BaseReader* reader)
{
	_Reader = reader;
	_CurrentClusterNumber = 0;
}

Cluster* ClusterIterator::GetCluster() {
	_CurrentClusterNumber++;
	return _Reader->GetClusterByNumber(_CurrentClusterNumber);
}

bool ClusterIterator::HasMore() {
	int nextClusterNumber = _CurrentClusterNumber + 1;
	return nextClusterNumber < _Reader->GetTotalClustersCount();
}

ClusterIterator::~ClusterIterator() { }
