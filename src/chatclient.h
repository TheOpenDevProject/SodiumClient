#ifndef CHATCLIENT_H
#define CHATCLIENT_H
#include <QObject>
#include <QTcpSocket>

class ChatClient : public QObject
{
    Q_OBJECT
public:
    ChatClient(QString username, QString host, int port);
    void connectTS();
    void disconnectFS();
    void sendMessage(QByteArray _message);
    QString getError();
private:
    QString _username,host;
    int port;
    QTcpSocket *_chatClient;
    QString error;
public slots:
    void serverJoin();

private slots:
    void dataPending();
signals:
    void dataRecieve(QByteArray);
};

#endif // CHATCLIENT_H
