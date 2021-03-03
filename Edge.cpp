struct Edge {
	int from, to, dist;
	Edge* nxt;
	Edge(int from = 0, int to = 0, int dist = 0, Edge* nxt = NULL):
		from(from), to(to), dist(dist), nxt(nxt) {}
	inline bool operator < (const Edge obj) const {
		return dist < obj.dist;
	}
};
Edge* head[MAXN];
