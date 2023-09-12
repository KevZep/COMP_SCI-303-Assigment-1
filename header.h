#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void getMatrix(ifstream &inFile, vector<vector<int>> &v1, int size1, int size2);
void printMatrix(vector<vector<int>> &v1, int size1, int size2);
void checkInd(vector<vector<int>> &v1, int indexC, int size1, int size2);
void changeInd(vector<vector<int>> &v1, int indexC, int size1, int size2, int &tempNum);
void addToArr(vector<vector<int>> &v1, int indexC, int newNum);
void subToArr(vector<vector<int>> &v1, int indexC,int size2);
void transForm(vector<vector<int>> &v1,int indexC, int &size1, int &size2);