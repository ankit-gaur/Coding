def permute(s,i):
	if(i==len(s)):
		print(s)
		return	
	l = i 
	while l<len(s):
		n = s[:]
		n[l],n[i] = n[i],n[l]
		permute(n,i+1)
		l+=1

s = raw_input()
l = list(s)
print(len(l))
permute(l,0)


