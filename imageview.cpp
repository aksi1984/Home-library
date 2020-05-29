#include "imageview.hpp"
#include "ui_imageview.h"
#include <QMessageBox>

ImageView::ImageView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageView),
    labelWidth_{230},
    labelHeight_{510},
    scene_{new Scene},
    posY_{}
{
    ui->setupUi(this);

    ui->graphicsView->setScene(scene_);
    ui->graphicsView->setAlignment(Qt::AlignLeft);

    initTimer();
    initConnect();
}

ImageView::~ImageView()
{
    delete ui;
}

void ImageView::initTimer()
{
    timer_.setInterval(1000);
    timer_.start();
}

void ImageView::initConnect()
{
    connect(&timer_, &QTimer::timeout, this, &ImageView::updateRemoveButtonEnabled);
    connect(ui->buttonLoad, &QPushButton::clicked, this, &ImageView::loadImage);
    connect(ui->buttonRemove, &QPushButton::clicked, this, &ImageView::removeImage);
}

void ImageView::load(const QString &reqFileName)
{
    fileName_ = reqFileName;
    loadPixmap();
}

void ImageView::setImageChecked(const QString &fileName)
{
    for(auto& x : scene_->items())
    {
        if(fileName.compare(x->data(0).toString()) == 0)
        {
            x->setSelected(true);
        }
    }
}

QString ImageView::fileName() const noexcept
{
    return fileName_;
}

Scene* ImageView::scene()
{
    return scene_;
}

void ImageView::loadPixmap()
{
    QPixmap pixmap(fileName_);

    int width = pixmap.width();
    int height = pixmap.height();

    while (width > ui->graphicsView->width()) {
        width /= 2;
        height /= 2;
    }

    auto copy = pixmap.scaled(width, height);
    qreal heightt = scene_->sceneRect().height() + height;
    heightt += copy.height() / 8;
    scene_->setSceneRect(0, 0, scene_->sceneRect().x(), heightt);
    QGraphicsPixmapItem* pixmapItem = scene_->addPixmap(copy);
    pixmapItem->setData(0, fileName_);
    pixmapItem->setFlag(QGraphicsPixmapItem::ItemIsSelectable);
    pixmapItem->setPos((ui->graphicsView->width() - width) / 2, posY_);
    pixmapItem->setToolTip("You can choose a image that will be\n"
                           "shown in the short book description in main program.\n"
                           "To do this, double-click the image");


    posY_ += height + 5;
}

// Slots

void ImageView::updateRemoveButtonEnabled()
{
    bool enabled = ( isSceneEmpty() ? false : true );

    ui->buttonRemove->setEnabled(enabled);
}

void ImageView::loadImage()
{
    QFileDialog fileDialog(this);

    fileDialog.setWindowTitle("Open image");
    fileDialog.setNameFilter("Images(*.png *.jpg *.bmp)");
    fileDialog.setDefaultSuffix("*.png");
    fileDialog.selectFile("Select image");

    if(fileDialog.exec() == QDialog::Accepted)
    {
        fileName_ = fileDialog.selectedFiles()[0];
        loadPixmap();
    }

    emit imageWasLoaded();
}

void ImageView::removeImage()
{
    scene_->clear();

    emit imageWasRemoved();
}

bool ImageView::isSceneEmpty()
{
    return scene_->items().isEmpty();
}
