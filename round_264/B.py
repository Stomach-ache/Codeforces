n = int(input());
a = map(int, raw_input().split());
ans, h, e = 0, 0, 0;
for i in xrange(n):
  	if h + e < a[i]:
		ans += a[i] - h - e;
		e = 0;
	else :
		e += h - a[i];
	h = a[i];
print ans;
