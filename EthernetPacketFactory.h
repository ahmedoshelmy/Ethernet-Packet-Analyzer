
#include <bits/stdc++.h>
#include "EthernetPacket.h"

#ifndef PACKETANALUZER_ETHERNETPACKETFACTORY_H
#define PACKETANALUZER_ETHERNETPACKETFACTORY_H



class EthernetPacketFactory {
public:
    void readPackets(std::string) ;
    void parsePackets() ;
    EthernetPacketFactory() ;
private:
   std::vector<std::string> EthernetPackets ;
};


#endif
