/** Licensed as GPLv2
  *
  * Course: Linux Rootkit for RED-BLUE Team
  * Author: Vivek Ramachandran
  * Website: www.pentesteracademy.com
  */
#define pr_fmt(fmt) KBUILD_MODNAME "->%s: %d: " fmt, __func__, __LINE__
#define iamhere(x) 	pr_info("IAMHERE: " x "\n")

#include <linux/module.h>
#include <linux/init.h>
#include <linux/stat.h>

static int counter;
module_param(counter, int, S_IWUSR | S_IRUGO);
MODULE_PARAM_DESC(counter, "A simple integer counter variable");

static char *message = NULL;
module_param(message, charp, S_IWUSR | S_IRUGO);
MODULE_PARAM_DESC(message, "A message from user space.");

static int __init lkm_init(void){
	pr_info("Hello Cruel World of Kernel Programming!\n");

	pr_info("Hello Cruel World of Kernel Programming!\n");
	pr_info("Param 1: Counter %d\n", counter);
	pr_info("Param 2: Message %s\n", message);

	return (0);
}
static void __exit(void){
	pr_info("Woow! You exited early\n");

	pr_info("Param 1: on exit: Counter %d\n", counter);
	pr_info("Param 2: on exit: Message %d\n", message);
}

module_init(lkm_init);
module_exit(lkm_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A Hello World Module");
