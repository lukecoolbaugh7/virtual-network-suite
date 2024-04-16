#ifndef __TUNTAP_H
#define __TUNTAP_H

#include <fcntl.h> 
#include <string.h> 
#include <sys/ioctl.h> 
#include <unistd.h> 
#include <net/if.h> 

#include <sys/kern_control.h> 
#include <sys/kern_event.h> 
#include <sys/socket.h> 
#include <sys/sys_domain.h> 

int tap_alloc(char* dev); 

#endif