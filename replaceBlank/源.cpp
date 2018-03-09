#include <iostream>

using namespace std;

//void replaceSpace(char str[],int length) {
//	if (str == NULL)
//		return;
//	int count = 0;
//	int len = 0;
//	for (size_t i = 0; str[i]!='\0'; i++){
//		if (str[i] == ' ')
//			count++;
//		len++;
//	}
//	int new_len = len + count * 2;
//	if (new_len > length)
//		return;
//	int i = len;
//	int j = new_len;
//	while (i>=0 && j>i)
//	{
//		cout << i << " " << j;
//		if (str[i] == ' ') {
//			str[j--] = '0';
//			str[j--] = '2';
//			str[j--] = '%';
//		}
//		else
//		{
//			cout << str[i] << endl;
//			str[j--] = str[i];
//		}
//		i--;
//	}
//}
void replaceSpace(char *str, int length) {
	if (str == NULL)
		return;
	int CountOfBlanks = 0;
	int Originallength = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		Originallength++;
		if (str[i] == ' ')
			++CountOfBlanks;
	}
	int len = Originallength + 2 * CountOfBlanks;
	if (len + 1>length)
		return;

	char*pStr1 = str + Originallength;//¸´ÖÆ½áÊø·û¡®\0¡¯
	char*pStr2 = str + len;
	while (pStr1<pStr2)
	{
		if (*pStr1 == ' ')
		{
			*pStr2-- = '0';
			*pStr2-- = '2';
			*pStr2-- = '%';
		}
		else
		{
			*pStr2-- = *pStr1;
		}
		--pStr1;
	}
}
int main() {
	char* s = "we are happy.";
	replaceSpace(s,30);
	cout << s;
	cin.get();
	return 0;
}