import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
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
                //console.log("btn plane clicked.")
            }
        }
        Button {
            id: btn_translate
            objectName: "btn_translate"
            text:"translate"
            Layout.preferredHeight:parent.height
            signal qmlSignal(int num)
            onClicked: {
                btn_translate.qmlSignal(42+3)
                //console.log("btn2 clicked.")
            }
        }
    }
    Rectangle {
        id: item_instance
        x:0
        y:0
        width: 71; height: 42
        border.color: "green"
        objectName: "item_instance"
        signal qmlSignal3(variant item_var)

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log(parent.objectName, "clicked")
                item_instance.qmlSignal3(item_instance)
            }
        }
    }

}
