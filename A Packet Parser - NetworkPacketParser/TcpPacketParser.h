//TcpPacketParser: Header file for TcpPacketParser
//Name: Inderpreet Singh Parmar
//EMAIL: iparmar1@myseneca.ca
//Student Id: 164132219
#ifndef _TCPPACKETPARSER_H_
#define _TCPPACKETPARSER_H_
#include "PacketParser.h"
#include <iomanip>//using manipulators
class TcpPacketParser : public PacketParser 
{
private:
    int sequence_number;
    int ack_number;
    int ignore;
    int checksum;
    int ignore2;
    char* data;
public:
    virtual bool parse(const char* packet);
    void display(std::ostream& os);
};
std::ostream& operator<<(std::ostream& os, TcpPacketParser& parser);

#endif //TcpPacketParser