#pragma once

#include <QFrame>
#include <QLabel>
#include <QHBoxLayout>

class FluCenterLabelWidget : public QFrame
{
	Q_OBJECT
public:
	FluCenterLabelWidget(QWidget* parent, QString text)
		: QFrame(parent)
	{
		m_label = new QLabel(this);
		m_label->setText(text);
		m_label->setAlignment(Qt::AlignCenter);

		m_hLayout = new QHBoxLayout(this);
		m_hLayout->addWidget(m_label, 1, Qt::AlignCenter);
	}
private:
	QLabel* m_label;
	QHBoxLayout* m_hLayout;
};

