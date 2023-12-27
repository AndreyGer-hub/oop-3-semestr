#include "TrainFile.h"

TTrain *TrainFile::getNewTrain()
{
    if (readFile()==0) return _train;
    else return nullptr;
}

int TrainFile::readFile()
{
    std::cout<<"-------------READING FILE-------------"<<std::endl;
    TTrain* newFTrain = new TTrain();
    std::ifstream fin;
    int CounterStr=0;
    std::string Str;

    fin.open(_filePath);
    if((!fin.is_open()))
    {
      std::cout<<"NOT FOUND!"<<std::endl;
      return -1;
    }
    else{
    std::cout<<"FOUND!"<<std::endl;

    int id;
    std::string type;

    while(!fin.eof())
    {
        getline(fin,Str);
        if(Str.length()>0)
        {
            //cout<<Str<<endl;;
            CounterStr++;
        }
    }
    if(CounterStr==0)
    {
        std::cout<<"File is emty!"<<std::endl;
        return -1;
    }
    fin.clear();
    fin.seekg(0,std::ios::beg);
    while(fin>>id>>type)
    {
        TWagon* newWagon = new TWagon();
        newWagon->setNodeID(id);
        newWagon->setCargoType(type);
        newFTrain->push(newWagon);
    }
        _train = newFTrain;
        fin.close();
    }
    return 0;
}

void TrainFile::setFilePath(std::string fpath)
{
    _filePath=fpath;
}

TrainFile::TrainFile()
{

}

TrainFile::~TrainFile()
{

}
