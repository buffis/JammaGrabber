// Initializes the TVP7002 board in three steps
//
// 1: Reset board
// 2: Read some values to verify I2C works
// 3: Write the defaults
//
// Once all steps is completed, the indicator led will be lit if everything went well.
// On error, the LED will blink (and the program will crashloop).
//
// TVP_RESET: 12
// LED: 13
// I2C: A4 (SDA) and A5 (SCL).

#include <Wire.h>

#define TVP_ADDR         (0xB8 >> 1)
#define LED_PIN          13           
#define TVP_RESET_PIN    12      

// Note: this is oversized, and uses zero-termination.
unsigned char i2c_writes[100] = {
  0x01,0x30,
  0x02,0x00,
  0x03,0x20,
  0x04,0x81,
  0x05,0x02,
  0x06,0x06,
  0x07,0x1c, // sync length (28 pixels)
  0x10,0x58,
  0x11,0x40,
  0x12,0x01,
  0x17,0x02,
  0x1A,0xDA,
  0x22,0x00,
  0x31,0x09, // lores?
  0x35,0x00,
  0x3D,0x06,
  0x00,0x00  // zero terminate.
  };

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(TVP_RESET_PIN, OUTPUT);
  
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // Step 1.
  reset_tvp();
  Serial.println("TVP7002 was reset");
  Wire.begin();
  delay(500);

  
  // Step 2.
  get_and_verify_defaults();
  Serial.println("Defaults are OK");

  // Step3.
  write_registers_and_verify();
  Serial.println("Registers written");
  
  // Done.
  digitalWrite(LED_PIN, HIGH);
  Serial.println("All OK!");
  while (1) delay (1000);
}

void reset_tvp() {
  digitalWrite(TVP_RESET_PIN, LOW);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(TVP_RESET_PIN, HIGH);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}

/* Gets the first 5 sub registers, and verifies that they are set correctly. */
void get_and_verify_defaults() {
  read_and_verify(0x00, 0x02);  // Chip revision     (0x02)
  read_and_verify(0x01, 0x67);  // HPLL Feedback MSB (0x67)
  read_and_verify(0x02, 0x20);  // HPLL Feedback LSB (0x20)
  read_and_verify(0x03, 0xA8);  // HPLL Control      (0xA8)
  read_and_verify(0x04, 0x80);  // HPLL Phase        (0x80)
}

unsigned char tvp_read_data(unsigned char address) {
  unsigned char data;
  Wire.beginTransmission(TVP_ADDR);
  Wire.write(address);
  Wire.endTransmission();          
  Wire.beginTransmission(TVP_ADDR);
  Wire.requestFrom(TVP_ADDR, 1);
  data = Wire.read();
  Wire.endTransmission();

  Serial.print("Read ");
  Serial.print(address, HEX);
  Serial.print("=");
  Serial.println(data, HEX);
  
  return data;
}

void tvp_write_data(unsigned char address, unsigned char data) {
  Serial.print("Writing ");
  Serial.print(address, HEX);
  Serial.print("=");
  Serial.println(data, HEX);
  
  Wire.beginTransmission(TVP_ADDR);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}

void read_and_verify(unsigned char address, unsigned char expected) {
  unsigned char data = tvp_read_data(address);
  if (data != expected) {
    Serial.print("Got ");
    Serial.print(data, HEX);
    Serial.print(" expected ");
    Serial.print(expected, HEX);
    Serial.print("\n");
    crashloop(500);
  }
}

void write_registers_and_verify() {
  char i;
  char address;
  char data;
  char expectedData;

  // Write registers.
  for (i=0;;i+=2) {
    address = i2c_writes[i];
    data = i2c_writes[i+1];
    if (address == 0) {
      break; // zero termination.
    } else {
      tvp_write_data(address, data);
    }
  }

  // Verify registers.
  for (i=0;;i+=2) {
    address = i2c_writes[i];
    expectedData = i2c_writes[i+1];
    if (address == 0) {
      break; // zero termination.
    } else {
      data = tvp_read_data(address);
      if (data != expectedData) {
        crashloop(1000);
      }
    }
  }
}

void crashloop(int blinktime) {
  Serial.print("Entering crashloop");
  while (1) {
    delay(blinktime);
    digitalWrite(LED_PIN, LOW);
    delay(blinktime);
    digitalWrite(LED_PIN, HIGH);
  }
}
