#include "pch.h"
#include "EthernetPacketFactory.h"


int main() {
    EthernetPacketFactory EthernetPacketFactoryInstance  ;
    std::string fileName = "input_packets" ;
    EthernetPacketFactoryInstance.readPackets(fileName);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
