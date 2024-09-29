#include "notedialog.h"
#include "ui_notedialog.h"

NoteDialog::NoteDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NoteDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Notes");
    connect(ui->saveButton, &QPushButton::clicked, this, &NoteDialog::accept);
    connect(ui->cancelButton, &QPushButton::clicked, this, &NoteDialog::reject);
}

NoteDialog::~NoteDialog()
{
    delete ui;
}

QString NoteDialog::getNoteText() const
{
    return ui->textEdit->toPlainText();
}

void NoteDialog::setNoteText(const QString &text)
{
    ui->textEdit->setPlainText(text);
}

QString NoteDialog::getNoteTitle() const
{
    return ui->lineEdit->text();
}

void NoteDialog::setNoteTitle(const QString &title)
{
    ui->lineEdit->setText(title);
}
