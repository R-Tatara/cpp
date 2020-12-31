#include <iostream>
#include <iomanip>
#include <queue>


//1 data queue
class OnedataQueue {
private:
	const unsigned int MAX_QSIZE;
	unsigned int qsize;
	std::queue<double> data;
public:
	OnedataQueue();
	void Get(double arg_data);
	bool Disp(void);
};

OnedataQueue::OnedataQueue() :
	MAX_QSIZE(8) {
}

//Queue storing
void OnedataQueue::Get(double arg_data) {
	this->data.push(arg_data);

	if (this->data.size() > this->MAX_QSIZE) {
		this->data.pop();
	}
	return;
}

//Displaying queue
bool OnedataQueue::Disp() {
	if (this->data.empty() == true) {
		std::cerr << "Queue is empty" << std::endl;
		return false;
	}
	else {
		std::cout << "   data1" << std::endl;
		this->qsize = this->data.size();
		for (unsigned int qnum = 0; qnum < this->qsize; qnum++) {
			std::cout << std::setw(8) << this->data.front() << std::endl;
			this->data.pop();
		}
		return true;
	}
}

//2 data queue
class TwodataQueue {
private:
	const unsigned int MAX_QSIZE;
	unsigned int qsize;
	std::queue<double> data[2];
public:
	TwodataQueue();
	void Get(double arg_data1, double arg_data2);
	bool Disp(void);
};

TwodataQueue::TwodataQueue() :
	MAX_QSIZE(8) {
}

//Queue storing
void TwodataQueue::Get(double arg_data1, double arg_data2) {
	this->data[0].push(arg_data1);
	this->data[1].push(arg_data2);

	for (unsigned int num = 0; num < 2; num++) {
		if (this->data[num].size() > this->MAX_QSIZE) {
			this->data[num].pop();
		}
	}
	return;
}

//Displaying queue
bool TwodataQueue::Disp() {
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
		this->qsize = this->data[0].size();
		for (unsigned int qnum = 0; qnum < this->qsize; qnum++) {
			std::cout << std::setw(8) << this->data[0].front()
				<< std::setw(8) << this->data[1].front() << std::endl;
			for (unsigned int num = 0; num < 2; num++) {
				this->data[num].pop();
			}
		}
		return true;
	}
}

OnedataQueue q1;
TwodataQueue q2;

int main() {
	double data1[32];
	double data2[32];

	//Data storing
	for (int i = 0; i < 32; i++) {
		data1[i] = (double)i * 0.1;
		data2[i] = (double)i * 0.2;
		q1.Get(data1[i]);
		q2.Get(data1[i], data2[i]);
	}
	q1.Disp();
	q2.Disp();

	getchar();
	return 0;
}