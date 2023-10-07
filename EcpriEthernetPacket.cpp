
#include "EcpriEthernetPacket.h"

void EcpriEthernetPacket::parsePacket() {
    EthernetPacket::parsePacket();
    std::map<std::string,packet_parse_pos> ecpri_payload_m;
    ecpri_payload_m= {
            {"protocol_ver", {0, 1}},
            {"concat_indicator", {1, 1}},
            {"msg_type",{2,2}},
            {"payload_sz",{4,4}},
            {"rtc_id",{8,4}},
            {"seq_id",{12,4}}
    };


   protocol_ver = payload.substr(ecpri_payload_m["protocol_ver"].start, ecpri_payload_m["protocol_ver"].sz);
   concat_indicator = payload.substr(ecpri_payload_m["concat_indicator"].start, ecpri_payload_m["concat_indicator"].sz);
   msg_type = payload.substr(ecpri_payload_m["msg_type"].start, ecpri_payload_m["msg_type"].sz);
   payload_sz= payload.substr(ecpri_payload_m["payload_sz"].start, ecpri_payload_m["payload_sz"].sz);
   rtc_id = payload.substr(ecpri_payload_m["rtc_id"].start, ecpri_payload_m["rtc_id"].sz);
   seq_id = payload.substr(ecpri_payload_m["seq_id"].start, ecpri_payload_m["seq_id"].sz);
}


EcpriEthernetPacket::EcpriEthernetPacket(std::string data) : EthernetPacket(data) {
    raw_data = data ;
    sz = raw_data.size() ;
    parsePacket() ;
}

void EcpriEthernetPacket::logPacket(){
    std::cout<<this->raw_data<<std::endl;
    std::cout<<"CRC:"<<this->crc<<std::endl;

    std::cout<<"Concatenation Indicator:"<<this->concat_indicator<<std::endl;
    std::cout<<"Destination Address:"<<this->destination_address<<std::endl;

    std::cout<<"Message Type:"<<this->msg_type<<std::endl;
    std::cout<<"Payload Size:"<<this->payload_sz<<std::endl;
    std::cout<<"Protocol Version:"<<this->protocol_ver<<std::endl;


    std::cout<<"RTC ID:"<<this->rtc_id<<std::endl;
    std::cout<<"Sequence ID:"<<this->seq_id<<std::endl;


    std::cout<<"Source Address:"<<this->source_address<<std::endl;
    std::cout<<"Type:"<<this->type<<std::endl;

}