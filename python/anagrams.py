from collections import defaultdict
a = raw_input()
b = raw_input()
class Solution:
	def __init__(self,a,b):
		self.a = a
		self.b = b
	def ana(self):
		counta = defaultdict(lambda: 0)
		countb = defaultdict(lambda: 0)
		for x in self.a:
			counta[x] += 1;
		for x in self.b:
			countb[x] +=1;

		if len(counta)!= len(countb):
			print('not anagrams')
		else:
			an = True
			for k in counta:
				if k not in countb or counta[k] != countb[k]:
					an = False
					break
			if an: 
				print('anagram')
			else:
				print('not anagram')	
x = Solution(a,b)
x.ana



