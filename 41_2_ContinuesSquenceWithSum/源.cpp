#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> ans;
	if (sum <= 0)
		return ans;
	vector<int> temp;
	int begin = 1, end = begin + 1;
	while (end <= sum / 2 + 1 && begin < end) {
		int temp_sum = begin;
		for (int i = begin + 1; i <= end; i++)
			temp_sum += i;
		if (temp_sum == sum) {
			for (int i = begin; i <= end; i++)
				temp.push_back(i);
			ans.push_back(temp);
			temp.clear();
			end++;
		}
		else if (temp_sum > sum) {
			begin++;
		}
		else
		{
			end++;
		}
	}
	return ans;
}
int main() {
	vector<vector<int>> sequence = FindContinuousSequence(25);
	for (int i = 0; i < sequence.size(); ++i) {
		for (int j = 0; j < sequence[i].size(); ++j)
			cout << sequence[i][j] << " ";
		cout << endl;
	}
	return 0;
}