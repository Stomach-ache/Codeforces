n, m = map(int, raw_input().split())
print sum([1 for i in xrange(m+1) if i*i<=m and (m-i*i)**2+i == n])
