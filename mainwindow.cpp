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
    this->setWindowTitle("New Programmerz Association Notes");
    notes.push_back({"Array", "An array is a collection of items stored at contiguous memory locations."});
    notes.push_back({"Linked List", "A linked list is a linear data structure where each element is a separate object."});
    notes.push_back({"Stack", "A stack is a linear data structure which follows a particular order in which the operations are performed."});
    notes.push_back({"Queue", "A queue is a linear data structure which follows a particular order in which the operations are performed."});
    notes.push_back({"Binary Tree", "A binary tree is a tree data structure in which each node has at most two children."});
    notes.push_back({"Graph", "A graph is a data structure that consists of a finite set of nodes (or vertices) and a set of edges connecting them."});
    notes.push_back({"Sorting Algorithms", "Sorting algorithms are used to rearrange a given array or list elements according to a comparison operator on the elements."});
    notes.push_back({"Searching Algorithms", "Searching algorithms are designed to check for an element or retrieve an element from any data structure where it is stored."});

    for (const auto &note : notes) {
        addListItem(note.title);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    Note newNote = {"New Note", ""};
    notes.push_back(newNote);
    addListItem(newNote.title);
}

void MainWindow::addListItem(const QString &text)
{
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    QWidget *widget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout();

    QLabel *label = new QLabel(text);
    QPushButton *openButton = new QPushButton("Open");
    QPushButton *deleteButton = new QPushButton("Delete");
    widget->setStyleSheet({"border-bottom: 1px solid #824d17; margin-bottom: 5px; margin-top: 5px;"});
    openButton->setStyleSheet({"QPushButton {"
                               "background-color: #824d17;"
                               "border-radius: 8px; "
                               "border: 1px solid black; "
                               "color: white;}"
                                "QPushButton:hover {"
                                "background-color: rgba(255, 255, 255, 0.5);"
                                "color: black;}"
                                "QPushButton:pressed {"
                                "background-color: black;"
                                "color: white;"});
    deleteButton->setStyleSheet({"QPushButton {"
                               "background-color: #8B0000;"
                               "border-radius: 8px; "
                               "border: 1px solid black; "
                               "color: white;}"
                               "QPushButton:hover {"
                               "background-color: rgba(255, 255, 255, 0.5);"
                               "color: black;}"
                               "QPushButton:pressed {"
                               "background-color: black;"
                               "color: white;"});

    layout->addWidget(label);
    layout->addWidget(openButton);
    layout->addWidget(deleteButton);
    layout->setContentsMargins(0, 0, 0, 0);
    widget->setLayout(layout);

    item->setSizeHint(widget->sizeHint());
    ui->listWidget->setItemWidget(item, widget);

    connect(openButton, &QPushButton::clicked, this, [this, item, label]() {
        int index = ui->listWidget->row(item);
        NoteDialog dialog(this);
        dialog.setNoteTitle(notes[index].title);
        dialog.setNoteText(notes[index].body);
        if (dialog.exec() == QDialog::Accepted) {
            notes[index].title = dialog.getNoteTitle();
            notes[index].body = dialog.getNoteText();
            label->setText(notes[index].title);
        }
    });

    connect(deleteButton, &QPushButton::clicked, this, [this, item]() {
        int index = ui->listWidget->row(item);
        notes.erase(notes.begin() + index);
        delete item;
    });
}
