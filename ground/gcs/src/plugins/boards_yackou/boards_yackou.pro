TEMPLATE = lib
TARGET = Yackou
include(../../taulabsgcsplugin.pri)
include(../../plugins/uavobjects/uavobjects.pri)
include(../../plugins/coreplugin/coreplugin.pri)

OTHER_FILES += Yackou.pluginspec

HEADERS += \
    yackouplugin.h \
    minim4.h

SOURCES += \
    yackouplugin.cpp \
    minim4.cpp

RESOURCES += \
    yackou.qrc
