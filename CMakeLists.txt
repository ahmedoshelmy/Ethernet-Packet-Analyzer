cmake_minimum_required(VERSION 3.25)
project(PacketAnaluzer)

set(CMAKE_CXX_STANDARD 20)

add_executable(PacketAnaluzer main.cpp EthernetPacket.cpp EthernetPacket.h EthernetPacketParser.cpp EthernetPacketParser.h EcpriEthernetPacket.cpp EcpriEthernetPacket.h)
