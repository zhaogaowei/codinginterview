#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int> > array) {
	int row = array.size();
	int col = array[0].size();
	for (int i = 0,j=col-1; i < row&&j>=0;)
	{
		if (array[i][j] == target)
			return true;
		else if (array[i][j] < target) {
			++i;
			continue;
		}
		else {
			--j;
			continue;
		}
	}
	return false;
}
int main() {
	vector<vector<int>> matrix = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	cout << Find(10, matrix);
	cin.get();
	return 0;
}