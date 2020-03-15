#include <iostream>
#include <random>
#include "statistics.h"
using namespace std;

#define THE_NUMBER_OF_POINTS 100 

int main() {
	double a[THE_NUMBER_OF_POINTS] = { 0 };
	double b[THE_NUMBER_OF_POINTS] = { 0 };
	
	//Sample data
	cout << "---Sample data---" << endl;
	cout << "No\ta\tb" << endl;
	for (int i = 0; i < THE_NUMBER_OF_POINTS; i++) {
		double it = 0.1 * (double)i;
		a[i] = 2 * it + (double(rand() % 5));
		b[i] = 3 * it - (double(rand() % 5));
		cout << i << "\t" << a[i] << "\t" << b[i] << endl;
	} 

	//Fundamental statistics
	cout << endl << "---Fundamental statistics---" << endl;
	cout << "mean_a : "					<< getMean(a)				<< endl
		 << "mean_b : "					<< getMean(b)				<< endl
		 << "max_a : "					<< getMax(a)				<< endl
		 << "max_b : "					<< getMax(b)				<< endl
		 << "min_a : "					<< getMin(a)				<< endl
		 << "min_b : "					<< getMin(b)				<< endl
		 << "variance_a : "				<< getVariance(a)			<< endl
		 << "variance_b : "				<< getVariance(b)			<< endl
		 << "standard_diviation_a : "	<< getStandardDiviation(a)	<< endl
		 << "standard_diviation_b : "	<< getStandardDiviation(b)	<< endl
		 << "covariance : "				<< getCovariance(a, b)		<< endl
		 << "correlation : "			<< getCorrelation(a, b)		<< endl;

	return 0;
}