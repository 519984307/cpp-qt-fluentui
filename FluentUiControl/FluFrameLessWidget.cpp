#include "FluDef.h"
#include "FluFrameLessWidget.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include <QMouseEvent>

FluFrameLessWidget::FluFrameLessWidget(QWidget *parent, QWidget* centerWidget)
	: FluWidget(parent)
{
	m_borderArea = BorderArea::BorderAreaNone;
	if (centerWidget == nullptr)
	{
		m_centerWidget = new QWidget(this);
	}

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
	m_bMouseLeftBtnPress = false;
	m_mouseLeftBtnPressPoint = QPoint(0, 0);

	m_vLayout = new QVBoxLayout(this);
	m_vLayout->setContentsMargins(0, 0, 0, 0);
	setLayout(m_vLayout);

	m_hLayout = new QHBoxLayout(this);
	m_hLayout->setContentsMargins(0, 0, 0, 0);
	m_hLayout->setSpacing(0);
	
	m_hLayout->addStretch(1);
	m_minBtn = new QPushButton(this);
	m_minBtn->setFixedSize(30, 30);
	//m_minBtn->setIconSize(QSize(30, 30));
	m_minBtn->setIcon(QIcon(FluentUiIconUtils::GetFluentIcon(FluAwesomeType::ChromeMinimize)));
	m_hLayout->addWidget(m_minBtn);

	m_maxNorBtn = new QPushButton(this);
	m_maxNorBtn->setFixedSize(30, 30);
	m_maxNorBtn->setIcon(QIcon(FluentUiIconUtils::GetFluentIcon(FluAwesomeType::ChromeMaximize)));
	m_hLayout->addWidget(m_maxNorBtn);

	m_closeBtn = new QPushButton(this);
	m_closeBtn->setFixedSize(30, 30);
	m_closeBtn->setIcon(QIcon(FluentUiIconUtils::GetFluentIcon(FluAwesomeType::ChromeClose)));
	m_hLayout->addWidget(m_closeBtn);

	m_vLayout->addLayout(m_hLayout, 0);

	m_centerWidget->setParent(this);
	m_vLayout->addWidget(m_centerWidget, 1);
	
	//m_vLayout->addStretch(1);

	setMinimumSize(800, 600);

	connect(m_minBtn, SIGNAL(clicked()), this, SLOT(slotClickMinBtn()));
	connect(m_maxNorBtn, SIGNAL(clicked()), this, SLOT(slotClickMaxNorBtn()));
	connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(slotClickCloseBtn()));

	m_minBtn->setObjectName("FluMinBtn");
	m_maxNorBtn->setObjectName("FluMaxNorBtn");
	m_closeBtn->setObjectName("FluCloseBtn");
	static QString styleSheet = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluFrameLessWidget.qss");
	setStyleSheet(styleSheet);
	setMouseTracking(true);
	m_closeBtn->setMouseTracking(true);
	m_centerWidget->setMouseTracking(true);
}

FluFrameLessWidget::~FluFrameLessWidget()
{

}

void FluFrameLessWidget::UpdateBorderArea(QPoint pos)
{
	m_borderArea = BorderArea::BorderAreaNone;
	int offset = 5;

	int x = pos.x();
	int y = pos.y();
	int w = this->width();
	int h = this->height();

	if (x >= -offset && x < offset && y >= -offset && y < offset)
	{
		m_borderArea = BorderArea::BorderAreaTopLeft;
		return;
	}

	if (x > w - offset && x <= w + offset && y >= -offset && y < offset)
	{
		m_borderArea = BorderArea::BorderAreaTopRight;
		return;
	}

	if (x >= -offset && x < offset && y > h - offset && y <= h + offset)
	{
		m_borderArea = BorderArea::BorderAreaBottomLeft;
		return;
	}

	if (x > w - offset && x <= w + offset && y > h - offset && y <= h + offset)
	{
		m_borderArea = BorderArea::BorderAreaBottomRight;
		return;
	}

	if (y <= offset && x > offset && x < w - offset)
	{
		m_borderArea = BorderArea::BorderAreaTop;
		return;
	}

	if (x <= offset && y > offset && y < h - offset)
	{
		m_borderArea = BorderArea::BorderAreaLeft;
		return;
	}

	if (x >= w - offset && y > offset && y < h - offset)
	{
		m_borderArea = BorderArea::BorderAreaRight;
		return;
	}

	if (y >= h - offset && x > offset && x < w - offset)
	{
		m_borderArea = BorderArea::BorderAreaBottom;
		return;
	}
}

