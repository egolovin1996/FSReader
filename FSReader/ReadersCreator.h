#pragma once

#include "BaseReader.h"
#include "FileReader.h"
#include "NTFSReader.h"
#include "FATReader.h"
#include "EXFATReader.h"

class ReadersCreator
{
public:
	static BaseReader* CreateReader(FileReader* fileReader);

private:
	ReadersCreator();
	~ReadersCreator();
};

