# linux_os_list_tasks

Create a kernel module that lists all the current tasks running on the linux operating system.

the code is provide int the above file name called kernel.c .

Abstract

This can be done  using the linux  virtual machine  that is available with this text. Although you may use an editor to write these C programs, you will have to use  the terminal application to compile the programs, and you will have enter commands on  the command line to manage the modules in the kernels.
The advantage of developing kernel modules is that it is a relatively easy method of interacting with the kernel, thus you to write programs that directly involve kernel functions. It is important for you to keep in mind that you are indeed writing kernel code that directly interacts with the kernel. That normally means that any errors in the  code could crash the system.


Code description

This is a Linux kernel module that lists all the processes running on the system. The main function is print_task() which is a recursive function that takes a task_struct pointer and an integer as arguments.
struct task_struct is a kernel data structure that represents a process or thread in the system. The task_struct structure has a member called pid which is the process ID and a member called comm which is the name of the process.
print_task() takes a task_struct pointer and an integer as arguments. The integer argument represents the depth of the current process in the process hierarchy. It uses this depth value to indent the output so that child processes are shown as indented below their parent processes.
Inside the function, it first prints the process ID, process name, and process state of the current task using the printk() function. The task_state_to_char() function is used to convert the process state to a character that can be printed.
The function then iterates over the children of the current task using a list_for_each() loop. list_for_each() is a macro that iterates over a linked list. In this case, it iterates over the children list of the current task. Each child task is obtained using the list_entry() function which returns a pointer to the parent structure (task_struct) of a given member (sibling) of that structure.
print_task() then recursively calls itself with the child task and an incremented depth value. This continues until all the processes in the system have been printed.
The module initializes with the init() function, which calls print_task() with a pointer to the init_task which is the root process of the system. The module is unloaded with the exit() function, which simply prints a message to the kernel log.
The MODULE_LICENSE, MODULE_DESCRIPTION, and MODULE_AUTHOR macros are used to specify information about the module. In this case, it is a GPL-licensed task list kernel module with a brief description and author information.


output 

To run the above files first you have to create a makefile which you will find in this repository(Makefile). the makefile and the code file should be in the same directory.
first run make command in the terminal. Then in the same directory few files will be added automatically called filename.ko ,filenamr.mod ,filename.mod.c,filename.mod.o ,filename.o.

now in terminal follow these commands

sudo insmod filename.ko

sudo dmesg

the command sudo insmod will insert you kernel module to the environment and gets acces to the environment . then dmesg command is describe message .

![image](https://github.com/abhipawar2003/linux_os_list_tasks/assets/112234264/5a7056e1-ef11-4e31-8746-f4dfcc2e39c3)


![image](https://github.com/abhipawar2003/linux_os_list_tasks/assets/112234264/02c6358b-846b-460d-84ca-8408ba61dc43)
