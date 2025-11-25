from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QVBoxLayout, QFileDialog, QMessageBox
import sys

class DataAnalyzer(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Аналіз числових даних (PySide6)")
        self.resize(400, 200)

        self.label = QLabel("Результати з’являться тут")
        self.button = QPushButton("Відкрити файл")
        self.button.clicked.connect(self.load_file)

        layout = QVBoxLayout()
        layout.addWidget(self.button)
        layout.addWidget(self.label)
        self.setLayout(layout)

    def load_file(self):
        filepath, _ = QFileDialog.getOpenFileName(self, "Відкрити файл", "", "Text Files (*.txt)")
        if not filepath:
            return
        try:
            with open(filepath, "r") as file:
                numbers = [float(line.strip()) for line in file if line.strip()]
            if not numbers:
                QMessageBox.information(self, "Результат", "Файл порожній")
                return
            total = sum(numbers)
            avg = total / len(numbers)
            minimum = min(numbers)
            maximum = max(numbers)
            self.label.setText(f"Сума: {total}\nСереднє: {avg}\nМінімум: {minimum}\nМаксимум: {maximum}")
        except Exception as e:
            QMessageBox.critical(self, "Помилка", f"Неможливо відкрити файл:\n{e}")

app = QApplication(sys.argv)
window = DataAnalyzer()
window.show()
app.exec()
