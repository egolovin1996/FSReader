#include "pch.h" 
#include <string> 
#include <iostream> 
#include <windows.h> 
#include "ReadersCreator.h"
#include "BaseReader.h"
#include "FileReader.h"
#include "BaseClusterIterator.h"
#include "NTFSClusterIterator.h"

using namespace std;

int main(int argc, char** argv)
{
	string fileName = "";
	if (argc == 2) {
		fileName = argv[1];
	}
	else {
		cout << "Enter file name:" << endl;
		getline(cin, fileName);
	}

	FileReader *fileReader = NULL;
	BaseReader *reader = NULL;
	BaseClusterIterator *clusterIterator = NULL;

	try {
		fileReader = new FileReader(fileName);
		reader = ReadersCreator::CreateReader(fileReader);
		reader->ShowInfo();

		cout << "Enter cluster number" << endl;
		int clusterNumber;
		cin >> clusterNumber;
		reader->ShowClusterByNumber(clusterNumber);

		clusterIterator = new NTFSClusterIterator(reader);
		clusterIterator->ShowCluster();
		clusterIterator->ShowCluster();
	}
	catch (runtime_error e) {
		cout << "Error: " << e.what() << endl;
	}

	delete reader;
	delete fileReader;
}