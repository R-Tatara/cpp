#include <iostream>
#include <iomanip>
#include <queue>

//One data queue
class OnedataQueue {
private:
	const unsigned int MAX_QSIZE; //Latest MAX_QSIZE items are saved
	std::queue<double> data;
public:
	OnedataQueue();
	void Store(double arg_data);
	bool Display(void);
};

OnedataQueue::OnedataQueue() :
	MAX_QSIZE(8) {
}

//Store queue
void OnedataQueue::Store(double arg_data) {
	this->data.push(arg_data);

	if (this->data.size() > this->MAX_QSIZE) {
		this->data.pop();
	}
	return;
}

//Display queue
bool OnedataQueue::Display() {
	const unsigned int CURRENT_QSIZE = this->data.size();

	if (this->data.empty() == true) {
		std::cerr << "Queue is empty" << std::endl;
		return false;
	}
	else {
		std::cout << "   data1" << std::endl;
		for (unsigned int qnum = 0; qnum < CURRENT_QSIZE; qnum++) {
			std::cout << std::setw(8) << this->data.front() << std::endl;
			this->data.pop();
		}
		return true;
	}
}

//Two data queue
class TwodataQueue {
private:
	const unsigned int MAX_QSIZE; //Latest MAX_QSIZE items are saved
	std::queue<double> data[2];
public:
	TwodataQueue();
	void Store(double arg_data1, double arg_data2);
	bool Display(void);
};

TwodataQueue::TwodataQueue() :
	MAX_QSIZE(8) {
}

//Store queue
void TwodataQueue::Store(double arg_data1, double arg_data2) {
	this->data[0].push(arg_data1);
	this->data[1].push(arg_data2);

	for (unsigned int num = 0; num < 2; num++) {
		if (this->data[num].size() > this->MAX_QSIZE) {
			this->data[num].pop();
		}
	}
	return;
}

//Display queue
bool TwodataQueue::Display() {
	const unsigned int CURRENT_QSIZE = this->data[0].size();

	if (this->data[0].size() != this->data[1].size()) {
		std::cerr << "Queue size is invalid" << std::endl;
		return false;
	}
	else if (this->data[0].empty() == true) {
		std::cerr << "Queue is empty" << std::endl;
		return false;
	}
	else {
		std::cout << "   data1" << "   data2" << std::endl;
		for (unsigned int qnum = 0; qnum < CURRENT_QSIZE; qnum++) {
			std::cout << std::setw(8) << this->data[0].front()
					  << std::setw(8) << this->data[1].front() << std::endl;
			for (unsigned int num = 0; num < 2; num++) {
				this->data[num].pop();
			}
		}
		return true;
	}
}


int main() {
	OnedataQueue q1;
	TwodataQueue q2;

	double data1[32];
	double data2[32];

	//Data storing
	for (int i = 0; i < 32; i++) {
		data1[i] = (double)i * 0.1;
		data2[i] = (double)i * 0.2;
		q1.Store(data1[i]);
		q2.Store(data1[i], data2[i]);
	}
	q1.Display();
	q2.Display();

	getchar();
	return 0;
}