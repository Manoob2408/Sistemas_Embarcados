#include "MKL25Z4.h"
#include "Serial.h"
#include "IO.h"
#include "string.h"

void sendmessage(char * message) {
  UART0 -> D = 32;
  for (int i = 0; i <= strlen(message); i++) {
    for (int j = 0; j < 1000000; j++) {}
    UART0 -> D = message[i];
  }
}

int main(void) {
  PLL_Init();

  Serial_Init();

  uint8_t byteReceived = 0;

  ENABLE_PORTS(PORT_A);
  ENABLE_PORTS(PORT_C);

  SetPinMode(PORT_C, 13);

  for (;;) {
    if (GetPinValue(PORT_C, 13)) {

      sendmessage("EU AMO A FACENS - HAHAHA FALA DAPAZ");
    }
  }
  return 0;
}