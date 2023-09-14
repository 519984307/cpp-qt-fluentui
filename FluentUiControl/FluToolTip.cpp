#include "FluToolTip.h"
#include <qmath.h>
#include "../FluentUiUtils/FluentUiLogUtils.h"

FluToolTip::FluToolTip(QWidget* parent /*= nullptr*/, QString text /*= ""*/) : QFrame(parent)
{
	m_text = text;
	m_duration = 1000;
	m_container = new QFrame(this);
	m_timer = new QTimer(this);

	m_hMainLayout = new QHBoxLayout();
	setLayout(m_hMainLayout);


	m_hContainerLayout = new QHBoxLayout(m_container);
	m_container->setLayout(m_hContainerLayout);

	m_label = new QLabel(text, this);
	//m_label->setWordWrap(true);

	m_hMainLayout->setContentsMargins(12, 8, 12, 12);
	m_hMainLayout->addWidget(m_container);

	m_hContainerLayout->addWidget(m_label);
	m_hContainerLayout->setContentsMargins(8, 6, 8, 6);

	// 透明度
	m_opcityAni = new QPropertyAnimation(this, "windowOpacity", this);
	m_opcityAni->setDuration(150);

	// 阴影效果
	m_shadowEffect = new QGraphicsDropShadowEffect(this);
	m_shadowEffect->setBlurRadius(25);
	m_shadowEffect->setColor(QColor(0, 0, 0, 60));
	m_shadowEffect->setOffset(0, 5);
	m_container->setGraphicsEffect(m_shadowEffect);

	m_timer->setSingleShot(true);// 单次定时器
	connect(m_timer, &QTimer::timeout, this, &FluToolTip::hide);

	setAttribute(Qt::WA_TransparentForMouseEvents, true);/*屏蔽该窗体的所有鼠标事件*/
	setAttribute(Qt::WA_TranslucentBackground);//背景透明
	//setAttribute(Qt::WA_StyledBackground);

	// Qt::Tool: 新窗口部件是一个工具(tool)窗口，它通常是一个用于显示工具按钮的小窗口。
	// 如果一个工具窗口有父窗口部件，则它将显示在父窗口的部件上面，
	// 否则相当于使用了Qt::WindowStaysOnTopHint提示。
	//ref:https://www.cnblogs.com/shuoguoleilei/p/12766432.html
	setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
	//setWindowFlags(Qt::ToolTip);

	__setQss();
}

void FluToolTip::__setQss()
{
	m_container->setObjectName("container");
	m_label->setObjectName("contentLabel");
	QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluToolTip.qss");
	setStyleSheet(qss);

	m_label->adjustSize();
	adjustSize();
}

QString FluToolTip::text()
{
	return m_text;
}

void FluToolTip::setText(const QString& text)
{
	m_text = text;
	m_label->setText(text);
	m_container->adjustSize();
	adjustSize();
}

int FluToolTip::duration()
{
	return m_duration;
}

void FluToolTip::setDuration(int duration)
{
	m_duration = duration;
}

void FluToolTip::showEvent(QShowEvent* event)
{
	//	m_opcityAni->setStartValue(0);
	//	m_opcityAni->setEndValue(1);
	//	m_opcityAni->start();

	m_timer->stop();
	if (m_duration > 0)
	{
		m_timer->start(m_duration + m_opcityAni->duration());
	}

	LogDebug << "pos:" << pos() << ", size:" << size() << ",label size:" << m_label->size();
	QFrame::showEvent(event);
}

void FluToolTip::hideEvent(QHideEvent* event)
{
	m_timer->stop();
	QFrame::hideEvent(event);
}

void FluToolTip::adjustPos(QWidget* widget, FluToolTipPositon position)
{
	FluToolTipPositionManager* manager = FluToolTipPositionManager::make(position);
	QPoint gPos = manager->position(this, widget);
	//gPos = mapToParent(gPos);
	move(gPos);
}

