#include <iostream>
using namespace std;


class Pulse {
private:
    bool buff;
    bool ret;
public:
    Pulse();
    bool IsFall(bool arg_data);
    bool IsRise(bool arg_data);
    void Update(bool arg_data);
};

Pulse::Pulse() :
    buff(false),
    ret(false)
{
}

//Falling edge detection
bool Pulse::IsFall(bool arg_data) {
    if (arg_data == false && this->buff == true) {
        this->ret = true;
    }
    else {
        this->ret = false;
    }
    return this->ret;
}

//Rising edge detection
bool Pulse::IsRise(bool arg_data) {
    if (arg_data == true && this->buff == false) {
        this->ret = true;
    }
    else {
        this->ret = false;
    }
    return this->ret;
}

//Update pulse buffer
void Pulse::Update(bool arg_data) {
    this->buff = arg_data;
    return;
}

Pulse pulse;


int main() {
    int data[30];
    bool pulse_data[30] = { 0,0,0,0,0,1,0,0,0,1,
                            0,0,0,0,0,0,1,0,0,1,
                            1,1,0,0,0,0,0,0,0,0 };

    //Data storing
    for (int i = 0; i < 30; i++) {
        data[i] = i;
        if (pulse.IsFall(pulse_data[i]) == true) {
            cout << "Fall edge : " << data[i] << endl;
        }
        if (pulse.IsRise(pulse_data[i]) == true) {
            cout << "Rise edge : " << data[i] << endl;
        }
        pulse.Update(pulse_data[i]);
    }

    getchar();
    return 0;
}