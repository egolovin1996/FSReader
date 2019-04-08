#pragma once

#include "BaseReader.h"
#include "FileReader.h"

class ReadersFactory
{
public:
	static BaseReader* CreateReader(FileReader* fileReader);

private:
	ReadersFactory();
	~ReadersFactory();
};

