def move(x, y, s, i):
		if s[i] == 'U':
			return x, y+1;
		elif s[i] == 'D':
			return x, y-1;
		elif s[i] == 'L':
			return x-1, y;
		else:
			return x+1, y;
a, b = map(int, raw_input().split());
s = raw_input();
l = len(s);
x, y = 0, 0
f = 0;
for i in xrange(l):
		if x == a and y == b:
			f = 1;
			break;
		x, y = move(x, y, s, i);
if x != 0 and y != 0:
	tmp = min(abs(a/x), abs(b/y));
	x *= tmp;
	y *= tmp;
elif x == 0 and y != 0:
	y *= abs(b/y);
elif y == 0 and x != 0:
	x *= abs(a/x);
for i in xrange(l):
		if x == a and y == b:
			f = 1;
			break;
		x, y = move(x, y, s, i);
if f:
	print "Yes";
else:
	print "No";


