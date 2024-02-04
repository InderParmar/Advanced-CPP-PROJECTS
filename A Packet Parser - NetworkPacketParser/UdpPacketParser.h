//UdpPacketParser.h-header file for UdpPacketPraser 
//Name: Inderpreet Singh Parmar
//EMAIL: iparmar1@myseneca.ca
//Student Id: 164132219
#ifndef _UDPPACKETPARSER_H_
#define _UDPPACKETPARSER_H_
#include "PacketParser.h"

class UdpPacketParser : public PacketParser 
{
    int checksum;
    char* data;
public:
    virtual bool parse(const char* packet);
     void display(std::ostream& os) ;
    ~UdpPacketParser();
};

std::ostream& operator<<(std::ostream& os, UdpPacketParser& parser);

#endif //UdpPacketParser