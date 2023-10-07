#include "pch.h"
#include "EthernetPacketFactory.h"


int main() {

    // The ethernet packet factory contains the packets to be parsed and logged
    EthernetPacketFactory EthernetPacketFactoryInstance  ;

    std::string fileName = "input_packets" ;

    EthernetPacketFactoryInstance.readPackets(fileName);
    EthernetPacketFactoryInstance.parsePackets() ;
    EthernetPacketFactoryInstance.logPackets();

    return 0;
}
