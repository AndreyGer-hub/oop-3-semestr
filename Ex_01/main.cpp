#include <iostream>

#include "TWagon.h"
#include "TTrain.h"
#include "TrainConsole.h"
#include "TrainFile.h"

using namespace std;

///При разделении одного поезда на 2 все вагоны с type = "LESS"///
/// идут в "левый" поезд, остальные в "правый"///

int main()
{
    //string FilePath="/home/vladislavrn/OOP/Ex_01/src/File.txt";
    string FilePath="../src/File.txt";
    TTrain* newTrain;
    bool Exist= false;
    int choice =1;
    while (choice<6)
{
    cout<<endl;
    cout<<"***********TRAIN_TOMAS_START***********"<<endl;
    cout<<"1. Create new train from console"<<endl;
    cout<<"2. Create new train from file"<<endl;
    cout<<"3. Show train"<<endl;
    cout<<"4. Delete train"<<endl;
    cout<<"5. Split into 2 trains"<<endl;
    cout<<"6. Exit"<<endl;
    cin>>choice;

switch(choice)
    {
        case 1:
         {
             if(Exist==false)
             {
                 TrainConsole trainConsole;
                 newTrain = trainConsole.getNewTrain();
                 if(newTrain != nullptr)
                 {
                     Exist=true;
                     cout<<"+++The train has been created from console+++"<<endl;
                 }else cout<<"---The train has not been created from console---"<<endl;
             } else cout<<"!!!!!!!!!!!!TRAIN IS EXIST!!!!!!!!!!!!"<<endl;
         }
                break;
        case 2:
        {
            if(Exist==false)
            {
                TrainFile trainFile;
                trainFile.setFilePath(FilePath);
                newTrain=trainFile.getNewTrain();
                if(newTrain != nullptr)
                {
                    Exist=true;
                    cout<<"+++The train has been created from file+++"<<endl;
                } else cout<<"---The train has not been created from file"<<endl;
            } else cout<<"!!!!!!!!!!!!TRAIN IS EXIST!!!!!!!!!!!!"<<endl;
        }
                break;
        case 3:
        {
            if(Exist==true)
            {
                newTrain->PrintTrain();
            } else cout<<"!!!!!!!!!!!!TRAIN ISNOT EXIST!!!!!!!!!!!!"<<endl;
        }
                break;
        case 4:
        {
            if(Exist==true)
            {
                while(newTrain->getSize()>0)
                {
                    newTrain->pop();
                }
                cout<<"!!!!!!!!!!!!TRAIN IS DELETED!!!!!!!!!!!!"<<endl;
                Exist=false;
            } else cout<<"!!!!!!!!!!!!TRAIN ISNOT EXIST!!!!!!!!!!!!"<<endl;
        }
                break;
        case 5:
        {
            cout<<"~~~~~~~~~~~~~~~~TRAIN SORT~~~~~~~~~~~~~~~~"<<endl;
            if(Exist==true)
            {
                TTrain* leftTrain = new TTrain();
                TTrain* rightTrain= new TTrain();
                while(newTrain->getSize()>0)
                {
                    TWagon* wagon = newTrain->pop();
                    if(wagon->getCargoType()=="LESS")
                    {
                        leftTrain->push(wagon);
                    } else
                    {
                       rightTrain->push(wagon);
                    }
                }
                Exist=false;
                cout<<"~~~~~~~~~~~~~~~~~~END~~~~~~~~~~~~~~~~~~~~"<<endl;
                cout<<"#####INFO INITIAL TRAIN#####"<<endl;
                newTrain->PrintTrain();
                cout<<"#######INFO LEFT TRAIN######"<<endl;
                leftTrain->PrintTrain();
                cout<<"######INFO  RIGHT TRAIN#####"<<endl;
                rightTrain->PrintTrain();
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            } else cout<<"!!!!!!!!!!!!TRAIN ISNOT EXIST!!!!!!!!!!!!"<<endl;
        }
                break;
        default:
                break;
    }
}
    return 0;
}
