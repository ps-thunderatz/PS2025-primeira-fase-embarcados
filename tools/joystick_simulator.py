import vgamepad as vg
from input_handler import InputHandler


class JoystickSimulator(InputHandler):
    def __init__(self):
        self.gamepad = vg.VX360Gamepad()
        self.current_x = 0
        self.current_y = 0
        self.current_button = False

    def handle_input(self, x: int, y: int, button: bool):
        x = int(x * 256)
        y = int(y * 256)

        x = max(-32768, min(32767, x))
        y = max(-32768, min(32767, y))

        if x != self.current_x:
            self.gamepad.left_joystick(x, self.current_y)
            self.current_x = x

        if y != self.current_y:
            self.gamepad.left_joystick(self.current_x, y)
            self.current_y = y

        if button != self.current_button:
            if button:
                self.gamepad.press_button(vg.XUSB_BUTTON.XUSB_GAMEPAD_START)
            else:
                self.gamepad.release_button(vg.XUSB_BUTTON.XUSB_GAMEPAD_START)
            self.current_button = button

        self.gamepad.update()
