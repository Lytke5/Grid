#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include "paint.h"
#include "canvas.h"


/** c'tor */
Paint::Paint(QWidget *parent)
	: QWidget(parent)
{
	// instantiate Canvas and button
	viewport = new Canvas();

    btnGenPoints = new QPushButton("&Generate Points");
    leNumPoints = new QLineEdit("100");

    cobColModes = new QComboBox();
    cobColModes->addItem(tr("Black"),   Canvas::BLACK);
    cobColModes->addItem(tr("Red"),     Canvas::RED);
    cobColModes->addItem(tr("Green"),   Canvas::GREEN);
    cobColModes->addItem(tr("Blue"),    Canvas::BLUE);
    cobColModes->addItem(tr("Cyan"),    Canvas::CYAN);
    cobColModes->addItem(tr("Magenta"), Canvas::MAGENTA);
    cobColModes->addItem(tr("Yellow"),  Canvas::YELLOW);
    cobColModes->setCurrentIndex(1);

    lblColModes = new QLabel("Choose selection color:");
    lblColModes->setBuddy(cobColModes);

	// create layout and add gui elements to it
	QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(viewport,     0, 0, 1, 3);
    mainLayout->addWidget(lblColModes,  1, 1, Qt::AlignRight);
    mainLayout->addWidget(cobColModes,  1, 2);
    mainLayout->addWidget(leNumPoints,  2, 1, Qt::AlignRight);
    mainLayout->addWidget(btnGenPoints, 2, 2);

	// add layout to this widget instance
	setLayout(mainLayout);
	
	// connect button click event to draw handler
    connect(btnGenPoints, SIGNAL(clicked()), this, SLOT(genBtnPressed()));
	// connect list view to event handler
    connect(cobColModes, SIGNAL(activated(int)), this, SLOT(colModeChanged(int)));
}

/** d'tor */
Paint::~Paint()
{
}

/** method for handling button clicked event */
void Paint::genBtnPressed()
{
    int num = leNumPoints->text().toInt();
    viewport->genPoints(num > 0 ? num : 1);
    update();   // force redraw
}

void Paint::colModeChanged(int val)
{
    viewport->setColor(val >= 0 ? val : 0);
    update();   // force redraw
}
