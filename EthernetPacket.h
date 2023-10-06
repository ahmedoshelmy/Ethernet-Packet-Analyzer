
#ifndef PACKETANALUZER_ETHERNETPACKET_H
#define PACKETANALUZER_ETHERNETPACKET_H

#include <bits/stdc++.h>

class EthernetPacket {
private:
    std::string raw_data;
    std::string premable;
    std::string source_address;
    std::string destination_address;
    std::string type;
    std::string payload;
    std::string crc;

};


#endif
