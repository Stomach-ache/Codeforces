def main():
	fib = [0] * 51;
	fib[1] = fib[2] = 1;
	for i in xrange(51):
		fib[i] = fib[i-2] + fib[i-1];

	k, x, n, m = raw_input().split();
	if x == 0:
		print 'A' * n;
		print 'A' * m;
	else:
		flag = 0;
		for i in xrange(3, 51):
			if x == fib[i]:
				flag = 1
				if n == 1 or m == 1:
					print 'Happy new year!';
				else:
					print 'AC' + 'C' * (n - 2)
					print 'AC' + 'A' * (m - 2)
		if flag == 0:
			for i in xrange(3, 51):
				if x == fib[i] + 1:
					flag = 1
					if n <= 2 or m <= 2:
						print 'Happy new year!'
					else:
						print 'AC' + 'C' * (n - 3) + 'A'
						print 'C' + 'AC' + 'A' * (m - 3)
		if flag == 0:
			print 'Happy new year!'

if __name__ == '__main__':
	main()
