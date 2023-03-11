#include "mbed.h"

class MLX90614{

    public:
        /** Create MLX90614 interface, initialize with selected I2C port and address.
        *
        * @param i2c I2C device pointer
        * @param addr Device address(default=0xB4)  
        */    
        MLX90614(I2C* i2c,int addr=0xB4);
        
        /** Get Temperature data from MLX90614. 
        *
        * @param temp_val return valiable pointer
        * @return 0 on success (ack), or non-0 on failure (nack)
        */
        bool getTemp(float* temp_val);
        
    private:
       I2C* i2c;
       int i2caddress;

};