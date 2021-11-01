// https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat){
	vector<int> tempArray;
	for (vector<int> array: Mat)
		for (int value: array)
			tempArray.push_back(value);

	sort(tempArray.begin(), tempArray.end());

	int k = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Mat[i][j] = tempArray[k++];

	return Mat;
}

int main(){
	vector<vector<int>> matrix = {
		{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 48},
		{32, 33, 39, 50}
	};
	int N = 4;
		
		vector<vector<int>> sortMatrix = sortedMatrix(N, matrix) ;

		for (vector<int> array: sortMatrix){
			for (int i: array)
				cout << i << " ";
			cout << endl;
		}

	return 0;
}
