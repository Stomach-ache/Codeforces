def main():
	k, x, n, m = map(int, raw_input().split());

	fib = [0] * 51;
	can = ['A', 'C', 'X']
	for first1 in can:
		for last1 in can:
			if n == 1:
				last1 = first1;
			for num1 in xrange(0, n/2+1):
				for first2 in can:
					for last2 in can:
						if m == 1:
							last2 = first2;
						for num2 in xrange(0, m/2+1):
							fib[1], fib[2] = num1, num2;
							f1, l1, f2, l2 = first1, last1, first2, last2;
							for i in xrange(3, k+1):
								fib[i] = fib[i-2] + fib[i-1];
								if l1 == 'A' and f2 == 'C':
									fib[i] += 1;
								f1, f2 = f2, f1;
								l1 = l2;
							if x == fib[k]:
								if n == 1 and m == 1:
									print first1
									print last1
									return ;
								if n == 1:
									print first1;
									print first2 + 'AC'*num2 + 'X'*(m-2-num2*2) + last2;
									return ;
								if m == 1:
									print first1 + 'AC'*num1 + 'X'*(n-2-num1*2) + last1;
									print first2;
									return ;
									last2 = ''
								print first1 + 'AC' * num1 + 'X'*(n-2-num2*2) + last1;
								print first2 + 'AC'*num1 + 'X'*(m-2-num2*2) + last2;
								return ;
	print 'Happy new year!'

if __name__ == '__main__':
	main()
