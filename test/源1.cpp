#include<iostream>  
#include<algorithm>  
#include<cmath>  
using namespace std;
struct point
{
	double x, y;
} a[4];
bool cmp(point a, point b)
{
	if (a.x != b.x)
		return a.x>b.x;
	return a.y<b.y;
}
int main()
{
	int t, k;
	double s1, s2, s3, s4;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 4; i++)
			cin >> a[i].x;
		for (int i = 0; i < 4; i++)
			cin >> a[i].y;
		sort(a, a + 4, cmp);
		s1 = sqrt((a[0].x - a[2].x)*(a[0].x - a[2].x) + (a[0].y - a[2].y)*(a[0].y - a[2].y));
		s2 = sqrt((a[0].x - a[1].x)*(a[0].x - a[1].x) + (a[0].y - a[1].y)*(a[0].y - a[1].y));
		s3 = sqrt((a[3].x - a[1].x)*(a[3].x - a[1].x) + (a[3].y - a[1].y)*(a[3].y - a[1].y));
		s4 = sqrt((a[2].x - a[3].x)*(a[2].x - a[3].x) + (a[2].y - a[3].y)*(a[2].y - a[3].y));
		k = (a[0].x - a[2].x)*(a[0].x - a[1].x) + (a[0].y - a[1].y)*(a[0].y - a[2].y);
		if (s1 == s2&&s3 == s4&&s1 == s2&&s1 != 0 && fabs(k)<0.00001)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}