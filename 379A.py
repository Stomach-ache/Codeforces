my_input = lambda : map(int, raw_input().split());

a, b = my_input();
ans = a;
while a >= b:
	tmp = a / b;
	ans += tmp;
	a = a % b + tmp;
print ans;


