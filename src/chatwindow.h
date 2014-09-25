#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>

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

private:
    Ui::ChatWindow *ui;
    QString _clientUsername;
};

#endif // CHATWINDOW_H
