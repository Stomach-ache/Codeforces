n, m = map(int, raw_input().split()) 
if m < n-1 or m > n + n + 2:
	print -1
else:
	ans = []
	for i in xrange(n):
		if m > n - i - 1:
			ans.append('1')
			m -= 1
		if m > n - i - 1:
			ans.append('1')
			m -= 1
		ans.append('0f	ans.append('1' * m)
	print "".join(ans)
