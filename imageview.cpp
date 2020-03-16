#include "imageview.hpp"
#include "ui_imageview.h"
#include <QMessageBox>

ImageView::ImageView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageView),
    labelWidth_{230},
    labelHeight_{510}
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&scene_);

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

QString ImageView::fileName() const noexcept
{
    return fileName_;
}

void ImageView::loadPixmap()
{
    QPixmap pixmap(fileName_);

    if(!isSceneEmpty())
    {
        scene_.clear();
    }

    scene_.addPixmap(pixmap);
    ui->graphicsView->fitInView(scene_.itemsBoundingRect(), Qt::KeepAspectRatio);
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
    scene_.clear();

    emit imageWasRemoved();
}

bool ImageView::isSceneEmpty()
{
    return scene_.items().isEmpty();
}
