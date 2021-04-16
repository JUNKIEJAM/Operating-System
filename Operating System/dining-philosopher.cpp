#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int main()
{
     int no_of_philosophers;
     cout<<"Enter the number of philosophers: ";
     cin >> no_of_philosophers;

         struct Chopstics
     {
     public:
         Chopstics() { ; }
         std::mutex mu;
    };
    
    auto eat = [](Chopstics &left_chopstics, Chopstics& right_chopstics, int philosopher_number) {
        
        std::unique_lock<std::mutex> llock(left_chopstics.mu);
        std::unique_lock<std::mutex> rlock(right_chopstics.mu);
        
        cout << "Philosopher " << philosopher_number << " is eating" << endl;
        cout << "Philosopher " << philosopher_number << " has finished eating" << endl;
    };
    
   
    Chopstics chp[no_of_philosophers];
    
    std::thread philosopher[no_of_philosophers];
    
    
    cout << "Philosopher "<<"1" <<" is reading.." << endl;
    philosopher[0] = std::thread(eat, std::ref(chp[0]), std::ref(chp[no_of_philosophers-1]), (0+1));
    
    for(int i = 1; i < no_of_philosophers; ++i) {
        cout << "Philosopher " << (i+1) << " is reading.." << endl;
        philosopher[i] = std::thread(eat, std::ref(chp[i]), std::ref(chp[i-1]), (i+1));
    }
    
    for(auto &ph: philosopher) {
        ph.join();
    }
    
    return 0;
}