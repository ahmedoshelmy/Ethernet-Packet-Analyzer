
#ifndef PACKETANALUZER_ETHERNETPACKETPARSER_H
#define PACKETANALUZER_ETHERNETPACKETPARSER_H


#include "EthernetPacket.h"
#include "EcpriEthernetPacket.h"


    
   
struct packet_parse_pos{
            int start;
            int sz;
};

std::unordered_map<std::string,packet_parse_pos> generic_m ;
std::unordered_map<std::string,packet_parse_pos> ecpri_payload_m;
  

    

class EthernetPacketParser {
private:
 
public:
    EthernetPacketParser(int sz) ;
    void parseEthernetPacket (EthernetPacket & EthernetPacketInstance );
    void parseEcpriPacket (EcpriEthernetPacket & EthernetPacketInstance );

};


#endif
