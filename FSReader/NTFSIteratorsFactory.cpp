#include "pch.h"
#include "NTFSIteratorsFactory.h"


NTFSIteratorsFactory::NTFSIteratorsFactory()
{
}

BaseClusterIterator * NTFSIteratorsFactory::CreateClusterIterator(BaseReader * fileReader)
{
	return nullptr;
}

BaseClusterIterator * NTFSIteratorsFactory::CreateEmptyClusterIterator(BaseReader * fileReader)
{
	return nullptr;
}


NTFSIteratorsFactory::~NTFSIteratorsFactory()
{
}
