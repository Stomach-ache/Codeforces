n = int(input());
res = 0
for i in xrange(n):
	p, q = map(int, raw_input().split());
	if (p + 2 <= q):
	  	res += 1;
print res
