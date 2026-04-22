import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from collections import deque

ser = serial.Serial('COM3', 9600)

temps = deque(maxlen=100)
hums = deque(maxlen=100)
dists = deque(maxlen=100)
lights = deque(maxlen=100)

fig, axes = plt.subplots(2, 2)

ax_temp = axes[0, 0]
ax_hum  = axes[0, 1]
ax_dist = axes[1, 0]
ax_light= axes[1, 1]

def setup_axes():
    ax_temp.set_title("Temperature")
    ax_temp.set_ylabel("°C")

    ax_hum.set_title("Humidity")
    ax_hum.set_ylabel("%")

    ax_dist.set_title("Distance")
    ax_dist.set_ylabel("cm")

    ax_light.set_title("Light")
    ax_light.set_ylabel("Light Density")

setup_axes()

def update(frame):
    line = ser.readline().decode().strip()

    try:
        h, t, d, l = map(float, line.split(','))

        temps.append(t)
        hums.append(h)
        dists.append(d)
        lights.append(l)

        ax_temp.cla()
        ax_hum.cla()
        ax_dist.cla()
        ax_light.cla()

        setup_axes()

        ax_temp.plot(temps)
        ax_hum.plot(hums)
        ax_dist.plot(dists)
        ax_light.plot(lights)

    except:
        pass

ani = FuncAnimation(fig, update, interval=200)

plt.tight_layout()
plt.show()