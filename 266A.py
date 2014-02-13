n = input();
string = raw_input();
cnt = pos = 0;
le = len(string);
for i in xrange(1, le):
	if string[i] == string[pos]:
		cnt += 1;
	else:
		pos = i;
print cnt;


