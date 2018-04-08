#include <iostream>
#include <vector>

using namespace std;

bool VerifySquenceOfBST(vector<int> sequence) {
	if (!sequence.size())
		return false;
	else if (sequence.size()<3)
		return true;
	else
	{
		bool flag = true;
		int root = sequence[sequence.size() - 1];
		int index = 0;
		for (int i = 0; i < sequence.size(); ++i)
			if (sequence[i] >= root) {
				index = i;
				break;
			}
		vector<int> left(sequence.begin(), sequence.begin() + index);
		vector<int> right(sequence.begin() + index, sequence.end()-1);
		for(int i=0;i<left.size();++i)
			if (left[i] > root) {
				flag = false;
				break;
			}
		for (int i = 0; i < right.size(); ++i)
			if (right[i] < root) {
				flag = false;
				break;
			}
		flag = flag && VerifySquenceOfBST(left);
		flag = flag && VerifySquenceOfBST(right);
		if (left.size() && right.size()) {
			flag = flag && VerifySquenceOfBST(left);
			flag = flag && VerifySquenceOfBST(right);
		}
		else if (!left.size())
			flag = flag && VerifySquenceOfBST(right);
		else
			flag = flag && VerifySquenceOfBST(left);
		return flag;
	}
}
int main() {
	vector<int> v = {};
	cout << VerifySquenceOfBST(v);
	return 0;
}