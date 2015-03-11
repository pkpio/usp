#include <linux/module.h>
#include <linux/errno.h>
#include <linux/workqueue.h> // we use workqueues

static int rate = 1;
static int item = 5;
module_param(rate, int, 0);
module_param(item, int, 0);

#define WORK_QUEUE "producer_work_queue"

extern void add_item(int *);

MODULE_AUTHOR("Praveen Kumar Pendyala");
MODULE_DESCRIPTION("Producer");
MODULE_LICENSE("GPL");

static struct workqueue_struct *wq;
static struct delayed_work task;

static void produce_item(void){
	int items[4] = {item, item, item, item};
	add_item(items);
	queue_delayed_work(wq, &task, HZ / rate);
}

static DECLARE_DELAYED_WORK(task, produce_item); // Declare the delayed task

static int __init producer_init(void)
{
	// Allocate a work queue - this gives context to run our tasks in.
	wq = alloc_workqueue(WORK_QUEUE, WQ_UNBOUND, 1);

	// Queue the delayed work into our work queue
	queue_delayed_work(wq, &task, HZ / rate);

	return 0;	
}

static void __exit producer_cleanup(void)
{
	// Cancel the delayed work
	cancel_delayed_work(&task);

	// Destroy the workqueue
	destroy_workqueue(wq);
}

module_init(producer_init);
module_exit(producer_cleanup);
