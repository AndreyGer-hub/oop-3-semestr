#ifndef TWEAK_PTR_H
#define TWEAK_PTR_H

#include "TShared_ptr.h"

template <typename T>
class WeakPtr
{
public:
    WeakPtr(): ptr_(nullptr), counter_(nullptr){}
    WeakPtr(SharedPtr<T> my_ptr): ptr_(nullptr), counter_(nullptr){
        if (my_ptr.get() == nullptr) return;
        ptr_ = my_ptr.get();
        counter_ = my_ptr.count_ref();
        counter_->weakCounter++;
    }
    WeakPtr( WeakPtr& r):ptr_{nullptr}, counter_{nullptr}{
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->weakCounter++;
        }
    }

    WeakPtr& operator=( WeakPtr& r )
    {
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->weakCounter+= 1;
        }
        return *this;
    }

    WeakPtr& operator=( SharedPtr<T>& r )
    {
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->weakCounter+= 1;
        }
        return *this;
    }

    ~WeakPtr(){reset();}

    bool valid(){
        if(counter_ == nullptr) return false;
        if(counter_->sharedCounter == 0) return false;
        return true;
    }

    T* get(){return ptr_;}

    Counter count(){return *counter_;}
    Counter* count_ref(){return counter_;}

    void reset(){
        if(!(ptr_)) return;
        counter_->weakCounter--;
        if ((counter_->weakCounter == 0)&&(counter_->sharedCounter == 0)) delete counter_;
        ptr_ = nullptr;
        counter_ = nullptr;
    }

private:
    T* ptr_;
    Counter* counter_;
};

#endif
