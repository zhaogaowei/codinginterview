#include <iostream>

using namespace std;

double Power(double base, int exponent) {
	if (base == 0.0 && exponent < 0)
		return 0.0;
	double abs = 1.0;
	int exp = exponent >= 0 ? exponent : (-1 * exponent);
	for (size_t i = 0; i < exp; i++)
	{
		abs *= base;
	}
	return exponent >= 0 ? abs : 1 / abs;
}

int main() {
	cout << Power(2, -3) << endl;
	return 0;
}