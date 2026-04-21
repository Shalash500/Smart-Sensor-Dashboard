import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM3', 9600)

humidity = []

plt.ion()

while True:
    line = ser.readline().decode().strip()

    try:
        h, _, _, _ = map(float, line.split(','))
        humidity.append(h)
        temps = humidity[-100:]
        plt.clf()
        plt.plot(humidity)
        plt.title("Humidity")
        plt.pause(0.01)

    except:
        continue
