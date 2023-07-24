#ifndef CANVAS_H
#define CANVAS_H
#include <QFrame>
#include <QVector>
#include <vector>
#include "circle.h"

#define GRID_ROWS  6
#define GRID_COLS  8

//typedef QVector<QPoint> Grid[GRID_ROWS][GRID_COLS];
typedef QVector<Circle*> Grid[GRID_ROWS][GRID_COLS];


class Canvas : public QFrame
{
	Q_OBJECT

public:
	enum ActiveColor {
		BLACK = 0, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW
	};

	Canvas(QWidget *parent = 0);
	~Canvas();

	QSize minimumSizeHint() const;
	QSize sizeHint() const;

	void genPoints(int num);
	void setColor(int col);

protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	int cell_size_x, cell_size_y;
	Grid grid;
	ActiveColor color;
    // Helper attribs for clicked row, column and current index:
    //int clickedRow, clickedCol, clickedPos;
};

#endif // CANVAS_H
