#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include "chatclient.h"
#include <QStringListModel>
namespace Ui {
class ChatWindow;
}

class ChatWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);
    ~ChatWindow();
    void setUsername(QString username);
private slots:
    void on_sendBttn_clicked();

    void on_checkBox_clicked(bool checked);
    void newMessage(QByteArray message);
private:
    Ui::ChatWindow *ui;
    QString _clientUsername;
    ChatClient *_chatClient;
    QStringListModel chatHistory;
    QStringList chatHistory_List;
};

#endif // CHATWINDOW_H
