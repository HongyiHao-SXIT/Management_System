from PyQt6.QtWidgets import QWidget, QLabel, QVBoxLayout


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        label = QLabel('欢迎进入主界面！')
        layout = QVBoxLayout()
        layout.addWidget(label)
        self.setLayout(layout)
        self.setWindowTitle('主界面')
        self.setGeometry(300, 300, 400, 300)
    