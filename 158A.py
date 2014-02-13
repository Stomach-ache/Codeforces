n, k = map(int, raw_input().split());
a = map(int, raw_input().split());
ans = 0;
for i in range(n):
	if a[i] >= a[k-1] and a[i] > 0:
		ans += 1;
print ans;
