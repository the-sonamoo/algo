
Node query(int l, int r , int node , int nodeL , int nodeR) {
	if (nodeR < l || nodeL > r) return {0, 0, 0, 0};
	if (l <= nodeL && nodeR <= r) return seg[node];
	
	int mid = (nodeL+nodeR)/2;
	Node Leftdata = query(l , r , node*2 , nodeL , mid);
	Node Rightdata = query(l , r , node*2+1 , mid+1 , nodeR);
	
	Node nowdata;
	nowdata.Lval = max(Leftdata.Lval , Leftdata.all+Rightdata.Lval);
	nowdata.Rval = max(Rightdata.Rval , Rightdata.all+Leftdata.Rval);
	nowdata.val = max(max(Leftdata.val , Rightdata.val) , Leftdata.Rval+Rightdata.Lval);
	nowdata.all = Leftdata.all+Rightdata.all;
	
	return nowdata;
}

Node update(int idx , ll value , int node , int nodeL , int nodeR) {
	if (idx < nodeL || idx > nodeR) return seg[node];
	if (idx == nodeL && idx == nodeR) {
		seg[node].Lval += value;
		seg[node].Rval += value;
		seg[node].val += value;
		seg[node].all += value;
		
		return seg[node];
	} 
	
	int mid = (nodeL+nodeR)/2;
	Node Leftdata = update(idx , value , node*2 , nodeL , mid);
	Node Rightdata = update(idx , value , node*2+1 , mid+1 , nodeR);
	
	seg[node].Lval = max(Leftdata.Lval , Leftdata.all+Rightdata.Lval);
	seg[node].Rval = max(Rightdata.Rval , Rightdata.all+Leftdata.Rval);
	seg[node].val = max(max(Leftdata.val , Rightdata.val) , Leftdata.Rval+Rightdata.Lval);
	seg[node].all = Leftdata.all+Rightdata.all;

	return seg[node];
}
