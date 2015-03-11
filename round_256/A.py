a1, a2, a3 = map(int, raw_input().split());
b1, b2, b3 = map(int, raw_input().split());
n = int(input());
a = a1+a2+a3;
b = b1+b2+b3;
flag = True;
if b/10 > n:
	flag = False;
else:
	n -= b/10;
	b %= 10;
if a/5 > n:
	flag = False;
else:
	n -= a/5;
	a %=5;
if n == 0 and (a or b):
  	flag = False
if n  == 1 and  (a and b):
  	flag = False;
print 'YES' if flag else 'NO'

