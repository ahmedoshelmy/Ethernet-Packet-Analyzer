
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
   std::vector<std::string> EthernetPacketsStrings ;
   std::vector<EthernetPacket *> EthernetPackets ;

};


#endif
