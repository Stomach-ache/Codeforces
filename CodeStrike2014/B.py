n, m = map(int, raw_input().split());
can = [0] * (n+1);
login = [0]*(n+1);
known = [1] * (n+1)
log = []
now = set();
for i in xrange(m):
  	a, b = raw_input().split();
	b = int(b)
  	known[b] = 0;
	log.append((a, b));
	if a == '+':
		login[b] += 1;
	else :
		if login[b] == 0:
			now.add(b);
flag = 0;
for i in xrange(m):
  	if log[i][0] == '+':
		now.add(log[i][1]);
	else:
		if len(now) == 1:
			one = log[i][1]
			flag += 1
		now.remove(log[i][1]);
if flag == 1 or flag == 0:
	print sum(known[1:]) + flag;
	if flag : known[one] = 1,
	for i in xrange(1, n+1):
	  	if known[i]: print i,
	print ''
else :
	ans = sum(known[1:])
	print ans;
	for i in xrange(1, 1+n):
	  	if known[i]: print i,
	if ans:
		print ''

