#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

int can_socket = socket(PF_CAN, SOCK_RAW. CAN_RAW);
