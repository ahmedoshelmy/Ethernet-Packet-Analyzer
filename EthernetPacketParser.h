
#ifndef PACKETANALUZER_ETHERNETPACKETPARSER_H
#define PACKETANALUZER_ETHERNETPACKETPARSER_H


#include "EthernetPacket.h"

class EthernetPacketParser {
public:
    EthernetPacketParser() ;
    void parseEthernetPacket (EthernetPacket EthernetPacketInstance );
    void parseEcpriPacket (EthernetPacket EthernetPacketInstance );

};


#endif
