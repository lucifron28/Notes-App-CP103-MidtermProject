#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "notedialog.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    addListItem("New Note");
}

void MainWindow::addListItem(const QString &text)
{
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    QWidget *widget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout();

    QLabel *label = new QLabel(text);
    QPushButton *openButton = new QPushButton("Open");
    QPushButton *deleteButton = new QPushButton("Delete");

    layout->addWidget(label);
    layout->addWidget(openButton);
    layout->addWidget(deleteButton);
    layout->setContentsMargins(0, 0, 0, 0);
    widget->setLayout(layout);

    item->setSizeHint(widget->sizeHint());
    ui->listWidget->setItemWidget(item, widget);

    connect(openButton, &QPushButton::clicked, this, &MainWindow::on_openButton_clicked);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
}

void MainWindow::on_openButton_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QWidget *widget = button->parentWidget();
        QLabel *label = widget->findChild<QLabel*>();
        if (label) {
            NoteDialog dialog(this);
            dialog.setNoteTitle(label->text());
            dialog.setNoteText(""); // Optionally set the note text if needed
            if (dialog.exec() == QDialog::Accepted) {
                label->setText(dialog.getNoteTitle());
            }
        }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QWidget *widget = button->parentWidget();
        QListWidgetItem *item = ui->listWidget->itemAt(widget->pos());
        delete item;
    }
}
