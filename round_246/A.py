n, k = map(int, raw_input().split())
y = map(int, raw_input().split());
y = sorted(y);
cnt = 0;
cur = 2;
while cur < n:
  if y[cur]+k <= 5:
  	cnt += 1;
  else:
 	break;
  cur += 3;
print cnt
