#include "pch.h"
#include "Cluster.h"

Cluster::Cluster(BYTE * data, int size)
{
	_data = data;
	_size = size;
}

BYTE * Cluster::GetData()
{
	return _data;
}

int Cluster::GetSize()
{
	return _size;
}

void Cluster::ShowHexData()
{
	for (int i = 1; i < _size + 1; i++) {
		printf("%02x ", _data[i - 1]);

		if (i % 16 == 0) {
			cout << endl;
		}
		else if (i % 8 == 0)
		{
			cout << "  ";
		}
	}
}

Cluster::~Cluster() { }
