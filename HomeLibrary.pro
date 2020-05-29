QT       += core gui
QT       += printsupport
QT       += xml

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
    bookeditor.cpp \
    bookimage.cpp \
    bookscollection.cpp \
    categories.cpp \
    categoryselection.cpp \
    configuration.cpp \
    dictionaries.cpp \
    fileinput.cpp \
    filterwidget.cpp \
    general.cpp \
    imageview.cpp \
    languages.cpp \
    main.cpp \
    application.cpp \
    menueditor.cpp \
    newcategorydialog.cpp \
    objectsnames.cpp \
    othercategory.cpp \
    pdfdocument.cpp \
    pdfsettings.cpp \
    scene.cpp \
    settings.cpp \
    shortdescription.cpp \
    stackedwidgeteditor.cpp \
    storageplace.cpp \
    table.cpp \
    tableeditor.cpp \
    tree.cpp \
    xmlfile.cpp

HEADERS += \
    actionsrange.hpp \
    application.hpp \
    book.hpp \
    bookdataio.hpp \
    bookdetails.hpp \
    bookeditor.hpp \
    bookimage.hpp \
    bookscollection.hpp \
    categories.hpp \
    categoryselection.hpp \
    common.hpp \
    configuration.hpp \
    conversion.hpp \
    datatowidget.hpp \
    dictionaries.hpp \
    fileinput.hpp \
    filterwidget.hpp \
    general.hpp \
    imageview.hpp \
    languages.hpp \
    menueditor.hpp \
    newcategorydialog.hpp \
    objectsnames.hpp \
    othercategory.hpp \
    pdfdocument.hpp \
    pdfsettings.hpp \
    scene.hpp \
    settings.hpp \
    shortdescription.hpp \
    stackedwidgeteditor.hpp \
    storageplace.hpp \
    table.hpp \
    tableeditor.hpp \
    tree.hpp \
    value.hpp \
    xmlfile.hpp

FORMS += \
    application.ui \
    bookeditor.ui \
    categoryselection.ui \
    dialog.ui \
    dictionaries.ui \
    filterwidget.ui \
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
