#ifndef SENDOSCMSG_H
#define SENDOSCMSG_H
#include <string>
#include <string.h>

using namespace std;

#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"

#define OUTPUT_BUFFER_SIZE 1024

class Sendoscmsg
{
public:
    Sendoscmsg();
    void setIpAddress(int ipaddressA, int ipaddressB, int ipaddressC, int ipaddressD);
    void setPort(int port);
    void send(string method, float value);

private:
    int rx_ipaddressA;
    int rx_ipaddressB;
    int rx_ipaddressC;
    int rx_ipaddressD;
    int rx_port;
};

#endif // SENDOSCMSG_H
