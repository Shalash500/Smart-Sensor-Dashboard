T = readtable("sensor_log.csv");

fprintf("=== Sensor Statistics ===\n\n");

fprintf("Temperature (C):\n");
fprintf("  Mean:  %.2f\n", mean(T.Temperature));
fprintf("  Max:   %.2f\n", max(T.Temperature));
fprintf("  Min:   %.2f\n", min(T.Temperature));
fprintf("  Std:   %.2f\n\n", std(T.Temperature));

fprintf("Humidity (%%):\n");
fprintf("  Mean:  %.2f\n", mean(T.Humidity));
fprintf("  Max:   %.2f\n", max(T.Humidity));
fprintf("  Min:   %.2f\n", min(T.Humidity));
fprintf("  Std:   %.2f\n\n", std(T.Humidity));

fprintf("Distance (cm):\n");
fprintf("  Mean:  %.2f\n", mean(T.Distance));
fprintf("  Max:   %.2f\n", max(T.Distance));
fprintf("  Min:   %.2f\n", min(T.Distance));
fprintf("  Std:   %.2f\n\n", std(T.Distance));

fprintf("Light (ADC 0-1023):\n");
fprintf("  Mean:  %.2f\n", mean(T.Light));
fprintf("  Max:   %.2f\n", max(T.Light));
fprintf("  Min:   %.2f\n", min(T.Light));
fprintf("  Std:   %.2f\n\n", std(T.Light));

figure('Name', 'Smart Sensor Dashboard', 'NumberTitle', 'off');

subplot(2, 2, 1);
plot(T.Temperature);
title('Temperature');
xlabel('Sample');
ylabel('°C');
grid on;

subplot(2, 2, 2);
plot(T.Humidity);
title('Humidity');
xlabel('Sample');
ylabel('%');
grid on;

subplot(2, 2, 3);
plot(T.Distance);
title('Distance');
xlabel('Sample');
ylabel('cm');
grid on;

subplot(2, 2, 4);
plot(T.Light);
title('Light Intensity');
xlabel('Sample');
ylabel('ADC (0–1023)');
grid on;

sgtitle('Smart Sensor Dashboard — Logged Data Analysis');

saveas(gcf, 'sensor_analysis.png');
fprintf("Plot saved as sensor_analysis.png\n");
