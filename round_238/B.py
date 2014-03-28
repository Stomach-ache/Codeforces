n = int(input())
s = raw_input()
cnt = 0
Left, Right = [-1] * (n+1), [-1] * (n+1);
for i in xrange(n):
	if s[i] == 'R':
		Left[i] = i
	elif s[i] == 'L':
		Left[i] = -1
	elif i == 0:
		Left[i] = -1
	else:
		Left[i] = Left[i-1]
for i in xrange(n-1, -1, -1):
	if s[i] == 'L':
		Right[i] = i
	elif s[i] == 'R':
		Right[i] = -1
	else:
		Right[i] = Right[i+1]
for i in xrange(n):
	if s[i] != '.':
		continue
	if Left[i] == -1 and Right[i] == -1:
		cnt += 1
	elif Left[i] != -1 and Right[i] != -1 and Left[i] + Right[i] == i * 2:
		cnt += 1

print cnt