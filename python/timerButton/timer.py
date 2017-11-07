from Tkinter import *
from PIL import ImageTk, Image
import os

root = Tk()
root.minsize(width=666, height=666)
original = Image.open('on.png').convert("RGBA")
resized = original.resize((300,300),Image.ANTIALIAS)
img = ImageTk.PhotoImage(resized)
panel = Label(root, image = img)
panel.grid(row = 0, column = 0, pady = (30,20))
panel.pack(side = TOP, pady = 30)
Label(text='Buzz Time = 100ms',font=(None, 20)).pack(side=TOP,pady=50)
root.mainloop()