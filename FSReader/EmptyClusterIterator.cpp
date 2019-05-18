#include "pch.h"
#include "EmptyClusterIterator.h"

EmptyClusterIterator::EmptyClusterIterator(ClusterIterator* clusterReader)
	: ClusterIterator(NULL)
{
	_clusterReader = clusterReader;
	_lastEmptyClaster = NULL;
}

Cluster* EmptyClusterIterator::GetCluster()
{
	if (_lastEmptyClaster == NULL) {
		throw runtime_error("First call \"HasMore\" method or there are no more empty clusters");
	}
	
	return _lastEmptyClaster;
}

bool EmptyClusterIterator::HasMore()
{
	while (_clusterReader->HasMore()) {
		Cluster* cluster = _clusterReader->GetCluster();
		if (isEmpty(cluster)) {
			_lastEmptyClaster = cluster;
			return true;
		}
	}

	return false;
}

bool EmptyClusterIterator::isEmpty(Cluster * cluster)
{
	BYTE * data = cluster->GetData();
	int size = cluster->GetSize();
	for (int i = 1; i < size + 1; i++) {
		if (data[i - 1] != 0) {
			return false;
		}
	}

	return true;
}

EmptyClusterIterator::~EmptyClusterIterator()
{
}
