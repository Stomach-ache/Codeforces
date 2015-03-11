n, m, a, b = map(int, raw_input().split());
res = n * a;
if b < a * m:
	res = min(res, n/m*b+n%m*a);
	if n%m:
		res = min(res, (n/m+1)*b);
print res;
