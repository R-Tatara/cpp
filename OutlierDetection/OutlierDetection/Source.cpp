#include <iostream>
#define NUM_DATA 128
using namespace std;

int main() {
	double data_sample[NUM_DATA] = {0};
	double diff[NUM_DATA - 1];
	double mean;
	double sd;
	double sum = 0.0;
	double sum2 = 0.0;
	double test_data = 1.0;

	//Sample data
	for (int i = 1; i < NUM_DATA; i++) {
		data_sample[i] = sin((double)i * 0.1);
		diff[i - 1] = data_sample[i] - data_sample[i - 1];
		cout << diff[i - 1] << endl;
	}

	//Calculate standard diviation
	for (int i = 0; i < NUM_DATA; i++) {
		sum += data_sample[i];
		sum2 += data_sample[i] * data_sample[i];
	}
	mean = sum / NUM_DATA;
	sd = sqrt(sum2 / NUM_DATA - mean * mean);
	cout << "sd : " << sd << endl;
	cout << "Diff : " << test_data - data_sample[NUM_DATA - 1] << endl;

	//Outlier detection
	if (abs(test_data - data_sample[NUM_DATA - 1]) > 3 * sd) {
		cout << "Outlier is detected" << endl;
	}
	else {
		cout << "Not outlier" << endl;
	}

	return 0;
}