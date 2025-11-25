import tkinter as tk
from tkinter import filedialog, messagebox

def load_file():
    filepath = filedialog.askopenfilename(filetypes=[("Text Files", "*.txt")])
    if not filepath:
        return
    try:
        with open(filepath, "r") as file:
            numbers = [float(line.strip()) for line in file if line.strip()]
        if not numbers:
            messagebox.showinfo("Результат", "Файл порожній")
            return
        total = sum(numbers)
        avg = total / len(numbers)
        minimum = min(numbers)
        maximum = max(numbers)
        result_text = f"Сума: {total}\nСереднє: {avg}\nМінімум: {minimum}\nМаксимум: {maximum}"
        result_label.config(text=result_text)
    except Exception as e:
        messagebox.showerror("Помилка", f"Неможливо відкрити файл:\n{e}")

root = tk.Tk()
root.title("Аналіз числових даних (Tkinter)")
root.geometry("300x200")

load_button = tk.Button(root, text="Відкрити файл", command=load_file)
load_button.pack(pady=10)

result_label = tk.Label(root, text="Результати з’являться тут", justify="left")
result_label.pack(pady=10)

root.mainloop()
