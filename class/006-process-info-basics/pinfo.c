/** Licensed as GPLv2
  *
  * Course: Linux Rootkit for RED-BLUE Team
  * Author: Vivek Ramachandran
  * Website: www.pentesteracademy.com
  */
#define pr_fmt(fmt) KBUILD_MODNAME "->%s: %d: " fmt, __func__, __LINE__

#include <linux/module.h>
#include <linux/init.h>

#include "processlibrary.h"


static int process_id;
module_param(process_id, int, S_IWUSR | S_IRUGO);
MODULE_PARAM_DESC(process_id, "Process ID of target process");

static int __init lkm_init(void){

	struct task_struct *target_process;

	target_process = get_task_struct_by_pid(process_id);

	if (!IS_ERR_OR_NULL())
	{
		pr_info("*************** PROCESS DETAILS ***************\n");

		pr_info("Received Process ID: %d\n", process_id);

		print_task_pid_details(target_process);

		print_task_parent_pid_details(target_process);

		pr_info("\n\n");
		pr_info("***********************************************\n");
	}
	else
	{
		pr_info("Invalid Process ID: %d Received\n", process_id);
		return -EINVAL;
	}
	return (0);
}
static void __exit(void){
	pr_info("Exiting...\n");
}

module_init(lkm_init);
module_exit(lkm_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A Hello World Module");
