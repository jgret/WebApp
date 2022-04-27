QT += \
    core \
    gui \
    network \
    multimedia \
    openglwidgets

SOURCES += \
    imagestream.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    imagestream.h \
    widget.h

FORMS += \
    widget.ui

RESOURCES += \
    files.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
