
#include "EthernetPacket.h"
#include <utility>

EthernetPacket::EthernetPacket(std::string data) {
    raw_data = std::move(data);
    sz = raw_data.size();
    parsePacket() ;
}

void EthernetPacket::parsePacket() {
    std::unordered_map<std::string,packet_parse_pos> generic_m ;
    generic_m = {
            {"preamble", {0, 16}},
            {"destination_address", {16, 12}},
            {"source_address", {28, 12}},
            {"type", {40, 4}},
            {"payload", {44, (sz -8 - 44)}},
            {"crc", {sz-8, 8}}};

    preamble = raw_data.substr(generic_m["preamble"].start,generic_m["preamble"].sz);
    source_address = raw_data.substr(generic_m["source_address"].start,generic_m["source_address"].sz);
    destination_address = raw_data.substr(generic_m["destination_address"].start,generic_m["destination_address"].sz);
    type = raw_data.substr(generic_m["type"].start,generic_m["type"].sz);
    payload = raw_data.substr(generic_m["payload"].start,generic_m["payload"].sz);
    crc = raw_data.substr(generic_m["crc"].start,generic_m["crc"].sz);
}
void EthernetPacket::logPacket(){

    std::ofstream outputFile;

    std::string outputFileName = "output_packets" ;

    std::string file_path = __FILE__;
    std::string dir_path = file_path.substr(0, file_path.rfind('/')); // This contains the current directory of the source file

    outputFile.open(dir_path + "\\" + outputFileName, std::ios::app) ;


    if (!outputFile.is_open()) {
        std::cerr << "Unable to open the output file." << std::endl;
        return;
    }

    outputFile<<this->raw_data<<std::endl;
    outputFile<<"CRC:"<<this->crc<<std::endl;
    outputFile<<"Destination Address :"<<this->destination_address<<std::endl;
    outputFile<<"Source Address :"<<this->source_address<<std::endl;
    outputFile<<"Type :"<<this->type<<std::endl;

    outputFile.close();

}

