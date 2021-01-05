#include <usb/usb.h>
#include <usb/usbcfg.h>
#include <usb/usbhw.h>
#include <usb/usbcore.h>
#include <usb/cdc.h>
#include <usb/cdcuser.h>
#include <usb/mscuser.h>
#include <CDCSerial.h>
#include <usb/mscuser.h>

extern uint32_t MSC_SD_Init(uint8_t pdrv);

extern "C" void disk_timerproc();
void SysTick_Callback() { disk_timerproc(); }


void usb_cdc_idle() {
  MSC_RunDeferredCommands();
}

void usb_cdc_init() {
  USB_Init();                               // USB Initialization
  USB_Connect(FALSE);                       // USB clear connection
  delay(1000);                              // Give OS time to notice
  USB_Connect(TRUE);
  MSC_SD_Init(0);                         // Enable USB SD card access

  while (!USB_Configuration ) {
    delay(50);
    usb_cdc_idle();
  }
}
