original="CODEFORCES"
s=raw_input()
if(len(s)<10):
	print "NO"
	exit()
else:
	if(s[0:10]==original or s[-10:]==original):
		print "YES"
		exit()
	for i in range(1,10):
		#	print s[0:i]+s[i-10:]
		if(s[0:i]+s[i-10:]==original):
			print "YES"
			exit()
print "NO"
exit()