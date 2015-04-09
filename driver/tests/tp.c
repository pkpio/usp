#include <linux/module.h>
#include "../types.h"

extern int usctp_register_rcb(int, struct usctp_rcb_t *);

static int __init tp_init(void)
{
	struct usctp_rcb_t test;
	test.a = 33;
	usctp_register_rcb(22, &test);
	return 0;	
}

static void __exit tp_cleanup(void)
{
}

module_init(tp_init);
module_exit(tp_cleanup);
