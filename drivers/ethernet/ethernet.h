/*
 * ethernet.h
 *
 *  Created on: 4 mrt. 2025
 *      Author: geert
 */

#ifndef DRIVERS_ETHERNET_ETHERNET_H_
#define DRIVERS_ETHERNET_ETHERNET_H_

#include "../../common.h"

typedef enum {
	ETHERNET_STATUS_NOT_INIT,
	ETHERNET_STATUS_NO_LINK,
	ETHERNET_STATUS_NO_IP,
	ETHERNET_STATUS_READY
} ethernet_status_t;

typedef enum {
	ETHERNET_MODE_DHCP,
	ETHERNET_MODE_STATIC
} ethernet_mode_t;

typedef union {
	uint32_t ip32;
	uint8_t ip[4];
} ethernet_ip_t;

ethernet_status_t ethernet_get_status();
void ethernet_set_mode_static_ip(ethernet_ip_t* ip);
void ethernet_set_mode_dhcp_ip();
ethernet_mode_t ethernet_get_mode();
void ethernet_run();
void ethernet_config();

#endif /* DRIVERS_ETHERNET_ETHERNET_H_ */
