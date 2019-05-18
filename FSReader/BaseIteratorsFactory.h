#pragma once
#include "BaseClusterIterator.h"
#include "BaseReader.h"

class BaseIteratorsFactory
{
public:
	BaseIteratorsFactory();

	virtual BaseClusterIterator* CreateClusterIterator(BaseReader* fileReader) = 0;
	virtual BaseClusterIterator* CreateEmptyClusterIterator(BaseReader* fileReader) = 0;

	~BaseIteratorsFactory();
};

