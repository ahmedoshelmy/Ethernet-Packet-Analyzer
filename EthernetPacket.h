
#ifndef PACKETANALUZER_ETHERNETPACKET_H
#define PACKETANALUZER_ETHERNETPACKET_H

#include <bits/stdc++.h>

class EthernetPacket {
private:
    std::string raw_data;
    std::string preamble;
    std::string source_address;
    std::string destination_address;
    std::string type;
    std::string payload;
    std::string crc;
public:
    std::string getRawData() ;
    std::string getPreamble() ;
    std::string getSourceAddress() ;
    std::string getDestinationAddress() ;
    std::string getType() ;
    std::string getPayload() ;
    std::string getCrc() ;
    void setRawData(std::string) ;
    void setPreamble(std::string) ;
    void setSourceAddress(std::string) ;
    void setDestinationAddress(std::string) ;
    void setType(std::string) ;
    void setPayload(std::string) ;
    void setCrc(std::string) ;



};


#endif
