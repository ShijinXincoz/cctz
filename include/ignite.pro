QT -= qt core gui

SOURCES += \
    main.cpp

QMAKE_CXXFLAGS +=  -std=c++11


INCLUDEPATH +=  /usr/local/gcc4.8.0/include \
                /usr/local/gcc4.8.0/lib/gcc/x86_64-unknown-linux-gnu/4.8.0/include/ \
                /usr/local/include \
#                /usr/local/include \
#                /usr/local/include/ignite/ \
                /usr/java/jdk1.8.0_102/include \
                apache-ignite-fabric-2.0.0-bin/platforms/cpp/core/include \
                apache-ignite-fabric-2.0.0-bin/platforms/cpp/examples/include \
                apache-ignite-fabric-2.0.0-bin/platforms/cpp/jni/include \
                apache-ignite-fabric-2.0.0-bin/platforms/cpp/common/os/linux/include/ \
                apache-ignite-fabric-2.0.0-bin/platforms/cpp/common/include \
                apache-ignite-fabric-2.0.0-bin/platforms/cpp/common/os/linux/include \
                apache-ignite-fabric-2.0.0/platforms/cpp/binary/include \
                /usr/local/include/ignite/jni/ \
                apache-ignite-fabric-2.0.0-bin/platforms/cpp/binary/include \
                apache-ignite-fabric-2.0.0-bin/include


HEADERS += \
    ../include/ignite/examples/person.h \
    ../include/ignite/examples/organization.h \
    ../include/ignite/examples/address.h \
    ../include/ignite/examples/test.h \
    ../include/ignite/examples/TestKey.h

LIBS += -L/usr/java/jdk1.8.0_102/jre/lib/amd64/server/ \
        -L/usr/local/gcc4.8.0/lib/ \
        -L/usr/local/gcc4.8.0/lib64/ \
        -ljvm -ldl -lpthread -lignite -lignite-jni
