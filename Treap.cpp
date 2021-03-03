//18.10.09
template<typename Type>
class Treap {
private:
	struct Node {
	typedef Node* iterator;
		Type key;
		int var_val, var_size;
		iterator lch, rch;
		Node(Type key):	key(key), var_val(rand()), var_size(1), lch(NULL), rch(NULL) {}
		int size() const {return this ? var_size : 0;}
		int val() const {return this ? var_val : 0;}
		void update() {var_size = lch->size() + rch->size() + 1;}
	};
	typedef Node* iterator;
	iterator Root;
	
	void RotateRight(iterator& p) {
		iterator q = p->lch;
		p->lch = q->rch, q->rch = p, p = q;
		p->rch->update(), p->update();
	}
	
	void RotateLeft(iterator& p) {
		iterator q = p->rch;
		p->rch = q->lch, q->lch = p, p = q;
		p->lch->update(), p->update();
	}
	
	void insert(iterator& p, const Type key) {//mine
		if(!p) return p = new Node(key), void();
		if(key <= p->key) {
			insert(p->lch, key);
			if(p->lch->val() > p->val())
				RotateRight(p);
		}
		else {
			insert(p->rch, key);
			if(p->rch->val() > p->val())
				RotateLeft(p);
		}
		p->update();
	}
	
	void erase(iterator& p, Type key) {
		if(key == p->key) {
			if(!p->lch && !p->rch)
				return p = NULL, void();
			if(!p->rch || p->lch->val() > p->rch->val())
				RotateRight(p), erase(p->rch, key);
			else RotateLeft(p), erase(p->lch, key);
		}
		else if(key < p->key) erase(p->lch, key);
		else erase(p->rch, key);
		p->update();
	}
	
public:
	void insert(int key) {insert(Root, key);}
	void erase(int key) {erase(Root, key);}
	
	int rank(const Type key) const {
		int rank = 1;
		iterator p = Root;
		while(p)
			if(key <= p->key) p = p->lch;
			else rank += p->lch->size()+1, p = p->rch;
		return rank;
	}
	
	iterator Kth(int rank) const {
		iterator p = Root;
		while(p){
			int cnt = p->lch->size()+1;
			if(rank<cnt) p=p->lch;
			else if(rank==cnt) return p;
			else rank -= cnt, p = p->rch;
		}
		return NULL;
	}
	
	int getpre(int key) {return Kth(rank(key)-1)->key;}
	int getsuf(int key) {return Kth(rank(key+1))->key;}
	Treap() {Root = NULL;}
};
