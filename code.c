#include<linux/init.h>
#include<linux/module.h>
#include<linux/sched/signal.h>

static void print_task(struct task_struct *task, int depth)
{
    struct task_struct *child_task;
    struct list_head *list;

    printk(KERN_INFO "%*s%d %s [%c]\n", depth * 2, "", task->pid, task->comm, task_state_to_char(task));

    list_for_each(list, &task->children) {
        child_task = list_entry(list, struct task_struct, sibling);
        print_task(child_task, depth + 1);
    }
}

static int __init init(void)
{
    printk(KERN_INFO "Listing tasks:\n");
    print_task(&init_task, 0);
    return 0;
}

static void __exit exit(void)
{
    printk(KERN_INFO "Module unloaded.\n");
}

module_init(init);
module_exit(exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Task list kernel module.");
MODULE_AUTHOR("abc <abc@email.com>");
