#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL"); //*
MODULE_AUTHOR("Ayan"); //!
MODULE_DESCRIPTION("first dynamically loadable kernel module"); //!

static struct proc_dir_entry *custom_proc_node;

static ssize_t ayandriver_read(struct file *file_pointer,
                            char __user *user_space_buffer,
                            size_t count,
                            loff_t *offset){
  char msg[] = "Ack!\n";
  size_t len = strlen(msg);
  int result;
  printk("ayan_driver_101 Read\n");

  if(*offset >= len){
    return 0;
  }
  result = copy_to_user(user_space_buffer, msg, len);
  *offset += len;

  return len;
}

struct proc_ops driver_proc_ops =  {
  .proc_read = ayandriver_read
};

static int ldd_module_init(void){
  printk("ayan_module_init: entry\n");
  custom_proc_node = proc_create("ayan_driver_101",
                               0,
                               NULL,
                               &driver_proc_ops);

  printk("ayan_module_init: exit\n");
  return 0;
}

static void ldd_module_exit(void){
  printk("ayan_module_exit: entry\n");
  proc_remove(custom_proc_node);
  printk("ayan_module_exit: exit\n");
}

module_init(ldd_module_init);
module_exit(ldd_module_exit);
