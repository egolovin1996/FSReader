#include "pch.h"
#include "IteratorsFactory.h"


IteratorsFactory::IteratorsFactory()
{
}

ClusterIterator * IteratorsFactory::GetClusterIterator(BaseReader * reader)
{
	return new ClusterIterator(reader);
}

EmptyClusterIterator * IteratorsFactory::GetEmptyClusterIterator(BaseReader * reader)
{
	// Необходимо для EmptyClusterIterator создавать отдельный ClusterIterator,
	// иначе если вызвать у ClusterIterator метод GetCluster, то счетчик изменится в обоих классах,
	// хотя возможны ситуации когда нужно будет прочитать просто кластер после пустого,
	// поэтому есть метод GetEmptyClusterIteratorWithExistingIterator
	return new EmptyClusterIterator(new ClusterIterator(reader));
}

EmptyClusterIterator * IteratorsFactory::GetEmptyClusterIteratorWithExistingIterator(ClusterIterator * iterator)
{
	return new EmptyClusterIterator(iterator);
}

IteratorsFactory::~IteratorsFactory()
{
}
