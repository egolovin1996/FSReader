#pragma once
#include "ClusterIterator.h"
#include "EmptyClusterIterator.h"
#include "BaseReader.h"

class IteratorsFactory
{
public:
	static ClusterIterator* GetClusterIterator(BaseReader* reader);
	static EmptyClusterIterator* GetEmptyClusterIterator(BaseReader* reader);
	static EmptyClusterIterator* GetEmptyClusterIteratorWithExistingIterator(ClusterIterator* iterator);

private:
	IteratorsFactory();
	~IteratorsFactory();
};

