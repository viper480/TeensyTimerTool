#include "TeensyTimerTool.h"
using namespace TeensyTimerTool;

PeriodicTimer t1(TCK);
PeriodicTimer t2(TCK);

void isr1()
{
    Serial.printf("called @: %u ms\n", millis());
}

void isr2()
{
    digitalToggleFast(LED_BUILTIN);
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    t1.begin(isr1, 5.02s);  // instead of 5020000
    t2.begin(isr2, 25ms);   // instead of   25000
}

void loop()
{
}