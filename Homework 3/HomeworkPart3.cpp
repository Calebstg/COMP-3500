#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <pthread.h>
#include <sstream> 


using namespace std;

#define NUM_THREADS 10
string lines[10];
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex5 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex6 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex7 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex8 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex9 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex10 = PTHREAD_MUTEX_INITIALIZER;
int g1 = 0;
int g2 = 0;
int g3 = 0;
int g4 = 0;
int g5 = 0;
int g6 = 0;
int g7 = 0;
int g8 = 0;
int g9 = 0;
int g10 = 0;
int threadindex;



void* linetrace()
{
   stringstream ss(lines[threadindex]);
   string holder;
   int num;
   while (ss >> holder) {
      num = stoi(holder);
   
      if ((num >= 0) && (num <= 9)) {
         pthread_mutex_lock(&mutex1);
         g1++;
         pthread_mutex_unlock(&mutex1);
      }
      else if ((num >= 10) && (num <= 19)) {
         pthread_mutex_lock(&mutex2);
         g2++;
         pthread_mutex_unlock(&mutex2);
      }
      else if ((num >= 20) && (num <= 29)) {
         pthread_mutex_lock(&mutex3);
         g3++;
         pthread_mutex_unlock(&mutex3);
      }
      else if ((num >= 30) && (num <= 39)) {
         pthread_mutex_lock(&mutex4);
         g4++;
         pthread_mutex_unlock(&mutex4);
      }
      else if ((num >= 40) && (num <= 49)) {
         pthread_mutex_lock(&mutex5);
         g5++;
         pthread_mutex_unlock(&mutex5);
      }
      else if ((num >= 50) && (num <= 59)) {
         pthread_mutex_lock(&mutex6);
         g6++;
         pthread_mutex_unlock(&mutex6);
      }
      else if ((num >= 60) && (num <= 69)) {
         pthread_mutex_lock(&mutex7);
         g7++;
         pthread_mutex_unlock(&mutex7);
      }
      else if ((num >= 70) && (num <= 79)) {
         pthread_mutex_lock(&mutex8);
         g8++;
         pthread_mutex_unlock(&mutex8);
      }
      else if ((num >= 80) && (num <= 89)) {
         pthread_mutex_lock(&mutex9);
         g9++;
         pthread_mutex_unlock(&mutex9);
      }
      else if ((num >= 90) && (num <= 99)) {
         pthread_mutex_lock(&mutex10);
         g10++;
         pthread_mutex_unlock(&mutex10);
      }
   }
}




int main() {
   ifstream myfile;
   myfile.open("numbers.txt");
   pthread_t threads[NUM_THREADS];

   for (int i = 0; i < 10; i++) {
      getline(myfile, lines[i]);
      int rc = pthread_create(&threads[i], NULL, void* linetrace, (void*)i);
      threadindex++;
   }
  
   for (int i = 0; i < 10; i++) {
      pthread_join(threads[i], NULL);
   }

   //Create output file and write the group ints to it
   
}