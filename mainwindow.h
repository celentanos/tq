#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QFileDialog>
#include <QTimer>
#include <QLineEdit>
#include <QDropEvent>
#include <QMimeData>

#include <QSpacerItem>
#include <QSizePolicy>

#include "log.h"
#include "character.h"
#include "widget_properties.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    QString name;
    Log *log;
    QTimer *logTimer;

    QString filePath;
    WidgetProperties *wProperties;

    Character *player;
//    CharProperties *properties;
//    CharSkills *skills;

    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void setPath(QString &path, QLineEdit &le);

    void initGui();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotAddLogMsg(QString log);
    void slotResetSkills();

    void on_butRead_clicked();
    void on_butWrite_clicked();
};

#endif // MAINWINDOW_H
