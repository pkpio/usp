#include <linux/module.h>
#include <linux/errno.h>
#include <linux/semaphore.h> // for semaphores & mutex

#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE]; // Arrays make good circular queues
int ins_pos = 0; // Inserting position in buffer
int rem_pos = 0; // Removing position in buffer

// For race conditioning
static struct semaphore full;
static struct semaphore empty;
static struct semaphore cr; // Mutex for critical region

MODULE_AUTHOR("Praveen Kumar Pendyala");
MODULE_DESCRIPTION("Fifo module");
MODULE_LICENSE("GPL");

void add_item(int *item){
	down(&empty);
	
	down(&cr);
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
	
	down(&full);
	
	down(&cr);
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
