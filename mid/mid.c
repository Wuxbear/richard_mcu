
#include <stdio.h>
#include <string.h>

#include "include/cmds.h"
#include "include/type.h"
#include "include/driver.h"
#include "include/errors.h"
#include "include/ds.h"

struct system sys;
struct system *sysp = &sys;

struct cmdcast {
	s8 *cmd;
	ERR_CODE (*func)(void);
};

s8 cmd[32] = {0};
s8 data[128] = {0};

ERR_CODE cmd_sysinfo(void)
{
	//sysinfo func
	printf("sysinfo! data: %s\n", data);
	return ERR_NONE;
}

ERR_CODE cmd_selftest(void)
{
	//diagnostic func
	printf("selftest! data: %s\n", data);
	//process data and selftest
	return ERR_NONE;
}

ERR_CODE cmd_sensor(void)
{
	//get the sensor data
	//call i2c, spi driver
	printf("sensor! data: %s\n", data);
	//process data and control sensor 
	return ERR_NONE;
}

ERR_CODE cmd_net(void)
{
	//call ethernt protocol
	printf("net! data: %s\n", data);
	//setup net ?
	return ERR_NONE;
}

ERR_CODE cmd_gpio(void)
{
	//control gpio
	//call gpio driver
	printf("gpio! data: %s\n", data);
	//gpio control
	return ERR_NONE;
}

struct cmdcast cmdlist[] = {
	{"sysinfo", cmd_sysinfo},
	{"selftest", cmd_selftest},
	{"gpio",  cmd_gpio},
	{"sensor",  cmd_sensor},
	{"net",  cmd_net}
};

ERR_CODE cmd_process(s8 *cbuf)
{
	u8 i;

	memset(cmd, sizeof(cmd), 0);
	memset(data, sizeof(data), 0);

	sscanf(cbuf, "%[^:]:%s", cmd, data);
	//printf("cmd: %s, data: %s\n", cmd, data);
	//printf("sizeof: %ld\n", sizeof(cmdlist)/sizeof(struct cmdcast));

	for (i = 0; i < sizeof(cmdlist)/sizeof(struct cmdcast); i++)
	{
		if (0 == strcmp(cmd, cmdlist[i].cmd))
		{
			return cmdlist[i].func();
		}
	}	

	return ERR_NOCMD;
}

int system_init(void)
{
	sysp->sw_version = "v0.0.0";
	sysp->hw_version = "platformA_v0";

	//ipv4, ipv6?
	strncpy (sysp->ip_address, "127.0.0.1", 10);
	sysp->ip_port = 9999;
		

	driver_init();

}

