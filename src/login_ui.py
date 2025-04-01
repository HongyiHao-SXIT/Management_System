import sys
import mysql.connector
import bcrypt
from PyQt6.QtWidgets import QApplication, QWidget, QLabel, QLineEdit, QPushButton, QVBoxLayout, QMessageBox


def get_db_connection():
    try:
        connection = mysql.connector.connect(
            host='localhost',
            user='root',
            password='123456',
            database='furry_bloggie'
        )
        return connection
    except mysql.connector.Error as err:
        QMessageBox.critical(None, 'Database Connection Error', f'Error connecting to the database: {err}')
        return None


def authenticate_user(username, password):
    connection = get_db_connection()
    if connection:
        try:
            cursor = connection.cursor()
            query = "SELECT password FROM users WHERE username = %s"
            cursor.execute(query, (username,))
            result = cursor.fetchone()
            if result:
                hashed_password = result[0].encode('utf-8')
                if bcrypt.checkpw(password.encode('utf-8'), hashed_password):
                    return True
            return False
        except mysql.connector.Error as err:
            QMessageBox.critical(None, 'Database Query Error', f'Error executing query: {err}')
            return False
        finally:
            if connection.is_connected():
                cursor.close()
                connection.close()


class LoginWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setStyleSheet("""
            QWidget {
                background-color: #f4f4f9;
            }
            QLabel {
                font-size: 14px;
                color: #333;
                margin-bottom: 5px;
            }
            QLineEdit {
                padding: 8px;
                font-size: 14px;
                border: 1px solid #ccc;
                border-radius: 4px;
                margin-bottom: 15px;
            }
            QPushButton {
                padding: 10px;
                font-size: 14px;
                background-color: #007BFF;
                color: white;
                border: none;
                border-radius: 4px;
                margin-bottom: 10px;
            }
            QPushButton:hover {
                background-color: #0056b3;
            }
        """)

        self.username_label = QLabel('Username:')
        self.username_input = QLineEdit()
        self.password_label = QLabel('Password:')
        self.password_input = QLineEdit()
        self.password_input.setEchoMode(QLineEdit.EchoMode.Password)

        self.login_button = QPushButton('Login')
        self.login_button.clicked.connect(self.login)
        self.exit_button = QPushButton('Exit')
        self.exit_button.clicked.connect(self.close)

        layout = QVBoxLayout()
        layout.addWidget(self.username_label)
        layout.addWidget(self.username_input)
        layout.addWidget(self.password_label)
        layout.addWidget(self.password_input)
        layout.addWidget(self.login_button)
        layout.addWidget(self.exit_button)

        self.setLayout(layout)
        self.setWindowTitle('Login')
        self.setGeometry(300, 300, 300, 250)

    def login(self):
        username = self.username_input.text()
        password = self.password_input.text()

        if authenticate_user(username, password):
            QMessageBox.information(self, 'Login Result', 'Login successful!')
        else:
            QMessageBox.warning(self, 'Login Result', 'Incorrect username or password!')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    login_window = LoginWindow()
    login_window.show()
    sys.exit(app.exec())
    