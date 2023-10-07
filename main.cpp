#include "pch.h"
#include "EthernetPacketFactory.h"


int main() {
    EthernetPacketFactory EthernetPacketFactoryInstance  ;
    std::string fileName = "input_packets" ;
    EthernetPacketFactoryInstance.readPackets(fileName);
    EthernetPacketFactoryInstance.parsePackets() ;
    EthernetPacketFactoryInstance.logPackets();

    return 0;
}
