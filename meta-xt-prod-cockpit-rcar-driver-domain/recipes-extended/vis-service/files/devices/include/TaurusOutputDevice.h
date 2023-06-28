#ifndef TAURUSOUTPUTDEVICE_H
#define TAURUSOUTPUTDEVICE_H

#include "VisServiceClient.h"

class TaurusOutputDevice: public OutputDevice
{
public:
    explicit TaurusOutputDevice(vis_string path);
    ~TaurusOutputDevice();
    OutputDevice& operator << (const OutputParam& op)override;

private:
    int mFdept;
};

#endif // TAURUSOUTPUTDEVICE_H
