import math

a, b = map(int, raw_input().split())
table = [0] * 2000005
for i in xrange(1, 1001):
	for j in xrange(1, 1001):
		 table[i * i + j * j] = 1
if table[a] == 0 or table[b] == 0:
	print "NO"
else:
	flag = 1
	if a == b:
		#flag = 1
		for i in xrange(a):
			if i * i > a:
				break
			if i * i == a:
				flag = 0
				break
		if flag == 0:
			print "NO"
	if flag:
		#print "YES"
		if a > b:
			a, b = b, a
		c_2 = 0
		if a == b:
			if table[a*a + b*b] == 0:
				flag = 0
			c_2 = a * a + b * b
		else:
			if table[b*b - a*a] == 0 and table[b*b + a * a] == 0:
				flag = 0
			
		print "YES" if flag else "NO"

		if flag:
			x1, y1 = 0, 0
			print 0, 0
			f =0
			for x in xrange(-a, 0):
				for y in xrange(a):
					if x * x + y * y == a:
						x1, y1 = x, y
						print x, y
						f = 1
						break
				if f: break 
			f = 0
			for x in xrange(b):
				for y in xrange(b):
					if x * x + y * y == b and (x1 != -x and y1 != y):
						print x, y
						f = 1
						break
				if f: break




