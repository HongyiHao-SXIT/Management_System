import sys
from PyQt6.QtWidgets import QApplication, QWidget, QLabel

app = QApplication(sys.argv)
window = QWidget()
window.setWindowTitle('Furry Blog - Test')
window.setGeometry(100, 100, 300, 200)
label = QLabel('Hello, Furry Blog!', window)
label.move(100, 100)
window.show()
sys.exit(app.exec())