#include <iostream>

#include <RedSquare.h>
#include <Circle.h>
#include <Triangle.h>
#include <Rectangle.h>

int main()
{
    RedSquare bigSquare;
    bigSquare.addShape( new Circle(1));
    bigSquare.addShape(new TriAngle(3,6));
    bigSquare.addShape(new Rectangle(2,4));
    std::cout<< bigSquare.calcSquare()<<std::endl;
    return 0;

}
