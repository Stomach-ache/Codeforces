s = raw_input();
a = {}
for i in range(len(s)):
	if  a.has_key(s[i]) == 0:
		a[s[i]] = 1;
print "CHAT WITH HER!" if len(a)%2==0 else "IGNORE HIM!"
