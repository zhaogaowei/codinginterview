#include <iostream>
#include <vector>

using namespace std;

vector<int> insert_matrix(vector<int> &v1, vector<int> &v2) {
	if (v1.size() == 0 && v2.size() == 0)
		return v1;
	if (v1.size() == 0)
		return v2;
	if (v2.size() == 0)
		return v1;
	int old_len = v1.size();
	v1.resize(v1.size() + v2.size());
	int i, j,k=v1.size()-1;
	for (i=old_len-1,j=v2.size()-1;i>=0&&j>=0;)
	{
		if (v1[i] > v2[j])
			v1[k--] = v1[i--];
		else
			v1[k--] = v2[j--];
	}
	while (i>=0)
		v1[k--] = v1[i--];
	while (j >= 0)
		v1[k--] = v2[j--];
	return v1;
}
int main() {
	vector<int> v1 = { 1,2,3,4,5,6 };
	vector<int> v2 = { 3,4,5,6,7,8,9 };
	v1 = insert_matrix(v1, v2);
	for (auto num : v1)
		cout << num << " ";
	cin.get();
	return 0;
}