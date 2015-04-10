#include <linux/module.h>
#include <linux/errno.h>
#include <linux/workqueue.h> // we use workqueues

static int rate = 1;
module_param(rate, int, 0);

#define WORK_QUEUE "consumer_work_queue"

extern int get_item(void);

MODULE_AUTHOR("Praveen Kumar Pendyala");
MODULE_DESCRIPTION("Lab 3 Solution");
MODULE_LICENSE("GPL");

static struct workqueue_struct *wq;
static struct delayed_work task;

static void consume_item(void){
	printk("Item received : %d \n", get_item());
	queue_delayed_work(wq, &task, HZ / rate);
}

static DECLARE_DELAYED_WORK(task, consume_item); // Declare the delayed task

static int __init consumer_init(void)
{
	// Allocate a work queue - this gives context to run our tasks in.
	wq = alloc_workqueue(WORK_QUEUE, WQ_UNBOUND, 1);

	// Queue the delayed work into our work queue
	queue_delayed_work(wq, &task, HZ / rate);

	return 0;	
}

static void __exit consumer_cleanup(void)
{
	// Cancel the delayed work
	cancel_delayed_work(&task);

	// Flush workqueue
	flush_workqueue(wq);	
	
	// Destroy the workqueue
	destroy_workqueue(wq);
}

module_init(consumer_init);
module_exit(consumer_cleanup);
