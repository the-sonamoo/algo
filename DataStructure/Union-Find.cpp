int find_parent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find_parent(parent[a]);
}

void merge(int a , int b) {
	parent[find_parent(b)] = find_parent(a);
}
