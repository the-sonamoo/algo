for (int i = 1; i <= n; i++) if (ind[i] == 0) q.push(i);
	
while(!q.empty()) {
  if (q.empty()) {
    //impossible
    return 0;
  }

  int here = q.front();
  q.pop();
  ans.push_back(here);
  for (int i = 0; i < v[here].size(); i++) {
    int next = v[here][i];
    if (--ind[next] == 0) q.push(next);
  }
}
