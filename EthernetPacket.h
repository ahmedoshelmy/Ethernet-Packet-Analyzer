
#ifndef PACKETANALUZER_ETHERNETPACKET_H
#define PACKETANALUZER_ETHERNETPACKET_H

#include"pch.h"

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
public:
    std::string getRawData() const { return preamble; }
    std::string getPremable() const { return preamble; }
    std::string getSourceAddress() const { return source_address; }
    std::string getDestinationAddress() const { return destination_address; }
    std::string getType() const { return type; }
    std::string getPayload() const { return payload; }
    std::string getCrc() const { return crc; }


    friend EthernetPacketParser;




};


#endif
