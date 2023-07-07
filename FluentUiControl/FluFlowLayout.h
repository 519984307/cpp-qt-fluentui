#pragma once

#include <QLayout>
#include <QWidget>
#include <QLayoutItem>
#include <QVector>
#include <QStyle>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSize>

// ref: https://doc.qt.io/qt-5/qtwidgets-layouts-flowlayout-example.html
class FluFlowLayout : public QLayout
{
public:
	explicit FluFlowLayout(QWidget* parent, int margin = -1, int hSpacing = -1, int vSpacing = -1);
	explicit FluFlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);
	~FluFlowLayout();

	void addItem(QLayoutItem* item) override;
	int horizontalSpacing() const;
	int verticalSpacing() const;
	Qt::Orientations expandingDirections() const override;
	bool hasHeightForWidth() const override;
	int heightForWidth(int) const override;
	int count() const override;
	QLayoutItem* itemAt(int index) const override;
	QSize minimumSize() const override;
	void setGeometry(const QRect& rect) override;
	QSize sizeHint() const override;
	QLayoutItem* takeAt(int index) override;

private:
	int doLayout(const QRect& rect, bool testOnly) const;
	int smartSpacing(QStyle::PixelMetric pm) const;

private:
	QList<QLayoutItem*> itemList;
	int m_hSpace;
	int m_vSpace;
};
