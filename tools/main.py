import argparse
from serial_reader import SerialReader
from key_simulator import KeySimulator
from joystick_simulator import JoystickSimulator


def main():
    parser = argparse.ArgumentParser(description="Simulador de Teclas ou Joystick.")
    parser.add_argument(
        "--mode",
        choices=["keyboard", "joystick"],
        default="keyboard",
        help="Escolha entre simular teclado ou joystick.",
    )
    parser.add_argument(
        "--port", required=True, help="Porta serial para se conectar à Blackpill."
    )
    parser.add_argument(
        "--invert-x",
        action="store_true",
        help="Inverte o eixo X do joystick.",
    )
    parser.add_argument(
        "--invert-y",
        action="store_true",
        help="Inverte o eixo Y do joystick.",
    )

    parser.add_argument(
        "--invert-x-y",
        action="store_true",
        help="Inverte o eixo X com o Y do joystick.",
    )

    args = parser.parse_args()

    serial_reader = SerialReader(args.port)

    if args.mode == "keyboard":
        input_handler = KeySimulator()
    else:
        input_handler = JoystickSimulator()

    print(f"Iniciando em modo {args.mode}")

    while True:
        data = serial_reader.read_package()
        if data:
            x, y, button = data
            if args.invert_x:
                x = -x
            if args.invert_y:
                y = -y
            if args.invert_x_y:
                x, y = y, x
            input_handler.handle_input(x, y, button)


if __name__ == "__main__":
    main()
