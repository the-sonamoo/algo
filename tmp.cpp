ll f(ll a , ll b , ll c) {
	if (b == 0) return 1;
	if (b == 1) return a%c;
	
	ll t = f(a , b/2 , c);
	
	if (b%2 == 1) return ((t*t%c)*a)%c;
	else return t*t%c;
}
