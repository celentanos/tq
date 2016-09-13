#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    name = "MainWindow";
    filePath = "";
    ui->setupUi(this);
//    delete ui->menuBar;
//    delete ui->mainToolBar;
    this->setFixedSize(this->size());
    this->setAcceptDrops(true);         /// file prop

    log = Log::getInstance();
    connect(log, &Log::signalAddLog, this, &MainWindow::slotAddLogMsg);

    logTimer = new QTimer();
    logTimer->setSingleShot(true);
    connect(logTimer, &QTimer::timeout, ui->statusBar, &QStatusBar::clearMessage);
    // INIT System #############################################################

    this->player = new Character;
    connect(ui->butResetSkills, &QPushButton::clicked, this, &MainWindow::slotResetSkills);
    initGui();
}

MainWindow::~MainWindow()
{
    if(log)
        delete log;
    if(logTimer)
        delete logTimer;
    if(player)
        delete player;
    delete ui;
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    // check for our needed mime type, here a file or a list of files
    if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();

        if(urlList.size() == 1) {
            filePath = urlList.at(0).toLocalFile();
            ui->leCharFilePath->setText(urlList.at(0).toLocalFile());
        } else
            Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "to many files droped!");
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
//    if (event->mimeData()->hasFormat("text/plain"))
    event->acceptProposedAction();
}

void MainWindow::slotAddLogMsg(QString log)
{
    ui->statusBar->showMessage(log);
    ui->tbLog->append(log);
    logTimer->start(4000);
    //    QTimer::singleShot(4000, this, &MainWindow::slotClearStatusBar);
}

void MainWindow::slotResetSkills()
{
    player->resetSkills();
}

void MainWindow::initGui()
{
    wProperties = new WidgetProperties(player->getProperties(), this);
    for (int i = 0; i < player->getProperties()->size(); ++i) {
        ui->tabChar->layout()->addWidget(wProperties->at(i));
        connect(wProperties->at(i), &WidgetProperty::signalSetValue, player->getProperties()->at(i), &CharProperty::slotSetValue);
        connect(player->getProperties()->at(i), &CharProperty::signalValOldChanged, wProperties->at(i)->getValOld(), &QLabel::setText);
        connect(player->getProperties()->at(i), &CharProperty::signalValNewChanged, wProperties->at(i), &WidgetProperty::slotSetValue);
    }
    ui->tabChar->layout()->addItem(new QSpacerItem(-1, -1, QSizePolicy::Fixed, QSizePolicy::Expanding));
}

void MainWindow::on_butRead_clicked()
{
    player->clearAll();
    if(filePath == "") {
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "no character-file!");
        return;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "can't open file!");
        return;
    }
    *player->getCharacter() = file.readAll();

    // Properties ##############################################################
    player->parseProperties();
    for (int i = 0; i < player->getProperties()->size(); ++i)
        qDebug() << player->getProperties()->getProperty(i)->getProperty() << player->getProperties()->getProperty(i)->getValOld();
    // Skills ##################################################################
    player->parseSkills();
    for (int i = 0; i < player->getSkills()->size(); ++i)
        qDebug() << "skill" << i << player->getSkills()->at(i)->getSkillName0();
}

void MainWindow::on_butWrite_clicked()
{
    int count = 0;
    for (int i = 0; i < player->getProperties()->size(); ++i) {
        if(player->getProperties()->at(i)->getValid()) {
            *player->getCharacter() = player->getCharacter()->replace(
                                          player->getProperties()->at(i)->getValOffset(),
                                          player->getProperties()->at(i)->getValLength(),
                                          Character::getBaLittleFromInt(player->getProperties()->at(i)->getValNew()));
            count++;
        }
    }
    if(!count) {
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "no valid properties found!");
        return;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "can't open file!");
        return;
    }
    file.write(*player->getCharacter());
}

void MainWindow::on_butSetCharFilePath_clicked()
{
    setPath(filePath, *ui->leCharFilePath);
}

void MainWindow::setPath(QString &path, QLineEdit &le)
{
    QString s = QFileDialog::getOpenFileName(this, "Directory", "./");
    if(s == "")
        return;
    path = s;
    le.setText(s);
}
