import serial


class SerialReader:
    def __init__(self, port: str, baudrate: int = 9600):
        self.serial = serial.Serial(port, baudrate)

    def read_package(self):
        """
        Lê um pacote de 5 bytes da serial, validando o início e o fim.
        """
        data = self.serial.read(5)
        if data[0] == 0x7E and data[4] == 0x7F:
            x = data[1] - 128
            y = data[2] - 128
            button = bool(data[3])
            return x, y, button
        return None
