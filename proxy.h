#ifndef PROXY_H
#define PROXY_H

#include <QtCore>

class Proxy : public QObject
{
    Q_OBJECT

public:
    enum MyEnum { EnumValue = 20, AnotherEnumValue };
    Q_ENUM(MyEnum)

    explicit Proxy(QObject *parent = nullptr);

private:
    struct Foo // only used internally
    {
        MyEnum e;
        int v;
    };

signals:
    void fooChanged(int index, MyEnum e, int v);

public slots:
    void setFoo(int index, MyEnum e, int v);
    void initFoos();

private:
    QVector<Foo> foos;
};

#endif // PROXY_H
