/*
 * ethernet.c
 *
 *  Created on: 4 mrt. 2025
 *      Author: geert
 */

#include "ethernet.h"

#include "../../gpio/gpio.h"
#include "../../spi/spi.h"
#include "../../rcc/rcc.h"
#include "../../timer/simpel_timer/simpel_timer.h"

#include "../w5500/wizchip_conf.h"
#include "../w5500/dhcp.h"
#include "../w5500/W5500/w5500.h"

#define ETH_MAX_BUF_SIZE	2048

static ethernet_status_t status = ETHERNET_STATUS_NOT_INIT;
static ethernet_ip_t ip;
static ethernet_mode_t mode = ETHERNET_MODE_DHCP;

static uint8_t dhcpEthernetBuffer[ETH_MAX_BUF_SIZE];

void TIM7_IRQHandler(){
	static int tick = 0;
	if(simpel_timer_interrupt_pending(SIMPEL_TIMER_7)){
		simpel_timer_interrupt_acknolede(SIMPEL_TIMER_7);
		DHCP_time_handler();
	}
}

static void ethernet_spi_write(uint8_t data){
	spi_transfer(SPI_2, data);
}

static uint8_t ethernet_spi_read(){
	return spi_transfer(SPI_2, 0x00);
}

static void ethernet_select(){
	gpio_reset(GPIO_PORT_B, GPIO_PIN_1); //deselect chip
}

static void ethernet_deselect(){
	gpio_set(GPIO_PORT_B, GPIO_PIN_1); //deselect chip
}

static void ethernet_w5500_setup(){
	simpel_timer_setup(SIMPEL_TIMER_7, 47999 , 1000);

	reg_wizchip_spi_cbfunc(ethernet_spi_read, ethernet_spi_write);
	reg_wizchip_cs_cbfunc(ethernet_select, ethernet_deselect);
}

static void ethernet_w5500_init(){
	wiz_NetInfo net = {0};
	//ip mode = static IP
	net.dhcp = NETINFO_STATIC;
	//mac adress
	net.mac[0] = 0xEE;
	net.mac[1] = 0x9D;
	net.mac[2] = 0x10;
	net.mac[3] = 0xFD;
	net.mac[4] = 0xED;
	net.mac[5] = 0xE6;

	//subnet mask
	net.sn[0] = 0xff;
	net.sn[1] = 0xff;
	net.sn[2] = 0xff;
	net.sn[3] = 0x00;

	//static IP address
	ip.ip[0] = 192;
	ip.ip[1] = 168;
	ip.ip[2] = 2;
	ip.ip[3] = 180;

	net.ip[0] = ip.ip[0];
	net.ip[1] = ip.ip[1];
	net.ip[2] = ip.ip[2];
	net.ip[3] = ip.ip[3];

	//router / gateway IP
	net.gw[0] = 0;
	net.gw[1] = 0;
	net.gw[2] = 0;
	net.gw[3] = 0;

	wizchip_setnetinfo(&net);
}

static void ethernet_spi_setup(){
	rcc_apb1_clock_enable(RCC_APB1_SPI2);
	rcc_ahb_clock_enable(RCC_AHB_GPIOB);

	gpio_set_mode(GPIO_PORT_B, GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_MODE_ALTERNATE_FUNCTION);
	gpio_set_alternate_function(GPIO_PORT_B, GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_AF0); //SPI 2
	gpio_set_output_settings(GPIO_PORT_B, GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_OUTPUT_TYPE_DEFAULT, GPIO_OUTPUT_SPEED_HIGH);
	gpio_set_input_settings(GPIO_PORT_B, GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_INPUT_TYPE_NORMAL);

	gpio_set_mode(GPIO_PORT_B, GPIO_PIN_1, GPIO_MODE_OUTPUT);
	gpio_set(GPIO_PORT_B, GPIO_PIN_1); //deselect chip

	spi_set_master_mode(SPI_2);
	spi_set_data_size(SPI_2, SPI_DATA_SIZE_8);
	spi_set_mode(SPI_2, SPI_MODE_0);
	spi_set_baudrate(SPI_2, SPI_BAUDRATE_DIV2);
	spi_set_frame_format(SPI_2, SPI_FRAME_FORMAT_MSB);
	spi_set_software_slave_management(SPI_2);
	spi_enable(SPI_2);

	core_clock_delay(100);
}

ethernet_status_t ethernet_get_status(){
	return status;
}

void ethernet_set_mode_static_ip(ethernet_ip_t* ip_n){
	ip.ip32 = ip_n->ip32;
	setSIPR(&(ip.ip[0]));
	if(mode == ETHERNET_MODE_STATIC) return;
	mode = ETHERNET_MODE_STATIC;
}

void ethernet_set_mode_dhcp_ip(){
	if(mode == ETHERNET_MODE_DHCP) return;
	mode = ETHERNET_MODE_DHCP;
	DHCP_init(0, dhcpEthernetBuffer);
}

ethernet_mode_t ethernet_get_mode(){
	return mode;
}

void ethernet_run(){
	int link = wizphy_getphylink();

	if(!link || status != ETHERNET_STATUS_NO_IP || mode != ETHERNET_MODE_DHCP){
		simpel_timer_disable(SIMPEL_TIMER_7);
	}else{
		simpel_timer_enable(SIMPEL_TIMER_7);
	}

	if(!link){
		status = ETHERNET_STATUS_NO_LINK;
		return;
	}

	if(status == ETHERNET_STATUS_NO_LINK){
		status = ETHERNET_STATUS_NO_IP;
		DHCP_init(0, dhcpEthernetBuffer);
	}
	if(mode == ETHERNET_MODE_DHCP && status == ETHERNET_STATUS_NO_IP){
		//proccess dhcp request
		if(DHCP_run() == DHCP_IP_LEASED){
			DHCP_stop();
			getSIPR(&(ip.ip[0]));
			status = ETHERNET_STATUS_READY;
		}
	}
	if(mode == ETHERNET_MODE_STATIC && status == ETHERNET_STATUS_NO_IP){
		setSIPR(&(ip.ip[0]));
		DHCP_stop();
		status = ETHERNET_STATUS_READY;
	}
}

void ethernet_config(){
	ethernet_spi_setup();
	ethernet_w5500_setup();
	ethernet_w5500_init();
	ip.ip32 = 0;
	status = ETHERNET_STATUS_NO_LINK;
}
