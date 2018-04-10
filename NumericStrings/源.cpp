#include <iostream>

using namespace std;

bool isNumeric(char* string)
{
	if (string == NULL)
		return false;
	if (*string == '+' || *string == '-')
		string++;
	int dot = 0, e = 0;
	while (*string)
	{
		if (isdigit(*string))
			string++;
		else {
			if (*string == '.' && isdigit(*(string + 1)) && e==0) {
				string += 2;
				dot++;
			}
			else if (tolower(*string) == 'e' && (isdigit(*(string + 1)) || *(string + 1) == '+' || *(string + 1) == '-')) {
				string += 2;
				e++;
			}
			else
				return false;
		}
	}
	if (dot < 2 && e < 2)
		return true;
	else
		return false;
}
int main() {
	cout << isNumeric("12e+5.4") << endl;
	return 0;
}