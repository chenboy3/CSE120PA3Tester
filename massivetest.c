#define Main UselessMain
#include "pa3d.c"
#undef Main

// piazza 591
void test1() {
  InitRoad();
  if (Fork () == 0) {
    Delay (0);
    driveRoad (WEST, 10);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (0);
    driveRoad (WEST, 20);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (0);
    driveRoad (EAST, 30);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (0);
    driveRoad (EAST, 40);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (0);
    driveRoad (EAST, 50);
    Exit ();
  }
  driveRoad (WEST, 5);
  Exit ();
}

// last test on discussion slide
void test2() {
  InitRoad();
  if (Fork() == 0){
    Delay(5);
    driveRoad (WEST, 60);
    Exit();
  }
  if (Fork() == 0){
    Delay(10);
    driveRoad (EAST, 50);
    Exit();
  }
  driveRoad(WEST, 10);
  Exit();
}

// same direction going east
void test3() {
  InitRoad();
  if (Fork() == 0){
    Delay(100);
    driveRoad(EAST, 60);
    Exit();
  }
  if (Fork() == 0){
    Delay(150);
    driveRoad(EAST, 20);
    Exit();
  }
  driveRoad(EAST, 30);
  Exit();
}

// dl slide 22
void test4() {
  InitRoad();
  if (Fork() == 0){
    Delay(500);
    driveRoad(WEST, 60);
    Exit();
  }
  if (Fork() == 0){
    Delay(1000);
    driveRoad(EAST, 60);
    Exit();
  }
  driveRoad(WEST, 60);
  Exit();
}

// dl slide 30
void test5() {
  InitRoad();
  if (Fork() == 0){
    Delay(200);
    driveRoad(EAST, 60);
    Exit();
  }
  if (Fork() == 0){
    Delay(300);
    driveRoad(WEST, 60);
    Exit();
  }
  driveRoad(WEST, 60);
  Exit();
}

// di slide 31
void test6() {
  InitRoad();
  if (Fork() == 0){
    driveRoad(WEST, 60);
    Exit();
  }
  if (Fork() == 0){
    driveRoad(WEST, 60);
    Exit();
  }
  if (Fork() == 0){
    driveRoad(WEST, 60);
    Exit();
  }
  if (Fork() == 0){
    driveRoad(EAST, 60);
    Exit();
  }
  if (Fork() == 0){
    driveRoad(EAST, 60);
    Exit();
  }
  if (Fork() == 0){
    driveRoad(EAST, 60);
    Exit();
  }
  driveRoad(WEST, 60);
  Exit();
}

// Rule B: test 2 cars start
void test7() {
  InitRoad();
  if (Fork () == 0) {
    Delay (200);     // car 2
    driveRoad (WEST, 60);
    Exit ();
  }

  driveRoad (EAST, 80);     // car 1
  Exit ();
}

// test 4 cars start
void test8() {
  InitRoad();
  if (Fork () == 0) {
    Delay (100);     // car 2
    driveRoad (WEST, 60);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (100);     // car 3
    driveRoad (EAST, 40);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (100);     // car 4
    driveRoad (WEST, 20);
    Exit ();
  }

  driveRoad (EAST, 80);     // car 1

  Exit ();
}

// test 6 cars start
void test9() {
  InitRoad();
  if (Fork () == 0) {
    Delay (200);     // car 2
    driveRoad (WEST, 130);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 3
    driveRoad (EAST, 100);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 4
    driveRoad (WEST, 70);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 5
    driveRoad (EAST, 40);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 6
    driveRoad (WEST, 10);
    Exit ();
  }

  driveRoad (EAST, 160);     // car 1

  Exit ();
}


// test 10 cars
void test10() {
  InitRoad();
  if (Fork () == 0) {
    Delay (200);     // car 2
    driveRoad (WEST, 240);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 3
    driveRoad (EAST, 210);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 4
    driveRoad (WEST, 190);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 5
    driveRoad (EAST, 160);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 6
    driveRoad (WEST, 130);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 7
    driveRoad (EAST, 100);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 8
    driveRoad (EAST, 70);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 9
    driveRoad (WEST, 40);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);     // car 10
    driveRoad (WEST, 10);
    Exit ();
  }

  driveRoad (EAST, 270);     // car 1

  Exit ();
}

// test 2 cars west east
void test11() {
  InitRoad();
  if (Fork () == 0) {
    Delay (900);     // car 2
    driveRoad (WEST, 20);
    Exit ();
  }
  driveRoad (WEST, 10);     // car 1
  Exit ();
}

// test 2 cars east
void test12() {
  InitRoad();
  if (Fork () == 0) {

    Delay (900);     // car 2
    driveRoad (EAST, 20);
    Exit ();
  }
  driveRoad (EAST, 10);     // car 1
  Exit ();
}

// test 4 cars west
void test13() {
  InitRoad();
  if (Fork () == 0) {
    Delay (300);     // car 2
    driveRoad (WEST, 30);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 3
    driveRoad (WEST, 50);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 4
    driveRoad (WEST, 70);
    Exit ();
  }
  driveRoad (WEST, 10);     // car 1
  Exit ();
}

// test 4 cars east
void test14() {
  InitRoad();
  if (Fork () == 0) {
    Delay (300);     // car 2
    driveRoad (EAST, 30);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 3
    driveRoad (EAST, 50);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 4
    driveRoad (EAST, 70);
    Exit ();
  }
  driveRoad (EAST, 10);     // car 1
  Exit ();
}

