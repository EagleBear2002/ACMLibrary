//18.07.29
template<typename Type>
struct Heap {
	const static int Root = 1;
	Type node[MAXN];
	int size;
	
	Heap(): size(0) {}
	
	void pushup(int rt){
		while(node[rt>>1] > node[rt] && rt > Root) {
			std::swap(node[rt], node[rt >>= 1]);
		}
	}
	
	void pushdown(int rt) {
		while(rt << 1 <= size) {
			int s = rt << 1;
			if(s < size && node[s+1] < node[s]) s++;
			if(node[rt] <= node[s]) return;
			std::swap(node[s], node[rt]), rt = s;
		}
	}
	
	void insert(Type key) {
		node[++size] = key, pushup(size);
	}
	
	Type top() {
		return node[Root];
	}
	
	void pop() {
		node[Root]=node[size--], pushdown(Root);
	}
	
	int search(int rt, Type key) {
		if(node[rt] > key) return 0;
		if(node[rt] == key) return rt;
		int s = rt << 1;
		if(int ans = search(s, key)) return ans;
		if(int ans = search(s+1,key)) return ans;
		return 0;
	}
	
	void erase(Type key) {
		int rt = search(Root, key);
		node[rt] = node[size], pushdown(rt);
	}
	
	void print() {
		for(int i = 1; i <= size; ++i)
			printf("node[%d] = %lld\n", i, node[i]);
	}
	
	void sort() {
		std::deque<int> tmp;
		while(size)
			tmp.push_back(top()),
			printf("%lld ", top()), pop();
		while(tmp.empty()==false)
			insert(tmp.front()), tmp.pop_front();
	}
};
