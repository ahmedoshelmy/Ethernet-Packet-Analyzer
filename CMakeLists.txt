cmake_minimum_required(VERSION 3.25)
project(PacketAnaluzer)

set(CMAKE_CXX_STANDARD 23)
include_directories("${CMAKE_SOURCE_DIR}")

add_executable(PacketAnaluzer main.cpp EthernetPacket.cpp  pch.h EthernetPacket.h EcpriEthernetPacket.cpp EcpriEthernetPacket.h EthernetPacketFactory.cpp EthernetPacketFactory.h)
