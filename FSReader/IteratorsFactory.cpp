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
	// ���������� ��� EmptyClusterIterator ��������� ��������� ClusterIterator,
	// ����� ���� ������� � ClusterIterator ����� GetCluster, �� ������� ��������� � ����� �������,
	// ���� �������� �������� ����� ����� ����� ��������� ������ ������� ����� �������,
	// ������� ���� ����� GetEmptyClusterIteratorWithExistingIterator
	return new EmptyClusterIterator(new ClusterIterator(reader));
}

EmptyClusterIterator * IteratorsFactory::GetEmptyClusterIteratorWithExistingIterator(ClusterIterator * iterator)
{
	return new EmptyClusterIterator(iterator);
}

IteratorsFactory::~IteratorsFactory()
{
}
