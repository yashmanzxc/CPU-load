#include "sysinfo.h"
#include "sysinfowindowsimpl.h"
#include <QtGlobal>

SysInfo &SysInfo::instans()
{
    static SysInfoWindowsImpl singleton;
    return singleton;
}

SysInfo::SysInfo()
{

}

SysInfo::~SysInfo()
{

}
