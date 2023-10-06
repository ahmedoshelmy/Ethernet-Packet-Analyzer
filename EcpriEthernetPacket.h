

#ifndef PACKETANALUZER_ECPRIETHERNETPACKET_H
#define PACKETANALUZER_ECPRIETHERNETPACKET_H

#include <bits/stdc++.h>
#include "EthernetPacket.h"

class EcpriEthernetPacket : public EthernetPacket{
private:
    std::string protocol_ver;
    std::string concat_indicator;
    std::string msg_type;
    std::string payload_sz;
    std::string rtc_id;
    std::string seq_id;
};


#endif
