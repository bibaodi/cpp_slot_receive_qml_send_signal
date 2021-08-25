#include "MyClass.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    QObject *root = engine.rootObjects()[0];

    MyClass myClass(nullptr, root);

    return app.exec();
}
#if 0
int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/MyItem.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
#endif
