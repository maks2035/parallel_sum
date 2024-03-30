#include <iostream>
#include <omp.h>

int main() {

   setlocale(LC_ALL, "Russian");

   int n, k;

   std::cout << "введите количество чисел " << std::endl;
   if (!(std::cin >> n)) {
      std::cout << "Не число!" << std::endl;
      return 0;
   }

   std::cout << "введите количество потоков " << std::endl;
   if (!(std::cin >> k)) {
      std::cout << "Не число!" << std::endl;
      return 0;
   }

   int sum = 0;

#pragma omp parallel num_threads(k)
   {
      int thread_id = omp_get_thread_num();
      int local_sum = 0;

#pragma omp for
      for (int i = 1; i <= n; i++) {
         local_sum += i;
      }

#pragma omp critical
      {
         std::cout << "Номер потока " << thread_id + 1  << ", сумма вычесленная в потоке: " << local_sum << std::endl;
         sum += local_sum;
      }
   }

   std::cout << "Сумма чисел от 1 до " << n << " равна " << sum << std::endl;

   return 0;
}