import keyboard
import json
import copy
import serial

ARM_SERIAL_PORT = "COM5"
ARM_SERIAL_BAUD = 9600

ARM_SERIAL = serial.Serial()
ARM_SERIAL.baudrate = ARM_SERIAL_BAUD
ARM_SERIAL.port = ARM_SERIAL_PORT

ARM_DATA_JSON = {
    "LAC": 0,
    "UAC": 0,
    "TRT": 0,
    "GRPR": 0,
    "GRPX": 0,
    "GRPY": 0
}


def sendDataToArm(data):
    data_to_send = (json.dumps(data, separators=(',', ':')) +
                    '\r\n').encode('ascii')
    print(data_to_send)
    ARM_SERIAL.write(data_to_send)
    print(ARM_SERIAL.readline())


def setFieldAndSend(field, value):
    ARM_DATA_JSON[field] = value
    sendDataToArm(ARM_DATA_JSON)


def stopArm():
    ARM_DATA_JSON["LAC"] = 0
    ARM_DATA_JSON["UAC"] = 0
    ARM_DATA_JSON["TRT"] = 0
    ARM_DATA_JSON["GRPR"] = 0
    ARM_DATA_JSON["GRPX"] = 0
    ARM_DATA_JSON["GRPY"] = 0
    sendDataToArm(ARM_DATA_JSON)


if __name__ == "__main__":
    ARM_SERIAL.open()

    keyboard.add_hotkey("q", lambda: setFieldAndSend("LAC", 250))
    keyboard.add_hotkey("a", lambda: setFieldAndSend("LAC", 0))
    keyboard.add_hotkey("z", lambda: setFieldAndSend("LAC", -250))

    keyboard.add_hotkey("w", lambda: setFieldAndSend("UAC", 250))
    keyboard.add_hotkey("s", lambda: setFieldAndSend("UAC", 0))
    keyboard.add_hotkey("x", lambda: setFieldAndSend("UAC", -250))

    keyboard.add_hotkey("l", lambda: setFieldAndSend("TRT", 250))
    keyboard.add_hotkey("k", lambda: setFieldAndSend("TRT", 0))
    keyboard.add_hotkey("j", lambda: setFieldAndSend("TRT", -250))

    keyboard.add_hotkey("p", lambda: setFieldAndSend("GRPR", 250))
    keyboard.add_hotkey("o", lambda: setFieldAndSend("GRPR", 0))
    keyboard.add_hotkey("i", lambda: setFieldAndSend("GRPR", -250))

    keyboard.add_hotkey("e", lambda: setFieldAndSend("GRPX", 250))
    keyboard.add_hotkey("d", lambda: setFieldAndSend("GRPX", 0))
    keyboard.add_hotkey("c", lambda: setFieldAndSend("GRPX", -250))

    keyboard.add_hotkey("r", lambda: setFieldAndSend("GRPY", 250))
    keyboard.add_hotkey("f", lambda: setFieldAndSend("GRPY", 0))
    keyboard.add_hotkey("v", lambda: setFieldAndSend("GRPY", -250))

    keyboard.add_hotkey("0", lambda: stopArm())

    keyboard.wait()
