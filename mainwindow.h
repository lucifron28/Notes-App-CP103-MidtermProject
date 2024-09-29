#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Note {
    QString title;
    QString body;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();


private:
    Ui::MainWindow *ui;
    std::vector<Note> notes;
    void addListItem(const QString &text);
};

#endif // MAINWINDOW_H
