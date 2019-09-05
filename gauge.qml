import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    CircularGauge {
        id: gauge

        y: 0
        x: 0
        height: parent.height * 1.8
        width: parent.width

        maximumValue: 100
        minimumValue: 0
        value: 0

        style: CircularGaugeStyle {
            tickmarkStepSize: 10
            minimumValueAngle: -90
            maximumValueAngle: 90
        }

//        Behavior on value {
//            SmoothedAnimation {
//                velocity: 15
//            }
//        }

        Behavior on value {
            NumberAnimation {
                duration: 750
            }
        }

        Connections {
            target: MainWindow
            onUpdate_gauge: gauge.value = value * 0.000008 /* bytes/ms to Gb/s */
        }
    }

    Text {
        id: element
        x: parent.width / 2 - width / 2
        y: parent.height / 2
        text: qsTr("0.0\nGbps")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: parent.height / 10

        Connections {
            target: MainWindow
            onUpdate_gauge: element.text =  Number(value * 0.000008).toFixed(1) + qsTr("\nGbps") /* bytes/ms to Gb/s */
        }
    }
}
//http://192.168.40.212/file.txt

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
