#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/i2c.h"
#include "driver/gpio.h"



struct coordenadas
{
  uint8_t x;
  uint8_t y;
  uint8_t z;
}coord;

struct acelerometro
{
  uint8_t vel;
}accel;



void set_coord(void)
{

 i2c_slave_write_buffer(I2C_NUM_1, &coord.x, 8, 4);
 i2c_slave_write_buffer(I2C_NUM_1, &coord.y, 8, 4);
 i2c_slave_write_buffer(I2C_NUM_1, &coord.z, 8, 4);
}


void set_accel(void)
{
  accel.vel=0.0;
}

float get_coord_x(void)
{
  return coord.x;
}

float get_coord_y(void)
{
  return coord.y;
}

float get_coord_z(void)
{
  return coord.z;
}

float get_accel(void)
{
  return accel.vel;
}

void Control(void) /* Funcion que se encarga de interpretar los valores del giroscopio y del acelerometro */
{

float x,y,z,acel;

  x=get_coord_x();
  
  y=get_coord_y();
  
  z=get_coord_z();
  
  acel=get_accel();

  
  
  
}


void setup() 
{
  // put your setup code here, to run once:
 // Seleccionamos los pins que vamos a usar
 i2c_cmd_link_create();
 i2c_set_pin(I2C_NUM_1,39,38,GPIO_PULLUP_DISABLE,GPIO_PULLUP_DISABLE,I2C_MODE_SLAVE);
 i2c_set_pin(I2C_NUM_1,36,35,GPIO_PULLUP_DISABLE,GPIO_PULLUP_DISABLE,I2C_MODE_SLAVE);
 i2c_set_pin(I2C_NUM_1,27,25,GPIO_PULLUP_DISABLE,GPIO_PULLUP_DISABLE,I2C_MODE_SLAVE);
 i2c_set_pin(I2C_NUM_1,42,34,GPIO_PULLUP_DISABLE,GPIO_PULLUP_DISABLE,I2C_MODE_SLAVE);

}

void loop() 
{
  // put your main code here, to run repeatedly:

  set_coord();
  set_accel();
  Control();

}
