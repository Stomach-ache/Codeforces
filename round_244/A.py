n = int(input())
cnt = 0
police = 0
a = map(int, raw_input().split())
for i in xrange(n):
	if a[i] > 0:
		police += a[i];
	if a[i] < 0:
		if police == 0:
			cnt += 1
		else:
			police -= 1
print cnt

