class BinaryIndexTree {
	typedef long long LL;
private:
	LL s[MAXN];
	inline int lowbit(int x) {
		return x & -x;
	}
	
public:
	int n;
	void insert(int pos, int key) {
		for(int i = pos; i <= n; i += lowbit(i))
			s[i] += key;
	}
	
	LL getsum(int pos) {
		LL ans = 0;
		for(int i = pos; i; i -= lowbit(i))
			ans += s[i];
		return ans;
	}
	
	LL getsum(int l, int r) {
		return getsum(r) - getsum(l-1);
	}
	
	BinaryIndexTree(int n): n(n){
		memset(s, 0, sizeof s);
	} 
};
