//UdpPacketParser.cpp - file for UdpPacketParser opearations and functions
//Name: Inderpreet Singh Parmar
//EMAIL: iparmar1@myseneca.ca
//Student Id: 164132219
#include "UdpPacketParser.h"
#include <iomanip>
#include <string.h>

using namespace std;

bool UdpPacketParser::parse(const char* packet)
{
    bool flag = false;
    flag = PacketParser::parse(packet);
    int z = 4;
    int length = packet[z+1] + (0x100 * packet[z]);
    Setlength(length);
    z = 6;
    int checksum = packet[z+1] + (0x100 * packet[z]);
    this->checksum = checksum;
    z = 8;
    data = new char[length];
    for (int i = 0; i < length; ++i)
    {
        data[i] = '\0';
    }
    for (int x = z, y = 0; x < (length + z); x++, y++)
    {
        memcpy(&data[y], &packet[x], 2);
    }

    if ((GetSourcePort() + GetDestPort() + Getlength()) == this->checksum) {
        flag = true;
    }
    return flag;
}

void UdpPacketParser::display(std::ostream& os)
{
    cout << "Report for UDP Packet Parser" << endl;
    PacketParser::display(os);
    os << setw(14) << "data length: " << Getlength() << endl;
    os << setw(14) << "Data: " << data << endl;
}

UdpPacketParser::~UdpPacketParser()
{}

std::ostream& operator<<(std::ostream& os, UdpPacketParser& Udp_parser)
{
    Udp_parser.display(os);
    return os;
}