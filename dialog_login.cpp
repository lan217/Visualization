#include "dialog_login.h"

#include <QMessageBox>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent)
{

    this->setFixedSize(Utils::windowSize().width() * 0.2, Utils::windowSize().height() * 0.2);

    loginButton = new QPushButton(tr("登录"), this);
    cancelButton = new QPushButton(tr("取消"), this);

    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::login);
    connect(cancelButton, &QPushButton::clicked, this, &LoginDialog::reject);

    usernameLabel = new QLabel(tr("用户名:"));
    passwordLabel = new QLabel(tr("密码:"));
    usernameEdit = new QLineEdit();
    usernameEdit->setText("admin");
    usernameEdit->setMaximumWidth(Utils::windowSize().width() * 0.2);
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setMaximumWidth(Utils::windowSize().width() * 0.2);

    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(usernameLabel, 0, 0);
    mainLayout->addWidget(usernameEdit, 0, 1, 1, 2);
    mainLayout->addWidget(passwordLabel, 1, 0);
    mainLayout->addWidget(passwordEdit, 1, 1, 1, 2);
    mainLayout->addWidget(loginButton, 2, 1);
    mainLayout->addWidget(cancelButton, 2, 2);
    this->setLayout(mainLayout);

    this->setWindowTitle(tr("登录"));

}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::login()
{
    if (usernameEdit->text() == "admin" && passwordEdit->text() == "s") {
        accept();
    } else {
        QMessageBox::warning(this, tr("警告"), tr("用户名或密码错误!"), tr("确定"));
    }
}
