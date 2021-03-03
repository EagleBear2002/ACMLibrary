//18.07.13
LL sum[MAXN];
struct SegmentTreeinPointer {
	struct Node {
		int l, r;
		LL sum, lz;
		Node* lch, * rch;
	};
	typedef Node* iterator;
	iterator Root;
	
	void build(int n) {
		insert(Root,1,n);
	}
	
	void insert(iterator& rt, int l, int r) {
		rt=new Node;
		rt->l=l, rt->r=r, rt->lz=0;
		rt->sum = sum[rt->r] - sum[rt->l-1];
		rt->lch = rt->rch = NULL;
	}
 	
	void pushup(iterator rt ) {
		rt->sum = rt->lch->sum + rt->rch->sum;
	}
	
	void pushdown(iterator rt) {
		rt->lch->sum += (rt->lch->r - rt->lch->l + 1) * rt->lz;
		rt->lch->lz += rt->lz;
		rt->rch->sum += (rt->rch->r - rt->rch->l+1) * rt->lz;
		rt->rch->lz += rt->lz;
		rt->lz = 0;
	}
	
	void update(iterator rt, int l, int r, int key) {
		if(r < rt->l || rt->r < l) return;
		if(l <= rt->l && rt->r <= r) {
			rt->sum += (rt->r-rt->l + 1LL) * key, rt->lz += key;
			return;
		}
		if(rt->lch == NULL) insert(rt->lch, rt->l, (rt->l + rt->r) >> 1);
		if(rt->rch == NULL) insert(rt->rch, (rt->l + rt->r) / 2 + 1, rt->r);
		if(rt->lz) pushdown(rt);
			
		update(rt->lch,l,r,key), update(rt->rch,l,r,key), pushup(rt);
	}
	
	LL getsum(iterator rt, int l, int r) {
		if(r<rt -> l || rt->r < l) return 0;
		if(l <= rt->l && rt->r <= r) return rt->sum;
			
		if(rt->lch == NULL) insert(rt->lch, rt->l, (rt->l + rt->r) / 2);
		if(rt->rch == NULL) insert(rt->rch, (rt->l+rt->r) / 2 + 1, rt->r);
		if(rt->lz) pushdown(rt);
		LL ret = getsum(rt->lch, l, r) + getsum(rt->rch, l, r);
		return pushup(rt), ret;
	}
};

//18.07.13
int a[MAXN];
struct SegmentTreeinArray {
	struct Node {
		int l, r;
		LL sum, lz;
	};
	Node node[MAXN << 2];
	
	void Build(int rt, int l, int r) {
		node[rt].l = l, node[rt].r = r;
		if(l == r) return node[rt].sum = a[l], void();
		
		int s = rt << 1, mid = (l+r) >> 1;
		Build(s, l, mid), Build(s+1, mid+1, r);
		Pushup(rt);
	}
	
	void Pushup(int rt) {
		int s = rt << 1;
		node[rt].sum = node[s].sum + node[s+1].sum;
	}
	
	void Pushdown(int rt) {
		int s = rt << 1;
		node[s].sum += node[rt].lz * (node[s].r - node[s].l + 1);
		node[s].lz += node[rt].lz;
		node[s+1].sum += node[rt].lz * (node[s+1].r - node[s+1].l + 1);
		node[s+1].lz += node[rt].lz;
		node[rt].lz = 0;
	}
	
	void Update(int rt, int l, int r, int key) {
		if(r < node[rt].l || node[rt].r < l) return;
		if(l <= node[rt].l && node[rt].r <= r) {
			node[rt].sum += key * (node[rt].r - node[rt].l + 1);
			return node[rt].lz += key, void();
		}
		if(node[rt].lz) Pushdown(rt);
			
		int s = rt << 1;
		Update(s, l, r, key), Update(s+1, l, r, key);
		Pushup(rt);
	}
	
	LL GetSum(int rt, int l, int r) {
		if(r < node[rt].l || node[rt].r < l) return 0;
		if(l <= node[rt].l && node[rt].r <= r) return node[rt].sum;
		if(node[rt].lz) Pushdown(rt);
			
		int s = rt << 1;
		LL ret = GetSum(s, l, r) + GetSum(s+1, l, r);
		return Pushup(rt), ret;
	}
};

