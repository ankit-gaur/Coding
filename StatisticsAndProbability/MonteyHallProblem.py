from random import randint 


winsWhenMoved = 0.0
numTrials = 10000000
for i in range(numTrials):
	carPos = randint(1,3)
	chosenPos = randint(1,3)
	if(carPos!=chosenPos):
		winsWhenMoved += 1

print winsWhenMoved/numTrials

