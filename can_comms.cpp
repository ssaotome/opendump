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
#include <thread>
#include <chrono>

void build_obd_ask(struct can_frame* obd_frame, int code){
	memset(&obd_frame, 0, sizeof(obd_frame)); //11 bytes frames. 8 data. OBD defines padding 0x55... or 0x00
	obd_frame->id = 0x7DF; //request type, diff numbers diff ECUs
	obd_frame->dlc = 8; //data bytes, OBD spec defines 8 per
	obd_frame->data[0] = 0x02; //num rel bytes, in my case just 2 per cause 1 data mode and 1 byte of actual data
	obd_frame->data[1] = 0x01; //obd data mode
	obd_frame->data[2] = code;
}

void smart_write(){
}

int main(){

//setup, used AI to generate this, but basically makes and endpoint for us to send and receive data, and connects it to the program
int s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
struct ifreq ifr;
strcpy(ifr.ifr_name "can0");
ioctl(s, STOCGIFINDEX, &ifr);
struct sockaddr_can addr;
memset(&addr, 0, sizeof(addr));
addr.can_family = AF_CAN;
addr.can_ifindex = ifr_ifindex;
bind(s, (struct sockaddr *)&addr, sizeof(addr)); //socket: heres your phone. bind: now its connected to the net to accept/make calls

struct can_filter rfilter[1]; //receive filter
rfilter[0].can_id = 0x7E8; // ecu outputs
rfilter[0].can_mask = 0x7FF;

setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));

std::cout << "CAN SOCKET READY" << std::endl;
bool running = true;

int oil_pid = 0x5C; //slow
int coolant_pid = 0x05; //slow
int iat_pid = 0x0F; //medium
int map_pid = 0x0B; //fast
int baro_pid = 0x33; //fast
		    //
struct can_frame oil_frame;
struct can_frame coolant_frame;
struct can_frame iat_frame;
struct can_frame baro_frame;
struct can_frame map_frame;

build_obd_ask(&oil_frame, oil_pid);
build_obd_ask(&coolant_frame, coolant_pid);
build_obd_ask(&iat_frame, iat_pid);
build_obd_ask(&baro_frame, baro_pid);
build_obd_ask(&map_frame, map_pid);

struct can_frame oil_out;
struct can_frame coolant_out;
struct can_frame iat_out;
struct can_frame baro_out;
struct can_frame map_out;
//loop
while(running){

	write(s,&oil_frame,sizeof(oil_frame) //ask
	read(s, &oil_frame, sizeof(oil_frame)
	if(oil_frame.id == 0x7E8 && oil_frame.data[2] == oil_pid){ 
	
		int oil_temp = oil_frame.data[3] - 40; //just one byte, comes in the next spot in the data region
		std::cout << "Oil Temp (C): "<< oil_temp << std::endl; }
	else{
		continue
	}


	write(s,&coolant_frame,sizeof(coolant_frame) //ask
	read(s, &coolant_frame, sizeof(coolant_frame)
	if(coolant_frame.id == 0x7E8 && coolant_frame.data[2] == coolant_pid){ 
	
		int oil_temp = oil_obd_frame.data[3] - 40; 
		std::cout << "Coolant Temp (C): "<< oil_temp << std::endl; }
	else{
		continue
	}

	write(s,&oil_obd_frame,sizeof(oil_obd_frame) //ask
	read(s, &oil_out_frame, sizeof(oil_out_frame)
	if(oil_out_frame.id == 0x7E8 && oil_out_frame.data[2] == oil_pid){ 
	
		int oil_temp = oil_obd_frame.data[3] - 40; 
		std::cout << "IAT Temp (C): "<< oil_temp << std::endl; }
	else{
		continue
	}

	write(s,&oil_obd_frame,sizeof(oil_obd_frame) //ask
	read(s, &oil_out_frame, sizeof(oil_out_frame)
	if(oil_out_frame.id == 0x7E8 && oil_out_frame.data[2] == oil_pid){ 
	
		int oil_temp = oil_obd_frame.data[3] - 40;
		std::cout << "Oil Temp (C): "<< oil_temp << std::endl; }
	else{
		continue
	}

	write(s,&oil_obd_frame,sizeof(oil_obd_frame) //ask
	read(s, &oil_out_frame, sizeof(oil_out_frame)
	if(oil_out_frame.id == 0x7E8 && oil_out_frame.data[2] == oil_pid){ 
	
		int oil_temp = oil_obd_frame.data[3] - 40;
		std::cout << "Oil Temp (C): "<< oil_temp << std::endl; }
	else{
		continue
	}

return 0;
}


typedef struct{

oil_temp; //raw - 40 = temp (C)
coolant_temp; // raw - 40 = temp (C)
boost_pressure; //raw //raw
iat; //raw - 40 = temp (C)


} RAW_ENGINE_INFO;

float kpa_psi_factor = 0.145038;
float BOOST_PRESSURE_PSI = kpa_psi_factor*(raw_map - raw_baro);




















