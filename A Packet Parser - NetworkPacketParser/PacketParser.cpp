//PacketParser - file for PacketParser functions 
//Name: Inderpreet Singh Parmar
//EMAIL: iparmar1@myseneca.ca
//Student Id: 164132219
#include "PacketParser.h"
#include <iostream>
using namespace std;
void PacketParser::SetSourcePort(int sourcePort) 
{
    source_port = sourcePort;
}

void PacketParser::SetDestPort(int destPort) 
{
    dest_port = destPort;
}
void PacketParser::Setlength(int Length)
{
    length = Length;
}

int PacketParser::GetDestPort()
{
    return dest_port;
}
int PacketParser::Getlength()
{
    return length;
}
PacketParser::PacketParser()
{
    source_port = 0;
    dest_port = 0;
    length = 0;
}

int PacketParser::GetSourcePort()
{
    return source_port;
}

bool PacketParser::parse(const char* Packet_)
{
    bool retval = true;
    int i = 0;
    int source_port = Packet_[i + 1] + (0x100 * Packet_[i]); //as given in the instructions
   SetSourcePort(source_port);
    i = 2;
    int dest_port = Packet_[i + 1] + (0x100 * Packet_[i]);
    SetDestPort(dest_port);
    return retval;
}
void PacketParser::display(std::ostream& os)
{
    os << left << setw(13);
    os << setw(14) << "source port: " << source_port << endl;//USE OF MANIPULATOR setw()
    os << setw(14) << "dest port: " << dest_port << endl;
}
std::ostream& operator<<(std::ostream& os, PacketParser& PacPar) {
    PacPar.display(os);
    return os;
}

