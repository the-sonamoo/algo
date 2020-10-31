cin >> n;
lis.push_back(-1e9);
for (int i = 0; i < n; i++) {
  cin >> a[i];
  if (a[i] > lis.back()) {
    lis.push_back(a[i]);
    ans++;
    cache[i] = ans;
  }
  else {
    int idx = lower_bound(lis.begin() , lis.end() , a[i])-lis.begin();
    lis[idx] = a[i];
    cache[i] = idx;
  }
}

cout << ans << "\n";
for (int i = n-1; i >= 0; i--) {
  if (cache[i] == ans) {
    ans--;
    res.push_back(i);
  }
}

for (int i = res.size()-1; i >= 0; i--) cout << a[res[i]] << " ";
