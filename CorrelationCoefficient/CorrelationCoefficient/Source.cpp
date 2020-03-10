#include <iostream>
#include <random>

#define THE_NUMBER_OF_POINTS 100 

//Calculate the number of elements in array
template<typename tArray>
std::size_t getArraySize(tArray& iArray) {
	return std::extent<tArray>::value;
}

//Calculate mean value of array
template<typename tArray>
double getMean(tArray& iArray) {
	double mean;
	double sum = 0.0;

	std::size_t element = getArraySize(iArray);
	if (element == 0) {
		std::cerr << "Array size should be more than zero" << std::endl;
		return 0;
	}
	for (int i = 0; i < (int)element; i++) {
		sum += iArray[i];
	}
	mean = sum / element;

	return mean;
}

//Calculate maximum value of array
template<typename tArray>
double getMax(tArray& iArray) {
	double max;

	std::size_t element = getArraySize(iArray);
	if (element == 0) {
		std::cerr << "Array size should be more than zero" << std::endl;
		return 0;
	}

	max = iArray[0];
	for (int i = 1; i < (int)element; i++) {
		if (max < iArray[i]) {
			max = iArray[i];
		}
	}

	return max;
}

//Calculate minimum value of array
template<typename tArray>
double getMin(tArray& iArray) {
	double min;

	std::size_t element = getArraySize(iArray);
	if (element == 0) {
		std::cerr << "Array size should be more than zero" << std::endl;
		return 0;
	}

	min = iArray[0];
	for (int i = 1; i < (int)element; i++) {
		if (min > iArray[i]) {
			min = iArray[i];
		}
	}

	return min;
}

//Calculate variance of array
template<typename tArray>
double getVariance(tArray& iArray) {
	double variance;
	double sum = 0.0;
	double mean = getMean(iArray);

	std::size_t element = getArraySize(iArray);
	if (element == 0) {
		std::cerr << "Array size should be more than zero" << std::endl;
		return 0;
	}
	for (int i = 0; i < (int)element; i++) {
		sum += pow(iArray[i] - mean, 2.0);
	}
	variance = sum / element;

	return variance;
}

//Calculate standard diviation of array
template<typename tArray>
double getStandardDiviation(tArray& iArray) {
	double sd;
	double variance = getVariance(iArray);

	sd = sqrt(variance);

	return sd;
}

//Calculate covariance of arrays
template<typename tArray1, typename tArray2>
double getCovariance(tArray1& iArray1, tArray2& iArray2) {
	double covariance;
	double sum = 0.0;
	double mean1 = getMean(iArray1);
	double mean2 = getMean(iArray2);

	std::size_t element1 = getArraySize(iArray1);
	std::size_t element2 = getArraySize(iArray2);
	if (element1 == 0 ||
		element2 == 0) {
		std::cerr << "Array size should be more than zero" << std::endl;
		return 0;
	}
	if (element1 != element2) {
		std::cerr << "Array sizes should be same" << std::endl;
		return 0;
	}
	for (int i = 0; i < (int)element1; i++) {
		sum += (iArray1[i] - mean1) * (iArray2[i] - mean2);
	}
	covariance = sum / element1;

	return covariance ;
}

//Calculate correlation coefficient of arrays
template<typename tArray1, typename tArray2>
double getCorrelation(tArray1& iArray1, tArray2& iArray2) {
	double correlation;
	double deno;
	double nume;

	deno = getCovariance(iArray1, iArray2);
	nume = getStandardDiviation(iArray1) * getStandardDiviation(iArray2);
	if (nume == 0.0) {
		std::cerr << "Standard diviations of arrays should not be zero" << std::endl;
		return 0;
	}
	correlation = deno / nume;

	return correlation;
}

int main() {
	double a[THE_NUMBER_OF_POINTS] = { 0 };
	double b[THE_NUMBER_OF_POINTS] = { 0 };
	
	std::cout << "No\ta\tb" << std::endl;
	for (int i = 0; i < THE_NUMBER_OF_POINTS; i++) {
		double it = 0.1 * (double)i;
		a[i] = 2 * it + (double(rand() % 5));
		b[i] = 3 * it - (double(rand() % 5));
		std::cout << i << "\t" << a[i] << "\t" << b[i] << std::endl;
	} 
	
	std::cout << std::endl;
	std::cout << "mean_a : " << getMean(a) << std::endl << "mean_b : " << getMean(b) << std::endl;
	std::cout << "max_a : " << getMax(a) << std::endl << "max_b : " << getMax(b) << std::endl;
	std::cout << "min_a : " << getMax(a) << std::endl << "min_b : " << getMax(b) << std::endl;
	std::cout << "variance_a : " << getVariance(a) << std::endl << "variance_b : " << getVariance(b) << std::endl;
	std::cout << "sd_a : " << getStandardDiviation(a) << std::endl << "sd_b : " << getStandardDiviation(b) << std::endl;
	std::cout << "covariance : " << getCovariance(a, b) << std::endl;
	std::cout << "correlation : " << getCorrelation(a, b) << std::endl;

	return 0;
}