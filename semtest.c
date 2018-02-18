#include "umix.h"
#include "mykernel3.h"
#include "aux.h"
#include "sys.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define BLOCK 0
#define UNBLOCK 1

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* Used to keep track of the previous CALLS Unblock/Block calls */
struct call {
  int valid;
  int calledFunction;
  int arg;
} lastCall;

/* Keep track of failures and tests run */
int failures = 0;
int testFailures = 0;
int tests = 0;

/* debug output */
int debug = 0;

/* Blank out everything regarding the tester */
void initTester() {
  lastCall.valid = 0;
  lastCall.calledFunction = -1;
  failures = 0;
}

/* Alias of above */
void invalidate() {
  initTester();
}

/* Stub UMIX functions */
void Printf(char *fmt, ...) {
  va_list va;
  va_start(va, fmt);
  if (debug) {
    printf("[Printf] ");
    vprintf(fmt, va);
  }
  va_end(va);
}

void DPrintf(char* fmt, ...) {
  va_list va;
  va_start(va, fmt);
  if (debug) {
    printf("[DPrintf] ");
    vprintf(fmt, va);
  }
  va_end(va);
}

int Unblock(int p) {
  if (debug)
    printf("[DEBUG] [USER] Unblock called with %d\n",p);

  lastCall.valid = 1;
  lastCall.calledFunction = UNBLOCK;
  lastCall.arg = p;
}

int Block(int p) {
  if (debug)
    printf("[DEBUG] [USER] Block called with %d\n",p);

  lastCall.valid = 1;
  lastCall.calledFunction = BLOCK;
  lastCall.arg = p;
}


/* Tester functions to assert Block/Unblock calls */
void assert_block_called_with(int param) {
  if (debug)
    printf("[DEBUG] Expecting last call to be Block with %d\n", param);
  if (lastCall.valid && lastCall.calledFunction == BLOCK && lastCall.arg) {
    if (lastCall.arg != param) {
      printf(">ERR: Expected Block call with %d but called with %d\n",param,
          lastCall.arg);
      failures++;
    }
  } else {
    printf(">ERR: Expected Block call with %d but never called\n", param);
    failures++;
  }
  lastCall.valid = 0;
}

void assert_unblock_called_with(int param) {
  if (debug)
    printf("[DEBUG] Expecting last call to be Unblock with %d\n", param);
  if (lastCall.valid && lastCall.calledFunction == UNBLOCK && lastCall.arg) {
    if (lastCall.arg != param) {
      printf(">ERR: Expected Unblock call with %d but called with %d\n",param,
          lastCall.arg);
      failures++;
    }
  } else {
    printf(">ERR: Expected Unblock call with %d but never called\n", param);
    failures++;
  }
  lastCall.valid = 0;
}


void assert_block_not_called_with() {
  if (debug)
    printf("[DEBUG] Expecting last call to NOT BE Block\n");

  if (lastCall.valid && lastCall.calledFunction == BLOCK) {
    printf(">ERR: Did not expect Block call, but called with %d\n",
        lastCall.arg);
    failures++;
  }
}


void assert_unblock_not_called_with() {
  if (debug)
    printf("[DEBUG] Expecting last call to NOT BE Unblock\n");

  if (lastCall.valid && lastCall.calledFunction == UNBLOCK) {
    printf(">ERR: Did not expect Unblock call, but called with %d\n",
        lastCall.arg);
    failures++;
  }
}

void fail(char* reason) {
    failures++;
    if (debug) {
        printf("fail() fail: %s\n", reason);
    }
}

void assert_true(int expr, char* reason) {
    if (!expr) {
        failures++;
        if (debug) {
            printf("assert_true() fail: %s\n", reason);
        }
    }
}

void assert_false(int expr, char* reason) {
    if (expr) {
        failures++;
        if (debug) {
            printf("assert_false() fail: %s\n", reason);
        }
    }
}

