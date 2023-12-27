#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> //rand
#include <iterator>

#include "TBubbleSort.h"
using namespace std;

template<typename T>
unsigned long long durationFastSort(T &base_vec) // ms
{
    auto copy = base_vec;
    auto start = chrono::high_resolution_clock::now();
    fastSort(copy);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    return duration.count();
}

template<typename T>
unsigned long long durationBubbleSort(T &base_vec) // ms
{
    auto copy = base_vec;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(copy);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    return duration.count();
}

void display_vector(const vector<double> &v)
{
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<double>(std::cout, " "));
}

int main()
{

    vector<int> base_int_vec = {};
    for(size_t i = 0; i < 1000000; i++){
        base_int_vec.push_back(rand());
    }
    vector<double> base_double_vec = {};
    for(size_t i = 0; i < 1000000; i++){
        base_double_vec.push_back(rand()); //for shits and giggles
    }

    std::cout <<"\n\tvec<int>[1'000'000] fast sort test :\n\n";
    std::cout <<"ind\t|\tduration\n";
    int shortest = -1;
    int longest = -1;
    double mean = 0.;
    int duration;
    for(int i = 0; i < 10; i++){
        duration = durationFastSort(base_int_vec);
        cout <<i+1<<"\t|\t" << duration <<"ms\n";
        if(shortest < 0) shortest = duration;
        if(longest < 0) longest = duration;
        if(longest < duration) longest = duration;
        if(shortest > duration) shortest = duration;
        mean += duration;
    }
    mean /= 10.;

    cout <<"\n";
    cout << "shortest : " << shortest << endl;
    cout << "longest : " << longest << endl;
    cout << "mean : " << mean << endl;

    cout <<"______________________________________________________"<<endl;


    std::cout <<"\n\tvec<double>[1'000'000] fast sort test :\n\n";
    std::cout <<"ind\t|\tduration\n";
    shortest = -1;
    longest = -1;
    mean = 0.;

    for(int i = 0; i < 10; i++){
        duration = durationFastSort(base_double_vec);
        cout <<i+1<<"\t|\t" << duration <<"ms\n";
        if(shortest < 0) shortest = duration;
        if(longest < 0) longest = duration;
        if(longest < duration) longest = duration;
        if(shortest > duration) shortest = duration;
        mean += duration;
    }
    mean /= 10.;

    cout <<"\n";
    cout << "shortest : " << shortest << endl;
    cout << "longest : " << longest << endl;
    cout << "mean : " << mean << endl;


    cout <<"______________________________________________________"<<endl;

    vector<int> base_int_vec_bub = {};
    for(size_t i = 0; i < 10000; i++){
        base_int_vec_bub.push_back(rand());
    }
    vector<double> base_double_vec_bub = {};
    for(size_t i = 0; i < 10000; i++){
        base_double_vec_bub.push_back(rand()); //for shits and giggles
    }

    std::cout <<"\n\tvec<int>[10'000] bubble sort test :\n\n";
    std::cout <<"ind\t|\tduration\n";
    shortest = -1;
    longest = -1;
    mean = 0.;

    for(int i = 0; i < 10; i++){
        duration = durationBubbleSort(base_int_vec_bub);
        cout <<i+1<<"\t|\t" << duration <<"ms\n";
        if(shortest < 0) shortest = duration;
        if(longest < 0) longest = duration;
        if(longest < duration) longest = duration;
        if(shortest > duration) shortest = duration;
        mean += duration;
    }
    mean /= 10.;

    cout <<"\n";
    cout << "shortest : " << shortest << endl;
    cout << "longest : " << longest << endl;
    cout << "mean : " << mean << endl;

    cout <<"______________________________________________________"<<endl;

    std::cout <<"\n\tvec<double>[10'000] bubble sort test :\n\n";
    std::cout <<"ind\t|\tduration\n";
    shortest = -1;
    longest = -1;
    mean = 0.;

    for(int i = 0; i < 10; i++){
        duration = durationBubbleSort(base_double_vec_bub);
        cout <<i+1<<"\t|\t" << duration <<"ms\n";
        if(shortest < 0) shortest = duration;
        if(longest < 0) longest = duration;
        if(longest < duration) longest = duration;
        if(shortest > duration) shortest = duration;
        mean += duration;
    }
    mean /= 10.;

    cout <<"\n";
    cout << "shortest : " << shortest << endl;
    cout << "longest : " << longest << endl;
    cout << "mean : " << mean << endl;



    return 0;
}
