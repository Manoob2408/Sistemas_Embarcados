#ifndef IO_H_
#define IO_H_

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4

void ENABLE_PORTS(int port);
void SetPinMode(int port, int pin);
void Pin_OutputMode(int port, int pin);
void Pin_Set(int port, int pin);
void Pin_Clear(int port, int pin);
int GetPinValue(int port, int pin);
#endif /* IO_H_ */