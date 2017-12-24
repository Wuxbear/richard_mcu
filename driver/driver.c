#include "include/ds.h"

//#define CHIP CHIP##AAAA
#include "driver/chips/chipA.c"

int driver_init(struct system *p)
{
	//function pointer mapping for each arch
//#ifdef CHIP_A
	p->gpio_driver = chipA_gpio_drv;
	p->i2c_driver = chipA_i2c_drv;
	p->spi_driver = chipA_spi_drv;
	p->net_driver = chipA_net_drv;
//#endif //CHIP_A

	return 0;
}

