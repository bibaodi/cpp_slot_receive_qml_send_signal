#include "MyClass.h"

MyClass::MyClass(QObject *parent, QObject *root) : QObject(parent), qml_root(root) {
    if (!root) {
        qDebug() << "Err: root item is null";
    }
    QObject::connect(root, SIGNAL(qmlSignal(QString)), this, SLOT(cppSlot(QString)));
}

void MyClass::cppSlot(const QString &msg) { qDebug() << "cpp received signal from qml " << msg; }
