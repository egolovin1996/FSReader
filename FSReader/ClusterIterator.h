#pragma once
#include "BaseReader.h"
#include "BaseReader.h"

using namespace std;

class ClusterIterator
{
protected:
	int _CurrentClusterNumber;
	BaseReader* _Reader;

public:
	ClusterIterator(BaseReader* reader);

	virtual Cluster* GetCluster();
	virtual bool HasMore();

	~ClusterIterator();
};

