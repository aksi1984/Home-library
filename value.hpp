#ifndef VALUE_HPP
#define VALUE_HPP

#include <QSpinBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QDateEdit>

#include <QMessageBox>


//////////////////////////////////////////////////////////////////////////////////////

template<typename T, typename = void>
struct IsList : public std::false_type { };

template<typename T>
struct IsList<T, std::conditional_t<false, std::void_t<typename T::value_type, typename T::size_type, decltype (std::declval<T>().size())>, void> > : public std::true_type { };

///////////////////////////////////////////////////////////////////////////////////////

template<typename T>
struct Value { };

template<>
struct Value<QSpinBox*>
{
    static QVariant get(QSpinBox* spinBox)
    {
        return QVariant(spinBox->value());
    }

    static void get(QSpinBox* spinBox, QVariant variant)
    {
        auto value = variant.toInt();
        spinBox->setValue(value);
    }
};

template<>
struct Value<QDoubleSpinBox*>
{
    static QVariant get(QDoubleSpinBox* doubleSpinBox)
    {
        return QVariant(doubleSpinBox->value());
    }

    static void get(QDoubleSpinBox* doubleSpinBox, QVariant variant)
    {
        auto value = variant.toDouble();
        doubleSpinBox->setValue(value);
    }
};

template<>
struct Value<QLineEdit*>
{
    static QVariant get(QLineEdit* lineEdit)
    {
        return QVariant(lineEdit->text());
    }

    static void get(QLineEdit* lineEdit, QVariant variant)
    {
        lineEdit->setText(variant.toString());
    }
};

template<>
struct Value<QTextEdit*>
{
    static QVariant get(QTextEdit* textEdit)
    {
        return QVariant(textEdit->toPlainText());
    }

    static void get(QTextEdit* textEdit, QVariant variant)
    {
        auto text = variant.toString();
        textEdit->setText(text);
    }
};

template<>
struct Value<QCheckBox*>
{
    static QVariant get(QCheckBox* checkBox)
    {
        return QVariant(checkBox->isChecked());
    }

    static void get(QCheckBox* checkBox, QVariant variant)
    {
        auto isChecked = variant.toBool();
        checkBox->setChecked(isChecked);
    }
};


template<>
struct Value<QDateEdit*>
{
    static QVariant get(QDateEdit* dateEdit)
    {
        return QVariant(dateEdit->date());
    }

    static void get(QDateEdit* dateEdit, QVariant variant)
    {
        auto date = variant.toDate();
        dateEdit->setDate(date);
    }
};

//////////////////////////////////////////////////////////

template<typename... Args>
QVariantList getVariants(int size, Args... args)
{
    QVariantList data;

    if constexpr((IsList<Args>{}, ...))
    {
        for(auto i = 0; i < size; ++i)
        {
            data.push_back( (QVariant(args[i]->text()), ...) );
        }
    }
    else
    {
        (data.push_back(Value<Args>::get(args)), ...);
    }

    return data;
}


#endif // VALUE_HPP
