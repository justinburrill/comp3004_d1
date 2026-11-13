#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enter_button_clicked();
    void on_exit_button_clicked();

private:
    Ui::MainWindow *ui;
    User* current_user = nullptr;
    void switch_to_dashboard(UserType type);
    void reset();
};
#endif // MAINWINDOW_H
