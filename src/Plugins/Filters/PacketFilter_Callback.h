/*
 * This file is part of USBProxy.
 */

#ifndef PACKETFILTER_CALLBACK_H_
#define PACKETFILTER_CALLBACK_H_

#include "PacketFilter.h"

typedef void (*f_cb)(Packet*);
typedef void (*f_cb_setup)(SetupPacket*,bool);

//uses function pointers to filter packets
class PacketFilter_Callback : public PacketFilter {
private:
	f_cb cb;
	f_cb_setup cb_setup;
public:
	PacketFilter_Callback(ConfigParser *cfg);
	PacketFilter_Callback(f_cb _cb, f_cb_setup _cb_setup);
	void filter_packet(Packet* packet);
	void filter_setup_packet(SetupPacket* packet,bool direction_out);
	virtual char* toString() {return (char*)"Filter";}

};

#endif /* PACKETFILTER_CALLBACK_H_ */
