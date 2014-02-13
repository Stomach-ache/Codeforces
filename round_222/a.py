a, b = map(int, raw_input().split());
if a == b:
	print "0 6 0"
elif a < b:
	if (a+b)%2 == 1:
		print (a+b)/2, 0, 6-(a+b)/2;
	else:
		print (a+b)/2-1, 1, 6-(a+b)/2;
else:
	if (a+b)%2 == 1:
		print 6-(a+b)/2, 0, (a+b)/2;
	else:
		print 6-(a+b)/2, 1, (a+b)/2-1
