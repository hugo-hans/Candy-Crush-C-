QMAKE_MAC_SDK = macosx10.13
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -static

SOURCES += main.cpp \
    Correc_prof/gridmanagement.cpp \
    Correc_prof/nsutil.cpp \
    Correc_prof/game.cpp \
    Correc_prof/params.cpp \
    Nos_fichiers/jeu.cpp \
    Nos_fichiers/parametres.cpp \
    Nos_fichiers/colors.cpp \
    Nos_fichiers/score.cpp \
    Nos_fichiers/firstmenu.cpp \
    Nos_fichiers/Help.cpp

HEADERS += \
    Correc_prof/nsutil.h \
    Correc_prof/type.h \
    Correc_prof/params.h \
    Correc_prof/gridmanagement.h \
    Correc_prof/game.h \
    Nos_fichiers/jeu.h \
    Nos_fichiers/parametres.h \
    Nos_fichiers/colors.h \
    Nos_fichiers/score.h \
    Nos_fichiers/Help.h \
    Nos_fichiers/firstmenu.h

DISTFILES += \
    Nos_fichiers/config.yaml
