#include "mbed.h"
#include <cstdio>


// Blinking rate in milliseconds
#define SLEEP     500ms

AnalogIn   potBase(PA_0);
AnalogIn   potS1(PA_1);
AnalogIn   potS2(PA_4);
AnalogIn   potS3(PB_0);
AnalogIn   potS4(PC_1);
AnalogIn   potS5(PC_0);
AnalogIn   potslider(PC_5);

static BufferedSerial usb(USBTX, USBRX);


int main()
{
    printf("start");
    usb.set_baud(9600);
    usb.set_format(8, BufferedSerial::None, 1);

    char buf[32] = {0};

    while (true) 
    {
        if (uint32_t num = usb.read(buf, sizeof(buf)))
        {
            printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", int(potBase.read_u16()/218.5), int(potS1.read_u16()/218.5), int(potS2.read_u16()/218.5), int(potS3.read_u16()/218.5), int(potS4.read_u16()/218.5), int(potS5.read_u16()/218.5), int(potslider.read_u16()/655));
        }
    }
}
