#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <QInputDialog>
#include <memory>
ChatWindow::ChatWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWindow),_chatClient(new ChatClient(_clientUsername,"localhost",8080))
{
    ui->setupUi(this);
   /*
    if(_chatClient == 0){
        bool hostNameAccepted;
        bool portAccepted;
        QString hostName = QInputDialog::getText(this,"Enter Server","IP Address",QLineEdit::Normal,0,&hostNameAccepted);
        int port = QInputDialog::getInt(this,"Enter Port Number","Port",8080,0,2147483647,1,&portAccepted);
        _chatClient = new ChatClient(_clientUsername,hostName,port);

    }
    */
    connect(_chatClient,SIGNAL(dataRecieve(QByteArray)),this,SLOT(newMessage(QByteArray)));
 ui->messageList->setModel(&chatHistory);


}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::setUsername(QString username)
{
  _clientUsername = username;
}

void ChatWindow::on_sendBttn_clicked()
{
    QByteArray msgToSend;
    msgToSend.append(ui->textEdit->toPlainText());
_chatClient->sendMessage(msgToSend);
}

void ChatWindow::on_checkBox_clicked(bool checked)
{

    if(checked){
        //Reduce startup memory footprint
        _chatClient->connectTS();
        qDebug() << _chatClient->getError();


    }else{
        _chatClient->disconnectFS();
    }
}

void ChatWindow::newMessage(QByteArray message)
{
    QString wholeMessage = message;
    chatHistory_List << wholeMessage;
    chatHistory.setStringList(chatHistory_List);

}
