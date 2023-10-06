
#include "EthernetPacketParser.h"

const int preamble_length = 8 ;
const int preamble_start_pos = 0 ;

const int destination_length = 8 ;
const int source_length = 8 ;


EthernetPacketParser::EthernetPacketParser() {

}

void EthernetPacketParser::parseEthernetPacket(EthernetPacket & EthernetPacketInstance) {
    std::string raw_data = EthernetPacketInstance.getRawData();
    EthernetPacketInstance.setPreamble(raw_data.substr(preamble_start_pos,preamble_length)) ;


}
