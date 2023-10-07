#include "EthernetPacketFactory.h"
#include "EcpriEthernetPacket.h"
#include <iostream>
#include <fstream>
#include <string>



void EthernetPacketFactory::readPackets(std::string fileName) {
    std::ifstream inputFile;
    std::string file_path = __FILE__;
    std::string dir_path = file_path.substr(0, file_path.rfind('/'));

    inputFile.open(dir_path + "\\" + fileName) ;

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return;
    }
    std::string line ;
    while (std::getline(inputFile, line)) {
        EthernetPacketsStrings.push_back(line) ;
    }
    inputFile.close();
}

EthernetPacketFactory::EthernetPacketFactory() {


}

std::string packetType(std::string packet){
    return packet.substr(40,4) ;
}

void EthernetPacketFactory::parsePackets() {
    for(auto & packet : EthernetPacketsStrings){
        if(packetType(packet) == "AEFE"){
            EthernetPacket * newPacket = new EcpriEthernetPacket(packet);
            EthernetPackets.push_back(newPacket) ;
        }else {
            EthernetPacket * newPacket = new EthernetPacket(packet) ;
            EthernetPackets.push_back(newPacket) ;
        }
    }
}

void EthernetPacketFactory::logPackets() {
    int index = 0;
    std::string separator = std::string(230 , '*') ;
    for(auto & packet : EthernetPackets){
        std::cout<<"Packet # "<<index++<<":\n";
        packet->logPacket();
        std::cout<<"\n"<<separator<<"\n\n";
    }
}
