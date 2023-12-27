#ifndef TWAGON_H
#define TWAGON_H

#include <string>
#include <iostream>

class TWagon
{
private:
    std::string _cargoType;
    int _nodeID;
    TWagon* _previousElem =nullptr;
public:
   void setNodeID (int ID);
   void setCargoType (std::string type);
   void setPrevElem(TWagon* prevElem);

   TWagon* getPrevElem();
   std::string getCargoType();
   int getNodeID();

    TWagon();
    ~TWagon();
};

#endif
