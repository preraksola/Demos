#include <SPI.h>
#include <Ethernet.h>
#include <OnionClient.h>
#include <OnionPacket.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>

Adafruit_NeoPixel board = Adafruit_NeoPixel(64,6);
byte mac[] = {0xDE,0xAD,0xBE,0xEF,0xFF,0xEE};
OnionClient client("kfItpX9p","OBdtLSEXOy4aY815");
char *SetParams[]={"led","R","G","B"};
char *DrawParam[]={"pic"};

const unsigned char onion_data[192] PROGMEM = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x01,0x04,0x07,0x01,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x02,0x08,0x02,0x06,0x15,0x05,0x10,0x03,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x01,0x11,0x04,0x0c,0x01,0x00,0x00,0x17,0x05,0x11,0x13,0x04,0x0e,0x05,0x01,0x04,0x00,0x00,0x00,0x04,0x01,0x03,0x13,0x04,0x0e,0x04,0x01,0x03,0x07,0x01,0x05,0x18,0x06,0x12,0x0d,0x03,0x0a,0x14,0x05,0x0f,0x06,0x01,0x05,0x13,0x04,0x0e,0x0c,0x03,0x09,0x00,0x00,0x00,0x13,0x04,0x0e,0x18,0x06,0x12,0x14,0x04,0x0f,0x09,0x02,0x07,0x14,0x05,0x0f,0x17,0x05,0x11,0x0c,0x03,0x09,0x00,0x00,0x00,0x16,0x05,0x10,0x18,0x06,0x12,0x16,0x05,0x10,0x08,0x02,0x06,0x17,0x05,0x11,0x0d,0x03,0x09,0x16,0x05,0x10,0x04,0x00,0x03,0x11,0x04,0x0d,0x18,0x06,0x12,0x10,0x04,0x0c,0x13,0x04,0x0e,0x0c,0x03,0x09,0x00,0x00,0x00,0x09,0x02,0x06,0x11,0x04,0x0d,0x11,0x04,0x0d,0x17,0x05,0x11,0x11,0x04,0x0c,0x09,0x02,0x06,0x00,0x00,0x00};
const unsigned char chan_data[192] PROGMEM = {0x00,0x00,0x00,0x01,0x06,0x01,0x01,0x06,0x00,0x00,0x00,0x00,0x02,0x07,0x02,0x08,0x13,0x06,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x23,0x0e,0x19,0x29,0x13,0x01,0x04,0x00,0x09,0x14,0x07,0x18,0x29,0x12,0x11,0x21,0x0d,0x00,0x00,0x00,0x01,0x09,0x01,0x06,0x1d,0x05,0x05,0x1d,0x04,0x03,0x0e,0x03,0x03,0x0e,0x02,0x05,0x1c,0x04,0x04,0x14,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x09,0x01,0x02,0x0a,0x02,0x00,0x02,0x00,0x00,0x04,0x00,0x02,0x0a,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x07,0x01,0x00,0x03,0x00,0x00,0x03,0x00,0x03,0x0b,0x03,0x01,0x05,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x0f,0x04,0x1d,0x2c,0x16,0x09,0x13,0x07,0x0d,0x18,0x0a,0x1f,0x2d,0x17,0x1a,0x2a,0x14,0x00,0x04,0x00,0x00,0x00,0x00,0x07,0x18,0x05,0x0b,0x20,0x08,0x06,0x15,0x05,0x02,0x0a,0x02,0x06,0x1d,0x05,0x04,0x15,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x01,0x02,0x10,0x02,0x02,0x0c,0x01,0x00,0x00,0x00,0x01,0x09,0x01,0x00,0x04,0x00,0x00,0x00,0x00};
const unsigned char space_data[192] PROGMEM = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00};
const unsigned char clear_data[192] PROGMEM = {0};

void setup() {
  board.begin();
  board.setBrightness(255);
  board.show();
  
  Ethernet.begin(mac);
  client.registerFunction("/set",SetPixel,SetParams,4);
  client.registerFunction("/draw",DrawPic,DrawParam,1);
  client.begin();
}

void loop() {
  client.loop();
}

void SetPixel(char** params) {
  uint16_t led = atoi(params[0]);
  uint16_t R = atoi(params[1]);
  uint16_t G = atoi(params[2]);
  uint16_t B = atoi(params[3]);
  board.setPixelColor(led,R,G,B);
  board.show();
}

void DrawPic(char** params) {
  char *data;
  if (!strcmp(params[0],"onion")) {
    data=(char*)onion_data;
  }
  else if (!strcmp(params[0],"chan")) {
    data=(char*)chan_data;
  }
  else if (!strcmp(params[0],"space")) {
    data=(char*)space_data;
  }
  else {
    data=(char*)clear_data;
  }
  for (int i = 0; i<64; i++) {
    board.setPixelColor(i,pgm_read_byte_near(&(data[3*i])),pgm_read_byte_near(&(data[3*i+1])),pgm_read_byte_near(&(data[3*i+2])));
  }
  board.show();
}
