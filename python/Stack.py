class Stack:
	def __init__(self):
		self.list = []
		self.size = 0;

	def push(self,data):
		self.list.append(data)
		self.size+=1

	def pop(self):
		l = self.size
		if(l==0):
			return
		t = self.list[l-1]	
		del self.list[l-1]
		self.size-=1
		return t
	def top(self):
		l = self.size
		if(l<=0):
			raise ValueError("stack is empty!!")
		return self.list[l-1]
	
	def size(self):
		return self.size	
	
	def empty(self):
		if(self.size==0):
			return True	
		else:
			return False	

s = Stack()

#Test 1
# for x in range(10):
# 	s.push(x)
# while not s.empty():
# 	print(s.size)
# 	print(s.pop())
print(s.p)
#Test2
#s.top()


	
				



				