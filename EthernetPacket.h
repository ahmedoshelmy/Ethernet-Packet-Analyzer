
#ifndef PACKETANALUZER_ETHERNETPACKET_H
#define PACKETANALUZER_ETHERNETPACKET_H

#include"pch.h"


struct packet_parse_pos{
    int start;
    int sz;
};


class EthernetPacketParser;

class EthernetPacket {
protected:
    std::string raw_data;
    std::string preamble;
    std::string source_address;
    std::string destination_address;
    std::string type;
    std::string payload;
    std::string crc;
    int sz ;
    void parsePacket() ;
public:

    virtual void logPacket() ;

    explicit EthernetPacket(std::string) ;

};


#endif
