#pragma once
#include <windows.h>
#include <iostream>

using namespace std;

class Cluster
{
private:
	BYTE * _data;
	int _size;
public:
	Cluster(BYTE * data, int size);

	BYTE * GetData();
	int GetSize();
	void ShowHexData();

	~Cluster();
};

