#include <cstdio>
#include <iostream>

using namespace std;

void merge(int *s, int m, int k, int n)
{
	int sizeA = k - m + 1;
	int sizeB = n - k;
	int size = sizeA + sizeB;
	int *c = (int*)malloc(sizeof(int)*size);

	int ia = m;
	int ib = k + 1;
	int tmpA;
	int tmpB;
	for (int i = 0; i<size; i++)
	{
		if (ia > k) tmpA = INT_MAX;
		else tmpA = s[ia];
		if (ib > n) tmpB = INT_MAX;
		else tmpB = s[ib];

		if (tmpA <= tmpB)
		{
			c[i] = s[ia];
			ia++;
		}
		else
		{
			c[i] = s[ib];
			ib++;
		}
	}

	memcpy(s + m, c, sizeof(int)*size);
	free(c);
	return;
}

void mergeSort(int *s, int m, int n)
{
	if (m == n) return;
	int mid = (n - m) / 2 + m;
	mergeSort(s, m, mid);
	mergeSort(s, mid + 1, n);
	merge(s, m, mid, n);
	return;
}

int main(int argc, char **argv)
{
	int size = 13;
	int s[] = { 5,1,7,9,11,53,24,65,86,14,15,44,99 };

	cout << "old: ";
	for (int i = 0; i<size; i++) cout << s[i] << " ";
	cout << endl;

	mergeSort(s, 0, size - 1);

	cout << "new: ";
	for (int i = 0; i<size; i++) cout << s[i] << " ";
	cout << endl;

	getchar();
	return 1;
}