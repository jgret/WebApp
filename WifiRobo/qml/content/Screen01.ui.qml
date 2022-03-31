import QtQuick 2.15
import QtQuick.Controls
import RoboGUI
import QtMultimedia 6.0

Rectangle {
    width: Constants.width
    height: Constants.height
    color: "#ffffff"
    border.color: "#ffffff"
    property alias btnPress: btnPress

    Text {
        text: qsTr("Hello Robo")
        anchors.verticalCenterOffset: -19
        anchors.horizontalCenterOffset: 1
        font.family: "Times New Roman"
        font.pointSize: 44
        anchors.centerIn: parent
    }

    Button {
        id: btnPress
        x: 420
        y: 445
        width: 185
        height: 74
        text: qsTr("Press")
        font.styleName: "Extra Bold"
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:2}
}
##^##*/

