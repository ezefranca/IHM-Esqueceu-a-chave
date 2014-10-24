
#Trabalho de IHM
#Professor Marcelo Hashimoto
#Senac-SP
#Ezequiel França
#Gabriel Vieira

#Serial bacana
import serial

#Coisas do terminal Bacana
import subprocess
import shlex
#Para gerar o Random Time
from time import gmtime, strftime
#Para o Mysql Bacana
#from __future__ import print_function

import pprint


ser = serial.Serial('/dev/ttyACM0',9600, timeout=1)

while True:
	x = ser.read()
	print x          
	if x == 'S':
		subprocess.call('echo "vc e uma pessoa bacana" | sudo gammu sendsms TEXT 11985753766', shell=True)