void FluFrameLessWidget::UpdateCursor()
{
	switch (m_borderArea)
	{
	case BorderArea::BorderAreaNone:
		setCursor(Qt::ArrowCursor);
		break;
	case BorderArea::BorderAreaTop:
	case BorderArea::BorderAreaBottom:
		setCursor(Qt::SizeVerCursor);
		break;

	case BorderArea::BorderAreaLeft:
	case BorderArea::BorderAreaRight:
		setCursor(Qt::SizeHorCursor);
		break;

	case BorderArea::BorderAreaTopLeft:
	case BorderArea::BorderAreaBottomRight:
		setCursor(Qt::SizeFDiagCursor);
		break;

	case BorderArea::BorderAreaTopRight:
	case BorderArea::BorderAreaBottomLeft:
		setCursor(Qt::SizeBDiagCursor);
		break;
	default:
		break;
	}
}

void FluFrameLessWidget::UpdateWindowByBorderArea()
{
	switch (m_borderArea)
	{
	case BorderArea::BorderAreaNone:
		break;
	case BorderArea::BorderAreaTop:

		break;
	case BorderArea::BorderAreaBottom:
		break;
	case BorderArea::BorderAreaLeft:
		break;
	case BorderArea::BorderAreaRight:
		break;
	case BorderArea::BorderAreaTopLeft:
		break;
	case BorderArea::BorderAreaTopRight:
		break;
	case BorderArea::BorderAreaBottomLeft:
		break;
	case BorderArea::BorderAreaBottomRight:
		break;
	default:
		break;
	}
}

