#pragma once
#include "BaseReader.h"
class FATReader :
	public BaseReader
{
public:
	FATReader(FileReader* fileReader);

	string GetFileSystemName() override;

	~FATReader();
};

