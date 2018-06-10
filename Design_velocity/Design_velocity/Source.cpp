//Designing desired velocity
#include <stdio.h>

int main() {
	int step;
	float a; //Acceleration[m/s^2]
	float v; //Velocity[m/s]
	float t = 0.0F; //Time[s]
	float T = 0.1F; //Rise time[s] / 2
	float total; //Total time[s]
	float k = 10.0F; //Slope
	float vmax; //Maximum velocity[m/s]
	float d = 0.5F; //Distance[m]

	vmax = k * T * T;
	total = d / vmax - 2 + 4 * T;

	if (total < 4 * T) {
		printf("Too close.");
		getchar();
		return -1;
	}

	while (1) {
		t += 0.01F;
		if (t >= 0 && t < T) {
			a = k * t;
			v = 0.5F * k * t * t;
			step = 1;
		}
		else if (t >= T && t < 2 * T) {
			a = -1.0F * k * (t - 2.0F * T);
			v = -0.5F * k * (t * t - 4.0F * T * t + 2.0F * T * T);
			step = 2;
		}
		else if (t >= 2.0F * T && t < total - 2.0F * T) {
			a = 0.0;
			v = k * T * T;
			step = 3;
		}
		else if (t >= total - 2 * T && t < total - T) {
			a = -1.0F * k * (t + 2 * T - total);
			v = -0.5F * k * (t * t - 2.0F * (total - 2.0F * T) * t + (total * total - 4.0F * total * T + 2.0F * T * T));
			step = 4;
		}
		else if (t >= total - T && t < total) {
			a = k * (t - total);
			v = 0.5F * k * (t * t - 2.0F * total * t + total * total);
			step = 5;
		}
		else {
			printf("------------------------------------------------------------\n");
			break;
		}
		printf("step : %d\tt : %.2f\ta : %.2f\tv : %f\n", step, t, a, v);
	}

	printf("Vmax : %f\n", vmax);
	printf("Total time : %f\n", total);
	printf("Distance : %f\n", d);

	getchar();
	return 0;
}