#include "TWagon.h"

void TWagon::setNodeID(int ID)
{
    _nodeID=ID;
}

void TWagon::setCargoType(std::string type)
{
    _cargoType=type;
}

void TWagon::setPrevElem(TWagon *prevElem)
{
    _previousElem =prevElem;
}

TWagon *TWagon::getPrevElem()
{
    return _previousElem;
}

std::string TWagon::getCargoType()
{
    return _cargoType;
}

int TWagon::getNodeID()
{
    return _nodeID;
}

TWagon::TWagon()
{
    std::cout<<sizeof(this)<<"IWAGON(create)   "<<this<<std::endl;
}

TWagon::~TWagon()
{

}
