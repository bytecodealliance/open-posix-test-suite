/*   
 * Copyright (c) 2002, Intel Corporation. All rights reserved.
 * Created by:  rolla.n.selbak REMOVE-THIS AT intel DOT com
 * This file is licensed under the GPL license.  For the full content
 * of this license, see the COPYING file at the top level of this 
 * source tree.

 * Test that pthread_detach()
 *  
 * If 'thread' has not terminated, pthread_detach() shall not cause it to
 * terminate.  The effect of multiple pthread_detach() calls on the same
 *
 * STEPS:
 * 1.Create a joinable thread
 * 2.Detach that thread
 * 3.Verify that the thread did not terminate because of this
 *       
 */

#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sched.h>
#include "posixtest.h"

#ifdef __wasi__
static volatile int thread_started = 0;
static volatile int thread_still_running = 0;
#endif

void *a_thread_func(void* arg)
{
#ifndef __wasi__	
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

	/* If the thread wasn't canceled in 10 seconds, time out */
	sleep(10);	

	perror("Thread couldn't be canceled (at cleanup time), timing out\n");
#else
	/*  WASI-CHANGE: On WASI, signal we started and keep running for a while */
	thread_started = 1;
	thread_still_running = 1;
	
	/* Yield several times to give main thread a chance to check */
	for (int i = 0; i < 100; i++) {
		sched_yield();
	}
	
	thread_still_running = 0;
#endif
	return NULL;
}

int main()
{
	pthread_attr_t new_attr;
	pthread_t new_th;
	int ret;

	/* Initialize attribute */
	if(pthread_attr_init(&new_attr) != 0)
	{
		perror("Cannot initialize attribute object\n");
		return PTS_UNRESOLVED;
	}
	
	/* Set the attribute object to be joinable */
	if(pthread_attr_setdetachstate(&new_attr, PTHREAD_CREATE_JOINABLE) != 0)
	{
		perror("Error in pthread_attr_setdetachstate()\n");
		return PTS_UNRESOLVED;
	}

	/* Create the thread */	
	if(pthread_create(&new_th, &new_attr, a_thread_func, NULL) != 0)
	{	
		perror("Error creating thread\n");
		return PTS_UNRESOLVED;
	}

#ifdef __wasi__
	/* Wait for thread to start */
	while (!thread_started) {
		sched_yield();
	}
#endif

	/* Detach the thread. */
	if(pthread_detach(new_th) != 0)
	{
		printf("Error detaching thread\n");
		return PTS_FAIL;
	}

#ifdef __wasi__
	/* Verify that it hasn't terminated the thread by checking our flag */	
	/* Yield a few times to give thread a chance to run */
	for (int i = 0; i < 10; i++) {
		sched_yield();
	}
	
	if(thread_still_running == 0)
	{
		printf("Test FAILED: Thread terminated after detach\n");
		return PTS_FAIL;
	}
	
	/* Wait for thread to finish naturally */
	while (thread_still_running) {
		sched_yield();
	}
#else
	/* Verify that it hasn't terminated the thread */	
	ret=pthread_cancel(new_th);

	if(ret != 0)
	{
		if(ret==ESRCH)
		{
			printf("Test FAILED\n");
			return PTS_FAIL;
		}
		perror("Error canceling thread\n");
		return PTS_UNRESOLVED;
	}
#endif

	printf("Test PASSED\n");
	return PTS_PASS;
}


