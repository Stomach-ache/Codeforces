a = raw_input()
b = raw_input()
c, d = a.count("1"), b.count("1")
print "YES" if c + c%2 >= d else "NO"
