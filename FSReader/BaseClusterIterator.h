#pragma once
#include "BaseReader.h"

using namespace std;

class BaseClusterIterator:
{
protected:
	int _CurrentClusterNumber;
	BaseReader* _Reader;

public:
	BaseClusterIterator(BaseReader* reader);

	virtual void ShowCluster();
	virtual bool HasMore();

	~BaseClusterIterator();
};

