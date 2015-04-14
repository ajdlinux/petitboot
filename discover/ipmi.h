#ifndef _IPMI_H
#define _IPMI_H

#include <stdbool.h>
#include <stdint.h>

enum ipmi_netfn {
	IPMI_NETFN_CHASSIS = 0x0,
};

enum ipmi_cmd {
	IPMI_CMD_CHASSIS_SET_SYSTEM_BOOT_OPTIONS	= 0x08,
	IPMI_CMD_CHASSIS_GET_SYSTEM_BOOT_OPTIONS	= 0x09,
};

enum ipmi_bootdev {
	IPMI_BOOTDEV_NONE = 0x00,
	IPMI_BOOTDEV_NETWORK = 0x01,
	IPMI_BOOTDEV_DISK = 0x2,
	IPMI_BOOTDEV_SAFE = 0x3,
	IPMI_BOOTDEV_CDROM = 0x5,
	IPMI_BOOTDEV_SETUP = 0x6,
};

struct ipmi;

bool ipmi_present(void);
bool ipmi_bootdev_is_valid(int x);
struct ipmi *ipmi_open(void *ctx);

int ipmi_transaction(struct ipmi *ipmi, uint8_t netfn, uint8_t cmd,
		uint8_t *req_buf, uint16_t req_len,
		uint8_t *resp_buf, uint16_t *resp_len,
		int timeout_ms);

#endif /* _IPMI_H */