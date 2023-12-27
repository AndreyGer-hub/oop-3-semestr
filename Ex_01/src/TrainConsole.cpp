#include "TrainConsole.h"

using namespace std;

TTrain *TrainConsole::getNewTrain()
{
  consoleMenu();
  return _train;
}


void TrainConsole::consoleMenu()
{
   cout<<"-------------CREATE NEW TRAIN-------------"<<endl;
   int choice =1;
   TTrain *newTrain;
   while(choice<5)
   {
       cout<<endl;
       cout<<"***********MASTERSKAIA***********"<<endl;
       cout<<"1. Add new wagon"<<endl;
       cout<<"2. Delete last wagon"<<endl;
       cout<<"3. Check size of train"<<endl;
       cout<<"4. Check FULL INFO"<<endl;
       cout<<"5. Exit"<<endl;
       cout<<"CHOOSE your action: "<<endl;
       cin>>choice;
   switch(choice)
        {
        case 1:
          {
                TWagon* newWagon = new TWagon();
                int id;
                string type;
                cout<<"***********ENTER  ID************"<<endl;
                cin>>id;
                cout<<"***********ENTER TYPE***********"<<endl;
                cin>>type;
                newWagon->setNodeID(id);
                newWagon->setCargoType(type);
                newTrain->push(newWagon);
                _train = newTrain;
                cout<<"+++The addition is completed!+++"<<endl;
                cout<<"------------------------------------"<<endl;

          }
            break;
        case 2:
                newTrain->pop();
                cout<<"~~~Top elem is removed~~~"<<endl;
            break;
        case 3:
                cout<<"SIZE OF TRAIN: "<<newTrain->getSize()<<endl;
            break;
        case 4:
                newTrain->PrintTrain();
            break;
        default:
            break;
        }
    }
}

TrainConsole::TrainConsole()
{

}

TrainConsole::~TrainConsole()
{

}
