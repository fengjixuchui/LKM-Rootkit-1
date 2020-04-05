#define pr_fmt(fmt) KBUILD_MODNAME "->%s:%d: " fmt,__func__,__LINE__
#define iamhere(x) pr_info("I AM HERE: " x "\n")

#include <linux/module.h>
#include <linux/init.h>

static int __init lkm_init(void)
{
	printk(KERN_INFO "Hello KERN INFO\n");
	pr_info("Hello Cruel World of Kernel Programming\n");

	printk(KERN_ALERT "Hello %s\n", "KERN_ALERT");
	pr_alert("Hello %s\n", "KERN_ALERT 2");

	printk(KERN_EMERG "This is an emergency\n");
	pr_emerg("This is an emergency 2");

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
