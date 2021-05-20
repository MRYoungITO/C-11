#include <sstream>
#include "ODU330.h"

ODU330::ODU330()
{

}

ODU330::~ODU330()
{

}

float ODU330::getWarnThreshold()
{
    return warnThreshold;
}

bool ODU330::setWarnThreshold(float threshold) {
    warnThreshold = threshold;
    return true;
}

float ODU330::getBER() {
    return 0.00005;  //ģ��ֵ
}

string ODU330::description()
{
    stringstream ret;
    ret << "���书��: " << txPower << "\t����Ƶ��: " << txFreq
        << "\t����: " << bandWidth << "\t������: " << getBER()
        << "\t�澯����: " << warnThreshold;
    return ret.str();
}
