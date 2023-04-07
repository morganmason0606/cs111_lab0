#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static int example(struct seq_file *m, void *v){
	//seq_printf(m, "hello world\n");//writes to file
	int i = 0;
	for_each_process(p){
		i++;
	}
	seq_printf(m,i);
	return 0;
}

static int __init proc_count_init(void)
{
	entry = proc_create_sinlge("count", 0, NULL, example)//creates a process of that name
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("One sentence description");
MODULE_LICENSE("GPL");
