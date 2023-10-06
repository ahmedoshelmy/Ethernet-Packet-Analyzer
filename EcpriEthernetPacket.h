

#ifndef PACKETANALUZER_ECPRIETHERNETPACKET_H
#define PACKETANALUZER_ECPRIETHERNETPACKET_H


#include "EthernetPacket.h"

class EthernetPacketParser;

class EcpriEthernetPacket : public EthernetPacket{
private:
    std::string protocol_ver;
    std::string concat_indicator;
    std::string msg_type;
    std::string payload_sz;
    std::string rtc_id;
    std::string seq_id;

public:

    std::string getProtocolVer() const { return protocol_ver; }
    std::string getConcatIndicator() const { return concat_indicator; }
    std::string getMsgType() const { return msg_type; }
    std::string getPayloadSz() const { return payload_sz; }
    std::string getrtcId() const { return rtc_id; }
    std::string getseqId() const { return seq_id; }

    friend EthernetPacketParser;
};


#endif
