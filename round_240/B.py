n, a, b = map(long, raw_input().split())
x = map(long, raw_input().split())

w = [0] * n
if a % b != 0:
	a = a % b
	for i in xrange(n):
		w[i] = x[i] * a % b
		w[i] /= a;

for i in xrange(n):
	print w[i], 