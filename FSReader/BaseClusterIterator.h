#pragma once
#include "BaseReader.h"

using namespace std;

class BaseClusterIterator
{
protected:
	int _CurrentClusterNumber;
	BaseReader* _Reader;

public:
	BaseClusterIterator(BaseReader* reader);

	void ShowCluster();
	bool HasMore();

	~BaseClusterIterator();
};

