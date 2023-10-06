
#include "EthernetPacketParser.h"


EthernetPacketParser::EthernetPacketParser(int sz)
{
    generic_m = {
        {"preamble", {0, 16}},
        {"destination_address", {16, 12}},
        {"source_address", {28, 12}},
        {"type", {40, 4}},
        {"payload", {44, (sz -8 - 44)}},
        {"CRC", {sz-8, 8}}};
    ecpri_payload_m= {
        {"protocol_ver", {0, 1}},
        {"concat_indicator", {1, 1}},
        {"msg_type",{2,2}},
        {"payload_sz",{4,4}},
        {"rtc_id",{8,4}},
        {"seq_id",{12,4}}
    };

}

void EthernetPacketParser::parseEthernetPacket(EthernetPacket &EthernetPacketInstance)
{
    std::string data = EthernetPacketInstance.getRawData();
    int sz = data.size();

    EthernetPacketInstance.preamble = data.substr(generic_m["preamble"].start,generic_m["preamble"].sz);
    EthernetPacketInstance.source_address = data.substr(generic_m["source_address"].start,generic_m["source_address"].sz);
    EthernetPacketInstance.destination_address = data.substr(generic_m["destination_address"].start,generic_m["destination_address"].sz);
    EthernetPacketInstance.type = data.substr(generic_m["type"].start,generic_m["type"].sz);
    EthernetPacketInstance.payload = data.substr(generic_m["payload"].start,generic_m["payload"].sz);
    EthernetPacketInstance.crc = data.substr(generic_m["crc"].start,generic_m["crc"].sz);

}
void EthernetPacketParser::parseEcpriPacket(EcpriEthernetPacket &EthernetPacketInstance)
{
    std::string payload_data = EthernetPacketInstance.getPayload();
    EthernetPacketInstance.protocol_ver = payload_data.substr(ecpri_payload_m["protocol_ver"].start, ecpri_payload_m["protocol_ver"].sz);
    EthernetPacketInstance.concat_indicator = payload_data.substr(ecpri_payload_m["concat_indicator"].start, ecpri_payload_m["concat_indicator"].sz);
    EthernetPacketInstance.msg_type = payload_data.substr(ecpri_payload_m["msg_Type"].start, ecpri_payload_m["msg_type"].sz);
    EthernetPacketInstance.payload_sz= payload_data.substr(ecpri_payload_m["payload_sz"].start, ecpri_payload_m["payload_sz"].sz);
    EthernetPacketInstance.rtc_id = payload_data.substr(ecpri_payload_m["rtc_id"].start, ecpri_payload_m["rtc_id"].sz);
    EthernetPacketInstance.seq_id = payload_data.substr(ecpri_payload_m["seq_id"].start, ecpri_payload_m["seq_id"].sz);

}