s = raw_input();
length = len(s);
flag = True
for i in xrange(length):
  	if s[i] != s[length-1-i] or s[i] not in 'AHIMOTUVWXY':
		flag = False;
		break;
print 'YES' if flag else 'NO'
