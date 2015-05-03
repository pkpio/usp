#include <linux/module.h>
#include "../common.h"

extern int usp_register_receive_cb(int, struct usp_receive_cb_t *);

void test_receive(int length, void *data){
	printk("Length got is: %d\n", length);
}

static int __init tp_init(void)
{
	struct usp_receive_cb_t test; // A test callback
	test.receive = test_receive;  // Call back fn set

	usp_register_receive_cb(22, &test); // Register callback with USP module

	return 0;	
}

static void __exit tp_cleanup(void)
{
}

module_init(tp_init);
module_exit(tp_cleanup);
