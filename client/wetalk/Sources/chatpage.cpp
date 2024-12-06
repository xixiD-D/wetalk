//
// Created by 29697 on 24-12-5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChatPage.h" resolved

#include "chatpage.h"
#include <QStyleOption>
#include <QPainter>
#include "Forms/ui_ChatPage.h"


ChatPage::ChatPage(QWidget *parent) : QWidget(parent), ui(new Ui::ChatPage) {
    ui->setupUi(this);

    // 设置按钮样式
    ui->receive_btn->SetState("normal", "hover", "press");
    ui->send_btn->SetState("normal", "hover", "press");

    // 设置图标样式
    ui->emo_lb->SetState("normal", "hover", "press", "normal", "hover", "press");
    ui->file_lb->SetState("normal", "hover", "press", "normal", "hover", "press");
}

ChatPage::~ChatPage() {
    delete ui;
}

void ChatPage::paintEvent(QPaintEvent *event) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}