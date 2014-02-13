t = input();
n = map(int, raw_input().split());
for i in xrange(t):
	print 4 * n[i] + 1 if n[i] % 2 == 0 else 2 * n[i] + 1
