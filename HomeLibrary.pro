QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    book.cpp \
    bookadditives.cpp \
    bookbasic.cpp \
    bookbasicnumbers.cpp \
    bookdescriprion.cpp \
    bookeditor.cpp \
    bookimage.cpp \
    bookpurchase.cpp \
    bookrating.cpp \
    bookrentalstatus.cpp \
    booksale.cpp \
    bookscollection.cpp \
    bookseries.cpp \
    booksourceoforigin.cpp \
    bookstatus.cpp \
    booktranslation.cpp \
    categories.cpp \
    categoryselection.cpp \
    configuration.cpp \
    dictionaries.cpp \
    fileinput.cpp \
    general.cpp \
    iconencoding.cpp \
    imageview.cpp \
    main.cpp \
    application.cpp \
    menueditor.cpp \
    newcategorydialog.cpp \
    objectsnames.cpp \
    othercategory.cpp \
    pdfdocument.cpp \
    pdfsettings.cpp \
    shortdescription.cpp \
    stackedwidgeteditor.cpp \
    storageplace.cpp \
    stylesheets.cpp \
    table.cpp \
    tableeditor.cpp \
    tree.cpp \
    treeseditor.cpp

HEADERS += \
    actionsrange.hpp \
    application.hpp \
    book.hpp \
    bookadditives.hpp \
    bookbasic.hpp \
    bookbasicnumbers.hpp \
    bookdescriprion.hpp \
    bookeditor.hpp \
    bookimage.hpp \
    bookpurchase.hpp \
    bookrating.hpp \
    bookrentalstatus.hpp \
    booksale.hpp \
    bookscollection.hpp \
    bookseries.hpp \
    booksourceoforigin.hpp \
    bookstatus.hpp \
    booktranslation.hpp \
    categories.hpp \
    categoryselection.hpp \
    common.hpp \
    configuration.hpp \
    dictionaries.hpp \
    fileinput.hpp \
    general.hpp \
    iconencoding.hpp \
    imageview.hpp \
    menueditor.hpp \
    newcategorydialog.hpp \
    objectsnames.hpp \
    othercategory.hpp \
    pdfdocument.hpp \
    pdfsettings.hpp \
    shortdescription.hpp \
    stackedwidgeteditor.hpp \
    storageplace.hpp \
    stylesheets.hpp \
    table.hpp \
    tableeditor.hpp \
    tree.hpp \
    treeseditor.hpp

FORMS += \
    application.ui \
    bookeditor.ui \
    categoryselection.ui \
    dialog.ui \
    dictionaries.ui \
    imageview.ui \
    newcategorydialog.ui \
    othercategory.ui \
    pdfsettings.ui \
    shortdescription.ui \
    table.ui \
    tree.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
