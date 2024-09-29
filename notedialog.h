#ifndef NOTEDIALOG_H
#define NOTEDIALOG_H

#include <QDialog>

namespace Ui {
class NoteDialog;
}

class NoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoteDialog(QWidget *parent = nullptr);
    ~NoteDialog();

    QString getNoteText() const;
    void setNoteText(const QString &text);

    QString getNoteTitle() const;
    void setNoteTitle(const QString &title);

private:
    Ui::NoteDialog *ui;
};

#endif // NOTEDIALOG_H
