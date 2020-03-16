#ifndef PDFSETTINGS_HPP
#define PDFSETTINGS_HPP

#include <QDialog>
#include <QCheckBox>
#include <QTimer>

namespace Ui {
class PdfSettings;
}

class PdfSettings : public QDialog
{
    Q_OBJECT

public:
    explicit PdfSettings(QWidget *parent = nullptr);
    ~PdfSettings();

    QVector<int> checked() const noexcept;

private slots:
    void countChecked();

private:

    void initCheckBoxesList();
    void initTimer();
    void initConnect();
    void setAcceptButtonEnabled();

    Ui::PdfSettings *ui;

    QTimer timer_;

    QList<QCheckBox*> checkBoxesList_;
    QVector<int> checked_;
};

#endif // PDFSETTINGS_HPP
