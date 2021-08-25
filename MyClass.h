#ifndef SIGNALSLOTLISTVIEW_H
#define SIGNALSLOTLISTVIEW_H

#include <QDebug>
#include <QObject>

class MyClass : public QObject {
    Q_OBJECT
  public:
    explicit MyClass(QObject *parent = 0, QObject *root = nullptr);
    QObject *qml_root;

  signals:

  public slots:
    void cppSlot(const QString &msg);
    void cppSlot(const int msg);
};

#endif // SIGNALSLOTLISTVIEW_H
