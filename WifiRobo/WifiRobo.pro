QT += \
    core \
    gui \
    network \
    multimedia \
    openglwidgets \
    bluetooth

SOURCES += \
    imagestream.cpp \
    main.cpp \
    robocontrol.cpp \
    widget.cpp

HEADERS += \
    imagestream.h \
    robocontrol.h \
    widget.h

FORMS += \
    widget.ui

RESOURCES += \
    files.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
