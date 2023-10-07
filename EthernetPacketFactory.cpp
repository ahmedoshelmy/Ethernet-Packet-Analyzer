#include "EthernetPacketFactory.h"
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
        EthernetPackets.push_back(line) ;
    }
    inputFile.close();
}

EthernetPacketFactory::EthernetPacketFactory() {


}

void EthernetPacketFactory::parsePackets() {
    for(auto & paket : EthernetPackets){

    }
}
