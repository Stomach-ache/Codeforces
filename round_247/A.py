a1, a2, a3, a4 = map(int, raw_input().split());
s = raw_input();
ans = 0
for i in xrange(len(s)):
  if s[i] == '1':
  	ans += a1;
  elif s[i] == '2':
  	ans += a2;
  elif s[i] == '3':
  	ans += a3;
  elif s[i] == '4':
  	ans += a4;
print ans
