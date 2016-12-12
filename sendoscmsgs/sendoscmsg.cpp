#include "sendoscmsg.h"
#include <stdio.h>


Sendoscmsg::Sendoscmsg()
    : rx_ipaddressA(127), rx_ipaddressB(0), rx_ipaddressC(0), rx_ipaddressD(1), rx_port(8000)
{

    /*p << osc::BeginBundleImmediate
        << osc::BeginMessage( "/test1" )
            << true << 23 << (float)3.1415 << "hello" << osc::EndMessage
        << osc::BeginMessage( "/test2" )
            << true << 24 << (float)10.8 << "world" << osc::EndMessage
        << osc::EndBundle;

    transmitSocket.Send( p.Data(), p.Size() );*/
}

void Sendoscmsg::setIpAddress(int ipaddressA, int ipaddressB, int ipaddressC, int ipaddressD){
    this->rx_ipaddressA = ipaddressA;
    this->rx_ipaddressB = ipaddressB;
    this->rx_ipaddressC = ipaddressC;
    this->rx_ipaddressD = ipaddressD;
}

void Sendoscmsg::setPort(int port){
    this->rx_port = port;
}

void Sendoscmsg::send(string method, float value){
    UdpTransmitSocket transmitSocket( IpEndpointName(rx_ipaddressA, rx_ipaddressB, rx_ipaddressC, rx_ipaddressD, rx_port) );

    char buffer[OUTPUT_BUFFER_SIZE];
    osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );

    p << osc::BeginBundleImmediate
        << osc::BeginMessage( method.c_str() )
            << value << osc::EndMessage
        << osc::EndBundle;

    transmitSocket.Send( p.Data(), p.Size() );
}
