
#include <bits/stdc++.h>
#include "EthernetPacket.h"

#ifndef PACKETANALUZER_ETHERNETPACKETFACTORY_H
#define PACKETANALUZER_ETHERNETPACKETFACTORY_H




class EthernetPacketFactory {
public:
    void readPackets(std::string) ;
    void parsePackets() ;
    void logPackets() ;
    EthernetPacketFactory() ;
private:
   int packetCount ;
   std::vector<std::string> EthernetPacketsStrings ; // Raw data of the ethernet packets
   std::vector<EthernetPacket *> EthernetPackets ; // Ethernet packets after parsing

};


#endif
