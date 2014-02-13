k = input();
num = input();

cur = k;
la = 0;
flag = 0;

while 1:
	if cur == num :
		flag = 1;
		break;
	la += 1;
	cur *= k;
	if cur > num:
		break;
if flag:
	print "YES";
	print la;
else:
	print "NO";
