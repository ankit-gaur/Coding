import serial
from serial.tools import list_ports
arduino_ports = [
    p.device
    for p in list_ports.comports()
    if 'arduino' in p.description or 'ttyACM0' in p.description
]
print(list_ports.comports())
for p in list_ports.comports():
    print(p.description)
if not arduino_ports:
    raise IOError("No Arduino found")
if len(arduino_ports) > 1:
    warnings.warn('Multiple Arduinos found - using the first')
re = serial.Serial(arduino_ports[0])
#re=serial.Serial('/dev/ttyACM0',9600)
currentTime = 0
previousTime = 0
while(1):
    if(re.inWaiting()>0):
        data=re.readline()
        if "started" in data:
            print(data)
            continue
        currentTime = float(data)
        print(currentTime)
        
        
        

        
    
