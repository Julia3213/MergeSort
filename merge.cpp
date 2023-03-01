#include <iostream>

using namespace std;

void merge(int* a, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int* l = new int[n1];
    int* m = new int[n2];

    for (int i = 0; i < n1; i++)
        l[i] = a[p + i];
    for (int j = 0; j < n2; j++)
        m[j] = a[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (l[i] <= m[j]) {
            a[k] = l[i];
            i++;
        }
        else {
            a[k] = m[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = m[j];
        j++;
        k++;
    }
}

void sort(int* a, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		sort(a, p, q);
		sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

int main() {
	int a[] = { 5,2,4,6,1,3,2,6 };
	sort(a, 0, (sizeof(a) / sizeof(a[0]) - 1));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		cout << a[i] << " ";
	}
	return 0;
}