QT += core gui widgets multimedia multimediawidgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        full_screen.cpp \
        initial_window.cpp \
        minimum_screen.cpp \
        signinout_title.cpp \
        the_button.cpp \
        the_button_backward.cpp \
        the_button_filter.cpp \
        the_button_forward.cpp \
        the_button_fullscreen.cpp \
        the_button_order.cpp \
        the_button_pause.cpp \
        the_button_print.cpp \
        the_button_random.cpp \
        the_button_save.cpp \
        the_button_share.cpp \
        the_button_signin.cpp \
        the_button_signout.cpp \
        the_button_sort.cpp \
        the_button_voice.cpp \
        the_customslider.cpp \
        the_menu.cpp \
        the_menu_audio.cpp \
        the_menu_file.cpp \
        the_menu_help.cpp \
        the_menu_tools.cpp \
        the_menu_video.cpp \
        the_player.cpp \
        tomeo.cpp \
        whole_widget.cpp

HEADERS += \
    full_screen.h \
    initial_window.h \
    minimum_screen.h \
    signinout_title.h \
    the_button.h \
    the_button_backward.h \
    the_button_filter.h \
    the_button_forward.h \
    the_button_fullscreen.h \
    the_button_order.h \
    the_button_pause.h \
    the_button_print.h \
    the_button_random.h \
    the_button_save.h \
    the_button_share.h \
    the_button_signin.h \
    the_button_signout.h \
    the_button_sort.h \
    the_button_voice.h \
    the_customslider.h \
    the_menu.h \
    the_menu_audio.h \
    the_menu_file.h \
    the_menu_help.h \
    the_menu_tools.h \
    the_menu_video.h \
    the_player.h \
    whole_widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc \
    buttons.qrc \
    buttons2.qrc \
    buttons3.qrc

FORMS += \
    form.ui


