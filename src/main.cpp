#include <Arduino.h>

#include "usb_cdc.h"
#include <CDCSerial.h>

//////////////////////////////
// Select one of these boards
//#define SKR1_3
#define SKR1_4
//////////////////////////////

#define X_STEP_PIN                         P2_02
#define X_DIR_PIN                          P2_06
#define X_ENABLE_PIN                       P2_01

#define Y_STEP_PIN                         P0_19
#define Y_DIR_PIN                          P0_20
#define Y_ENABLE_PIN                       P2_08

#define Z_STEP_PIN                         P0_22
#define Z_DIR_PIN                          P2_11
#define Z_ENABLE_PIN                       P0_21

#define E0_STEP_PIN                        P2_13
#define E0_DIR_PIN                         P0_11
#define E0_ENABLE_PIN                      P2_12

#ifdef SKR1_3
  #define E1_STEP_PIN                      P0_01
  #define E1_DIR_PIN                       P0_00
  #define E1_ENABLE_PIN                    P0_10
#elif defined(SKR1_4)
    #define E1_STEP_PIN                        P1_15
    #define E1_DIR_PIN                         P1_14
    #define E1_ENABLE_PIN                      P1_16
#endif


#define FAN0 P2_03 //on skr 14
#define LED_BUILTIN FAN0

void setup() {
  usb_cdc_init();
  UsbSerial.println("Starting...");
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(X_STEP_PIN   , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
  pinMode(X_ENABLE_PIN , OUTPUT);

  pinMode(Y_STEP_PIN   , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN , OUTPUT);

  pinMode(Z_STEP_PIN   , OUTPUT);
  pinMode(Z_DIR_PIN    , OUTPUT);
  pinMode(Z_ENABLE_PIN , OUTPUT);

  pinMode(E0_STEP_PIN  , OUTPUT);
  pinMode(E0_DIR_PIN   , OUTPUT);
  pinMode(E0_ENABLE_PIN, OUTPUT);

  pinMode(E1_STEP_PIN  , OUTPUT);
  pinMode(E1_DIR_PIN   , OUTPUT);
  pinMode(E1_ENABLE_PIN, OUTPUT);

  digitalWrite(X_ENABLE_PIN   , LOW);
  digitalWrite(Y_ENABLE_PIN   , LOW);
  digitalWrite(Z_ENABLE_PIN   , LOW);
  digitalWrite(E0_ENABLE_PIN  , LOW);
  digitalWrite(E1_ENABLE_PIN  , LOW);
}

void loop () {

  if (millis() %1000 <500)
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);

  if (millis() %10000 <5000) {
    digitalWrite(X_DIR_PIN    , HIGH);
    digitalWrite(Y_DIR_PIN    , HIGH);
    digitalWrite(Z_DIR_PIN    , HIGH);
    digitalWrite(E0_DIR_PIN   , HIGH);
    digitalWrite(E1_DIR_PIN   , HIGH);
  }
  else {
    digitalWrite(X_DIR_PIN    , LOW);
    digitalWrite(Y_DIR_PIN    , LOW);
    digitalWrite(Z_DIR_PIN    , LOW);
    digitalWrite(E0_DIR_PIN   , LOW);
    digitalWrite(E1_DIR_PIN   , LOW);
  }

  digitalWrite(X_STEP_PIN    , HIGH);
  digitalWrite(Y_STEP_PIN    , HIGH);
  digitalWrite(Z_STEP_PIN    , HIGH);
  digitalWrite(E0_STEP_PIN   , HIGH);
  digitalWrite(E1_STEP_PIN   , HIGH);
  delay(1);

  digitalWrite(X_STEP_PIN    , LOW);
  digitalWrite(Y_STEP_PIN    , LOW);
  digitalWrite(Z_STEP_PIN    , LOW);
  digitalWrite(E0_STEP_PIN   , LOW);
  digitalWrite(E1_STEP_PIN   , LOW);

  usb_cdc_idle();
}