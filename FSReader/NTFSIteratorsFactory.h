#pragma once
#include "BaseIteratorsFactory.h"
#include "BaseClusterIterator.h"

class NTFSIteratorsFactory :
	public BaseIteratorsFactory
{
public:
	NTFSIteratorsFactory();

	BaseClusterIterator* CreateClusterIterator(BaseReader* fileReader);
	BaseClusterIterator* CreateEmptyClusterIterator(BaseReader* fileReader);

	~NTFSIteratorsFactory();
};

