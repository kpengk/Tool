#ifndef GAUGEPANEL_H
#define GAUGEPANEL_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QPainter>

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT GaugePanel : public QWidget
#else
class GaugePanel : public QWidget
#endif
{
	Q_OBJECT
	Q_PROPERTY(double value_ READ getValue WRITE setValue)
	Q_PROPERTY(double lower_ READ getLower WRITE setLower)
	Q_PROPERTY(double upper_ READ getUpper WRITE setUpper)
	Q_PROPERTY(int hShearValue_ READ getHShearValue WRITE setHShearValue)
	Q_PROPERTY(int vShearValue_ READ getVShearValue WRITE setVShearValue)
	Q_PROPERTY(double radiusInner_ READ getRadiusInner WRITE setRadiusInner)
	Q_PROPERTY(double radiusOuter_ READ getRadiusOuter WRITE setRadiusOuter)
	Q_PROPERTY(double radiusHalo_ READ getRadiusHalo WRITE setRadiusHalo)
	Q_PROPERTY(QColor colorOuterFrame_ READ getColorOuterFrame WRITE setColorOuterFrame)
	Q_PROPERTY(QColor colorInnerStart_ READ getColorInnerStart WRITE setColorInnerStart)
	Q_PROPERTY(QColor colorInnerEnd_ READ getColorInnerEnd WRITE setColorInnerEnd)
	Q_PROPERTY(QColor colorOuterStart_ READ getColorOuterStart WRITE setColorOuterStart)
	Q_PROPERTY(QColor colorOuterEnd_ READ getColorOuterEnd WRITE setColorOuterEnd)
	Q_PROPERTY(QColor colorHaloStart_ READ getColorHaloStart WRITE setColorHaloStart)
	Q_PROPERTY(QColor colorHaloEnd_ READ getColorHaloEnd WRITE setColorHaloEnd)

Q_SIGNALS:
	void valueChanged(qreal value);

public:
	explicit GaugePanel(QWidget* parent = nullptr);
	~GaugePanel();

	double getValue()           const;
	double getLower()           const;
	double getUpper()           const;
	int    getHShearValue()     const;
	int    getVShearValue()     const;
	double getRadiusInner()     const;
	double getRadiusOuter()     const;
	double getRadiusHalo()      const;
	QColor getColorOuterFrame() const;
	QColor getColorInnerStart() const;
	QColor getColorInnerEnd()   const;
	QColor getColorOuterStart() const;
	QColor getColorOuterEnd()   const;
	QColor getColorHaloStart()  const;
	QColor getColorHaloEnd()    const;

	void setValue(int value);
	void setValue(double value);
	void setLower(double value);
	void setUpper(double value);
	void setValueRange(double lower, double upper);
	void setHShearValue(int value);
	void setVShearValue(int value);

	//?????????????????????
	void setColorOuterFrame(QColor color);

	//?????????????????????
	void setRadiusInner(int radius);
	void setRadiusInner(double radius);

	//?????????????????????
	void setRadiusOuter(int radius);
	void setRadiusOuter(double radius);

	//?????????????????????
	void setRadiusHalo(int radius);
	void setRadiusHalo(double radius);

	//??????????????????
	void setColorInnerStart(QColor color);
	void setColorInnerEnd(QColor color);

	//??????????????????
	void setColorOuterStart(QColor color);
	void setColorOuterEnd(QColor color);

	//????????????
	void setColorHaloStart(QColor color);
	void setColorHaloEnd(QColor color);

	void startShearAnimal(int duration, int hShearValue, int vShearValue);

public slots:
	void updateValue(double value);

protected:
	void paintEvent(QPaintEvent*);

private:
	void drawOuterGradient(QPainter* painter);
	void drawInnerGradient(QPainter* painter);
	void drawOuterHalo(QPainter* painter);
	void drawScale(QPainter* painter);
	void drawScaleNum(QPainter* painter);
	void drawPointer(QPainter* painter);
	void drawPointerSector(QPainter* painter);
	void drawValue(QPainter* painter);
	void drawUnit(QPainter* painter);

private:
	double value_;          //?????????
	double lower_;			//?????????
	double upper_;			//?????????
	int hShearValue_;       //H???V?????????
	int vShearValue_;       //H???V?????????
	double radiusInner_;    //?????????????????????
	double radiusOuter_;    //?????????????????????
	double radiusHalo_;     //???????????????
	QColor colorOuterFrame_;//?????????????????????
	QColor colorInnerStart_;//????????????????????????
	QColor colorInnerEnd_;  //????????????????????????
	QColor colorOuterStart_;//????????????????????????
	QColor colorOuterEnd_;  //????????????????????????
	QColor colorHaloStart_; //??????????????????
	QColor colorHaloEnd_;   //??????????????????

	QPropertyAnimation* hShearAnimation;
	QPropertyAnimation* vShearAnimation;
};

#endif // GaugePanel_H

