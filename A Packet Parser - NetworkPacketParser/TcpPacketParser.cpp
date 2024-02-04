//TcpPacketParser-file for TcpPacketParser operations and functions
//Name: Inderpreet Singh Parmar
//EMAIL: iparmar1@myseneca.ca
//Student Id: 164132219
#include "TcpPacketParser.h"

using namespace std;
bool TcpPacketParser::parse(const char* Packet_)
{
    bool flag = false;
    flag = PacketParser::parse(Packet_);
    int  z = 4;
    //AS GIVEN IN THE INSTRUCTIONS
    sequence_number = (Packet_[z] * 0x1000000) + (Packet_[z + 1] * 0x10000) + (Packet_[z + 2] * 0x100) + Packet_[z + 3];
    z = 8;
    ack_number = (Packet_[z] * 0x1000000) + (Packet_[z + 1] * 0x10000) + (Packet_[z + 2] * 0x100) + Packet_[z + 3];
    z = 12;
    ignore = (Packet_[z] * 0x1000000) + (Packet_[z + 1] * 0x10000) + (Packet_[z + 2] * 0x100) + Packet_[z + 3];
    z = 16;
    checksum = Packet_[z + 1] + (0x100 * Packet_[z]);
    z = 18;
    ignore2 = Packet_[z+1] + (0x100 * Packet_[z]);
    z = 20;
    int length = Packet_[z+1] + (0x100 * Packet_[z]);
    Setlength(length);
    z = 22;
    this->data = new char[length];
    for (int x = z, y = 0; x < (length+z); x++, y++)
    {
        memcpy(&data[y], &Packet_[x], 2);
    }
    if ((GetSourcePort() + GetDestPort() + sequence_number + ack_number + ignore + ignore2 + length) == checksum)
        flag = true;
    return flag;
}

void TcpPacketParser::display(std::ostream& os)
{
    os << endl;
    os << left << setw(13);
    os << "Report for TCP Packet Parser" << endl;
    PacketParser::display(os);
    os << setw(14) << "seq number:" << sequence_number << endl;
    os << setw(14) << "ack number:" << ack_number << endl;
    os << setw(14) << "data length:" << Getlength() << endl;
    os << setw(14) << "data:" << data << endl;
}
std::ostream& operator<< (std::ostream& os, TcpPacketParser& Tcp_parser)
{
    Tcp_parser.display(os);
    return os;
}
