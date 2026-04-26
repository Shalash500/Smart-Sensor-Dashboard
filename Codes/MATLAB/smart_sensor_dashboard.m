x = readtable("sensor_log.csv");

plot(x.Temperature)
title("Temperature Sensor")
xlabel("Temperature")
ylabel("℃")

figure
plot(x.Humidity)
title("Humidity Sensor")
xlabel("Humidity")
ylabel("%")

figure
plot(x.Distance)
title("Distance Sensor")
xlabel("Distance")
ylabel("cm")

figure
plot(x.Light)
title("Light Sensor")
xlabel("Light")
ylabel("Analog Reading (0:1023)")

