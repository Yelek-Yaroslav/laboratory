import tkinter as tk

class RoundButton:
    def __init__(self, canvas, x, y, r, text, command, fill="#000000", fg="white", equal=False):
        self.canvas = canvas
        self.r = r
        self.command = command
        self.equal = equal

        self.fg = fg
        self.normal_fill = fill
        self.pressed_fill = "#222222" if not equal else "#CC7A00"
        if equal:
            self.normal_fill = "#FF9500"
            self.pressed_fill = "#CC7A00"
            self.fg = "white"

        self.oval = canvas.create_oval(x-r, y-r, x+r, y+r, fill=self.normal_fill, outline="")
        self.label = canvas.create_text(x, y, text=text, fill=self.fg, font=("Helvetica", 18, "bold"))

        canvas.tag_bind(self.oval, "<Button-1>", lambda e: self.on_press(text))
        canvas.tag_bind(self.label, "<Button-1>", lambda e: self.on_press(text))
        canvas.tag_bind(self.oval, "<ButtonRelease-1>", lambda e: self.on_release())
        canvas.tag_bind(self.label, "<ButtonRelease-1>", lambda e: self.on_release())

    def on_press(self, text):
        self.canvas.itemconfig(self.oval, fill=self.pressed_fill)
        self.command(text)

    def on_release(self):
        self.canvas.itemconfig(self.oval, fill=self.normal_fill)

class Calculator(tk.Frame):
    def __init__(self, root):
        super().__init__(root, bg="#000000")
        self.formula = ""
        self.error_flag = False
        self.create_widgets()

    def create_widgets(self):
        self.display_var = tk.StringVar(value="0")
        self.display = tk.Label(self, textvariable=self.display_var, anchor="e",
                                bg="#000000", fg="white", font=("Helvetica", 25, "bold"))
        self.display.pack(side="top", fill="x", padx=10, pady=20)

        self.canvas = tk.Canvas(self, bg="#000000", highlightthickness=0)
        self.canvas.pack(expand=True, fill="both", padx=10, pady=10)

        self.buttons = [
            ["C", "<=", "%", "*"],
            ["1", "2", "3", "/"],
            ["4", "5", "6", "+"],
            ["7", "8", "9", "-"],
            ["", "0", ".", "="]
        ]
        self.radius = 40
        self.spacing = 20
        start_x = self.radius + 20
        start_y = self.radius + 20

        operator_text_color = "#FF9500"
        for r, row in enumerate(self.buttons):
            for c, bt in enumerate(row):
                if bt == "":
                    continue
                x = start_x + c * (2*self.radius + self.spacing)
                y = start_y + r * (2*self.radius + self.spacing)
                fg_color = operator_text_color if bt in ["C","<=","%","*","/","+","-"] else "white"
                RoundButton(self.canvas, x, y, self.radius, bt, self.calculate, fill="#000000", fg=fg_color, equal=(bt=="="))

    def calculate(self, key):
        operators = "+-*/"

        if self.error_flag:
            self.formula = ""
            self.error_flag = False

        if key == "C":
            self.formula = ""
        elif key == "<=":
            self.formula = self.formula[:-1]
        elif key == ".":
            if self.formula == "" or self.formula[-1] in operators:
                self.formula += "0."
            else:
                last_number = self.get_last_number()
                if "." not in last_number:
                    self.formula += "."
        elif key in operators:
            if self.formula == "":
                if key == "-":
                    self.formula = "-"
                return
            if self.formula[-1:] in operators:
                self.formula = self.formula[:-1] + key
            else:
                self.formula += key
        elif key == "%":
            try:
                result = eval(self.formula)
                result /= 100
                if isinstance(result, float):
                    result = round(result, 10)
                self.formula = str(result)
            except:
                self.formula = "Помилка"
                self.error_flag = True
        elif key == "=":
            try:
                result = eval(self.formula)
                if isinstance(result, float):
                    result = round(result, 10)
                self.formula = str(result)
            except:
                self.formula = "Помилка"
                self.error_flag = True
        else:
            self.formula += key

        if self.formula == "":
            self.display_var.set("0")
        else:
            self.display_var.set(self.formula)

    def get_last_number(self):
        operators = "+-*/"
        num = ""
        for ch in reversed(self.formula):
            if ch in operators:
                break
            num = ch + num
        return num

if __name__ == "__main__":
    root = tk.Tk()
    root.title("Калькулятор")
    root.geometry("445x630")
    app = Calculator(root)
    app.pack(expand=True, fill="both")
    root.mainloop()
