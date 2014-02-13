
def solve(a, dp, le, cur):
		if cur >= le:
			return 0;
		if cur == le - 1:
			dp[cur] = (1 if a[cur] == '9' else 0);
			return dp[cur];

		if dp[cur] != -1:
			return dp[cur];
		if int(a[cur]) + int(a[cur + 1]) == 9:
			dp[cur] = max(solve(a, dp, le, cur+2) + 1, solve(a, dp, le, cur+1));
		else:
			dp[cur] = solve(a, dp, le, cur + 1);
			if a[cur] == '9':
				dp[cur] += 1;

if __name__ == '__main__':
	a = raw_input();
	le = len(a);
	dp = [-1] * le;
 	solve(a, dp, le, 0);
	print dp;
