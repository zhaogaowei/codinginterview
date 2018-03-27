#include <iostream>
#include <vector>

using namespace std;

void printOneCirle(vector<vector<int> > matrix, vector<int> &v, int s) {
	int end_x = matrix.size() - 1 - s;
	int end_y = matrix[0].size() - 1 - s;
	for (int i = s; i <= end_y; ++i)
		v.push_back(matrix[s][i]);
	if (end_y > s)
		for (int i = s+1; i <= end_x; ++i)
			v.push_back(matrix[i][end_y]);
	if (end_x > s&&end_y > s)
		for (int i = end_y-1; i >= s; --i)
			v.push_back(matrix[end_x][i]);
	if (end_y-1 > s&&end_x > s)
		for (int i = end_x-1; i > s; --i)
			v.push_back(matrix[i][s]);
}
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> v;
	if (matrix.empty())
		return v;
	else {
		int start = 0;
		while (start *2 < matrix[0].size() && start * 2 < matrix.size())
		{
			printOneCirle(matrix, v, start);
			start++;
		}
		return v;
	}
}
int main() {
	vector<vector<int> > matrix = {
		{1,2,3,4,5},
		/*{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}*/
	};
	vector<int> v;
	v = printMatrix(matrix);
	for (int x : v)
		cout << x << '\t';
	return 0;
}