#define pr_fmt(fmt) KBUILD_MODNAME "->%s:%d: " fmt,__func__,__LINE__
#define iamhere(x) pr_info("I AM HERE: " x "\n")

#include <linux/moduleparam.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int counter;
static char *message = NULL;

module_param(counter, int, 0);
MODULE_PARM_DESC(counter, "A simple integer counter varaible");

module_param(message, charp, 0);
MODULE_PARM_DESC(message, "A message from user space");

static int __init lkm_init(void)
{
	pr_info("Hello Cruel World of Kernel Programming\n");

	pr_info("Parm 1: Counter:  %d\n", counter);
	pr_info("Parm 2: Message:  %s\n", message);

	return (0);
}
static void __exit lkm_exit(void)
{
	pr_info("Woow! You exited early\n");
	iamhere("Exiting!");
}
module_init(lkm_init);
module_exit(lkm_exit);

MODULE_AUTHOR("Vivek Ramachadran");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Hello World Module");
