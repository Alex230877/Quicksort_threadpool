#include "ThreadPool.h"
#include <iostream>
#include <future>
#include <random>
#include <chrono>

const int SIZE = 1000000;

int main()
{
  srand(0);
  ThreadPool tp;
  std::vector<int> v;
  
  std::cout << "Source array: \n";
   for (int i = 0; i < SIZE; i++)
   {
    int a = rand() % 80 + 10;
    std::cout << a << " ";
    v.push_back(a);
   }
  std::cout << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  tp.push_task(new QuickSort(v, 0, SIZE - 1));
  std::future<void> f = std::async(std::launch::async, [&tp](){ tp.start();});
  f.get();
  auto stop = std::chrono::high_resolution_clock::now();
  std::cout << "Sorted array: \n";
   for (int i = 0; i < SIZE; i++)
   {
    std::cout << v[i] << " ";
   }
   std::chrono::duration<double> elapsed = stop - start;
  std::cout << "Sorting array with size " << SIZE << " took " << elapsed.count() << " sec." << std::endl;
 return 0;
}