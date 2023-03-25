from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.button import Button
import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)
class MainApp(App):
    def build(self):
        self.last_was_operator = None
        self.last_button = None
        main_layout = BoxLayout(orientation="vertical")
        buttons = [
            ["1", "2", "3", "4", "5", "6",  "7"],
        ]
        for row in buttons:
            h_layout = BoxLayout()
            for label in row:
                button = Button(
                    text=label,
                    pos_hint={"center_x": 0.5, "center_y": 0.5},
                )
                button.bind(on_press=self.on_button_press)
                h_layout.add_widget(button)
            main_layout.add_widget(h_layout)

        return main_layout

    def on_button_press(self, instance):
        button_text = instance.text
        if  button_text == "1":
            ser.write(str("1").encode())
        if  button_text == "2":
            ser.write(str("2").encode())
        if  button_text == "3":
            ser.write(str("3").encode())
        if  button_text == "4":
            ser.write(str("4").encode())
        if  button_text == "5":
            ser.write(str("5").encode())
        if  button_text == "6":
            ser.write(str("6").encode())
        if  button_text == "7":
            ser.write(str("7").encode())


if __name__ == "__main__":
    app = MainApp()
    app.run()