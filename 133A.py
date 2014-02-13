s = raw_input();

flag = 0;
for i in range(len(s)):
	if s[i] in "HQ9":
		flag = 1;
		break;
print "YES" if flag else "NO"
