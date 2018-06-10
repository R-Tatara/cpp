#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950288F
#define CHANNEL_NUMBER 8
#define CUTOFF_FREQUENCY 10.0F
#define SAMPLING_TIME 0.005F //check

float LowpassFilter(float vin, int i); //i : Channel number

class IIR {
public:
	const float fc; //Cutoff frequency
	const float Q;  //Quality factor
	float ts;       //Sampling time
	float fs;       //Sampling frequency
	float buf1[CHANNEL_NUMBER];
	float buf2[CHANNEL_NUMBER];
	float w0;
	float a;
	float b0;
	float b1;
	float b2;
	float a1;
	float a2;
	void setIIRparam(void);
	IIR();
};

void IIR::setIIRparam() {
	//this->ts = tim.sampling;
	this->fs = 1 / this->ts;
	this->w0 = tanf(PI * this->fc / this->fs);
	this->a = sinf(this->w0) / this->Q;
	this->b0 = (1.0F - cosf(this->w0)) / (2.0F * (1.0F + this->a));
	this->b1 = (1.0F - cosf(this->w0)) / (1.0F + this->a);
	this->b2 = (1.0F - cosf(this->w0)) / (2.0F * (1.0F + this->a));
	this->a1 = (2.0F * cosf(this->w0)) / (1.0F + this->a);
	this->a2 = (this->a - 1.0F) / (this->a + 1.0F);
}

IIR::IIR()
	:fc(CUTOFF_FREQUENCY), //must be less than fs/2
	Q(sqrt(2.0F) / 2.0F),
	ts(SAMPLING_TIME)
{
}

IIR iir;

int main() {
	int cycle = 0;
	int cycle_change = 100;
	int cycle_end = 200;
	float time = 0.0F;
	float v_in;
	float v_out;

	while (1) {
		if (cycle < cycle_change) {
			v_in = 0.0F;
		}
		else if (cycle >= cycle_change && cycle < cycle_end) {
			v_in = 1.0F;
		}
		else if (cycle >= cycle_end) {
			break;
		}
		else if (cycle >= cycle_end) {
			break;
		}

		v_out = LowpassFilter(v_in, 0);
		printf("cycle : %d\ttime : %.2f\tbefore : %f\tafter : %f\n", cycle, time, v_in, v_out);

		cycle++;
		time += SAMPLING_TIME;
	}

	getchar();
	return 0;
}

//IIR lowpass filter
float LowpassFilter(float vin, int i) {
	float reg;
	float vout;

	iir.setIIRparam();
	reg = vin + iir.a1 * iir.buf1[i] + iir.a2 * iir.buf2[i];
	vout = iir.b0 * reg + iir.b1 * iir.buf1[i] + iir.b2 * iir.buf2[i];
	iir.buf2[i] = iir.buf1[i];
	iir.buf1[i] = reg;
	return vout;
}