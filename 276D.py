l, r = map(long, raw_input().split())
if l == r:
	print 0
else:
	p = 0
	for i in xrange(61):
		if ((1 << i) & r > 0) and ((1 << i) & l) == 0:
			p = i
	print (1 << p) ^ ((1 << p) - 1)


