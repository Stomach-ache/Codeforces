a = raw_input();
b = set()
for i in xrange(1, len(a)-1):
  if a[i] >= 'a' and a[i] <= 'z':
  	b.add(a[i])
print len(b)
