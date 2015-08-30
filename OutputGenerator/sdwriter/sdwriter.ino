#include <SPI.h>

/*
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10
 * IN_DATA - pin 9
 * READY  - pin 8
 * EOF - A5
 */

#define PIN_INDATA 9
#define PIN_READY  8
#define PIN_EOF    A5
#define PIN_CS     10
#define PIN_DONE   A0
#define PIN_ERROR  A1

#define STATE_INIT 0
#define STATE_READ_DATA 1 
#define STATE_WAIT_FOR_DATA 2 
#define STATE_END_DATA 3 
#define STATE_SD_ERROR 4
#define STATE_FILE_ERROR 5
#define STATE_DONE 6
unsigned char state;

#include <SD.h>

File outFile;

void setup()
{
  // Use port D as raw inputs.
  DDRD = B00000000;
  
  pinMode(PIN_READY, OUTPUT);
  pinMode(PIN_INDATA, INPUT);
  pinMode(PIN_EOF, INPUT); 
  pinMode(PIN_DONE, OUTPUT);
  pinMode(PIN_ERROR, OUTPUT);

  digitalWrite(PIN_READY, LOW);
  digitalWrite(PIN_DONE,  LOW);
  digitalWrite(PIN_ERROR, LOW);
  
  state = STATE_INIT;

  delay(3000);
}

void handle_init() {
  digitalWrite(PIN_READY, LOW);
  
  if (!SD.begin(PIN_CS)) {
    state = STATE_SD_ERROR;
    return;
  }
  outFile = SD.open("debug.txt", FILE_WRITE);
  if (!outFile) {
    state = STATE_FILE_ERROR;
    return;
  }
  
  state = STATE_WAIT_FOR_DATA;
}

void handle_wait_for_data() {
  digitalWrite(PIN_READY, HIGH);
  if (digitalRead(PIN_INDATA)) {
    state = STATE_READ_DATA;
    return;
  }
  if (digitalRead(PIN_EOF)) {
    state = STATE_END_DATA;
    return;
  }
}

void handle_read_data() {
  digitalWrite(PIN_READY, LOW);
  unsigned char data = PIND;
  outFile.write(data);
  state = STATE_WAIT_FOR_DATA;
}

void handle_end_data() {
  outFile.close();
  state = STATE_DONE;
}

void handle_done() {
  digitalWrite(PIN_DONE,  HIGH);
}

void handle_error(unsigned char code) {
  digitalWrite(PIN_ERROR, HIGH);
}

void loop()
{
  switch (state) {
    case STATE_INIT:
      handle_init();
      break;
    case STATE_WAIT_FOR_DATA:
      handle_wait_for_data();
      break;
    case STATE_READ_DATA:
      handle_read_data();
      break;
    case STATE_END_DATA:
      handle_end_data();
      break;
    case STATE_SD_ERROR:
    case STATE_FILE_ERROR:
      handle_error(state);
      break;
    case STATE_DONE:
      handle_done();
      break;
  }
}










/*

void do_sdstuff() {
  if (!SD.begin(10)) {
    //Serial.println("initialization failed!");
    return;
  }
  //Serial.println("initialization done.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    myFile.println("testing 1, 2, 3.");
    myFile.close();
    //Serial.println("done.");
  } else {
    //Serial.println("error opening test.txt");
  }
  
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
        //Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    //Serial.println("error opening test.txt");
  }
}
*/
