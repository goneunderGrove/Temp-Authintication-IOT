#include "mbed.h"
#include "BufferedSerial.h"
#include "mlx90614.h"
#include "ThisThread.h"


DigitalOut led(LED1);; //displays I2C wait
I2C i2c(PTE25,PTE24);   //sda,scl
BufferedSerial pc(USBTX, USBRX);  //serial usb config
char data[3];
MLX90614 IR_thermometer(&i2c);

float temp; //temperature in degrees C

int main() 
{
    i2c.frequency(100000);
    int count = 0;
    float sum = 0;
    if (CHECK_SUCCESS = true) // take temperature 5 times
    {
        while (count<5)
        {
            int result = i2c.read(0x50, data, sizeof(data));
            led=1; // if led1 on - waiting on I2C
            if (IR_thermometer.getTemp(&temp)) 
            {
                //gets temperature from sensor via I2C bus
                led = 0;
                sum += temp; // accumulate temperature values
                count++;
            }
            //wait for device to produce next temperature reading
            ThisThread::sleep_for(500ms);
        }
        float average= sum / 5;
        average= (average*1.8)+40;
        //print average temperature on PC
        if (average >100.1 )
        {
            printf(" Temperature is %5.1F degrees F\n", average);
            printf("Sending employee info to manager\n");
            printf("Access denied\n");
        }
        else 
        {
            printf(" Temperature is %5.1F degrees F\n", average);
            printf("Access granted\n");
        }

    }
    else  
    {
      printf("RFID invalid\n");
    }
    // calculate average temperature

}