// test 10 cars west
void test15() {
  InitRoad();
  if (Fork () == 0) {
    Delay (300);     // car 2
    driveRoad (WEST, 30);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 3
    driveRoad (WEST, 50);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 4
    driveRoad (WEST, 70);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 5
    driveRoad (WEST, 90);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 6
    driveRoad (WEST, 110);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 7
    driveRoad (WEST, 130);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 8
    driveRoad (WEST, 150);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 9
    driveRoad (WEST, 170);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (30);     // car 10
    driveRoad (WEST, 190);
    Exit ();
  }
  driveRoad (WEST, 10);     // car 1
  Exit ();
}

// 10 cars east
void test16() {
  InitRoad();
  if (Fork () == 0) {
    Delay (300);     // car 2
    driveRoad (EAST, 30);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 3
    driveRoad (EAST, 50);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 4
    driveRoad (EAST, 70);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 5
    driveRoad (EAST, 90);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 6
    driveRoad (EAST, 110);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 7
    driveRoad (EAST, 130);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 8
    driveRoad (EAST, 150);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 9
    driveRoad (EAST, 170);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (30);     // car 10
    driveRoad (EAST, 190);
    Exit ();
  }
  driveRoad (EAST, 10);     // car 1
  Exit ();
}

// test 2 cars dif directions
void test17() {
  InitRoad();
  if (Fork () == 0) {
    Delay (100);     // car 2
    driveRoad (EAST, 20);
    Exit ();
  }
  driveRoad (WEST, 10);     // car 1
  Exit ();
}

// test 2 cars dif directions
void test18() {
  InitRoad();
  if (Fork () == 0) {

    Delay (100);     // car 2
    driveRoad (WEST, 20);
    Exit ();
  }
  driveRoad (EAST, 10);     // car 1
  Exit ();
}

// test 10 cars both directions
void test19() {
  InitRoad();
  if (Fork () == 0) {
    Delay (300);     // car 2
    driveRoad (WEST, 30);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 3
    driveRoad (EAST, 50);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 4
    driveRoad (WEST, 70);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 5
    driveRoad (EAST, 90);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 6
    driveRoad (WEST, 110);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 7
    driveRoad (EAST, 130);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 8
    driveRoad (WEST, 150);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 9
    driveRoad (EAST, 170);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (30);     // car 10
    driveRoad (WEST, 190);
    Exit ();
  }
  driveRoad (EAST, 10);     // car 1
  Exit ();
}

// test 10 cars both directions
void test20() {
  InitRoad();
  if (Fork () == 0) {
    Delay (300);     // car 2
    driveRoad (EAST, 30);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 3
    driveRoad (WEST, 50);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 4
    driveRoad (WEST, 70);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 5
    driveRoad (EAST, 90);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 6
    driveRoad (EAST, 110);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 7
    driveRoad (WEST, 130);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 8
    driveRoad (WEST, 150);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 9
    driveRoad (EAST, 170);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 10
    driveRoad (EAST, 190);
    Exit ();
  }
  driveRoad (EAST, 10);     // car 1
  Exit ();
}

// test 5 cars
void test21() {
  InitRoad();
  if (Fork () == 0) {
    Delay (300);     // car 2
    driveRoad (EAST, 75);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 3
    driveRoad (EAST, 70);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 4
    driveRoad (EAST, 65);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 5
    driveRoad (WEST, 60);
    Exit ();
  }
  driveRoad (EAST, 80);     // car 1
  Exit ();
}

// test 5 cars
void test22() {
  InitRoad();
  if (Fork () == 0) {
    Delay (300);     // car 2
    driveRoad (WEST, 75);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 3
    driveRoad (WEST, 70);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 4
    driveRoad (WEST, 65);
    Exit ();
  }
  if (Fork () == 0) {
    Delay (300);     // car 5
    driveRoad (EAST, 60);
    Exit ();
  }
  driveRoad (WEST, 80);     // car 1
  Exit ();
}

// Specific test to try and cause cars 2 and 3 to get on road at same time -
// if your updating the number of waiting cars isn't atomic, you might end up
// with a scenario where car 2/3 gets on the road, but before it updates the
// number of cars there's a context switch to car 3, where it can get on the
// road. Make sure you print out when a process is blocked in mykernel3 so
// you can check to see that they are properly blocking.
void test23() {
  InitRoad();
  if (Fork() == 0) { // car 2
    Delay(500);
    Yield(3);
    driveRoad (EAST, 50);
    Exit();
  }
  if (Fork() == 0) { // car 3
    Delay(520);
    //Yield(2);
    driveRoad (WEST, 50);
    Exit();

  }
  driveRoad (WEST, 80); // car 1
  Exit();
}

void Main(int c, char* argv[]) {
  void (*test_ptr[23])() = {test1, test2, test3, test4, test5, test6,
  test7, test8, test9, test10, test11, test12, test13, test14,
  test15, test16, test17, test18, test19, test20, test21, test22, test23};
  if (c != 2) {
    DPrintf("Need one extra argument: ./massivetest [TEST_NUMBER]\n");
    exit();
  }
  int test = atoi(argv[1]);
  if (test > 23 || test <= 0) {
    DPrintf("Arg must be between 1 and 23\n");
    exit();
  }
  DPrintf("Testing Test %d\n", test);
  (*test_ptr[test - 1])();


}
