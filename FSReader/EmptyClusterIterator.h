#pragma once
#include "ClusterIterator.h"
#include "BaseReader.h"
#include "Cluster.h"

class EmptyClusterIterator :
	public ClusterIterator
{
private:
	ClusterIterator *_clusterReader;
	Cluster *_lastEmptyClaster;

	bool isEmpty(Cluster* cluster);

public:
	EmptyClusterIterator(ClusterIterator* reader);

	Cluster* GetCluster() override;
	bool HasMore() override;

	~EmptyClusterIterator();
};

