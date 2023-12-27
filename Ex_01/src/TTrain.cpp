#include "TTrain.h"

void TTrain::push(TWagon *newWagon)
{
    newWagon->setPrevElem(nullptr);
    if(_headWagon!=nullptr)
    {

        newWagon->setPrevElem(_headWagon);
        _headWagon=newWagon;
    } else
    {
        std::cout<<"***PUSH FIRST WAGON IN EMPTY TRAIN***"<< std::endl;
        _headWagon =newWagon;
    }
    _size++;
}

void TTrain::PrintTrain()
{
    if(_headWagon != nullptr)
    {
        std::cout<<"*******************************"<<std::endl;
        std::cout<<"**HEAD WAGON INFO**"<<std::endl;
        int ID = _headWagon->getNodeID();
        std::string TYPE= _headWagon->getCargoType();
        std::cout<<"HEAD_ID: "<<ID<<"  HEAD_TYPE: "<<TYPE<<std::endl;
        std::cout<<"**TRAIN INFO**"<<std::endl;
        std::cout<<"SIZE --- "<<_size<< std::endl;
        TWagon* PrevElem = _headWagon;
        while(PrevElem != nullptr)
        {
            std::cout<<"Wagon ID: "<<PrevElem->getNodeID()<<". Type: "<<PrevElem->getCargoType()<<std::endl;
            PrevElem=PrevElem->getPrevElem();
        } std::cout<<"*******************************"<<std::endl;
    } else  std::cout<<"***TRAIN IS EMPTY***"<< std::endl;
}

int TTrain::getSize()
{
    return _size;
}

TWagon *TTrain::at(int index)
{
    if(_headWagon != nullptr)
    {
        int currentIndex =0;
        TWagon* searchWagon= _headWagon;
        while(currentIndex != index)
        {
            std::cout<<"AT IND "<<currentIndex<<std::endl;
            searchWagon=searchWagon->getPrevElem();
            currentIndex++;
        }
        return searchWagon;
    }else std::cout<<"***TRAIN IS EMPTY***"<< std::endl;
}

TWagon *TTrain::pop()
{
    if(_headWagon!=nullptr)
    {
        TWagon* TempWagon=_headWagon;
        _headWagon=_headWagon->getPrevElem();
        _size--;
        return TempWagon;
    }
    else std::cout<<"***TRAIN IS EMPTY (POP)*** "<< std::endl;
}

TWagon *TTrain::getHead()
{
    return _headWagon;
}


TTrain::TTrain()
{

}

TTrain::~TTrain()
{

}
