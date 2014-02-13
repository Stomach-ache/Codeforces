s = raw_input();
lf = rgt = 0;
le = len(s);
p = s.find('^');
for i in xrange(p):
	if s[i] >= '1' and s[i] <= '9':
		lf += long(s[i]) * (p - i);
for i in xrange(p+1, le):
	if s[i] >= '1' and s[i] <= '9':
		rgt += long(s[i]) * (i - p);
if lf == rgt :
	print "balance";
elif lf > rgt:
	print "left";
else:
	print "right"
