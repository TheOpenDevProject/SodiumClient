#include "chatwindow.h"
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatWindow w;
    bool ok;
    QString username = QInputDialog::getText(&w,"Pick a username","Username",QLineEdit::Normal,0,&ok);

    if(ok && !username.isEmpty()){
        w.setUsername(username);
        w.show();
    }else{
        QMessageBox invalidUser;
        invalidUser.setText("You must enter a username to continue");
        invalidUser.exec();
        qApp->quit();
    }


    return a.exec();
}
