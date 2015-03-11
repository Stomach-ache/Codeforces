n, m = map(int, raw_input().split())
div, lft = n / m, n % m;
mi = (div + 1) * (div) / 2 * lft + (div) * (div - 1) / 2 * (m - lft);
print mi, (n - m + 1) * (n - m) / 2
