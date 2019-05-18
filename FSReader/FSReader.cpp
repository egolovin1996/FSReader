#include "pch.h" 
#include <string> 
#include <iostream> 
#include <windows.h> 
#include "ReadersCreator.h"
#include "BaseReader.h"
#include "FileReader.h"
#include "Cluster.h"
#include "ClusterIterator.h"
#include "IteratorsFactory.h"

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
	ClusterIterator *clusterIterator = NULL;
	ClusterIterator *emptyClusterIterator = NULL;

	try {
		fileReader = new FileReader(fileName);
		reader = ReadersCreator::CreateReader(fileReader);
		reader->ShowInfo();

		// Чтение кластеров по номеру
		//cout << "Enter cluster number" << endl;
		//int clusterNumber;
		//cin >> clusterNumber;
		//reader->GetClusterByNumber(clusterNumber);

		cout << "Read first cluster" << endl;
		clusterIterator = IteratorsFactory::GetClusterIterator(reader);
		if (clusterIterator->HasMore()) {
			Cluster* cluster = clusterIterator->GetCluster();
			cluster->ShowHexData();
		}

		cout << "Read first empty cluster" << endl;
		emptyClusterIterator = IteratorsFactory::GetEmptyClusterIterator(reader);
		if (emptyClusterIterator->HasMore()) {
			Cluster* emptyCluster = emptyClusterIterator->GetCluster();
			emptyCluster->ShowHexData();
		}
	}
	catch (runtime_error e) {
		cout << "Error: " << e.what() << endl;
	}

	delete reader;
	delete fileReader;
	delete clusterIterator;
}