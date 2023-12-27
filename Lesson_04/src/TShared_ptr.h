#ifndef TSHARED_PTR_H
#define TSHARED_PTR_H

struct Counter
{
    int sharedCounter;
    int weakCounter;
};

template<typename T>
class SharedPtr
{
public:
    SharedPtr():ptr_{nullptr}, counter_{nullptr}{}
    SharedPtr(T* nptr):ptr_{nullptr}, counter_{nullptr}{reset(nptr);}
    SharedPtr( SharedPtr& r):ptr_{nullptr}, counter_{nullptr}{
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->sharedCounter+= 1;
        }
    }


    ~SharedPtr(){
        reset();
    }

    T* get(){return ptr_;}

    void reset(T* nptr){
        if(ptr_){
            if(counter_->sharedCounter == 1){
                delete ptr_;
                counter_->sharedCounter--;
                if(counter_->weakCounter == 0){
                    delete counter_;
                    counter_ = nullptr;
                }
            }else{
                counter_->sharedCounter--;
            }
        }
        if(nptr){
            ptr_ = nptr;
            counter_ = new Counter{1, 0};
        }
    }

    void reset(){reset(nullptr);}

    //SharedBadPtr& operator=( SharedBadPtr&& r ) = delete;
    SharedPtr& operator=( SharedPtr& r )
    {
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->sharedCounter+= 1;
        }
        return *this;
    }


    Counter count(){return *counter_;}
    Counter* count_ref(){return counter_;}

private:
    T* ptr_;
    Counter* counter_;
};


template <typename T>
SharedPtr<T> make_badShared(T* ptr){
    return SharedPtr<T>(ptr);
}

#endif
