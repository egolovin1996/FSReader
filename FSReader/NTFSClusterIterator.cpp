#include "pch.h"
#include "NTFSClusterIterator.h"

NTFSClusterIterator::NTFSClusterIterator(BaseReader* reader)
	: BaseClusterIterator(reader) 
{ 
	_CurrentClusterNumber = 0;
}

NTFSClusterIterator::~NTFSClusterIterator() { }
