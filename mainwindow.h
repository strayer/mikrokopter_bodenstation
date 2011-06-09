#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QSettings>

#include "messages/all_messages.h"

class SerialPortHandler;
class QListWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);

private:
	SerialPortHandler *serial;
	QThread serialPortThread;

	QSettings settings;

	QListWidget *msgList;

	void closeEvent(QCloseEvent *event);

signals:

public slots:
	void buttonClicked();

	void newMessageReceived(QSharedPointer<BaseMessage> msg);
	void messageSent(QSharedPointer<BaseMessage> msg);

};

#endif // MAINWINDOW_H
