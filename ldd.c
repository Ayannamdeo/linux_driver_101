#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL"); //*
MODULE_AUTHOR("Ayan"); //!
MODULE_DESCRIPTION("first dynamically loadable kernel module"); //!

static int ldd_module_init(void){
  printk("HELLO World! from ayan\n");
  return 0;
}

static void ldd_module_exit(void){
  printk("Good Bye! from ayan\n");
}

module_init(ldd_module_init);
module_exit(ldd_module_exit);
