#ifndef PDFSETTINGS_HPP
#define PDFSETTINGS_HPP

#include <QDialog>

namespace Ui {
class PdfSettings;
}

class PdfSettings : public QDialog
{
    Q_OBJECT

public:
    explicit PdfSettings(QWidget *parent = nullptr);
    ~PdfSettings();

private:
    Ui::PdfSettings *ui;
};

#endif // PDFSETTINGS_HPP
