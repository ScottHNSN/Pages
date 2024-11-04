#ifndef PROCWINDOW_H
#define PROCWINDOW_H

#include <QMainWindow>

class procwindow : public QMainWindow
{
    Q_OBJECT

public:
    procwindow(QWidget *parent = nullptr);
    ~procwindow();
};
#endif // PROCWINDOW_H
