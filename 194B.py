def gcd (a, b):
	if b == 0:
		return a;
	return gcd(b, a % b)

if __name__ == '__main__':
	t = int(input())
	n = map(int, raw_input().split());
	for i in xrange(t):
		print (n[i] * 4 / gcd(n[i] * 4, n[i] + 1) * (n[i] + 1)) / (n[i] + 1) + 1
