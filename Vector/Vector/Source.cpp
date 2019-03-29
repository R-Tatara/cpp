#include <iostream>
#include <vector>

#define NUMBER_1 5
#define NUMBER_2 3

using namespace std;

int main() {
	//Initialization of elements
	vector<double> data1{ 1.1, 1.2, 1.3, 1.4, 1.5 };

	//Generate dynamic array from original data
	double val[NUMBER_1] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
	vector<double> data2(val, end(val));

	//Copy constructor
	vector<double> data3;
	data3 = data2;
	//vector<double> data3(data2); //Same

	//Two dimensional array
	vector<vector<double>> data4{ { 2.1, 2.2, 2.3 },{ 2.4, 2.5, 2.6 },{ 2.7, 2.8, 2.9 } }; //3*3 matrix

																						   //Operation
																						   //data1.push_back(1.6); //Add data
																						   //data2.insert(data2.begin() + 3, 10.0); //Insert data
																						   //data3.pop_back(); //Delite the last element
																						   //data3.erase(data3.begin() + 1); //Delite element

	cout << "data1 : ";
	for (int i = 0; i < NUMBER_1; i++) {
		cout << data1[i] << "\t";
	}
	cout << endl << "data2 : ";
	for (int i = 0; i < NUMBER_1; i++) {
		cout << data2[i] << "\t";
	}
	cout << endl << "data3 : ";
	for (int i = 0; i < NUMBER_1; i++) {
		cout << data3[i] << "\t";
	}
	cout << endl << "data4 : ";
	for (int i = 0; i < NUMBER_2; i++) {
		for (int j = 0; j < NUMBER_2; j++) {
			cout << data4[i][j] << "\t";
		}
		cout << endl << "        ";
	}

	getchar();
	return 0;
}