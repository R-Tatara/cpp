#include <iostream>
#include <iomanip>
#include <queue>

const unsigned int NUMBER_OF_QUEUE = 2;

//Multi-data queue
class Queue {
private:
	const unsigned int MAX_QSIZE;
	std::queue<double> data[NUMBER_OF_QUEUE];
public:
	Queue();
	void Push(double arg_data1, double arg_data2);
	bool Print(void);
};

Queue::Queue() :
	MAX_QSIZE(8) {
}

//Queue storing
void Queue::Push(double arg_data1, double arg_data2) {
	this->data[0].push(arg_data1);
	this->data[1].push(arg_data2);

	for (unsigned int i = 0; i < NUMBER_OF_QUEUE; i++) {
		if (this->data[i].size() > this->MAX_QSIZE) {
			this->data[i].pop();
		}
	}
	return;
}

//Displaying queue
bool Queue::Print() {
	for (int i = 0; i < NUMBER_OF_QUEUE - 1; i++) {
		if (this->data[i].size() != this->data[i + 1].size()) {
			std::cerr << "Queue size is invalid" << std::endl;
			return false;
		}
	}

	if (this->data[0].empty() == true) {
		std::cerr << "Queue is empty" << std::endl;
		return false;
	}

	std::cout << "   data1" << "   data2" << std::endl;
	for (unsigned int qnum = 0; qnum < this->data[0].size(); qnum++) {
		std::cout << std::setw(8) << this->data[0].front()
				<< std::setw(8) << this->data[1].front() << std::endl;
		for (unsigned int num = 0; num < 2; num++) {
			this->data[num].pop();
		}
	}
	return true;
}

Queue q;

int main() {
	double data1[32];
	double data2[32];

	//Data storing
	for (int i = 0; i < 32; i++) {
		data1[i] = (double)i * 0.1;
		data2[i] = (double)i * 0.2;
		q.Push(data1[i], data2[i]);
	}
	q.Print();

	getchar();
	return 0;
}