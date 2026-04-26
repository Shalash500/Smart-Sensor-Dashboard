import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM3', 9600)

distance = []

plt.ion()

while True:
    line = ser.readline().decode().strip()

    try:
        _, _, d, _ = map(float, line.split(','))
        distance.append(d)
        distance = distance[-100:]
        plt.clf()
        plt.plot(distance)
        plt.title("Distance")
        plt.pause(0.01)

    except ValueError:
        continue
