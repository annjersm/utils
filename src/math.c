#include <math.h>

float sigmoid(float x)
{
	return 1.0 / (1.0 + expf(-x));
}
