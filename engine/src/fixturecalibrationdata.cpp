
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

#include "fixturecalibrationdata.h"


#define PI 3.14159265
#define KXMLQLCFixtureCaliData = "KXMLQLCFixtureCaliData";


FixtureCalibrationData::FixtureCalibrationData():
    pan0(127)
  , panLT(0)
  , panRT(255)
  , panLB(0)
  , panRB(255)
  , tiltLT(0)
  , tiltRT(0)
  , tiltLB(255)
  , tiltRB(255)
  , tilt0(127)
{
   // setName(tr("New Track"));
}

FixtureCalibrationData::~FixtureCalibrationData()
{

}

quint32 FixtureCalibrationData::getPan(quint32 x, quint32 y){

    quint32 xA = getPanLT();
    quint32 xB = getPanRT();
    quint32 xC = getPanLB();
    quint32 xD = getPanRB();

    float xcalc = ((float)(100-y)/100) * (xA + ((xB-xA) * x/100)) + ((float)y/100) * (xC + (xD-xC)*x/100);

   // quint32 xrot = xcalc * (float)cos(3.14159265/180 * ratio) - ycalc * (float)sin(3.14159265/ratio * 180);

    return xcalc;
}

quint32 FixtureCalibrationData::getTilt(quint32 x, quint32 y){

    quint32 yA = getTiltLT();
    quint32 yB = getTiltRT();
    quint32 yC = getTiltLB();
    quint32 yD = getTiltRB();

    float ycalc = ((float)(100-x)/100) * (yA + ((yC-yA) * y/100)) + ((float)x/100) * (yB + (yD-yB)*y/100);

    return ycalc;
}

quint32 FixtureCalibrationData::getPan0(){
    return pan0;
}
quint32 FixtureCalibrationData::getPanLT(){
    return panLT;
}
quint32 FixtureCalibrationData::getPanRT(){
    return panRT;
}
quint32 FixtureCalibrationData::getPanLB(){
    return panLB;
}
quint32 FixtureCalibrationData::getPanRB(){
    return panRB;
}
quint32 FixtureCalibrationData::getTilt0(){
    return tilt0;
}
quint32 FixtureCalibrationData::getTiltLT(){
    return tiltLT;
}
quint32 FixtureCalibrationData::getTiltRT(){
    return tiltRT;
}
quint32 FixtureCalibrationData::getTiltLB(){
    return tiltLB;
}
quint32 FixtureCalibrationData::getTiltRB(){
    return tiltRB;
}

void FixtureCalibrationData::setPoint0(quint32 x,quint32 y){
    pan0 = x;
    tilt0 = y;
}

void FixtureCalibrationData::setPointLT(quint32 x,quint32 y){
    panLT = x;
    tiltLT = y;
}

void FixtureCalibrationData::setPointRT(quint32 x,quint32 y){
    panRT = x;
    tiltRT = y;
}

void FixtureCalibrationData::setPointLB(quint32 x,quint32 y){
    panLB = x;
    tiltLB = y;
}

void FixtureCalibrationData::setPointRB(quint32 x,quint32 y){
    panRB = x;
    tiltRB = y;
}

/****************************************************************************
 * Load & Save
 ****************************************************************************/

bool FixtureCalibrationData::loadXML(QXmlStreamReader &root)
{

    while (root.readNextStartElement())
    {

        if (root.name() == "panRT")
        {
            panRT = (root.readElementText()).toInt();
        }
        else if (root.name() == "panLT")
        {
            panLT = (root.readElementText()).toInt();
        }
        else if (root.name() == "panRB")
        {
            panRB = (root.readElementText()).toInt();
        }
        else if (root.name() == "panLB")
        {
            panLB = (root.readElementText()).toInt();
        }
        else if (root.name() == "tiltLB")
        {
            tiltLB = (root.readElementText()).toInt();
        }
        else if (root.name() == "tiltLT")
        {
            tiltLT = (root.readElementText()).toInt();
        }else if (root.name() == "tiltRB")
        {
            tiltRB = (root.readElementText()).toInt();
        }
        else if (root.name() == "tiltRB")
        {
            tiltRB = (root.readElementText()).toInt();
        }
        else
        {
            qWarning() << Q_FUNC_INFO << "Unknown script tag:" << root.name();
            root.skipCurrentElement();
        }

    }

    return true;
}

bool FixtureCalibrationData::saveXML(QXmlStreamWriter *doc)
{
    Q_ASSERT(doc != NULL);

    /* Function tag */
    //doc->writeStartElement("KXMLQLCFixtureCaliData");
    doc->writeTextElement("panLT",QString::number(panLT));
    doc->writeTextElement("panRT",QString::number(panRT));
    doc->writeTextElement("panLB",QString::number(panLB));
    doc->writeTextElement("panRB",QString::number(panRB));
    doc->writeTextElement("tiltLT",QString::number(tiltLT));
    doc->writeTextElement("tiltRT",QString::number(tiltRT));
    doc->writeTextElement("tiltLB",QString::number(tiltLB));
    doc->writeTextElement("tiltRB",QString::number(tiltRB));
    //doc->writeEndElement();

    /* Common attributes */
    //saveXMLCommon(doc);

    /* Version */
    //doc->writeAttribute(KXMLQLCScriptVersion, QString::number(2));

//    /* Speed */
//    saveXMLSpeed(doc);

//    /* Direction */
//    saveXMLDirection(doc);

//    /* Run order */
//    saveXMLRunOrder(doc);

//    /* Contents */
//    foreach(QString cmd, dataLines())
//    {
//        doc->writeTextElement(KXMLQLCScriptCommand, QUrl::toPercentEncoding(cmd));
//    }

    /* End the <Function> tag */

    return true;
}
