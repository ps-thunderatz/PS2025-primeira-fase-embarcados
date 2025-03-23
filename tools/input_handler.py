from abc import ABC, abstractmethod


class InputHandler(ABC):
    """
    Interface para lidar com as entradas do dispositivo.
    """

    @abstractmethod
    def handle_input(self, x: int, y: int, button: bool):
        pass
