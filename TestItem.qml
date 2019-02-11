import QtQuick 2.12
import QtQuick.Controls 1.6
import test.proxy 1.0

Item {
    id: root
    objectName: "testItem"
    anchors.fill: parent
    signal testSignal

    Component.onCompleted: {
        console.log("Component.onCompleted: Proxy.EnumValue = " + Proxy.EnumValue)
    }

    Connections {
        id: connections
        target: proxy
        onFooChanged: {
            console.log("Connections.onFooChanged: index = " + index + ", e = " + e + ", v = " + v)
            console.log("Connections.onFooChanged: Proxy.EnumValue = " + Proxy.EnumValue)
        }
    }

    Button {
        id: testButton
        anchors.centerIn: parent
        text: "Test"
        onClicked: {
            console.log("testButton.onClicked: Proxy.EnumValue = " + Proxy.EnumValue)
            root.testSignal()
        }
    }
}
