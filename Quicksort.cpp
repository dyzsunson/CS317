#include <cstdio>
#include <iostream>

using namespace std;

void partition(int *s, int m, int n, int &ip)
{
	int v = s[m];
	int i = m;
	int j = n + 1;

	while (true)
	{
		while (s[i + 1] <= v && i + 1 != j) i++;
		while (s[j - 1]>v && i + 1 != j) j--;

		if (i + 1 == j)
		{
			s[m] = s[i];
			s[i] = v;
			ip = i;
			break;
		}
		else
		{
			int tmp = s[i + 1];
			s[i + 1] = s[j - 1];
			s[j - 1] = tmp;
			i++;
			j--;
		}
	}

}

void quickSort(int *s, int m, int n)
{
	if (m >= n) return;
	int ip;
	partition(s, m, n, ip);
	quickSort(s, m, ip - 1);
	quickSort(s, ip + 1, n);
}
int main(int argc, char **argv)
{
	int size = 13;
	int s[] = { 5, 1, 7, 9, 11, 53, 24, 65, 86, 14, 15, 44, 99 };

	cout << "old: ";
	for (int i = 0; i<size; i++)
		cout << s[i] << " ";
		cout << endl;

		quickSort(s, 0, size - 1);

	cout << "new: ";
	for (int i = 0; i<size; i++)
		cout << s[i] << " ";
		cout << endl;

		getchar();
	return 1;
}