QMap<FluToolTipPositon, FluToolTipPositionManager*> FluToolTipPositionManager::m_manages;
QPoint FluToolTipPositionManager::position(FluToolTip* toolTip, QWidget* parent)
{
	QPoint pos = _pos(toolTip, parent);
	//parent->mapToGlobal(QPoint());

	int x = pos.x();
	int y = pos.y();

	QRect rect = QApplication::screenAt(QCursor::pos())->availableGeometry();
	if (QCursor::pos().x() >= 0)
		x = qMax(-2, x);
	x = qMin(rect.width() - toolTip->width() - 4, x);
	y = qMin(qMax(-2, y), rect.height() - toolTip->height() - 4);

	return QPoint(x, y);
}

QPoint FluToolTipPositionManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	return QPoint();
}

FluToolTipPositionManager* FluToolTipPositionManager::make(FluToolTipPositon position)
{
	if (m_manages.empty())
	{
		m_manages[FluToolTipPositon::TOP] = new FluTopToolTipManager;
		m_manages[FluToolTipPositon::BOTTOM] = new FluBottomToolTipManager;
		m_manages[FluToolTipPositon::LEFT] = new FluLeftToolTipManager;
		m_manages[FluToolTipPositon::RIGHT] = new FluRightToolTipManager;
		m_manages[FluToolTipPositon::TOP_LEFT] = new FluTopLeftToolTipManager;
		m_manages[FluToolTipPositon::BOTTOM_LEFT] = new FluBottomLeftToolTipManager;
		m_manages[FluToolTipPositon::TOP_RIGHT] = new FluTopRightToolTipManager;
		m_manages[FluToolTipPositon::BOTTOM_RIGHT] = new FluBottomRightToolTipManager;
	}
	return m_manages[position];
}

QPoint FluTopToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() + parent->width() / 2 - toolTip->width() / 2;
	int y = gPos.y() - toolTip->height();
	return QPoint(x, y);
}

QPoint FluBottomToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() + parent->width() / 2 - toolTip->width() / 2;
	int y = gPos.y() + parent->height();
	return QPoint(x, y);
}

QPoint FluLeftToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() - toolTip->width();
	int y = gPos.y() + (parent->height() - toolTip->height()) / 2;
	return QPoint(x, y);
}

QPoint FluRightToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() + parent->width();
	int y = gPos.y() + (parent->height() - toolTip->height()) / 2;
	return QPoint(x, y);
}

QPoint FluTopLeftToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() - toolTip->layout()->contentsMargins().left();
	int y = gPos.y() - toolTip->height();
	return QPoint(x, y);
}

QPoint FluTopRightToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() + parent->width() - toolTip->width() + toolTip->layout()->contentsMargins().right();
	int y = gPos.y() - toolTip->height();
	return QPoint(x, y);
}

QPoint FluBottomLeftToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapFromGlobal(QPoint());
	int x = gPos.x() - toolTip->layout()->contentsMargins().left();
	int y = gPos.y() + parent->height();
	return QPoint(x, y);
}

QPoint FluBottomRightToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapFromGlobal(QPoint());
	int x = gPos.x() + parent->width() - toolTip->width() + toolTip->layout()->contentsMargins().right();
	int y = gPos.y() + parent->height();
	return QPoint(x, y);
}

FluToolTipFilter::FluToolTipFilter(QWidget* parent /*= nullptr*/, int showDelay /*= 300*/, FluToolTipPositon position /*= FluToolTipPositon::TOP*/) : QObject(parent)
{
	m_isEnter = false;
	m_toolTip = nullptr;
	m_toolTipDelay = showDelay;
	m_position = position;
	m_timer = new QTimer(this);
	m_timer->setSingleShot(true);
	connect(m_timer, &QTimer::timeout, this, &FluToolTipFilter::showToolTip);
}

