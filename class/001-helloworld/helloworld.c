#include <linux/module.h>
#include <linux/init.h>

static int __init lkm_init(void)
{
	pr_info("Hello Cruel World of Kernel Programming\n");
	return (0);
}
static void __exit lkm_exit(void)
{
	pr_info("Woow! You exited early\n");
}
module_init(lkm_init);
module_exit(lkm_exit);

MODULE_AUTHOR("Vivek Ramachadran");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Hello World Module");
