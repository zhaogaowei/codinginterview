#include <iostream>
#include <vector>

using namespace std;
inline bool fun(int n) {
	return (n & 1) == 0;
}
void reOrderArray(vector<int> &arr,bool (*fun)(int));

int main() {
	vector<int> v = { 1,2,3,4,5 };
	reOrderArray(v, fun);
	for (int n : v)
		cout << n << "\t";
	return 0;
}

void reOrderArray(vector<int> &arr, bool(*fun)(int)) {
	if (!arr.size())
		return;
	int *pBegin, *pEnd;
	pBegin = &arr[0];
	pEnd = &arr[arr.size() - 1];
	while (pBegin<pEnd)
	{
		while (pBegin < pEnd && !fun(*pBegin))
			pBegin++;
		while (pBegin < pEnd&&fun(*pEnd))
			pEnd--;
		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}