void assert_equals(int expected, int actual, char* reason) {
    if (expected != actual) {
        failures++;
        if (debug) {
            printf("assert_equals() expected %d, got %d: %s\n", expected, actual, reason);
        }
    }
}

/* Test function that outputs small summary */
void test(void (*testfunction)(), char* testName) {
  if (debug) {
    printf("---------------------------------------------\n");
    printf("STARTING %s TEST\n",testName);
  }
  invalidate();
  tests++;
  testfunction();
  printf("%s: ", failures == 0 ? "PASS" : "FAIL");
  printf("%d %s test failures\n",failures,testName);
  if (failures > 0)
    testFailures++;
  if (debug)
    printf("---------------------------------------------\n");
}

/* TESTS GO HERE ------------------- */
void test_fifo_impl() {
  int s = MySeminit(0,0);
  MyWait(1,s);
  assert_block_called_with(1);
  MyWait(2,s);
  assert_block_called_with(2);
  MyWait(3,s);
  assert_block_called_with(3);
  MyWait(4,s);
  assert_block_called_with(4);
  MyWait(5,s);
  assert_block_called_with(5);
  MyWait(6,s);
  assert_block_called_with(6);
  MySignal(0,s);
  assert_unblock_called_with(1);
  MySignal(0,s);
  assert_unblock_called_with(2);
  MySignal(0,s);
  assert_unblock_called_with(3);
  MySignal(0,s);
  assert_unblock_called_with(4);
  MySignal(0,s);
  assert_unblock_called_with(5);
  MySignal(0,s);
  assert_unblock_called_with(6);
  MySignal(0,s);
  assert_unblock_not_called_with();
}
void high_value_sem() {
  int s = MySeminit(0,5);
  MyWait(1,s);
  assert_block_not_called_with();
  MyWait(2,s);
  assert_block_not_called_with();
  MyWait(3,s);
  assert_block_not_called_with();
  MyWait(4,s);
  assert_block_not_called_with();
  MyWait(5,s);
  assert_block_not_called_with();
  MyWait(6,s);
  assert_block_called_with(6);
  MySignal(0,s);
  assert_unblock_called_with(6);
}
void nonlocked_sem_test() {
  int s = MySeminit(1,1);
  MyWait(1,s);
  assert_block_not_called_with();
}

void locked_sem_test_all_wait() {
  int s = MySeminit(0,0);
  MyWait(1,s);
  assert_block_called_with(1);
  MyWait(2,s);
  assert_block_called_with(2);
  MyWait(3,s);
  assert_block_called_with(3);
  MyWait(4,s);
  assert_block_called_with(4);
  MyWait(5,s);
  assert_block_called_with(5);
  MySignal(1,s);
  MySignal(1,s);
  MySignal(1,s);
  MySignal(1,s);
  MySignal(1,s);
}

void locked_sem_test() {
  int s = MySeminit(1,1);
  MyWait(1,s);
  assert_block_not_called_with();
  MyWait(2,s);
  assert_block_called_with(2);
  MySignal(1,s);
  assert_unblock_called_with(2);
}

/*
 * tests whether your semaphore wait list can handle every process waiting on it
 * technically if this happens there won't be any processes alive for there to be
 * a deadlock
 */
void test_max_wait_list_fifo() {
    int sem = MySeminit(1, 0);

    // add every process to the wait list
    for (int pid = 1; pid <= MAXPROCS; pid++) {
        MyWait(pid, sem);
        assert_block_called_with(pid);
    }

    for (int pid = 1; pid <= MAXPROCS; pid++) {
        // technically 0 here is invalid as a pid, but it probably doesn't matter?
        MySignal(0, sem);
        assert_unblock_called_with(pid);
    }
}

/*
 * tests repeatedly having a bunch of processes wait and then
 * be signaled on a single semaphore
 */
