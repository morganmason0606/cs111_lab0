#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static int example(struct seq_file *m, struct task_struct *p){
	

	//int here assumes there will be less than UINT_MAX processes on a computer, this feels like a fair assumption
	unsigned int i = 0; 
	
	//we use for_each_process(struct task_struct *p) to add to i for each process
	for_each_process(p){
		i++;
	}

	//print i to file		
	seq_printf(m,"%d\n", i);
	return 0;
}

static int __init proc_count_init(void)
{
	
	
	//creates a process named count permission 644 with no parent
	static struct proc_dir_entry *entry = proc_create_single("count", 0644, NULL, example);
	
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

MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("One sentence description");
MODULE_LICENSE("GPL");
