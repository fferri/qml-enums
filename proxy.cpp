#include "proxy.h"

Proxy::Proxy(QObject *parent)
    : QObject(parent)
{

}

void Proxy::setFoo(int index, MyEnum e, int v)
{
    auto &foo = foos[index];
    if(foo.e != e || foo.v != v)
    {
        foo.e = e;
        foo.v = v;
        emit fooChanged(index, e, v);
    }
}

void Proxy::initFoos()
{
    qDebug() << "Proxy::initFoos";
    foos.resize(2);
    setFoo(0, EnumValue, 100);
    setFoo(1, AnotherEnumValue, 550);
}
