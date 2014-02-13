n, m, a = map(int, raw_input().split());
ans  = 0;
if n % a != 0:
	ans += n / a + 1;
else :
	ans += n / a ;
ans *= (m / a + (1 if m % a != 0 else 0));
print ans;
