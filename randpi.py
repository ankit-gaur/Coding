import math

inside = 0

for i in range(0,10000) :
	randx = randint(0,4) - 2
	randy = randint(0,4) - 2
    
    ans = math.pow(randx,2)
    ans = ans + randy*randy

    dist = math.sqrt(ans)

    if dist<=2 :
    	inside++

rat = inside/10000    	

rat = 4*rat
print(rat)


