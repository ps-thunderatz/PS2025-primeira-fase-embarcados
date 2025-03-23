from pynput.keyboard import Controller
from input_handler import InputHandler


class KeySimulator(InputHandler):
    def __init__(self):
        self.keyboard = Controller()

    def handle_input(self, x: int, y: int, button: bool):
        if x < -100:
            print("a")
            self.keyboard.tap("a")
        elif x > 100:
            self.keyboard.tap("d")
            print("d")

        if y < -100:
            self.keyboard.tap("w")
            print("w")
        elif y > 100:
            self.keyboard.tap("s")
            print("s")
