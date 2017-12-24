#ifndef __DS__
#define __DS__

typedef struct _header {
	void *dp;
	unsigned int length;
	char data[0];
} header;

struct system {
	//version
	char *sw_version;
	char *hw_version;

	//ip setup
	char ip_address[128];
	char ip_mask;
	char ip_gw;
	unsigned int ip_port;

	char client_ip[128];

	//mid
	

	//driver function pointer
	int (*gpio_driver)(void *d);
	int (*i2c_driver)(void *d);
	int (*spi_driver)(void *d);
	int (*net_driver)(void *d);

};

#endif

