#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

#define _OPEN_SYS_ITOA_EXT
#include <stdlib.h>

static struct proc_dir_entry *entry = NULL;

static int example(struct seq_file *m, void *p){
	//seq_printf(m, "hello world\n");//writes to file
	int i = 0; //int here assumes there will be less than INT MAX processes on a computer, this feels like a fair assumption
	for_each_process(p){
		i++;
	}
	char buffer[sizeof(int) * 8  + 1]; // this is a string buffer we will put the string version of i, admittidly overkill
	itoa(i, buffer, DECIMAL) 
	seq_printf(m,buffer);
	return 0;
}

static int __init proc_count_init(void)
{
	//check if there is already an entry, if so removes it
	if(!entry){
		proc_remove(entry); //?? do i need this here too
		entry = NULL;
	}
	
	//creates a process of that name
	entry = proc_create_single("count", 0, NULL, example);
	
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	if(!entry){
		proc_remove(entry);
	}
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("One sentence description");
MODULE_LICENSE("GPL");
