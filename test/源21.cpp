#include <iostream>
#include <vector>

using namespace std;


int main() {
	int **b = new int*[2];       //����һ��ָ�����飬�����׵�ַ������b��                                                    
	for (int i = 0; i<2; i++)             //Ϊָ�������ÿ��Ԫ�ط���һ������
		b[i] = (int *)malloc(sizeof(int)*3);
	cout << b[0] << "\t" << &b[0][0];

	/*a = (int **)malloc(sizeof(int)*2*3);
	memset(a, 0, sizeof(int) * 2 * 3);
	cout << a[1][2];*/
	return 0;
}