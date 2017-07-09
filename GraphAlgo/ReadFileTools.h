#pragma once
#include "Graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ReadFileTools.h"
#include <vector>

using namespace std;

class ReadFileTools
{
public:
	ReadFileTools();
	static Graph* readFile(string fileName);
	static Graph* readFileToDg(string fileName);
	static Graph* readFileUdg(string fileName);
	static vector<int>* readFileToArray(string fileName);
	static void writeFile(vector<int>* result, string fileName);
	~ReadFileTools();
};

