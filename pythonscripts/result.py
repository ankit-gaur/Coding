import urllib
import urllib2 as url
import os




page = ""
while True:
	req = url.Request("http://cbseresults.nic.in/");
	response = url.urlopen(req)
	data = str(response.read())
	if page != data and len(page)!=0:
		print len(data) - len(page)
		page = data
		print page
		os.popen2("cvlc /home/ankit/Desktop/twentyonepilots/heavydirtysoul.mp3 --play-and-exit")
	
				


			