bool FluToolTipFilter::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::ToolTip)
	{
		LogDebug << "Event ToolTip";
		return true;
	}
	else if (event->type() == QEvent::Hide || event->type() == QEvent::Leave)
	{
		LogDebug << "Event Hide or Leave";
		hideToolTip();
	}
	else if (event->type() == QEvent::Enter)
	{
		LogDebug << "Event Enter";
		m_isEnter = true;
		QWidget* parent = (QWidget*)((QWidget*)(this->parent())->parent());
		if (_canShowToolTip())
		{
			if (m_toolTip == nullptr)
				m_toolTip = new FluToolTip(parent->window(), parent->toolTip());
			int nT = parent->toolTipDuration();
			if (parent->toolTipDuration() > 0)
				nT = -1;
			m_toolTip->setDuration(nT);
			m_timer->start(m_toolTipDelay);
		}
	}
	else if (event->type() == QEvent::MouseButtonPress)
		hideToolTip();

	return QObject::eventFilter(object, event);
}

void FluToolTipFilter::hideToolTip()
{
	m_isEnter = false;
	m_timer->stop();
	if (m_toolTip)
		m_toolTip->hide();
}

void FluToolTipFilter::showToolTip()
{
	if (!m_isEnter)
		return;

	QWidget* parent = (QWidget*)(((QWidget*)(this))->parent());
	m_toolTip->setText(parent->toolTip());
	m_toolTip->adjustPos(parent, m_position);
	LogDebug << "x:" << m_toolTip->x() << "y:" << m_toolTip->y();
	m_toolTip->show();
}

void FluToolTipFilter::setToolTipDelay(int delay)
{
	m_toolTipDelay = delay;
}

bool FluToolTipFilter::_canShowToolTip()
{
	QWidget* parent = (QWidget*)(((QWidget*)(this))->parent());
	return parent->isWidgetType() && !parent->toolTip().isEmpty() && parent->isEnabled();
}
#include "FluToolTip.h"
#include <qmath.h>
#include "../FluentUiUtils/FluentUiLogUtils.h"

FluToolTip::FluToolTip(QWidget* parent /*= nullptr*/, QString text /*= ""*/) : QFrame(parent)
{
	m_text = text;
	m_duration = 1000;
	m_container = new QFrame(this);
	m_timer = new QTimer(this);

	m_hMainLayout = new QHBoxLayout();
	setLayout(m_hMainLayout);


	m_hContainerLayout = new QHBoxLayout(m_container);
	m_container->setLayout(m_hContainerLayout);

	m_label = new QLabel(text, this);
	//m_label->setWordWrap(true);

	m_hMainLayout->setContentsMargins(12, 8, 12, 12);
	m_hMainLayout->addWidget(m_container);

	m_hContainerLayout->addWidget(m_label);
	m_hContainerLayout->setContentsMargins(8, 6, 8, 6);

	// 透明度
	m_opcityAni = new QPropertyAnimation(this, "windowOpacity", this);
	m_opcityAni->setDuration(150);

	// 阴影效果
	m_shadowEffect = new QGraphicsDropShadowEffect(this);
	m_shadowEffect->setBlurRadius(25);
	m_shadowEffect->setColor(QColor(0, 0, 0, 60));
	m_shadowEffect->setOffset(0, 5);
	m_container->setGraphicsEffect(m_shadowEffect);

	m_timer->setSingleShot(true);// 单次定时器
	connect(m_timer, &QTimer::timeout, this, &FluToolTip::hide);

	setAttribute(Qt::WA_TransparentForMouseEvents, true);/*屏蔽该窗体的所有鼠标事件*/
	setAttribute(Qt::WA_TranslucentBackground);//背景透明
	//setAttribute(Qt::WA_StyledBackground);

	// Qt::Tool: 新窗口部件是一个工具(tool)窗口，它通常是一个用于显示工具按钮的小窗口。
	// 如果一个工具窗口有父窗口部件，则它将显示在父窗口的部件上面，
	// 否则相当于使用了Qt::WindowStaysOnTopHint提示。
	//ref:https://www.cnblogs.com/shuoguoleilei/p/12766432.html
	setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
	//setWindowFlags(Qt::ToolTip);

	__setQss();
}

