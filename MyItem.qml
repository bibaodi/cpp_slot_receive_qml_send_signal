import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

Item {
    id: item
    width: 320; height: 240

    //signal qmlSignal(msg: string)

    MouseArea {
        anchors.fill: parent
        onClicked: item.qmlSignal("Hello from QML")
    }
    RowLayout {
        width:parent.width / 2
        height: 20
        x:0
        y: parent.height - height - 10
        Button {
            id: btn_select
            objectName: "btn_select"
            text: "act-plane"
            Layout.preferredHeight:parent.height
            signal qmlSignal(msg: string)
            onClicked: {
                btn_select.qmlSignal("Hello from QML from btn")
                console.log("btn plane clicked.")
            }
        }
        Button {
            id: btn_translate
            objectName: "btn_translate"
            text:"translate"
            Layout.preferredHeight:parent.height
            signal qmlSignal2(message:int )
            onClicked: {
                btn_translate.qmlSignal2(42)
                console.log("btn2 clicked.")
            }
        }
    }
}
