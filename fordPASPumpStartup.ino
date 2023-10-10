//CanTX pin - gpio 19
//CanRX pin - gpio 18

#include <esp32_can.h>

byte byte0 = 0x04;
byte byte1 = 0x3C;
byte byte2 = 0x3F;
byte byte3 = 0x56;
byte byte4 = 0x00;
byte byte5 = 0x00;
byte byte6 = 0x00;
byte byte7 = 0x80;

//canbus
CAN_FRAME outframe;

void Frames10MS()
{
static unsigned long timer10ms = millis();   

  if (millis() - timer10ms >= 10) 
    {
    timer10ms=millis();
    // 0x201
    outframe.id = 0x201;            // Set our transmission address ID
    outframe.length = 8;            // Data payload 8 bytes
    outframe.extended = 0;          // Extended addresses - 0=11-bit 1=29bit
    outframe.rtr=0;                 //No request
    outframe.data.uint8 [0]=byte0;
    outframe.data.uint8 [1]=byte1; 
    outframe.data.uint8 [2]=byte2;
    outframe.data.uint8 [3]=byte3;
    outframe.data.uint8 [4]=byte4;
    outframe.data.uint8 [5]=byte5;
    outframe.data.uint8 [6]=byte6;
    outframe.data.uint8 [7]=byte7;
    Can0.sendFrame(outframe); 
    }    
}

void setup() {  
  CAN_cfg.tx_pin_id = GPIO_NUM_19;
  CAN_cfg.rx_pin_id = GPIO_NUM_18;
  CAN0.begin(500000);// Initialize CAN0 and set baud rate.
}//end setup----------------------------------------------------------------------------------------------------------

void loop() {
Frames10MS();
}
