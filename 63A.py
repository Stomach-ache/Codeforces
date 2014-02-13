n = int(input());
li = [map(str, raw_input().split()) for i in xrange(n)];
for i in xrange(n):
	if li[i][1] == "rat":
		print li[i][0];
for i in xrange(n):
	if li[i][1] == "woman" or li[i][1] == "child":
		print li[i][0];
for i in xrange(n):
	if li[i][1] == "man":
		print li[i][0];
for i in xrange(n):
	if li[i][1] == "captain":
		print li[i][0];
