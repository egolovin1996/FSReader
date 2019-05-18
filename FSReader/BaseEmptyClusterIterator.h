#pragma once
#include "BaseClusterIterator.h"
class BaseEmptyClusterIterator :
	public BaseClusterIterator
{
public:
	BaseEmptyClusterIterator();

	void ShowCluster() override;
	bool HasMore() override;

	~BaseEmptyClusterIterator();
};

