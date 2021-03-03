struct Node {
	int id, dist;
	Node(int id = 0, int dist = 0):
		id(id), dist(dist) {}
	bool operator < (const Node& obj) const {
		return dist > obj.dist;
	}
};

//untested
void Dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	std::priority_queue<Node> heap;
	dist[s] = 0, heap.push(Node(s, 0));
	while(!heap.empty()) {
		int u = heap.top().id;
		heap.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(Edge* edg = head[u]; edg; edg = edg->nxt) {
			int v = edg->to;
			if(dist[v] > dist[u] + edg->dist)
				dist[v] = dist[u] + edg->dist, heap.push(Node(v, dist[v]));
		}
	}
}
