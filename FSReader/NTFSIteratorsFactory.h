#pragma once
#include "BaseIteratorsFactory.h"
#include "BaseClusterIterator.h"
#include "BaseReader.h"
#include "NTFSClusterIterator.h"

class NTFSIteratorsFactory :
	public BaseIteratorsFactory
{
public:
	NTFSIteratorsFactory();

	BaseClusterIterator* CreateClusterIterator(BaseReader* fileReader) override;
	BaseClusterIterator* CreateEmptyClusterIterator(BaseReader* fileReader) override;

	~NTFSIteratorsFactory();
};

