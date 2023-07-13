#include "FluDef.h"
#include "FluFrameLessWidgetV1.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"
#include <QThread>
#include <QMouseEvent>

FluFrameLessWidgetV1::FluFrameLessWidgetV1(QWidget *parent, QWidget* centerWidget)
	: QWidget(parent)
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

	setMinimumSize(1000, 640);

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
//	setAttribute(Qt::WA_Hover);
}

FluFrameLessWidgetV1::~FluFrameLessWidgetV1()
{

}

void FluFrameLessWidgetV1::UpdateBorderArea(QPoint pos)
{
	m_borderArea = BorderArea::BorderAreaNone;
	if (isMaximized())
		return;

	int offset =  5;

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

void FluFrameLessWidgetV1::UpdateCursor()
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

void FluFrameLessWidgetV1::UpdateWindowByBorderArea()
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

void FluFrameLessWidgetV1::adjustWndSizeByMouseMove(QMouseEvent* event)
{
	LogDebug << "BorderArea:" << (int)m_borderArea;
	if (m_borderArea == BorderArea::BorderAreaRight)
	{
		QPoint distancePoint = event->globalPos() - m_mouseLeftBtnPressPoint;
		int wndW = width() + distancePoint.x();
		int wndH = height();
		//setFixedWidth(wndW);
		resize(wndW, wndH);
		LogDebug  << "setFixedWidth:" << wndW;
		setMouseLeftBtnPressPoint(event->globalPos());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaLeft)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->globalPos() - m_mouseLeftBtnPressPoint;

		int gWndX = pos().x() + wndRect.x() + distancePoint.x();
		int gWndY = pos().y();
		int wndW = width() - distancePoint.x();
		int wndH = height();
		//setGeometry(gWndX, gWndY, wndW, wndH);
		move(gWndX, gWndY);
		//setFixedWidth(wndW);
		resize(wndW, wndH);
		LogDebug << geometry();
		setMouseLeftBtnPressPoint(event->globalPos());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaTop)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->globalPos() - m_mouseLeftBtnPressPoint;

		LogDebug << "distancePoint:" << distancePoint;

		int gWndX = pos().x();
		int gWndY = pos().y() + wndRect.y() + distancePoint.y();
		int wndW = width();
		int wndH = height() - distancePoint.y();

		LogDebug << "wndW:" << wndW << ",wndH:" << wndH;
		//setGeometry(gWndX, gWndY, wndW, wndH);
		//setFixedSize(wndW, wndH);
		//setFixedHeight(wndH);
		move(gWndX, gWndY);
		//setFixedHeight(wndH);
		resize(wndW, wndH);
		LogDebug << "BorderArea::BorderAreaTop After Set Geometry:" << geometry();
		setMouseLeftBtnPressPoint(event->globalPos());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaBottom)
	{
		QPoint distancePoint = event->globalPos() - m_mouseLeftBtnPressPoint;
		int wndW = width();
		int wndH = height() + distancePoint.y();
	//	setFixedHeight(wndH);
		resize(wndW, wndH);
		LogDebug << geometry();
		setMouseLeftBtnPressPoint(event->globalPos());
		return;
	}
	
	if(m_borderArea == BorderArea::BorderAreaTopLeft)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->globalPos() - m_mouseLeftBtnPressPoint;

		int gWndX = pos().x() + wndRect.x() + distancePoint.x();
		int gWndY = pos().y() + wndRect.y() + distancePoint.y();
		int wndW = width() - distancePoint.x();
		int wndH = height() - distancePoint.y();

		//setGeometry(gWndX, gWndY, wndW, wndH);
		move(gWndX, gWndY);
	//	setFixedSize(wndW, wndH);
		resize(wndW, wndH);
		LogDebug << geometry();
		setMouseLeftBtnPressPoint(event->globalPos());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaTopRight)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->globalPos() - m_mouseLeftBtnPressPoint;

		int gWndX = pos().x();
		int gWndY = pos().y() + wndRect.y() + distancePoint.y();
		int wndW = width() + distancePoint.x();
		int wndH = height() - distancePoint.y();

		//setGeometry(gWndX, gWndY, wndW, wndH);
		move(gWndX, gWndY);
		//setFixedSize(wndW, wndH);
		resize(wndW, wndH);
		LogDebug << geometry();
		setMouseLeftBtnPressPoint(event->globalPos());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaBottomLeft)
	{
		QRect wndRect = rect();
		QPoint distancePoint = event->globalPos() - m_mouseLeftBtnPressPoint;

		int gWndX = pos().x() + wndRect.x() + distancePoint.x();
		int gWndY = pos().y();
		int wndW = width() - distancePoint.x();
		int wndH = height() +distancePoint.y();
		//setGeometry(gWndX, gWndY, wndW, wndH);
		move(gWndX, gWndY);
		//setFixedSize(wndW, wndH);
		resize(wndW, wndH);
		LogDebug << "(" << wndW << ", " << wndH << ")" << "geometry:" << geometry();
		setMouseLeftBtnPressPoint(event->globalPos());
		return;
	}
	
	if (m_borderArea == BorderArea::BorderAreaBottomRight)
	{
		QPoint distancePoint = event->globalPos() - m_mouseLeftBtnPressPoint;
		int wndW = width() + distancePoint.x();
		int wndH = height() + distancePoint.y();
		//setFixedSize(wndW, wndH);
		resize(wndW, wndH);
		LogDebug << geometry();
		setMouseLeftBtnPressPoint(event->globalPos());
		return;
	}
}

