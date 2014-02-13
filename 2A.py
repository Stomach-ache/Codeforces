n = input();
name, score = [], []
dic, dic2= {}, {}
for i in xrange(n):
	na, sc = raw_input().split();
	name.append(na)
	score.append(sc)
	if dic.has_key(na):
		dic[na] += int(sc);
	else:
		dic[na] = int(sc);
m = max(dic.values());
for i in xrange(n):
	if dic2.has_key(name[i]):
		dic2[name[i]] += int(score[i]);
	else:
		dic2[name[i]] = int(score[i]);
	if dic[name[i]] == m and dic2[name[i]] >= m:
		print name[i];
		break;
