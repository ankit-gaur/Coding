import pyaudio
import wave
import sys

buff = []
class AudioFile:
    chunk = 1024

    def __init__(self, file):
        """ Init audio stream """ 
        self.file =file
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
        nxtdata = ""
        data = self.wf.readframes(self.chunk)
        nxtdata = self.wf.readframes(self.chunk)
        while True:
            self.stream.write(data)
            data = nxtdata
            nxtdata = self.wf.readframes(self.chunk)
            if nxtdata == '':
                self.wf = wave.open(self.file,'rb')

    def close(self):
        """ Graceful shutdown """ 
        self.stream.close()
        self.p.terminate()

a = AudioFile("beep.wav")
a.play()        