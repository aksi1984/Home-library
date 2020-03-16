#include "shortdescription.hpp"
#include "ui_shortdescription.h"

ShortDescription::ShortDescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortDescription)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&scene_);
}

ShortDescription::~ShortDescription()
{
    delete ui;
}

void ShortDescription::setText(const QString &text)
{
    ui->descrTextEdit->setText(text);
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
