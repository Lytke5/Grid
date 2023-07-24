#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "canvas.h"

Canvas::Canvas(QWidget *parent)
	: QFrame(parent)
{
	setFrameStyle(QFrame::Box);
	setMouseTracking(true);

    color = RED;
	cell_size_x = cell_size_y = 0;
    //clickedRow = clickedCol = clickedPos = - 1;
}

Canvas::~Canvas()
{
}

QSize Canvas::minimumSizeHint() const
{
	return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
	return QSize(640, 480);
}

void Canvas::genPoints(int num)
{
    //clickedRow = clickedCol = clickedPos = -1;

    /*
     * TASK 1: calculate cell_size_x and cell_size_y according
     *         to canvas size and remove points, where required
     *
     * START
     */


    cell_size_x = sizeHint().width() / GRID_COLS;
    cell_size_y = sizeHint().height() / GRID_ROWS;

    for(int i = 0; i < GRID_ROWS; i++)
    {
        for(int j = 0; j < GRID_COLS; j++)
        {
            for(Circle *c : grid[i][j])
            {
                delete c;
            }
            grid[i][j].clear();
        }
    }

    /*
     * END of Task 1
     */

    /*
     * TASK 2: fill grid with num random points on canvas
     *
     * START
     */
    for(int i = 0; i < num; i++)
    {
        int x = rand() % sizeHint().width();
        int y = rand() % sizeHint().height();

        Circle *newCircle = new Circle(QPoint(x,y));

        int col = x / cell_size_x;
        int row = y / cell_size_y;

        grid[row][col].push_back(newCircle);
    }   
    /*
     * END of Task 2
     */
}

void Canvas::setColor(int col)
{
	color = (Canvas::ActiveColor)col;
}

void Canvas::paintEvent(QPaintEvent *event)
{
	QFrame::paintEvent(event);

	QPainter painter(this);

    // white background
	painter.fillRect(QRect(1, 1, width() - 2, height() - 2), Qt::white);
	painter.setPen(Qt::gray);

    if (cell_size_x <= 0 || cell_size_y <= 0) {
        return;
    }

    // little color look-up-table (LUT)
	QColor cols[] = {
		Qt::black, Qt::red, Qt::green, Qt::blue,
        Qt::cyan, Qt::magenta, Qt::yellow
	};

    /*
     * TASK 3: draw grid lines along with all generated points,
     *         where color of clicked point should be cols[color]
     *
     * START
     */
    painter.setBrush(Qt::black);
    for(int i = 0; i < GRID_ROWS; i++)
    {
        painter.drawLine(QPoint(0,i*cell_size_y), QPoint(sizeHint().width(),i*cell_size_y));
    }

    for(int i = 0; i < GRID_COLS; i++)
    {
        painter.drawLine(QPoint(i*cell_size_x,0), QPoint(i*cell_size_x,sizeHint().height()));
    }

    for(int i = 0; i < GRID_ROWS; i++)
    {
        for(int j = 0; j < GRID_COLS; j++)
        {
            for(Circle *c : grid[i][j])
            {
                c->paint(&painter, cols[color]);
            }
        }
    }

    /*
     * END of Task 3
     */
}

void Canvas::resizeEvent(QResizeEvent *event) 
{
	QFrame::resizeEvent(event);
    // TODO; invalidate grid and rearrange points (no official task)
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		QPoint currPos = event->pos();

        // inside test with points for selection and new color
        //if (cell_size_x > 0 && cell_size_y > 0) {
            //clickedPos = -1;

            /*
             * TASK 4: calculate clicked grid indices, i.e. column / row,
             *         (attention, take care for valid indices, since
             *         invalid array position could happen on resize)
             *
             * START
             */

            int col = currPos.x() / cell_size_x;
            int row = currPos.y() / cell_size_y;

            /*
             * END of Task 4
             */


            /*
             * TASK 5: traverse array at clicked grid cell and test, which
             *         point (treated as mini circle with r = RADIUS) is
             *         nearest to click position (assign index to clickedPos)
             *
             *         TODO for enthusiasts: check neighbour cells if "circle"
             *         overlaps several grid cells (no official task)
             *
             * START
             */

            for(int i = 0; i < grid[row][col].size(); i++)
            {
                if(grid[row][col].at(i)->isInside(currPos))
                {
                    grid[row][col].at(i)->setClicked(true);
                    break;
                }
            }
            /*
             * END of Task 5
             */
		update();
	}
}
