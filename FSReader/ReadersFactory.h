#pragma once

#include "BaseReader.h"

class ReadersFactory
{
public:
	static BaseReader* CreateReader(HANDLE fileHandle);

private:
	ReadersFactory();
	~ReadersFactory();
};

