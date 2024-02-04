//PacketParser.h- header File for PacketParser variables and functions
//Name: Inderpreet Singh Parmar
//EMAIL: iparmar1@myseneca.ca
//Student Id: 164132219

#ifndef _PACKETPARSER_H_
#define _PACKETPARSER_H_
#include <iostream>
#include <iomanip>//using manipulators
class PacketParser
{
    //public variables
    int source_port;
    int dest_port;
    int length;
protected:
    void SetSourcePort(int sourcePort);
    void SetDestPort(int destPort);
    void Setlength(int Length);
    int GetSourcePort();
    int GetDestPort();
    int Getlength();
public:
   PacketParser();
    virtual bool parse(const char* packet);
    virtual void display(std::ostream& os);
    virtual ~PacketParser() {};
};
std::ostream& operator<<(std::ostream& os, PacketParser& parser);

#endif// _PACKETPARSER_H_
