#ifndef SIGNALSLOTLISTVIEW_H
#define SIGNALSLOTLISTVIEW_H

#include <QDebug>
#include <QObject>

class MyClass : public QObject {
    Q_OBJECT
  public:
    explicit MyClass(QObject *parent = 0);

  signals:

  public slots:
    void cppSlot(const QString &msg);
};

#endif // SIGNALSLOTLISTVIEW_H
