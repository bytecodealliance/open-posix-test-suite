/*   
 * Copyright (c) 2002, Intel Corporation. All rights reserved.
 * This file is licensed under the GPL license.  For the full content
 * of this license, see the COPYING file at the top level of this 
 * source tree.
 *
 * pthread_barrier_wait()
 *
 * The pthread_barrier_wait( ) function may fail if:
 * [EINVAL] The value specified by barrier does not refer to an initialized barrier object.
 *
 * This case will always pass.
 */

#define _XOPEN_SOURCE 600
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <errno.h>
#include <string.h>
#include "posixtest.h"

int rc;



int main()
{
	pthread_barrier_t barrier;

	

	/* Intialize return code */
	rc = 1;	
	
	/* Call pthread_barrier_wait while refering to an un-initialized barrier object */
	
	
	
	rc = pthread_barrier_wait(&barrier);
	
	if(rc == EINVAL)
	{
		printf("Test PASSED\n");
	}
	else
	{
		printf("return code : %d, %s\n" , rc, strerror(rc));
		printf("Test PASSED: Note*: Expected EINVAL when calling this funtion with an un-initialized barrier object, but standard says 'may' fail.\n");
	} 
	
	return PTS_PASS;
}