void FluFrameLessWidgetV1::mouseMoveEvent(QMouseEvent* event)
{
	if (!m_bMouseLeftBtnPress)
	{
		UpdateBorderArea(event->pos());
		UpdateCursor();
		return;
	}

	static bool bTemp = true;
	//qDebug() << __FUNCTION__ << "border area  = " << (int)m_borderArea;
	if (m_borderArea == BorderArea::BorderAreaNone)
	{
		if (isMaximized())
		{
			// 当前窗口是最大化的话，拖动鼠标确定鼠标位置
			QSize tmpMaxSize = geometry().size();
		//	move(geometry().x()+1,geometry().y()+1);

			// 确定geometry().x()所在第几个屏幕
			int nScreenIndex = geometry().x() / tmpMaxSize.width();
			
			int nScreenGlobalX = event->globalPos().x() % tmpMaxSize.width();
			int nScreenGeometryX = geometry().x() % tmpMaxSize.width();

			float tmpX = (nScreenGlobalX - nScreenGeometryX) * 1.0 / tmpMaxSize.width();
			float tmpY = (event->globalPos().y() - geometry().y()) * 1.0 / geometry().height();

			int realX = event->globalPos().x() - normalGeometry().width() * tmpX;
			int realY = event->globalPos().y() + normalGeometry().height() * tmpY;

			LogDebug << "realX:" << realX << "," << "realY:" << realY;
			setUpdatesEnabled(false);
			setWindowState(Qt::WindowState::WindowNoState);
			setGeometry(realX, realY, normalGeometry().size().width(), normalGeometry().height());
			setMouseLeftBtnPressPoint(event->globalPos());

			//repaint();
			setUpdatesEnabled(true);

			return;
		}

		LogDebug << "move to:" << event->globalPos() - m_mouseLeftBtnPressPoint + pos();
		move(event->globalPos() - m_mouseLeftBtnPressPoint + pos());
		setMouseLeftBtnPressPoint(event->globalPos());
	}
	else
	{
		adjustWndSizeByMouseMove(event);
	}
}

void FluFrameLessWidgetV1::mousePressEvent(QMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		return;
	}

	m_bMouseLeftBtnPress = true;
	setMouseLeftBtnPressPoint(event->globalPos());
	UpdateBorderArea(event->pos());
	UpdateCursor();
}

void FluFrameLessWidgetV1::mouseReleaseEvent(QMouseEvent* event)
{
	m_bMouseLeftBtnPress = false;
}

void FluFrameLessWidgetV1::resizeEvent(QResizeEvent* event)
{
	LogDebug << "size:" << event->size();
}

void FluFrameLessWidgetV1::moveEvent(QMoveEvent* event)
{
	LogDebug << event->oldPos() << " => " << event->pos();
}

void FluFrameLessWidgetV1::slotClickMinBtn()
{
	showMinimized();
}

void FluFrameLessWidgetV1::slotClickCloseBtn()
{
	close();
}

void FluFrameLessWidgetV1::slotClickMaxNorBtn()
{
	if (isMaximized())
	{
		m_maxNorBtn->setIcon(QIcon(FluentUiIconUtils::GetFluentIcon(FluAwesomeType::ChromeMaximize)));
		showNormal();
	}
	else
	{
		m_maxNorBtn->setIcon(QIcon(FluentUiIconUtils::GetFluentIcon(FluAwesomeType::ChromeRestore)));
		m_borderArea = BorderArea::BorderAreaNone;
		showMaximized();
	}
}
