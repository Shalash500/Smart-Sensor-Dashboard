import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM3', 9600)

temps = []

plt.ion()

while True:
    line = ser.readline().decode().strip()

    try:
        _, t, _, _ = map(float, line.split(','))
        temps.append(t)
        temps = temps[-100:]
        plt.clf()
        plt.plot(temps)
        plt.title("Temperature")
        plt.pause(0.01)

    except:
        continue
