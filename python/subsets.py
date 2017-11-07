def allsets(i,nums,lst):
	if(i==len(nums)):
		print(lst)
		return
	l1 = list(lst)	
	allsets(i+1,nums,l1)
	l = list(lst)
	l.append(nums[i])
	allsets(i+1,nums,l)

n = input()
nums = []
for i in range(n):		
	x = input()
	nums.append(x)
lst = []	
allsets(0,nums,lst)		

