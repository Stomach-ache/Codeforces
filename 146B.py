def mask(m):
	n = m;
	res = 0;
	a=[];
	while n:
		if (n % 10 == 4 or n % 10 == 7):
			a.append(n%10);	
		n /= 10;
	for i in xrange(len(a)-1, -1, -1):
		res = res*10 + a[i];
	return res;

a, b = map(int, raw_input().split());
if a < b :
	print b;
else:
	c = a + 1;
	while 1:
		if mask(c) == b:
			print c;
			break;
		c += 1;
		
