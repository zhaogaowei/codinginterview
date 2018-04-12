#include <iostream>
#include <vector>

using namespace std;


int main() {
	int **b = new int*[2];       //分配一个指针数组，将其首地址保存在b中                                                    
	for (int i = 0; i<2; i++)             //为指针数组的每个元素分配一个数组
		b[i] = (int *)malloc(sizeof(int)*3);
	cout << b[0] << "\t" << &b[0][0];

	/*a = (int **)malloc(sizeof(int)*2*3);
	memset(a, 0, sizeof(int) * 2 * 3);
	cout << a[1][2];*/
	return 0;
}