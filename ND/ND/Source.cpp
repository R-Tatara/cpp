#include <random>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define ARRAY_SIZE 51
#define DATA_COUNT 100000

int main() {
	default_random_engine generator;
	normal_distribution<double> distribution;

	int weight[ARRAY_SIZE] = { 0 };
	double val[DATA_COUNT];
	double delta = 0.1;
	double xlim = -2.5;
	double sum = 0.0;
	double mean;
	double sd;

	cout << "Normal distribution" << endl;

	for (int i = 0; i < DATA_COUNT; i++) {
		val[i] = distribution(generator);
		sum += val[i];

		for (int j = 0; j < ARRAY_SIZE; j++) {
			if (xlim + (double)j * delta <= val[i] && val[i] < xlim + (double)(j + 1) * delta) {
				weight[j] += 1;
			}
		}
	}

	for (int j = 0; j < ARRAY_SIZE; j++) {
		cout << showpos << fixed << setprecision(1) << endl;
		cout << xlim + (double)j * delta << " - " << xlim + (double)(j + 1) * delta << " : ";
		for (int k = 0; k < weight[j] / (double)(DATA_COUNT) * 1000.0; k++) {
			cout << "*";
		}
	}
	cout << endl << endl << "--------------------" << endl;

	mean = sum / (double)DATA_COUNT;
	sum = 0.0;
	for (int i = 0; i < DATA_COUNT; i++) {
		sum += (val[i] - mean) * (val[i] - mean);
	}
	sd = sqrt(sum / DATA_COUNT);
	cout << setprecision(6);
	cout << "Mean : " << mean << endl;
	cout << "SD  :  " << sd << endl;

	getchar();
	return 0;
}