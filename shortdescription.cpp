#include "shortdescription.hpp"
#include "ui_shortdescription.h"

ShortDescription::ShortDescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortDescription)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&scene_);
    ui->graphicsView->setFixedWidth(200);
}

ShortDescription::~ShortDescription()
{
    delete ui;
}

void ShortDescription::setText(const Book& book)
{
    QString category = book.basic().data()[4].toString();
    QString originalTitle = book.basic().data()[1].toString();
    QString edited = book.basic().data()[3].toString();
    QString ISBN = book.basic().data()[10].toString();
    QString ID = book.basic().data()[11].toString();
    QString description = book.description().data()[0].toString();

    ui->category->setText(category);
    ui->originalTitle->setText(originalTitle);
    ui->edited->setText(edited);
    ui->ISBN->setText(ISBN);
    ui->ID->setText(ID);
    ui->description->setText(description);


    //ui->descrTextEdit->setText(text);
}

void ShortDescription::setImage(const std::optional<QString> fileName)
{
    if(fileName != std::nullopt)
    {
        QPixmap pixmap(fileName.value());
        scene_.clear();
        scene_.addPixmap(pixmap);
        ui->graphicsView->fitInView(scene_.itemsBoundingRect(), Qt::KeepAspectRatio);
    }
    else
    {
        QGraphicsTextItem* textItem = new QGraphicsTextItem("No image");
        textItem->setDefaultTextColor(QColor("#9c9c9c"));

        scene_.addItem(textItem);
    }
}
