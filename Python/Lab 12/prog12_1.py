import tkinter as tk

# Клас створення кнопок вручну за допомогою Canvas та взаємодія з ними
class RoundButton:
    def __init__(self, canvas, x, y, r, text, command,
                 fill="#000000", fg="white", equal=False):

        self.canvas = canvas
        self.r = r
        self.command = command
        self.equal = equal

        # Колір тексту та фону кнопки у звичайному та натиснутому стані
        self.fg = fg
        self.normal_fill = fill
        self.pressed_fill = "#222222" if not equal else "#CC7A00"

        # Окрема кольорова схема для кнопки "="
        if equal:
            self.normal_fill = "#FF9500"
            self.pressed_fill = "#CC7A00"
            self.fg = "white"

        # Малюємо круг та текст усередині
        self.oval = canvas.create_oval(
            x - r, y - r, x + r, y + r,
            fill=self.normal_fill, outline=""
        )
        self.label = canvas.create_text(
            x, y, text=text, fill=self.fg,
            font=("Helvetica", 18, "bold")
        )

        # Прив'язуємо події натискання/відпускання миші як до кола, так і до тексту — щоб обидва реагували
        canvas.tag_bind(self.oval, "<Button-1>", lambda e: self.on_press(text))
        canvas.tag_bind(self.label, "<Button-1>", lambda e: self.on_press(text))
        canvas.tag_bind(self.oval, "<ButtonRelease-1>", lambda e: self.on_release())
        canvas.tag_bind(self.label, "<ButtonRelease-1>", lambda e: self.on_release())

    # Викликається при натисканні кнопки, міняє колір кнопки і передає її текст у функцію обробки
    def on_press(self, text):
        self.canvas.itemconfig(self.oval, fill=self.pressed_fill)
        self.command(text)

    # Повертає кнопці нормальний колір після відпускання
    def on_release(self):
        self.canvas.itemconfig(self.oval, fill=self.normal_fill)

# Основний клас калькулятора
# Відповідає за створення інтерфейсу, обробку натискань кнопок роботу з формулою та обчисленням результатів
class Calculator(tk.Frame):
    def __init__(self, root):
        super().__init__(root, bg="#000000")

        self.formula = ""       # Поточна математична формула
        self.error_flag = False # Встановлюється, якщо під час обчислення виникла помилка
        self.create_widgets()   # Створюємо графічні елементи

    # Створення всіх елементів інтерфейсу
    def create_widgets(self):
        # Рядок відображення формули та результату
        self.display_var = tk.StringVar(value="0")
        self.display = tk.Label(
            self, textvariable=self.display_var,
            anchor="e", bg="#000000", fg="white",
            font=("Helvetica", 25, "bold")
        )
        self.display.pack(side="top", fill="x", padx=10, pady=20)

        # Використовуємо Canvas для малювання круглих кнопок
        self.canvas = tk.Canvas(self, bg="#000000", highlightthickness=0)
        self.canvas.pack(expand=True, fill="both", padx=10, pady=10)

        # Сітка кнопок калькулятора
        self.buttons = [
            ["C", "<=", "%", "*"],
            ["1", "2", "3", "/"],
            ["4", "5", "6", "+"],
            ["7", "8", "9", "-"],
            ["", "0", ".", "="]
        ]

        # Параметри геометрії кнопок
        self.radius = 40
        self.spacing = 20
        start_x = self.radius + 20
        start_y = self.radius + 20

        operator_text_color = "#FF9500"  # Колір операторів та спецкнопок

        # Створюємо круглі кнопки відповідно до сітки
        for r, row in enumerate(self.buttons):
            for c, bt in enumerate(row):
                if bt == "":
                    continue  # Пусті комірки пропускаємо

                # Розрахунок координат центру кнопки
                x = start_x + c * (2 * self.radius + self.spacing)
                y = start_y + r * (2 * self.radius + self.spacing)

                # Визначаємо колір тексту: оператори — помаранчеві, цифри — білі
                fg_color = operator_text_color if bt in ["C","<=","%","*","/","+","-"] else "white"

                # Створюємо кнопку
                RoundButton(
                    self.canvas, x, y, self.radius, bt,
                    self.calculate, fill="#000000",
                    fg=fg_color, equal=(bt == "=")
                )

    # Метод, що обробляє логіку всіх кнопок калькулятора
    def calculate(self, key):
        operators = "+-*/"

        # Якщо раніше виникла помилка - очищаємо формулу
        if self.error_flag:
            self.formula = ""
            self.error_flag = False

        # Очищення всього рядка
        if key == "C":
            self.formula = ""

        # Видалення останнього символу
        elif key == "<=":
            self.formula = self.formula[:-1]

        # Обробка крапки
        elif key == ".":
            # Якщо число починається або стоїть після оператора - ставимо 0.
            if self.formula == "" or self.formula[-1] in operators:
                self.formula += "0."
            else:
                last_number = self.get_last_number()
                # Забороняємо другу крапку в числі
                if "." not in last_number:
                    self.formula += "."

        # Обробка операторів + - * /
        elif key in operators:
            if self.formula == "":
                # Єдиний випадок, коли можна почати формулу оператором - мінус
                if key == "-":
                    self.formula = "-"
                return
            # Якщо останній символ - оператор, замінюємо його
            if self.formula[-1:] in operators:
                self.formula = self.formula[:-1] + key
            else:
                self.formula += key

        # Обробка відсотка
        elif key == "%":
            try:
                result = eval(self.formula)
                result /= 100
                # Округлюємо лише для float
                if isinstance(result, float):
                    result = round(result, 10)
                self.formula = str(result)
            except:
                self.formula = "Помилка"
                self.error_flag = True

        # Обчислення результату
        elif key == "=":
            try:
                result = eval(self.formula)
                if isinstance(result, float):
                    result = round(result, 10)
                self.formula = str(result)
            except:
                self.formula = "Помилка"
                self.error_flag = True

        # Якщо натиснута цифра - додаємо її до формули
        else:
            self.formula += key

        # Оновлюємо дисплей
        self.display_var.set(self.formula if self.formula else "0")

    # Метод повертає останнє число у формулі, ігноруючи оператори
    def get_last_number(self):
        operators = "+-*/"
        num = ""
        # Рухаємось справа наліво до першого оператора
        for ch in reversed(self.formula):
            if ch in operators:
                break
            num = ch + num
        return num


# Запуск програми
if __name__ == "__main__":
    root = tk.Tk()
    root.title("Калькулятор")
    root.geometry("445x630")
    app = Calculator(root)
    app.pack(expand=True, fill="both")
    root.mainloop()