#include "log.h"

Log *Log::instance = 0;

Log::Log()
{

}

void Log::log(LOG l, QString s)
{
    QString msg = QDateTime::currentDateTime().toString("yyyy:MM:dd-HH:mm:ss") + ":";
    emit signalAddLog( msg.leftJustified(MSG_LENGTH, ' ') + s);
    (void)l;
}

void Log::log(Log::LOG l, QString funcName, QString s)
{
    QString msg = QDateTime::currentDateTime().toString("yyyy:MM:dd-HH:mm:ss") + " " + funcName + ":";
    emit signalAddLog( msg.leftJustified(MSG_LENGTH, ' ') + s);
    (void)l;
}

void Log::log(Log::LOG l, QString className, QString funcName, QString s)
{
    QString msg = QDateTime::currentDateTime().toString("yyyy:MM:dd-HH:mm:ss") + " " + className + "::" + funcName + ":";
    emit signalAddLog( msg.leftJustified(MSG_LENGTH, ' ') + s);
    (void)l;
}
