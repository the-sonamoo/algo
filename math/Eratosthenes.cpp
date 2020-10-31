void eratos() {
	chk[1] = 1;
	for (int i = 2; i <= n; i++) for (int j = i*2; j <= n; j += i) chk[j] = 1; 
	for (int i = 2; i <= n; i++) if (chk[i] == 0) prime.push_back(i); 
}
