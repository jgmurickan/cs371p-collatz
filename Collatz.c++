// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) {
    if (!(r >> i))
        return false;
    r >> j;
    return true;}

// ------------
// collatz_eval
// ------------
int lazy_cache[3000000] = {0};

int collatz_eval (int i, int j) {
   int max = 0;

   if(j < i) {
     int t;
     t = i;
     i = j;
     j = t;
   }

   for(int k = i; k <= j; ++k) {

     int temp = k;
     int count = 1;

     while(temp != 1){
      if(temp <= 3000000) {
        if(lazy_cache[temp] != 0){
          count = lazy_cache[temp];
          break;
        }
      }
      if(temp % 2 == 0)
        temp /= 2;
      else {
        temp = ((temp*3) + 1)/2;
        ++count;
      }
      ++count;
     }

     if(temp == 1)
      lazy_cache[temp] = count;
     if(count > max)
       max = count;
   }

    return max;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
