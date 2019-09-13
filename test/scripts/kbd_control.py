import keyboard
import json

ARM_DATA_JSON = {
    "LAC": 0,
    "UAC": 0,
    "TRT": 0,
    "GRPR": 0,
    "GRPX": 0,
    "GRPY": 0
}


def sendDataToArm(data):
    print(data)


def setFieldAndSend(field, value):
    ARM_DATA_JSON[field] = value
    sendDataToArm(ARM_DATA_JSON)


if __name__ == "__main__":
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

    keyboard.wait()
