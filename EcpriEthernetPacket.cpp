
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

    outputFile<<"Concatenation Indicator:"<<this->concat_indicator<<std::endl;
    outputFile<<"Destination Address:"<<this->destination_address<<std::endl;

    outputFile<<"Message Type:"<<this->msg_type<<std::endl;
    outputFile<<"Payload Size:"<<this->payload_sz<<std::endl;
    outputFile<<"Protocol Version:"<<this->protocol_ver<<std::endl;


    outputFile<<"RTC ID:"<<this->rtc_id<<std::endl;
    outputFile<<"Sequence ID:"<<this->seq_id<<std::endl;


    outputFile<<"Source Address:"<<this->source_address<<std::endl;
    outputFile<<"Type:"<<this->type<<std::endl;

    outputFile.close();

}