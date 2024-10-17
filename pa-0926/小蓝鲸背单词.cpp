#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* num = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < n; i++)
	{
		int j;
		for ( j = i + 1; j < n; j++)
		{
			if (num[j] > num[i])
			{
				break;
			}
		}
		if (j == n && num[j] <= num[i])
		{
			cout << 0 << " ";
		}
		else
		{
			cout << j - i << " ";
		}
	}
	return 0;
}