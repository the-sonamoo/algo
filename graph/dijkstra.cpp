pq.push({0 , s});
while(!pq.empty()) {
  int curr = pq.top().second;
  int cost = -pq.top().first;
  pq.pop();

  if (visited[curr] == 1) continue;
  dist[curr] = cost;
  visited[curr] = 1;
  for (int i = 0; i < v[curr].size(); i++) {
    int ncurr = v[curr][i].first;
    int ncost = v[curr][i].second;
    dist[ncurr] = min(dist[ncurr] , dist[curr]+ncost);
    pq.push({-dist[ncurr] , ncurr}); 
  }
}

printf("%d" , dist[e]);