void FluToolTip::__setQss()
{
	m_container->setObjectName("container");
	m_label->setObjectName("contentLabel");
	QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluToolTip.qss");
	setStyleSheet(qss);

	m_label->adjustSize();
	adjustSize();
}

QString FluToolTip::text()
{
	return m_text;
}

void FluToolTip::setText(const QString& text)
{
	m_text = text;
	m_label->setText(text);
	m_container->adjustSize();
	adjustSize();
}

int FluToolTip::duration()
{
	return m_duration;
}

void FluToolTip::setDuration(int duration)
{
	m_duration = duration;
}

void FluToolTip::showEvent(QShowEvent* event)
{
	//	m_opcityAni->setStartValue(0);
	//	m_opcityAni->setEndValue(1);
	//	m_opcityAni->start();

	m_timer->stop();
	if (m_duration > 0)
	{
		m_timer->start(m_duration + m_opcityAni->duration());
	}

	LogDebug << "pos:" << pos() << ", size:" << size() << ",label size:" << m_label->size();
	QFrame::showEvent(event);
}

void FluToolTip::hideEvent(QHideEvent* event)
{
	m_timer->stop();
	QFrame::hideEvent(event);
}

void FluToolTip::adjustPos(QWidget* widget, FluToolTipPositon position)
{
	FluToolTipPositionManager* manager = FluToolTipPositionManager::make(position);
	QPoint gPos = manager->position(this, widget);
	//gPos = mapToParent(gPos);
	move(gPos);
}

QMap<FluToolTipPositon, FluToolTipPositionManager*> FluToolTipPositionManager::m_manages;
QPoint FluToolTipPositionManager::position(FluToolTip* toolTip, QWidget* parent)
{
	QPoint pos = _pos(toolTip, parent);
	//parent->mapToGlobal(QPoint());

	int x = pos.x();
	int y = pos.y();

	QRect rect = QApplication::screenAt(QCursor::pos())->availableGeometry();
	if (QCursor::pos().x() >= 0)
		x = qMax(-2, x);
	x = qMin(rect.width() - toolTip->width() - 4, x);
	y = qMin(qMax(-2, y), rect.height() - toolTip->height() - 4);

	return QPoint(x, y);
}

QPoint FluToolTipPositionManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	return QPoint();
}

FluToolTipPositionManager* FluToolTipPositionManager::make(FluToolTipPositon position)
{
	if (m_manages.empty())
	{
		m_manages[FluToolTipPositon::TOP] = new FluTopToolTipManager;
		m_manages[FluToolTipPositon::BOTTOM] = new FluBottomToolTipManager;
		m_manages[FluToolTipPositon::LEFT] = new FluLeftToolTipManager;
		m_manages[FluToolTipPositon::RIGHT] = new FluRightToolTipManager;
		m_manages[FluToolTipPositon::TOP_LEFT] = new FluTopLeftToolTipManager;
		m_manages[FluToolTipPositon::BOTTOM_LEFT] = new FluBottomLeftToolTipManager;
		m_manages[FluToolTipPositon::TOP_RIGHT] = new FluTopRightToolTipManager;
		m_manages[FluToolTipPositon::BOTTOM_RIGHT] = new FluBottomRightToolTipManager;
	}
	return m_manages[position];
}

QPoint FluTopToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() + parent->width() / 2 - toolTip->width() / 2;
	int y = gPos.y() - toolTip->height();
	return QPoint(x, y);
}

QPoint FluBottomToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() + parent->width() / 2 - toolTip->width() / 2;
	int y = gPos.y() + parent->height();
	return QPoint(x, y);
}

