import re
s = raw_input();
s = s.lower();
s = re.sub(r'[aeiouy]', r'', s);
s = re.sub(r'[a-z]', lambda x : ('.'+x.group(0)), s);
print s;
