/** Licensed as GPLv2
  *
  * Course: Linux Rootkit for RED-BLUE Team
  * Author: Vivek Ramachandran
  * Website: www.pentesteracademy.com
  */
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/cred.h>

#define DEFAULT_SUCCESS 1
#define DEFAULT_FAILURE -1

#define PTR_NULL_CHECK(ptr) if(NULL == ptr) return DEFAULT_FAILURE;

static inline struct task_struct * get_task_struct_by_pid(int pid) {

	return pid_task(find_vpid(pid), PIDTYPE_PID);

}
static inline int print_task_pid_details(struct task_struct *tsk)
{
	PTR_NULL_CHECK(tsk);

	pr_info("Task Binary: %s TGID: %d PID: %d\n",
		tsk->comm,
		tsk->tgid,
		tsk->pid
	);
	return DEFAULT_SUCCESS;
}
static inline int print_task_parent_details(struct task_struct *tsk)
{
	PTR_NULL_CHECK(tsk);

	pr_info("Parent Task Binary: %s TGID: %d PID: %d\n",
		tsk->real_parent->comm,
		tsk->real_parent->tgid,
		tsk->real_parent->pid,
		);
	return DEFAULT_SUCCESS;
}
