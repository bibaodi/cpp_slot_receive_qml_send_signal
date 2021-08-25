import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: item
    width: 100; height: 100

    signal qmlSignal(msg: string)

    MouseArea {
        anchors.fill: parent
        onClicked: item.qmlSignal("Hello from QML")
    }
    Button {
        id: btn_select
        objectName: "btn_select"
        text: "act-plane"
        signal qmlSignal(msg: string)
        onClicked: {
            btn_select.qmlSignal("Hello from QML from btn")
            console.log("btn clicked.")
        }
    }
}
