#include "pch.h" 
#include <string> 
#include <iostream> 
#include <windows.h> 

#include "ReadersFactory.h"
#include "BaseReader.h"

using namespace std;

int main(int argc, char** argv)
{
	string fileName = "\\\\.\\D:";
	/*if (argc == 2) {
	fileName = argv[1];
	}
	else {
	cout << "Enter file name:" >> endl;
	getline(cin, fileName);
	}*/

	wstring wFileName(fileName.begin(), fileName.end());
	HANDLE fileHandle = CreateFileW(wFileName.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (fileHandle == INVALID_HANDLE_VALUE)
	{
		cout << "Error reading file";
		return 1;
	}
	
	BaseReader* reader = ReadersFactory::CreateReader(fileHandle);
	reader->ShowInfo();

	cout << "Enter cluster number"<< endl;
	int clusterNumber;
	cin >> clusterNumber;

	cout << "Cluster content: " << endl;
	reader->ShowClusterByNumber(clusterNumber);
	

	CloseHandle(fileHandle);
}