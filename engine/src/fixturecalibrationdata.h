#ifndef FIXTURECALIBRATIONDATA_H
#define FIXTURECALIBRATIONDATA_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QObject>

class QString;
class Doc;

class FixtureCalibrationData
{

public:
    FixtureCalibrationData();
    ~FixtureCalibrationData();

    void setPoint0(quint32 x,quint32 y);
    void setPointLT(quint32 x,quint32 y);
    void setPointRT(quint32 x,quint32 y);
    void setPointLB(quint32 x,quint32 y);
    void setPointRB(quint32 x,quint32 y);

    bool saveXML(QXmlStreamWriter *doc);
    bool loadXML(QXmlStreamReader &root);

    quint32 getPan0();
    quint32 getPanLT();
    quint32 getPanRT();
    quint32 getPanLB();
    quint32 getPanRB();
    quint32 getTiltLT();
    quint32 getTiltRT();
    quint32 getTiltLB();
    quint32 getTiltRB();
    quint32 getTilt0();

    quint32 getPan(quint32 x, quint32 y);
    quint32 getTilt(quint32 x, quint32 y);

protected:
    quint32 pan0;
    quint32 panLT;
    quint32 panRT;
    quint32 panLB;
    quint32 panRB;
    quint32 tiltLT;
    quint32 tiltRT;
    quint32 tiltLB;
    quint32 tiltRB;
    quint32 tilt0;
public slots:
};

#endif // FIXTURECALIBRATION_H
