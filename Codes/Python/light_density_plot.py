import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM3', 9600)

light_density = []

plt.ion()

while True:
    line = ser.readline().decode().strip()

    try:
        _, _, _, l = map(float, line.split(','))
        light_density.append(l)
        light_density = light_density[-100:]
        plt.clf()
        plt.plot(light_density)
        plt.title("Light Density")
        plt.pause(0.01)

    except:
        continue
