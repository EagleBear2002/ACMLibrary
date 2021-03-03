//18.10.16
template<typename Type>
class Splay {
private:
	struct Node {
		typedef Node* iterator;
		Type key;
		int var_size;
		iterator prt, lch, rch;
		Node(const Type key):
			key(key), var_size(1), prt(NULL), lch(NULL), rch(NULL) {}
		int size() const {return this ? var_size : 0;}
		void update() {
			if(!this) return;
			var_size = lch->size() + rch->size() + 1;
		}
	};
	typedef Node* iterator;
	iterator Root;
	
	void RotateLeft(const iterator p) {
		iterator q = p->rch;
		q->prt = p->prt;
		if(!p->prt) Root = q;
		else if(p == p->prt->lch) p->prt->lch = q;
		else p->prt->rch = q;
		
		p->rch = q->lch;
		if(p->rch) p->rch->prt = p;
		q->lch = p, p->prt = q;
		p->update(), q->update();
	}
	
	void RotateRight(const iterator p) {
		iterator q = p->lch;
		q->prt = p->prt;
		if(!p->prt) Root = q;
		else if(p == p->prt->lch) p->prt->lch = q;
		else p->prt->rch = q;
		
		p->lch = q->rch;
		if(p->lch) p->lch->prt = p;
		q->rch = p, p->prt = q;
		p->update(), q->update();
	}
	
	void Splaying(iterator p, iterator top) {
		while(p->prt != top)
			if(p->prt->prt == top)
				if(p == p->prt->lch) RotateRight(p->prt);
				else RotateLeft(p->prt);
			else
				if(p->prt == p->prt->prt->lch)
					if(p == p->prt->lch) RotateRight(p->prt->prt), RotateRight(p->prt);
					else RotateLeft(p->prt), RotateRight(p->prt);
				else
					if(p == p->prt->lch) RotateRight(p->prt), RotateLeft(p->prt);
					else RotateLeft(p->prt->prt), RotateLeft(p->prt);
	}
	
public:
	Splay() {
		Root = new Node(-INF);
		Root->rch = new Node(INF);
		Root->rch->prt = Root;
		Root->rch->update();
		Root->update();
	}
	
	void insert(const Type key) {
		int pre_rank = rank(key) - 1;
		Splaying(Kth(pre_rank), NULL);
		Splaying(Kth(pre_rank+1), Root);
		iterator p = new Node(key);
		Root->rch->lch = p, p->prt = Root->rch;
		Root->rch->update(), Root->update();
	}
	
	void erase(const Type key) {
		int rank = Splay::rank(key);
		Splaying(Kth(rank-1), NULL);
		Splaying(Kth(rank+1), Root);
		delete Root->rch->lch;
		Root->rch->lch = NULL;
		Root->rch->update();
		Root->update();
	}
	
	int rank(const Type key) {
		int rank = 1;
		iterator p = Root;
		while(p)
			if(key <= p->key) p = p->lch;
			else rank += p->lch->size()+1, p = p->rch;
		return rank;
	}
	
	iterator Kth(int rank) {
		iterator p = Root;
		while(p) {
			int cnt = p->lch->size()+1;
			if(rank < cnt) p = p->lch;
			else if(rank == cnt) return p;
			else rank -= cnt, p = p->rch;
		}
		return NULL;
	}
};
