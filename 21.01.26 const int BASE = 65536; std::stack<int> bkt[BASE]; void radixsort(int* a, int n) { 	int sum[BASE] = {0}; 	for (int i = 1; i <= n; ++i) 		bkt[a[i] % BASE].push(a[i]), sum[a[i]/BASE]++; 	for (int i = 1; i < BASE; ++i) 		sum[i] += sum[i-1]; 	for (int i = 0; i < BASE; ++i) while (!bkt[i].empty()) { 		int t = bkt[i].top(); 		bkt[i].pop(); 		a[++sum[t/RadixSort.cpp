// 21.01.26
const int BASE = 65536;
std::stack<int> bkt[BASE];
void radixsort(int* a, int n) {
	int sum[BASE] = {0};
	for (int i = 1; i <= n; ++i)
		bkt[a[i] % BASE].push(a[i]), sum[a[i] / BASE]++;
	for (int i = 1; i < BASE; ++i)
		sum[i] += sum[i-1];
	for (int i = 0; i < BASE; ++i) while (!bkt[i].empty()) {
		int t = bkt[i].top();
		bkt[i].pop();
		a[++sum[t/BASE-1]] = t;
	}
}
