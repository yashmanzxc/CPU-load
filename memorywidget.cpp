#include "memorywidget.h"
#include "sysinfo.h"
#include <QtCharts/QAreaSeries>
#include <QLinearGradient>
#include <QPen>
using namespace QtCharts;

const	int	CHART_X_RANGE_COUNT	=	50;
const	int	CHART_X_RANGE_MAX	=	CHART_X_RANGE_COUNT	-	1;

const	int	COLOR_DARK_GREEN	=	0x006400;
const	int	COLOR_LIGHT_GREEN	=	0x90EE90;
const	int	PEN_WIDTH	=	3;

MemoryWidget::MemoryWidget(QWidget *parent):SysInfoWidget(parent),mSeries(new QLineSeries(this)),mPointPoisitionX(0)
{
    QPen	pen(COLOR_DARK_GREEN);
                    pen.setWidth(PEN_WIDTH);

                    QLinearGradient	gradient(QPointF(0,	0),	QPointF(0,	1));
                    gradient.setColorAt(1.0,	COLOR_DARK_GREEN);
                    gradient.setColorAt(0.0,	COLOR_LIGHT_GREEN);
                    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);

    QAreaSeries *areaSeries = new QAreaSeries(mSeries);
    areaSeries->setPen(pen);
    areaSeries->setBrush(gradient);

    QChart*	chart = chartView().chart();
                chart->addSeries(areaSeries);
                chart->setTitle("Memory	used");
                chart->createDefaultAxes();
                chart->axisX()->setVisible(false);
                chart->axisX()->setRange(0,	CHART_X_RANGE_MAX);
                chart->axisY()->setRange(0,	100);

}

void MemoryWidget::updateSeries()
{
    double	memoryUsed	=	SysInfo::instans().memoryUser();
                    mSeries->append(mPointPoisitionX++,	memoryUsed);
                    if	(mSeries->count()>CHART_X_RANGE_COUNT){
                        QChart*	chart	=	chartView().chart();
                        chart->scroll(chart->plotArea().width()/CHART_X_RANGE_MAX,	0);

                         mSeries->remove(0);
                    }
}
