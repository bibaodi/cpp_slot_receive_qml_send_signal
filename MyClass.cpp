#include "MyClass.h"

MyClass::MyClass(QObject *parent, QObject *root) : QObject(parent), qml_root(root) {
    if (!root) {
        qDebug() << "Err: root item is null";
        return;
    }

    QObject *item = root->findChild<QObject *>("btn_select");
    QObject *item2 = root->findChild<QObject *>("btn_translate");
    QObject::connect(item, SIGNAL(qmlSignal(QString)), this, SLOT(cppSlot(QString)));
    QObject::connect(item2, SIGNAL(qmlSignal(int)), this, SLOT(cppSlot(int)));
}

void MyClass::cppSlot(const QString &msg) { qDebug() << "cpp received signal from qml: " << msg; }
void MyClass::cppSlot(const int msg) { qDebug() << "cpp received signal from qml: " << msg; }
