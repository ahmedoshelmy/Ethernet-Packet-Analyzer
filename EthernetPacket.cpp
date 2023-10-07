
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
    std::cout<<this->raw_data<<std::endl;
    std::cout<<"CRC:"<<this->crc<<std::endl;
    std::cout<<"Destination Address :"<<this->destination_address<<std::endl;
    std::cout<<"Source Address :"<<this->source_address<<std::endl;
    std::cout<<"Type :"<<this->type<<std::endl;
}

