#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static struct proc_dir_entry *entry; 
static int count_proc(struct seq_file *m, void *v){
	

	//uint here assumes there will be less than UINT_MAX(very large) processes on a computer
	unsigned int i = 0; 
	
	//we use for_each_process(struct task_struct *p) to add to i for each process
	struct task_struct *p;
	for_each_process(p){
		i++;
	}

	//print i to file		
	seq_printf(m,"%d\n", i);
	return 0;
}

static int __init proc_count_init(void)
{
	//creates a process named count with no parent
	entry = proc_create_single("count", 0, NULL, count_proc);
	
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	proc_remove(entry);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Morgan Mason");
MODULE_DESCRIPTION("writes number of processes to /proc/count");
MODULE_LICENSE("GPL");
