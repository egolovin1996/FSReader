#pragma once
#include "BaseReader.h"
class EXFATReader :
	public BaseReader
{
public:
	EXFATReader(FileReader* fileReader);

	string GetFileSystemName() override;

	~EXFATReader();
};

