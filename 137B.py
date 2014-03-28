n = int(input())
a = map(int, raw_input().split())
vis = [0] * 5005
for i in xrange(n):
	vis[a[i]] = 1
print sum([1 for i in xrange(1, n+1) if not vis[i]])