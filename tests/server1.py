import time
import socket

UDP_IP="127.0.0.1"
UDP_PORT=2424
MESSAGE="Hello, World 2424!"

print "UDP target IP:", UDP_IP
print "UDP target port:", UDP_PORT
print "message:", MESSAGE
		  
sock = socket.socket( socket.AF_INET, socket.SOCK_DGRAM )			
sock.sendto( MESSAGE, (UDP_IP, UDP_PORT) )	