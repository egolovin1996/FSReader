#pragma once

#include "BaseReader.h"
#include "FileReader.h"

class ReadersCreator
{
public:
	static BaseReader* CreateReader(FileReader* fileReader);

private:
	ReadersCreator();
	~ReadersCreator();
};

