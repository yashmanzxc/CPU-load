#ifndef SYSINFO_H
#define SYSINFO_H


class SysInfo
{
public:
    static SysInfo& instans();

    virtual ~SysInfo();

    virtual void init()=0; //позволяет производному классу выполнять любой процесс инициализации в зависимости от операционной системы
    virtual double cpuLoadAverage()=0; //вызывает определенный код ОС для получения средней нагрузки на CPU и возвращает ее в виде процентного значения
    virtual double memoryUser()=0; // вызывает определенный код ОС для извлечения используемой памяти и возвращает его в виде процентного значения
protected:
    explicit  SysInfo();
private:
    SysInfo(const	SysInfo&	rhs);
    SysInfo&	operator=(const	SysInfo&	rhs);
};

#endif // SYSINFO_H
