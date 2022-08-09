#include <Wire.h>
#include "vfd_driver/src/vfd_pin_driver.h"

void string_fill_tx_buf(char *buf);
void symbol_fill_tx_buf(char *buf);
void throw_fatal_error(char *msg);

void
setup()
{
    Serial.begin(9600);
    Wire.begin();   

    Serial.println("Starting transmission");
}


uint8_t low = 0;
void
loop()
{
    Serial.println("Enter 1 for string, 2 for symbol");

    while(Serial.available() < 2)
        ;

    char tx_buf[5];

    char cmd_code = Serial.read();
    Serial.read();
    
    switch(cmd_code)
    {
        case '1':
            tx_buf[0] = 0x01;
            string_fill_tx_buf(&(tx_buf[1]));
            break;
        
        case '2':
            tx_buf[0] = 0x02;
            symbol_fill_tx_buf(&(tx_buf[1]));
            break;

        default:

            break;
    }
    
    Serial.print(tx_buf[0]);
    Serial.print(tx_buf[1]);
    Serial.print(tx_buf[2]);
    Serial.print(tx_buf[3]);
    Serial.println(tx_buf[4]);


    int status;
    do
    {
        Wire.beginTransmission(99);
        
        // command code
        Wire.write(tx_buf[0]);

        // data
        Wire.write(tx_buf[1]);
        Wire.write(tx_buf[2]);
        Wire.write(tx_buf[3]);
        Wire.write(tx_buf[4]);

        status = Wire.endTransmission();
    } while(status != 0);
}

void string_fill_tx_buf(char *tx_buf)
{
    Serial.println("Enter the 4 character string");

    while(Serial.available() < 5) // account for newline
        ;

    tx_buf[0] = Serial.read();
    tx_buf[1] = Serial.read();
    tx_buf[2] = Serial.read();
    tx_buf[3] = Serial.read();

    // flush the newline
    Serial.read();
}

void symbol_fill_tx_buf(char *tx_buf)
{
    Serial.println("Enter a comma separated combination of the below options:");

    Serial.print(0); Serial.println(" : Mail symbol");
    Serial.print(1); Serial.println(" : Power symbol");
    Serial.print(2); Serial.println(" : House symbol");
    Serial.print(3); Serial.println(" : 5.1 symbol");
    Serial.print(4); Serial.println(" : HDTV symbol");
    Serial.print(5); Serial.println(" : 480 symbol");
    Serial.print(6); Serial.println(" : 480i symbol");
    Serial.print(7); Serial.println(" : 480p symbol");
    Serial.print(8); Serial.println(" : Colon symbol");
    Serial.print(9); Serial.println(" : Rec symbol");
    Serial.print(10); Serial.println(" : Auto symbol");
    Serial.print(11); Serial.println(" :  1080 symbol");
    Serial.print(12); Serial.println(" : 720p symbol");
    Serial.print(13); Serial.println(" : 720 symbol");
    Serial.print(14); Serial.println(" : 720i symbol");
    Serial.print(15); Serial.println(" : 1080i symbol");
    Serial.print(16); Serial.println(" : 1080p symbol");

    char buf[50];
    int buf_index = -1;

    do
    {
        buf_index ++;
        while(Serial.available() < 1)
            ;
        buf[buf_index] = Serial.read();
    } while(buf_index < 49 && buf[buf_index] != '\n');

    buf_index --;

    uint32_t flags = 0x00000000;

    for(;;)
    {

        int this_selection = 0;
        int multiplier = 1;

        while(buf[buf_index] != ',')
        {
            this_selection += (buf[buf_index] - '0') * multiplier;
            multiplier *= 10;
            if(buf_index == 0)
            {
                break;
            }
            buf_index --;
        }

        Serial.println(this_selection);

        switch(this_selection)
        {
            case 0:
                flags |= SYMB_FLAG_MAIL;
                break;
            
            case 1:
                flags |= SYMB_FLAG_POWER;
                break;
            
            case 2:
                flags |= SYMB_FLAG_HOUSE;
                break;
            
            case 3:
                flags |= SYMB_FLAG_5_1;
                break;
            
            case 4:
                flags |= SYMB_FLAG_HDTV;
                break;
            
            case 5:
                flags |= SYMB_FLAG_480;
                break;
            
            case 6:
                flags |= SYMB_FLAG_480_i;
                break;
            
            case 7:
                flags |= SYMB_FLAG_480_p;
                break;
            
            case 8:
                flags |= SYMB_FLAG_COLON;
                break;
            
            case 9:
                flags |= SYMB_FLAG_REC;
                break;
            
            case 10:
                flags |= SYMB_FLAG_AUTO;
                break;
            
            case 11:
                flags |= SYMB_FLAG_1080;
                break;
            
            case 12:
                flags |= SYMB_FLAG_720_p;
                break;
            
            case 13:
                flags |= SYMB_FLAG_720;
                break;
            
            case 14:
                flags |= SYMB_FLAG_720_i;
                break;
            
            case 15:
                flags |= SYMB_FLAG_1080_i;
                break;
            
            case 16:
                flags |= SYMB_FLAG_1080_p;
                break;
            
            default:
                Serial.println("Unknown value entered");
                break;
        }

        if(buf_index == 0)
        {
            break;
        }
    }

    tx_buf[0] = flags >> 24;
    tx_buf[1] = flags >> 16;
    tx_buf[2] = flags >> 8;
    tx_buf[3] = flags >> 0;
}


void throw_fatal_error(char *msg)
{
    Serial.print("FATAL ERROR: ");
    Serial.println(msg);
    for(;;)
    {
        asm("nop");
    }
}

/*
    This is for the I2C (not very built in) BIST
*/


    /*
    int status;  
    for(;;)
    {
        
        //    Continue sending the packet as long
        //    as we keep receiving NACKs
        

        if(low % 2 == 0)
        {
            Wire.beginTransmission(99);
            Wire.write((uint8_t)(0x10) | low);
            Wire.write((uint8_t)(0x20) | low);
            Wire.write((uint8_t)(0x30) | low);
            Wire.write((uint8_t)(0x40) | low);
            Wire.write((uint8_t)(0x50) | low);
            status = Wire.endTransmission();
        }
        else
        {
            Wire.beginTransmission(99);
            Wire.write((uint8_t)(0xde));
            Wire.write((uint8_t)(0xde));
            Wire.write((uint8_t)(0xde));
            Wire.write((uint8_t)(0xde));
            Wire.write((uint8_t)(0xde));
            status = Wire.endTransmission();
        }


        if(status == 0)
        {
            break;
        }
        else if(status == 1)
        {
            throw_fatal_error("status = 1: Data too long to fit in transmit buffer");
        }
        else if(status == 2)
        {
            throw_fatal_error("status = 2: Received address NACK");
        }
        else if(status == 3)
        {
            Serial.println("status = 3: Received data NACK. Retrying...");
        }
        else if(status == 4)
        {
            throw_fatal_error("status = 4: Other error");
        }
        else if(status == 5)
        {
            throw_fatal_error("status = 5: Timeout error");
        }
        else
        {
            throw_fatal_error("Unknown status value");
        }
    }

    Serial.println("SUCCESS");
    low ++;
    */