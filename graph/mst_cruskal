sort(graph.begin() , graph.end());
	
for (int i = 0; i < graph.size(); i++) {
  int cost = graph[i].first;
  int s = graph[i].second.first;
  int e = graph[i].second.second;

  if (find_parent(s) != find_parent(e)) {
    U(s , e);
    ans += cost;
  }
}
