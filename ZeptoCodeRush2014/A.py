n, x = map(int, raw_input().split());
t, h , m = []*n, []*n, []*n
for i in xrange(n):
  	tt, hh, mm = map(int, raw_input().split());
	t.append(tt)
	h.append(hh)
	m.append(mm)
	#a.append([t, h, m]);
ans = 0;
vis = [0] * n;
pre = -1;
while (True):
  	tt = -1;
	ii = -1;
  	for i in xrange(n):
	  	if (vis[i]==0 and x >= h[i] and tt < m[i] and pre != t[i]):
		  	tt = m[i];
			ii = i;
	if (tt == -1):
	  	break;
	x += m[ii];
	ans += 1;
	pre = t[ii]
	vis[ii] = 1
print x
		  
