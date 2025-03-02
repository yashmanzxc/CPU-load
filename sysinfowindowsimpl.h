#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H
#include <sysinfo.h>
#include	<QtGlobal>
#include	<QVector>

typedef	struct	_FILETIME	FILETIME;

class SysInfoWindowsImpl : public SysInfo
{
public:

    SysInfoWindowsImpl();

    virtual void init() override;
    virtual double cpuLoadAverage() override;
    virtual double memoryUser() override;

private:
    QVector<qulonglong>	cpuRawData();//вызовет Windows API для получения информации о времени системы

    qulonglong convertFileTime(const FILETIME& filetime)const; //
private:
    QVector<qulonglong>mCpuLoadLastValues;//переменная хранит время системы
};

#endif // SYSINFOWINDOWSIMPL_H
