n = int(input())
a = map(int, raw_input().split())
a.sort()
for i in xrange(n):
	print a[i],