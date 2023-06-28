
#include <unistd.h>
#include <stdint.h>
#include <linux/rpmsg.h>
#include <sys/ioctl.h>
#include <fcntl.h>    /* For O_RDWR */
#include <linux/r_taurus_cluster_protocol.h>
#include "devices/include/TaurusOutputDevice.h"

TaurusOutputDevice::TaurusOutputDevice(vis_string path)
{
    /*"/dev/cluster-taurus"*/
    mFdept = open(path.toStdString().c_str(), O_WRONLY);

    if(mFdept < 0)
    {
        throw std::invalid_argument("No device /dev/cluster-taurus");
    }
}
TaurusOutputDevice::~TaurusOutputDevice()
{
    close(mFdept);
}
OutputDevice& TaurusOutputDevice::operator << (const OutputParam& op)
{
    ioctl(mFdept, op.id, op.value);
    return *this;
}