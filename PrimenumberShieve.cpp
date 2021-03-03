bool vis[MAXN];
int prime[MAXN];
int cnt = 0;
void Sieve(int n) {
	for(int i = 2; i <= n; ++i) {
		if(!vis[i]) prime[++cnt] = i;
		for(int j = 1; j <= cnt && prime[j] <= n / i; ++j) {
			vis[prime[j] * i] = true;
			if(i % prime[j] == 0) break;
		}
	}
}
