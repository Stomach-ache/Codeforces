n = input();
a = map(int, raw_input().split());
b = a[:];
for i in range(n):
	b[a[i]-1] = i+1;
for i in range(n):
	print b[i],
