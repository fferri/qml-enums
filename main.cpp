#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "proxy.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qRegisterMetaType<Proxy::MyEnum>();
#if 0
    qmlRegisterType<Proxy>("test.proxy", 1, 0, "Proxy");
#else
    qmlRegisterUncreatableType<Proxy>("test.proxy", 1, 0, "Proxy", "Proxy object");
#endif
    Proxy proxy;
    engine.rootContext()->setContextProperty("proxy", &proxy);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if(engine.rootObjects().isEmpty())
        return -1;
    auto rootObject = engine.rootObjects()[0];
    auto testItem = rootObject->findChild<QObject*>("testItem");
    if(testItem)
        QObject::connect(testItem, SIGNAL(testSignal()), &proxy, SLOT(initFoos()));
    else
        qCritical() << "Cannot find object named 'testItem'";
    return app.exec();
}
