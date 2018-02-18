# CSE120PA3Tester
Test Suite/Setup for PA3


This is a compilation of PA3 tests from Brandon Milton's tester (https://github.com/brandonio21/ucsd-cs120-wi16-pa3-tester) and some Piazza
tests, plus one I added for a specific case.

Shoutouts to Zaki for help with this.

To install:
Copy over the Makefile (just beware if you made custom targets/dependencies)

# TESTS

## Semaphore Testing
Use Brandon Milton's tests to run that - make sure you comment out ALL DPrintf
statements in your mykernel3.c
Compile with:
> make semtest

Run with:
> ./semtest

It'll identify deadlock/starvation scenarios, so do this before you test pa3d.

## runforever.sh
Bash Script that runs any one executable forever (only really good for pa3d tbh)

Compile pa3d:
> make pa3d

To run the script:
> ./runforever.sh ./pa3d

This script just loops on pa3d while it doesn't throw an error, so if you get
deadlocks then it'll break the loop, I think if you can run for 100-200 times
without errors things should be fine.

## MassiveTest.c
Make sure you comment out main.c in pa3d.c before doing this test

Compile with:
> make massivetest

Run with:
> ./massivetest [TEST_NUMBER]

Currently the test numbers are from 1-23, but this will run one specific test one iteration.

## runtests.sh
The real beefy script that took FOREVER to get working yesterday night :(
Iterates through each test, running them 101 times before moving on to the next
one. Because this one takes a LONG time, it's one you set up to run overnight.

If you want to change the # of times you run the test, change the 101 in line 9, and if you add more tests to massivetest.c change the 23 in line 5.

Again like in MassiveTest.c, comment out main.c in pa3d.c

Compile with:
> make massivetest

Run with:
> ./runtests.sh

Note that this hides road output, and only shows kernel output (but that's cuz Dprintf is to stderr, Road output is to stdout so you won't see it til you get to the end of all loops)

Although more likely if youre sleeping:

> ./runtests.sh &> testoutput

Then all your stdout/stderr output goes to testoutput and then you can grep/search for 'Kernel panic' and 'Deadlock' phrases.

## test1.sh
Counterpart to runtests.sh, except runs a specific test 101 times.

Compile with:
> make massivetest

Run with:
> ./test1.sh [TEST_NUMBER]

Same deal pretty much, redirect output if you have to:

> ./test1.sh [TEST_NUMBER] &> testoutput

And otherwise just grep/search for 'Kernel Panic/Deadlock Phrases'

### Test 23 (in MassiveTest)

Is my own custom test, because I had a stupid bug where when one car finishes and two cars get to the road at the same time, if your logic between letting a car get on the road and updating the number of cars on the road isn't fully atomic you may eventually have a context switch where one car gets approved by the gate, doesn't update the number of cars yet, context switches to the other car which is able to get in through its gate on the other side, and thus you have an incoming crash/deadlock.

For example: (3 approved to enter road, doesn't update the number of cars yet as context switch to 4, so 4 is approved to enter road as number of cars on road is still 0)

>W---------1E Car 1 enters at 10 at 40 mph
W--------1-E Car 1 moves from 10 to 9
W-------1--E Car 1 moves from 9 to 8
W------1---E Car 1 moves from 8 to 7
W-----1----E Car 1 moves from 7 to 6
W----1-----E Car 1 moves from 6 to 5
W---1------E Car 1 moves from 5 to 4
W--1-------E Car 1 moves from 4 to 3
W-1--------E Car 1 moves from 3 to 2
W1---------E Car 1 moves from 2 to 1
W----------E Car 1 exits road
W---------3E Car 3 enters at 10 at 50 mph
W4--------3E Car 4 enters at 1 at 30 mph
W4-------3-E Car 3 moves from 10 to 9
W-4------3-E Car 4 moves from 1 to 2
W-4-----3--E Car 3 moves from 9 to 8
W-4----3---E Car 3 moves from 8 to 7
W--4---3---E Car 4 moves from 2 to 3
W--4--3----E Car 3 moves from 7 to 6
W---4-3----E Car 4 moves from 3 to 4
W---43-----E Car 3 moves from 6 to 5
Kernel Panic! Processes 2, 3 and 4 are deadlocked
System exiting (abnormal)

Not 100% sure it works since with my bug fix I think it's covered, but if you can generate the Kernel Panic/Deadlock then this is working as intended.

## Lastly
Make sure before you turnin you uncomment Main() in pa3d.

If you have any other changes, feel free to submit a pull request!
