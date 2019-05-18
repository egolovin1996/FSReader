#pragma once
#include "BaseClusterIterator.h"
#include "BaseReader.h"

class NTFSClusterIterator :
	public BaseClusterIterator
{
public:
	NTFSClusterIterator(BaseReader* reader);
	~NTFSClusterIterator();
};