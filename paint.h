#ifndef PAINT_H
#define PAINT_H
#include <QWidget>

class QPushButton;
class QComboBox;
class QLabel;
class QLineEdit;
class Canvas;

class Paint : public QWidget
{
	Q_OBJECT

public:
	Paint(QWidget *parent = 0);
	~Paint();

private slots:
    void genBtnPressed();
    void colModeChanged(int);

private:
	Canvas *viewport;

    QPushButton *btnGenPoints;
    QLineEdit *leNumPoints;
    QComboBox *cobColModes;
    QLabel *lblColModes;
};

#endif // PAINT_H
