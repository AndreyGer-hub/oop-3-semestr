#ifndef TMYVECTOR_H
#define TMYVECTOR_H

#include <iostream>

template <typename T>
class TMyVector
{
private:
    T* _arr;        //Указатель на массив
    size_t _size;   // Размер (кол-во  элементов)
    size_t _cap;    // Кол-во выделенной памяти (capacity)
public:
    TMyVector()
    {
        _size=0;
        _cap=1;
        _arr= new T[1];
        for(size_t i=0;i<_size;i++)
        {
            _arr[i]=NULL;
        }
    }
    TMyVector(size_t n,const T& value)
    {
        _size=n;
        _cap=n;
        _arr= new T[n];
        for(size_t i=0;i<_size;i++)
        {
            _arr[i]=value;
        }
    }
    ~TMyVector()
    {
        delete[] _arr;
        _arr=nullptr;
    }

    ///
    /// \brief reserve
    /// Выделяет память для n элементов (изменение capacity)
    /// \param n
    ///
    void reserve(size_t n)
    {
        if(n<=_cap) return;
        T* newarr= reinterpret_cast<T*>(new int8_t[n*sizeof(T)]); //!!
        size_t i =0;

//        try {
//            uninitialized_copy(_arr,_arr+_size,newarr); //Копирует элементы из диапазона в указанное место
//        }  catch (...) {
//            delete[] reinterpret_cast<int8_t*>(newarr);
//            throw;
//        }
        try {
            for (; i<_size;i++)
            {
                //newarr[i]=_arr[i];
                new(newarr+i) T(_arr[i]); //placement new
            }
            }  catch (...) {
                    for(size_t j=0;j<i;j++)
                    {
                        (newarr+i)->~T();
                    }
                    delete[] reinterpret_cast<int8_t*>(newarr);
                    throw;
            }
        for(size_t i=0;i<_size;i++)
        {
            (_arr+i)->~T();
        }
        delete [] reinterpret_cast<int8_t*>(_arr);
        _arr = newarr;
        _cap=n;
    }

    void resize(size_t n,const T& value =T())
    {
        if( n>_cap) reserve(n);
        for(size_t i = _size;i<n;i++)
        {
            //_arr[i]=value;
            new (_arr+i) T(value);
        }
        if(n<_size)
        {
            _size=n;
        }
    };

    ///
    /// \brief push_back
    /// Добавить новый элемент в вектор
    /// \param value
    ///
    void push_back(const T& value)
    {
        if (_cap ==_size)
        {
           reserve(2*_size);
        }
        //_arr[_size]=value;
        new (_arr+_size) T(value);
        ++_size;
    }

    void pop_back()
    {
        --_size;
        (_arr+_size)->~T();
    }

    T& operator[](size_t index)
    {
        return _arr[index];
    }
    const T& operator[](size_t index) const
    {
        return _arr[index];
    }

    T& at(size_t index)
    {
        if(index>=_size)
        {
            throw std::out_of_range("!!INCORRECT INDEX!!");
        }
        return _arr[index];
    }

    void insert(const size_t& index,const T& value)
    {
        if(index>=_size)
        {
            throw std::out_of_range("!!INCORRECT INDEX!!");
        }
        if(_size==_cap)
        {
            size_t newcap=2*_size;
            T* newarr= reinterpret_cast<T*>(new int8_t[newcap*sizeof(T)]);
            size_t i =0;
            try {
                for (; i<_size;i++)
                {
                    new(newarr+i) T(_arr[i]); //placement new
                }
                }  catch (...) {
                        for(size_t j=0;j<i;j++)
                        {
                            (newarr+i)->~T();
                        }
                        delete[] reinterpret_cast<int8_t*>(newarr);
                        throw;
                }
            for(size_t i=0;i<_size;i++)
            {
                (_arr+i)->~T();
            }
            delete [] reinterpret_cast<int8_t*>(_arr);
            _arr = newarr;
            _cap=newcap;
        }
        for(size_t k=_size;k>index;k--)
        {
            _arr[k]=_arr[k-1];
        }
        _arr[index]=value;
        _size++;
    }

    void PrintVector()
    {
        if(_size==0)
        {
            std::cout<<"Vector is empty"<<std::endl;
        }else
        {
            std::cout<<"Size="<<_size<<" Capacity="<<_cap<<std::endl;
            for(size_t i =0;i<_size;i++)
            {
                std::cout<<"Index="<<i<<" Value="<<_arr[i]<<std::endl;
            }
        }

    }
};
#endif
