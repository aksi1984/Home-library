#include "tree.hpp"
#include "ui_tree.h"

Tree::Tree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tree)
{
    ui->setupUi(this);
}

Tree::~Tree()
{
    delete ui;
}
