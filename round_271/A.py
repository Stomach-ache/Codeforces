s = 'qwertyuiopasdfghjkl;zxcvbnm,./';
d = raw_input();
a = raw_input();
ans = ''
if d == 'R':
	for i in xrange(len(a)):
	  	for j in xrange(len(s)):
		  	if s[j] == a[i]:
				k = j;
				break;
		ans += s[k-1];
if d == 'L':
	for i in xrange(len(a)):
	  	for j in xrange(len(s)):
		  	if s[j] == a[i]:
				k = j;
				break;
		ans += s[k+1];
print ans
		


