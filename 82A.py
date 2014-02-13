import time
import math
#time_beg = time.clock()
n = input();
name = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"];
m = int(math.log(n/5+1, 2));
n -= 5 * (2**m - 1);
print name[n/(2**m)-1] if n % (2**m) == 0 else name[n/(2**m)]
#time_end = time.clock()
#print "%lf time used" % (time_end - time_beg)
