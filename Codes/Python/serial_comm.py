import serial

ser = serial.Serial('COM3', 9600)

temperature = []
distances = []
lights = []
humidity = []

while True:
    line = ser.readline().decode().strip()

    try:
        h, t, d, l = map(float, line.split(','))

        humidity.append(h)
        temperature.append(t)
        distances.append(d)
        lights.append(l)

        print(h, t, d, l)

    except:
        continue
