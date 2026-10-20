#include <cstdio>
#include <cstring> //memcpy memset etc
#include <cstdlib>
#include <unistd.h> //r,w,close file descriptor

#include <net/if.h> //stocgifindex, network interface
#include <sys/types.h>
#include <sys/socket.h> //the socket stuff
#include <sys/ioctl.h> //ioctrl, catch all for file descriptor thats not just read or write

#include <linux/can.h> //can sock stuff
#include <linux/can/raw.h> //raw can stuff

int my_can_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
 
struct ifreq ifr; 
strcpy(ifr.ifr_name, "can0"); 
ioctl(my_can_socket, STOCGIFINDEX, &ifr); 


struct sockaddr_can addr; 
memset(&addr, 0, sizeof(addr));
addr.can_family = AF_CAN; 
addr.can_ifindex = ifr.ifr_ifindex;

bind(my_can_socket, (struct sockaddr *)&addr, sizeof(addr));
