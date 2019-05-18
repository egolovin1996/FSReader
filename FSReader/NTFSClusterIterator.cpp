#include "pch.h"
#include "NTFSClusterIterator.h"
#include "BaseClusterIterator.h"

NTFSClusterIterator::NTFSClusterIterator(BaseReader* reader) 
	: BaseClusterIterator(reader) 
{ 
	_CurrentClusterNumber = 0;
}

NTFSClusterIterator::~NTFSClusterIterator() { }
