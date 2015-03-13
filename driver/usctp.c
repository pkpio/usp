/*
 * usctp.c - Usb Stream Control Transmission Protocol
 *
 * Copyright (C) 2015 Praveen Kumar Pendyala <m@praveen.xyz>
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License v2. See the file COPYING in the main directory of this archive for
 * more details
 *
 */

#include <linux/module.h>
#include <linux/errno.h>
#include <linux/semaphore.h>
#include "config.h"

// Arrays make good circular queues
int in_buf[INSTREAM_COUNT][INSTREAM_BUFFER_SIZE];
int in_buf[OUTSTREAM_COUNT][OUTSTREAM_BUFFER_SIZE];

// Inserting position in buffers
int inbuf_inpos[INSTREAM_COUNT] = 0;
int outbuf_inpos[OUTSTREAM_COUNT] = 0;

// Removing position in a buffers
int inbuf_rmpos[INSTREAM_COUNT] = 0;
int outbuf_rmpos[OUTSTREAM_COUNT] = 0;

// For race conditioning
static struct semaphore inbuf_full[INSTREAM_COUNT];
static struct semaphore outbuf_full[OUTSTREAM_COUNT];
static struct semaphore inbuf_empty[INSTREAM_COUNT];
static struct semaphore outbuf_empty[OUTSTREAM_COUNT];

// Mutex for critical section
static struct semaphore inbuf_cs[INSTREAM_COUNT];
static struct semaphore outbuf_cs[OUTSTREAM_COUNT];

void add_item(int *item){
	if(down_trylock(&empty))
		return; // Buffer full
	
	if(down_interruptible(&cr))
		return;	// Interrupted

	// start of critical region
	buffer[ins_pos] = item[0];
	ins_pos = (ins_pos == BUFFER_SIZE-1) ? 0 : ins_pos + 1;
	// end of critical region

	up(&cr);
	up(&full);

	printk("Item added : %d\n", item[0]);
}

int get_item(void){
	int item;
	
	if(down_trylock(&full))
		return -ENODATA; // No data available
	
	if(down_interruptible(&cr))
		return -EINTR; // Interrupted

	// start of critical region
	item = buffer[rem_pos];
	rem_pos = (rem_pos == BUFFER_SIZE-1) ? 0 : rem_pos + 1;
	// end of critical region

	up(&cr);	
	up(&empty);
	
	return item;
}

// initialize module (executed when using insmod)
static int __init fifo_init(void)
{
	// Init semaphores
	sema_init(&full, 0);
	sema_init(&empty, BUFFER_SIZE);
	sema_init(&cr, 1); // using this as a mutex
	return 0;	
}

// cleanup module (executed when using rmmod)
static void __exit fifo_cleanup(void)
{

}

EXPORT_SYMBOL(add_item);
EXPORT_SYMBOL(get_item);

module_init(fifo_init);
module_exit(fifo_cleanup);


MODULE_AUTHOR("Praveen Kumar Pendyala");
MODULE_DESCRIPTION("USCTP Module");
MODULE_LICENSE("GPL");
