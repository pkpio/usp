#include <linux/module.h>
#include "../common.h"

extern int usctp_register_rcb(int, struct usctp_rcb_t *);

void test_receive(int length, void *data){
	printk("Length got is: %d\n", length);
}

static int __init tp_init(void)
{
	struct usctp_rcb_t test;
	test.receive = test_receive;
	usctp_register_rcb(22, &test);
	return 0;	
}

static void __exit tp_cleanup(void)
{
}

module_init(tp_init);
module_exit(tp_cleanup);
