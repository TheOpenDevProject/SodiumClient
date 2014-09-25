#include "chatclient.h"
#include <QHostAddress>
ChatClient::ChatClient(QString username, QString host, int port):
    _chatClient(new QTcpSocket)
{
    connect(_chatClient,SIGNAL(connected()),this,SLOT(serverJoin()));
    connect(_chatClient,SIGNAL(readyRead()),this,SLOT(dataPending()));
}

void ChatClient::connectTS()
{
    _chatClient->connectToHost(QHostAddress::LocalHost,8080);
    if(!_chatClient->waitForConnected()){
       error = _chatClient->errorString();
    }else{

    }
}

void ChatClient::disconnectFS(){
    _chatClient->disconnectFromHost();
}

void ChatClient::sendMessage(QByteArray _message)
{
    QByteArray sender;
    sender.append("<" + _username + ">");
    _chatClient->write(sender + _message);
    _chatClient->flush();
}

QString ChatClient::getError()
{
    return error;
}

void ChatClient::serverJoin()
{

}

void ChatClient::dataPending(){
    QByteArray array;

    while( !(array = _chatClient->readLine()).isNull()){
       emit(dataRecieve(array));
     }
}