QPoint FluLeftToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() - toolTip->width();
	int y = gPos.y() + (parent->height() - toolTip->height()) / 2;
	return QPoint(x, y);
}

QPoint FluRightToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() + parent->width();
	int y = gPos.y() + (parent->height() - toolTip->height()) / 2;
	return QPoint(x, y);
}

QPoint FluTopLeftToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() - toolTip->layout()->contentsMargins().left();
	int y = gPos.y() - toolTip->height();
	return QPoint(x, y);
}

QPoint FluTopRightToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapToGlobal(QPoint());
	int x = gPos.x() + parent->width() - toolTip->width() + toolTip->layout()->contentsMargins().right();
	int y = gPos.y() - toolTip->height();
	return QPoint(x, y);
}

QPoint FluBottomLeftToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapFromGlobal(QPoint());
	int x = gPos.x() - toolTip->layout()->contentsMargins().left();
	int y = gPos.y() + parent->height();
	return QPoint(x, y);
}

QPoint FluBottomRightToolTipManager::_pos(FluToolTip* toolTip, QWidget* parent)
{
	QPoint gPos = parent->mapFromGlobal(QPoint());
	int x = gPos.x() + parent->width() - toolTip->width() + toolTip->layout()->contentsMargins().right();
	int y = gPos.y() + parent->height();
	return QPoint(x, y);
}

FluToolTipFilter::FluToolTipFilter(QWidget* parent /*= nullptr*/, int showDelay /*= 300*/, FluToolTipPositon position /*= FluToolTipPositon::TOP*/) : QObject(parent)
{
	m_isEnter = false;
	m_toolTip = nullptr;
	m_toolTipDelay = showDelay;
	m_position = position;
	m_timer = new QTimer(this);
	m_timer->setSingleShot(true);
	connect(m_timer, &QTimer::timeout, this, &FluToolTipFilter::showToolTip);
}

bool FluToolTipFilter::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::ToolTip)
	{
		LogDebug << "Event ToolTip";
		return true;
	}
	else if (event->type() == QEvent::Hide || event->type() == QEvent::Leave)
	{
		LogDebug << "Event Hide or Leave";
		hideToolTip();
	}
	else if (event->type() == QEvent::Enter)
	{
		LogDebug << "Event Enter";
		m_isEnter = true;
		QWidget* parent = (QWidget*)((QWidget*)(this->parent())->parent());
		if (_canShowToolTip())
		{
			if (m_toolTip == nullptr)
				m_toolTip = new FluToolTip(parent->window(), parent->toolTip());
			int nT = parent->toolTipDuration();
			if (parent->toolTipDuration() > 0)
				nT = -1;
			m_toolTip->setDuration(nT);
			m_timer->start(m_toolTipDelay);
		}
	}
	else if (event->type() == QEvent::MouseButtonPress)
		hideToolTip();

	return QObject::eventFilter(object, event);
}

void FluToolTipFilter::hideToolTip()
{
	m_isEnter = false;
	m_timer->stop();
	if (m_toolTip)
		m_toolTip->hide();
}

void FluToolTipFilter::showToolTip()
{
	if (!m_isEnter)
		return;

	QWidget* parent = (QWidget*)(((QWidget*)(this))->parent());
	m_toolTip->setText(parent->toolTip());
	m_toolTip->adjustPos(parent, m_position);
	LogDebug << "x:" << m_toolTip->x() << "y:" << m_toolTip->y();
	m_toolTip->show();
}

void FluToolTipFilter::setToolTipDelay(int delay)
{
	m_toolTipDelay = delay;
}

bool FluToolTipFilter::_canShowToolTip()
{
	QWidget* parent = (QWidget*)(((QWidget*)(this))->parent());
	return parent->isWidgetType() && !parent->toolTip().isEmpty() && parent->isEnabled();
}
