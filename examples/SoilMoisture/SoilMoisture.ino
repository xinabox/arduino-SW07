#include <xCore.h>
#include <xSW07.h>

xSW07 SW07;

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

  // Start the I2C Communication
  Wire.begin();

  // Start the ☒CHIP Sensor
  SW07.begin();
}

void loop() {
  Serial.println("==============================");
  Serial.println("   SW07 Soil Moisture Measurement");
  Serial.println("==============================");

  float moisturePercent = 0;

  SW07.poll();

  moisturePercent = SW07.getMoisture();

  // Print Voltage
  Serial.print("Moisture = ");
  Serial.print(moisturePercent,3);
  Serial.println(" %");
  Serial.println();

  delay(1000);
}
