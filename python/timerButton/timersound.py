import serial
from serial.tools import list_ports
import threading
from Tkinter import *
from PIL import ImageTk, Image
import pyaudio
import wave

buff = []
class AudioFile:
    chunk = 1024

    def __init__(self, file):
        """ Init audio stream """ 
        self.wf = wave.open(file, 'rb')
        self.p = pyaudio.PyAudio()
        self.stream = self.p.open(
            format = self.p.get_format_from_width(self.wf.getsampwidth()),
            channels = self.wf.getnchannels(),
            rate = self.wf.getframerate(),
            output = True
        )

    def play(self):
        """ Play entire file """
        data = self.wf.readframes(self.chunk)
        while data != '':
            self.stream.write(data)
            data = self.wf.readframes(self.chunk)
        self.play()

    def close(self):
        """ Graceful shutdown """ 
        self.stream.close()
        self.p.terminate()

class SensorThread(threading.Thread):
    def run(self):
        # arduino_ports = [
        #     p.device
        #     for p in list_ports.comports()
        #     if 'arduino' in p.description or 'ttyACM0' in p.description
        # ]
        # if not arduino_ports:
        #     raise IOError("No Arduino found")
        # if len(arduino_ports) > 1:
        #     warnings.warn('Multiple Arduinos found - using the first')
        # re = serial.Serial(arduino_ports[0])
        re=serial.Serial('/dev/ttyACM0',9600)
        currentTime = 0
        previousTime = 0
        a = AudioFile('beep.wav')
        while(1):
            if(re.inWaiting()>0):
                data=re.readline()
                if "started" in data:
                    print("buzzing.....")
                    if  len(buff)>0 and "started" in str(buff[-1]):
                        pass
                    else:
                        a.play()
                        buff.append("started")

                if("started" in data):
                    continue   
                a.close()
                currentTime = float(data)    
                buff.append(currentTime)

        

class Gui():
    def __init__(self):
        self.root = Tk();
        self.bzlbl = Label(self.root, text="Started",font=(None, 20))
        self.root.minsize(width=800, height=800)
        self.original = Image.open('on.png')
        self.resized = self.original.resize((300,300),Image.ANTIALIAS)
        self.img = ImageTk.PhotoImage(self.resized)
        self.org2 = Image.open('off.png')
        self.resized2 = self.org2.resize((300,300),Image.ANTIALIAS)
        self.img2 = ImageTk.PhotoImage(self.resized2)
        self.panel = Label(self.root, image = self.img)
        self.updateLabel()
        self.mintime = 100000

    def run(self):
        self.panel.pack(side = TOP, pady = 30)
        self.bzlbl.pack(side = TOP, pady = 50)
        self.root.mainloop()

    def updateLabel(self):
        if len(buff)==0:
            self.bzlbl.after(50, self.updateLabel)
            return 
        if "started" in str(buff[0]):
            if(self.mintime==100000):
                self.bzlbl["text"] = "Started"
            else:
                self.bzlbl["text"] = "   Started\n\nMinimum Time Taken : "+ str(self.mintime)+" seconds"
            self.panel.configure(image=self.img)
            self.panel.image = self.img
        else:
            self.bzlbl["text"] = "Time taken :  "+str(buff[0]) + " seconds"
            if(self.mintime>float(buff[0])):
                self.mintime = buff[0]
            self.panel.configure(image=self.img2)
            self.panel.image = self.img2
        del buff[0]

        self.root.update()
        self.bzlbl.after(50, self.updateLabel)

if __name__ == "__main__":
    SensorThread().start()
    Gui().run()
    
        
    