void FluFrameLessWidget::adjustWndSizeByMouseMove(QMouseEvent* event)
{
	if (m_borderArea == BorderArea::BorderAreaRight)
	{
		QPoint distancePoint = event->pos() - m_mouseLeftBtnPressPoint;
		int wndW = width() + distancePoint.x();
		setFixedWidth(wndW);
		m_mouseLeftBtnPressPoint = event->pos();
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaLeft)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->pos() - m_mouseLeftBtnPressPoint;

		int gWndX = pos().x() + wndRect.x() + distancePoint.x();
		int gWndY = pos().y();
		int wndW = width() - distancePoint.x();
		int wndH = height();
		setGeometry(gWndX, gWndY, wndW, wndH);
		setFixedWidth(wndW);
		m_mouseLeftBtnPressPoint = event->pos();
		m_mouseLeftBtnPressPoint.setX(m_mouseLeftBtnPressPoint.x() - distancePoint.x());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaTop)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->pos() - m_mouseLeftBtnPressPoint;

		int gWndX = pos().x();
		int gWndY = pos().y() + wndRect.y() + distancePoint.y();
		int wndW = width();
		int wndH = height() - distancePoint.y();

		setGeometry(gWndX, gWndY, wndW, wndH);
		setFixedHeight(wndH);
		m_mouseLeftBtnPressPoint = event->pos();
		m_mouseLeftBtnPressPoint.setY(m_mouseLeftBtnPressPoint.y() - distancePoint.y());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaBottom)
	{
		QPoint distancePoint = event->pos() - m_mouseLeftBtnPressPoint;
		int wndH = height() + distancePoint.y();
		setFixedHeight(wndH);
		m_mouseLeftBtnPressPoint = event->pos();
		return;
	}
	
	if(m_borderArea == BorderArea::BorderAreaTopLeft)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->pos() - m_mouseLeftBtnPressPoint;

		int gWndX = pos().x() + wndRect.x() + distancePoint.x();
		int gWndY = pos().y() + wndRect.y() + distancePoint.y();
		int wndW = width() - distancePoint.x();
		int wndH = height() - distancePoint.y();

		setGeometry(gWndX, gWndY, wndW, wndH);
		setFixedSize(wndW, wndH);
		m_mouseLeftBtnPressPoint = event->pos();
		m_mouseLeftBtnPressPoint.setX(m_mouseLeftBtnPressPoint.x() - distancePoint.x());
		m_mouseLeftBtnPressPoint.setY(m_mouseLeftBtnPressPoint.y() - distancePoint.y());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaTopRight)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->pos() - m_mouseLeftBtnPressPoint;

		int gWndX = pos().x();
		int gWndY = pos().y() + wndRect.y() + distancePoint.y();
		int wndW = width() + distancePoint.x();
		int wndH = height() - distancePoint.y();

		setGeometry(gWndX, gWndY, wndW, wndH);
		setFixedSize(wndW, wndH);
		m_mouseLeftBtnPressPoint = event->pos();
		m_mouseLeftBtnPressPoint.setY(m_mouseLeftBtnPressPoint.y() - distancePoint.y());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaBottomLeft)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->pos() - m_mouseLeftBtnPressPoint;

		int gWndX = pos().x() + wndRect.x() + distancePoint.x();
		int gWndY = pos().y();
		int wndW = width() - distancePoint.x();
		int wndH = height() +distancePoint.y();
		setGeometry(gWndX, gWndY, wndW, wndH);
		setFixedSize(wndW, wndH);
		m_mouseLeftBtnPressPoint = event->pos();
		m_mouseLeftBtnPressPoint.setX(m_mouseLeftBtnPressPoint.x() - distancePoint.x());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaBottomRight)
	{
		QPoint distancePoint = event->pos() - m_mouseLeftBtnPressPoint;
		int wndW = width() + distancePoint.x();
		int wndH = height() + distancePoint.y();
		setFixedSize(wndW, wndH);
		m_mouseLeftBtnPressPoint = event->pos();
		return;
	}
}

void FluFrameLessWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (!m_bMouseLeftBtnPress)
	{
		UpdateBorderArea(event->pos());
		UpdateCursor();
		return;
	}

	if (m_borderArea == BorderArea::BorderAreaNone)
	{
		move(event->pos() - m_mouseLeftBtnPressPoint + pos());
	}
	else
	{
		adjustWndSizeByMouseMove(event);
	}
}

void FluFrameLessWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		return;
	}

	m_bMouseLeftBtnPress = true;
	m_mouseLeftBtnPressPoint = event->pos();
	UpdateBorderArea(event->pos());
	UpdateCursor();
}

void FluFrameLessWidget::mouseReleaseEvent(QMouseEvent* event)
{
	m_bMouseLeftBtnPress = false;
}

void FluFrameLessWidget::resizeEvent(QResizeEvent* event)
{

}

void FluFrameLessWidget::slotClickMinBtn()
{
	showMinimized();
	//m_borderArea = BorderArea::BorderAreaNone;
	//m_mouseLeftBtnPressPoint = QPoint(0, 0);
}

void FluFrameLessWidget::slotClickCloseBtn()
{
	close();
	//m_borderArea = BorderArea::BorderAreaNone;
	//m_mouseLeftBtnPressPoint = QPoint(0, 0);
}

void FluFrameLessWidget::slotClickMaxNorBtn()
{
	if (isMaximized())
	{
		m_maxNorBtn->setIcon(QIcon(FluentUiIconUtils::GetFluentIcon(FluAwesomeType::ChromeMaximize)));
		showNormal();
	}
	else if(isMinimized())
	{
		// todo
	}
	else
	{
		m_maxNorBtn->setIcon(QIcon(FluentUiIconUtils::GetFluentIcon(FluAwesomeType::ChromeRestore)));
		showMaximized();
	}
	//m_borderArea = BorderArea::BorderAreaNone;
	//m_mouseLeftBtnPressPoint = QPoint(0, 0);
}
