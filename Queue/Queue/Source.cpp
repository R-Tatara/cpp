#include <iostream>
#include <queue>
using namespace std;

class Queue {
private:
    const unsigned int max_qsize;
    unsigned int qsize;
    queue<double> data;
public:
    Queue();
    void Get(double arg_data);
    void Disp(void);
};

Queue::Queue() :
    max_qsize(8)
{
}

//Queue processing
void Queue::Get(double arg_data) {
    this->data.push(arg_data);
    if (this->data.size() > this->max_qsize) {
        this->data.pop();
    }

    return;
}

//Displaying queue
void Queue::Disp() {
    if (this->data.empty() == true) {
        cout << "Queue is empty" << endl;
    }
    else {
        this->qsize = this->data.size();
        for (unsigned int i = 0; i < this->qsize; i++) {
            cout << this->data.front() << endl;
            this->data.pop();
        }
    }

    return;
}

Queue q;

int main() {
    double data[32];

    //Data storing
    for (int i = 0; i < 32; i++) {
        data[i] = (double)i * 0.1;
        q.Get(data[i]);
    }
    q.Disp();

    getchar();
    return 0;
}