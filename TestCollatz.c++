// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read_1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}
TEST(CollatzFixture, read_2) {
    istringstream r("200 400\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 200, i);
    ASSERT_EQ( 400, j);}
TEST(CollatzFixture, read_3) {
    istringstream r("90000 100000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 90000, i);
    ASSERT_EQ( 100000, j);}
TEST(CollatzFixture, read_4) {
    istringstream r("10 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(10, i);
    ASSERT_EQ(10, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(1000, 1500);
    ASSERT_EQ(182, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(1500, 2000);
    ASSERT_EQ(180, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(10, 1);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(100, 100);
    ASSERT_EQ(26, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(1, 2);
    ASSERT_EQ(2, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}
TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 16, 421, 221);
    ASSERT_EQ("16 421 221\n", w.str());}
TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, -2, 4, 0);
    ASSERT_EQ("-2 4 0\n", w.str());}
TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 5, 10, 15);
    ASSERT_EQ("5 10 15\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
TEST(CollatzFixture, solve_2) {
    istringstream r("997855 998761\n997855 998761\n948094 951375\n533575 534854\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("997855 998761 277\n997855 998761 277\n948094 951375 414\n533575 534854 346\n", w.str());}
TEST(CollatzFixture, solve_3) {
    istringstream r("6118 25970\n714690 716038\n323337 329714\n941507 944251\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("6118 25970 282\n714690 716038 305\n323337 329714 384\n941507 944251 352\n", w.str());}
TEST(CollatzFixture, solve_4) {
    istringstream r("1 1\n2 2\n3 3\n4 4\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 1 1\n2 2 2\n3 3 8\n4 4 3\n", w.str());}
