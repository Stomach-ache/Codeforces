# by Stomach_ache
def move(s, i):
		if s[i] == 'U':
			return 0, 1;
		elif s[i] == 'D':
			return 0, -1;
		elif s[i] == 'L':
			return -1, 0;
		else:
			return 1, 0;
a, b = map(long, raw_input().split());
s = raw_input();
l = len(s);
x, y = [0]*(l+1), [0]*(l+1)
f = 0;
for i in xrange(1, l+1):
	x[i], y[i] = x[i-1], y[i-1];
	tmpx, tmpy = move(s, i-1)
	x[i] += tmpx;
	y[i] += tmpy;
if a == 0 and b == 0:
	print "Yes";
else:
	# x[l] and y[l] can both be zero, so we can not divide directly
	# k must be a nonegative interger
	for i in xrange(1, l+1):
		if x[l] == 0 and y[l] != 0:
			if a == x[i] and (b - y[i]) % y[l] == 0 and (b - y[i]) / y[l] >= 0:
				f = 1
				break;
		elif y[l] == 0 and x[l] != 0:
			if b == y[i] and (a - x[i]) % x[l] == 0 and (a - x[i]) / x[l] >= 0:
				f = 1
				break;	
		elif x[l] == 0 and y[l] == 0:
			if a == x[i] and b == y[i]:
				f = 1;
				break;
		elif (a - x[i]) % x[l] == 0 and (b - y[i]) % y[l] == 0:
			if (a - x[i]) / x[l] == (b - y[i]) / y[l] and (b - y[i]) / y[l] >= 0:
				f = 1;
				break;

	if f:
		print "Yes";
	else:
		print "No";


