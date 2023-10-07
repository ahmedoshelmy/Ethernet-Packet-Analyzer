#include "EthernetPacketFactory.h"
#include "EcpriEthernetPacket.h"
#include <iostream>
#include <fstream>
#include <string>



void EthernetPacketFactory::readPackets(std::string fileName) {
    std::ifstream inputFile;
    std::string file_path = __FILE__;
    std::string dir_path = file_path.substr(0, file_path.rfind('/')); // This contains the current directory of the source file

    inputFile.open(dir_path + "\\" + fileName) ;

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return;
    }

    std::string line ;
    while (std::getline(inputFile, line)) {
        // Reading the file line by line
        EthernetPacketsStrings.push_back(line) ;
    }
    inputFile.close();
}

EthernetPacketFactory::EthernetPacketFactory() {


}

std::string packetType(std::string packet){
    // 40 is the starting position of the type and 4 is its size
    return packet.substr(40,4) ;
}

void EthernetPacketFactory::parsePackets() {
    for(auto & packet : EthernetPacketsStrings){
        if(packetType(packet) == "AEFE"){ // It means it's an ECPRI packet
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

    std::ofstream outputFile;

    std::string outputFileName = "output_packets" ;

    std::string file_path = __FILE__;
    std::string dir_path = file_path.substr(0, file_path.rfind('/')); // This contains the current directory of the source file

    outputFile.open(dir_path + "\\" + outputFileName, std::ios::app) ;

    if (!outputFile.is_open()) {
        std::cerr << "Unable to open the output file." << std::endl;
        return;
    }

    for(auto & packet : EthernetPackets){
        outputFile<<"Packet # "<<index++<<":"<<std::endl;
        packet->logPacket(); // It's a virtual function. It will map to the correct fucntion
        outputFile<<std::endl<<separator<<std::endl<<std::endl;
    }
    outputFile.close();

}
