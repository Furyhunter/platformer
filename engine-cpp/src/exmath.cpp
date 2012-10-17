#include "exmath.h"

int round(double value) {
	return (value >= 0) ? (int)(value + 0.5) : (int)(value - 0.5);
}