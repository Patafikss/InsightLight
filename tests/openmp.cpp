#include <iostream>
#include <ctime>
#include <limits>
#include <cmath>

using namespace std;
int main(int argc,char **argv)
{
    int n = 1000000;
    std::cout << "This test shows that OpenMP is activated" << std::endl;
    std::cout << n << " iterations" << std::endl;

    clock_t begin = clock();
    for(int i=0;i<n;i++)
    {
        double k = i;
        double res = pow(k,pow(k,k))/pow(k,k)*sin(k/180);
    }
    clock_t end = clock();
#pragma omp parallel for
    for(int i=0;i<n;i++)
    {
        double k = i;
        double res = pow(k,pow(k,k))/pow(k,k)*sin(k/180);
    }
    clock_t end2 = clock();
    double firstLoop = double(end-begin)/CLOCKS_PER_SEC;
    double secondLoop = double(end2-end)/CLOCKS_PER_SEC;
    std::cout << "first loop, sequential : "<< firstLoop << "ms \nsecond loop, parallel :" << secondLoop <<"ms"<<std::endl;
    if(firstLoop > secondLoop)
    {
        std::cout << "Test Passed" << std::endl;
        return EXIT_SUCCESS;
    }
    else
    {
        std::cout << "Test failed, please check that OpenMP is correctly installed and linked" << std::endl;
        return EXIT_FAILURE;
    }
}
