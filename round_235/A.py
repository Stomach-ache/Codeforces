n, x = map(int, raw_input().split())
cnt = sum(map(int, raw_input().split()));
ans = abs(cnt) / x if abs(cnt) % x == 0 else abs(cnt) / x + 1
print ans
