#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h> // for copy_from_user
#include <linux/string.h>  // for strlen

MODULE_LICENSE("GPL"); //*
MODULE_AUTHOR("Ayan"); //!
MODULE_DESCRIPTION("first dynamically loadable kernel module"); //!

static struct proc_dir_entry *custom_proc_node;

static char msg[16] = "Ack!\n";

static ssize_t ayandriver_write(struct file *file_pointer,
                            char __user *user_space_buffer,
                            size_t count,
                            loff_t *offset){

  size_t bytes_to_write = min(count, sizeof(msg) - 1); // Prevent buffer overflow
  printk(KERN_INFO "ayan_driver_101: Write called\n");
  // Copy data from user space to kernel space
  if (copy_from_user(msg, user_space_buffer, bytes_to_write)) {
    printk(KERN_ERR "ayan_driver_101: Failed to copy data from user space\n");
    return -EFAULT;
  }
  msg[bytes_to_write] = '\0'; // Ensure null-terminated string
  printk(KERN_INFO "ayan_driver_101: Received message: %s\n", msg);

  return bytes_to_write;
}

static ssize_t ayandriver_read(struct file *file_pointer,
                            const char __user *user_space_buffer,
                            size_t count,
                            loff_t *offset){
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
  .proc_read = ayandriver_read,
  .proc_write = ayandriver_write,
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