void test_repeated_all_wait_all_signal() {
    int sem = MySeminit(1, 0);

    for (int cycle = 0; cycle < 4; cycle++) {
        for (int pid = 1; pid <= 5; pid++) {
            MyWait(pid, sem);
            assert_block_called_with(pid);
        }

        for (int pid = 1; pid <= 5; pid++) {
            MySignal(6, sem);
            assert_unblock_called_with(pid);
        }
    }
}

/*
 * tests "inchworming" processes by having them all wait on a semaphore
 * and then incrementally having each one be unblocked and then blocked again
 */
void test_fifo_no_starvation() {
    int sem = MySeminit(1, 0);

    for (int pid = 1; pid <= 5; pid++) {
        MyWait(pid, sem);
        assert_block_called_with(pid);
    }

    for (int cycle = 0; cycle < 5; cycle++) {
        for (int pid = 1; pid <= 5; pid++) {
            MySignal(6, sem);
            assert_unblock_called_with(pid);
            MyWait(pid, sem);
            assert_block_called_with(pid);
        }
    }
}

/*
 * Attempts to allocate MAXSEMS semaphores in a loop, verifying
 * that no semaphore id is reused.
 * Finally verifies that once MAXSEMS semaphores have been allocated,
 * additional calls to MySeminit() return an invalid semaphore id (-1).
 *
 * NOTE: InitSem() must be called immediately before this test is run
 * so that semaphores allocated by previous tests are freed up.
 */
void test_allocate_all_semaphores() {
    // "boolean" array of the semaphore ids allocated so far
    int allocated_sems[MAXSEMS];
    for (int i = 0; i < MAXSEMS; i++) {
        allocated_sems[i] = FALSE;
    }
    int count_allocated = 0;

    char buf[80];
    for (int i = 0; i < MAXSEMS; i++) {
        int sem = MySeminit(1, 0);

        // fail if the semaphore id is out of bounds
        if (sem < 0 || sem >= MAXSEMS) {
            sprintf(buf, "semaphore id out of bounds: %d (%dth iteration)", sem, i);
            fail(buf);
            break;
        }

        sprintf(buf, "Already allocated semaphore id %d (%dth iteration)", sem, i);
        // fail if we already allocated this semaphore id
        assert_false(allocated_sems[sem], buf);

        if (!allocated_sems[sem]) {
            count_allocated++;
        }

        // mark this semaphore id as acquired
        allocated_sems[sem] = TRUE;
    }

    if (count_allocated != MAXSEMS) {
        if (debug) {
            printf("Only allocated %d out of %d semaphore ids\n", count_allocated, MAXSEMS);
            printf("Missed Ids: ");
            for (int sem = 0; sem < MAXSEMS; sem++) {
                if (!allocated_sems[sem]) {
                    printf("%d ", sem);
                }
            }
            printf("\n");
        }
    }

    // try to allocate one last semaphore (which should be -1)
    int sem = MySeminit(1, 0);
    assert_equals(-1, sem, "Allocating last semaphore");
}

/* TESTS ARE CALLED HERE ----------- */
void main(int argc, char** argv) {
  if (argc > 1 && strcmp(argv[1], "-v") == 0)
    debug = 1;
  InitSem();
  test(nonlocked_sem_test, "Simple non-wait");
  test(locked_sem_test_all_wait, "Zero-val semaphore 5 procs");
  test(locked_sem_test, "2 proc must wait");
  test(high_value_sem, "High value semaphore");
  test(test_fifo_impl, "FIFO Test");
  test(test_max_wait_list_fifo, "Maxing out process wait list");
  test(test_repeated_all_wait_all_signal, "Repeated all wait / all signal");
  test(test_fifo_no_starvation, "Cyclic wait signal one at a time");

  // need to clear all allocated semaphores in order to allocate them in this test
  InitSem();
  test(test_allocate_all_semaphores, "Allocate MAXSEMS semaphores");
  InitSem();

  /* final output */
  printf("%d/%d TESTS PASSED\n", tests-testFailures, tests);
}
