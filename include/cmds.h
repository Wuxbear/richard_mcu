#ifndef __CMDS_H__
#define __CMDS_H__

typedef enum CMDS_t {
	CMD_SELFTEST = 0,
	CMD_SENSOR,
	CMD_I2C,
	CMD_NET,
	CMD_GPIO,
	CMD_NONE
} CMDS;

#endif	//__CMDS_H__

