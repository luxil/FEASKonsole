#ifndef PUNKTEVERARBEITERUNGSK_H
#define PUNKTEVERARBEITERUNGSK_H

#include "facedetandfpl.h"
#include "sendoscmsg.h"

class PunkteVerarbeiterungsK
{
public:
    PunkteVerarbeiterungsK();
    void pMundAuf();
private:
    Sendoscmsg *sendoscmsg;
};

#endif // PUNKTEVERARBEITERUNGSK_H
