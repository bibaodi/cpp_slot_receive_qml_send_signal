#include "MyClass.h"

MyClass::MyClass(QObject *parent) : QObject(parent) {}

void MyClass::cppSlot(const QString &msg) { qDebug() << "cpp received signal from qml " << msg; }
