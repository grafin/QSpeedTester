import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    CircularGauge {
        id: gauge
        maximumValue: 100
        minimumValue: 0
        value: 50
        anchors.centerIn: parent

        Behavior on value {
            NumberAnimation {
                duration: 100
            }
        }

        Connections {
            target: MainWindow
            onUpdate_gauge: gauge.value = value
        }
    }
}

