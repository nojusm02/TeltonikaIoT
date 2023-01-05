.PHONY: all clean 

all: device

device: device.c inputHandling.c deviceHandling.c
	gcc -I/home/studentas/Desktop/iot-c-master/iot-c/src/wiotp/sdk -I /home/studentas/Desktop/iot-c-master/iot-c/paho.mqtt.c/src -o device device.c inputHandling.c deviceHandling.c -L/home/studentas/Desktop/iot-c-master/iot-c/build -liotp-as-device -L/home/studentas/Desktop/iot-c-master/iot-c/paho.mqtt.c/build/output -lpaho-mqtt3as -Wall

clean:
	rm device
#Usage: deviceSample --config config_file_path
