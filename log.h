#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <QString>
#include <QDateTime>

#define MSG_LENGTH  50
#define INT_LENGTH  4

class Log : public QObject
{
    Q_OBJECT
public:

    enum LOG {
        INFO,
        FAILURE,
        ERROR,
        FATAL
    };

    static Log *getInstance() {
        if (instance == 0)
            instance = new Log();
        return instance;
    }

    void log(LOG l, QString s);
    void log(LOG l, QString funcName, QString s);
    void log(LOG l, QString className, QString funcName, QString s);

private:
    Log();                  // verhindert, dass ein Objekt von außerhalb von 'Classe' erzeugt wird
    Log(const Log &);       // verhindert, dass eine weitere Instanz via Kopie-Konstruktor erstellt werden kann
    static Log *instance;

signals:
    void signalAddLog(QString s);
};

#endif // LOG_H
