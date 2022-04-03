#include <chrono>  // for high_resolution_clock
#include <iostream>
//...
using namespace std;
int main(){

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Portion of code to be timed
    long long  int n=100000000;
    while(n--){
        // if(n%2==0){
        //     n^(n+1);
        // }
        // else {
        //     n&(n+1);
        // }
        n%2==0?n^(n+1):n&(n+1);
    }

    // ...

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();std::chrono::duration<double> elapsed = finish - start;std::cout << "Elapsed time: "<<elapsed.count() <<" s\n";

}
//  0.23241+0.237393+0.2364+0.237363 if
//   0.234404+0.23736+0.236395+0.235335  ternary