// 21.01.25
void quicksort(int* a, int l, int r) {
	if (l >= r) return;
	int i = l, j = r, p = a[l];
	while (i < j) {
		while (a[j] >= p && i < j) --j;
		while (a[i] <= p && i < j) ++i;
		if (i < j) a[i] ^= a[j], a[j] ^= a[i], a[i] ^= a[j];
	}
	a[l] = a[i], a[i] = p;
	quicksort(a, l, i-1);
	quicksort(a, i+1, r);
}
