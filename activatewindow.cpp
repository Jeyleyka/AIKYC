#include "activatewindow.h"

void ActivateWindow::initInputKeyContainer() {
    this->enterKey = new QLabel("Enter the activation key:", this);
    this->enterKey->setStyleSheet("color: #fff; font-size: 15px; font-weight: 500; margin-left: 40px");

    this->inputKey = new QTextEdit(this);
    this->inputKey->setStyleSheet("margin-top: 15px; max-height: 20px; max-width: 250px; background-color: #fff; margin-left: 40px;");
    this->inputKey->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->inputKey->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->inputKey->setWordWrapMode(QTextOption::NoWrap);

    this->active = new QPushButton("Active", this);
    this->active->setStyleSheet("background-color: #2667fd; color: #fff; font-weight: 600; font-size: 15px; min-height: 25px; max-height: 25px; min-width: 100px; max-width: 100px;"
                                "border: 2px solid #fff; margin-top: 15px;; margin-left: 40px;");

    connect(this->active, &QPushButton::clicked, this, [] {
        QMessageBox msgBox;
        msgBox.setText("Activation Failed - wrong activation key!");
        msgBox.setStyleSheet("background-color: white; color: black; font-size: 12px;");
        msgBox.setModal(true);
        msgBox.exec();
    });

    this->activeKey = new QLabel("If there is no activation key:", this);
    this->activeKey->setStyleSheet("color: #fff; font-size: 15px; font-weight: 500; margin-top: 40px; margin-left: 40px;");
}

void ActivateWindow::initBuyKeyContainer() {
    this->buy = new QPushButton("Buy", this);
    this->buy->setStyleSheet("background-color: #296303; color: #fff; font-weight: 600; font-size: 15px; min-height: 25px; max-height: 25px; min-width: 100px; max-width: 100px;"
                             "border: 2px solid #fff; margin-top: 15px; margin-left: 40px;");

    BuyKeyWindow* buyWnd = new BuyKeyWindow(this);

    connect(this->buy, &QPushButton::clicked, buyWnd, &BuyKeyWindow::show);
}

void ActivateWindow::initWarningText() {
    QJsonObject json = loadJsonFromFile("../../settings.json");

    this->warning = new QLabel(this);
    this->warning->setStyleSheet("color: #fff; font-weight: 500; margin-top: 15px; font-size: 11px;");

    this->warning->setText(json.value("warning").toString());
}

void ActivateWindow::initMainLayout() {
    this->mainLayout = new QVBoxLayout(this);
    this->mainLayout->addWidget(this->enterKey);
    this->mainLayout->addWidget(this->inputKey);
    this->mainLayout->addWidget(this->active);
    this->mainLayout->addWidget(this->activeKey);
    this->mainLayout->addWidget(this->buy);
    this->mainLayout->addWidget(this->warning);
    this->mainLayout->setAlignment(this->enterKey, Qt::AlignTop);
    this->mainLayout->setSpacing(0);
    this->mainLayout->addStretch(0);
    this->mainLayout->setContentsMargins(10,50,0,0);
}

QJsonObject ActivateWindow::loadJsonFromFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(nullptr, "Error", "Cannot open the file for reading.");
        return QJsonObject();  // Возвращаем пустой объект в случае ошибки
    }

    QByteArray jsonData = file.readAll();  // Чтение всех данных из файла
    QJsonDocument document = QJsonDocument::fromJson(jsonData);  // Преобразуем данные в документ JSON

    if (document.isObject()) {
        return document.object();  // Возвращаем объект JSON, если он есть
    }

    QMessageBox::critical(nullptr, "Error", "Invalid JSON format.");
    return QJsonObject();  // Возвращаем пустой объект в случае ошибки
}

ActivateWindow::ActivateWindow(QWidget* parent) : QDialog(parent)
{
    this->setWindowTitle("Active");

    this->initInputKeyContainer();
    this->initBuyKeyContainer();
    this->initWarningText();
    this->initMainLayout();

    this->setLayout(this->mainLayout);
    this->setFixedSize(700, 350);
}
