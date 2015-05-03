/*
 * usp - Usb Streams Protocol
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
#include "common.h"

/**
 * Send data over a stream.
 * Non-blocking call. When sufficient buffer space is not available, 
 * only partial data will be sent.
 *
 * stream:
 *	stream number for the data
 * data:
 *	pointer to data
 * length:
 *	length of data (in bytes), starting from the pointer
 * 
 * returns:
 *	Number of bytes sent. In case of error, a negative value is returned 
 *	with errno set.
 */
int usp_send_data(int stream, void *data, int length){
	printk("Send data called\n");
	return 0;
}

/**
 * Register receive callback, tobe called, when new data arrives for a stream.
 * Non-blocking call.
 *
 * stream:
 *	stream number for which call back is being registered
 * receive_cb:
 *	receive callback function
 *
 * returns:
 *	0 if success else negative value with errno set
 */
int usp_register_receive_cb(int stream, struct usp_receive_cb_t *receive_cb){
	/**
	 * -TODO-
	 * Define receive_cb struct. Also figure out how to use the same struct
	 * in other files where this fn is imported through symtables.
	 */
	printk("Register called for %d\n", stream);

	/**
	 * As a proof of concept, we call the receive fn passed with test values.
	 * You may verify this data with printk in the receive fn.
	 */
	receive_cb->receive(7, NULL);
	return 0;
}

// initialize module (executed when using insmod)
static int __init usp_init(void)
{
	return 0;	
}

// cleanup module (executed when using rmmod)
static void __exit usp_cleanup(void)
{

}

EXPORT_SYMBOL(usp_send_data);
EXPORT_SYMBOL(usp_register_receive_cb);

module_init(usp_init);
module_exit(usp_cleanup);

MODULE_AUTHOR("Praveen Kumar Pendyala");
MODULE_DESCRIPTION("USP Module");
MODULE_LICENSE("GPL");
