#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

MODULE_AUTHOR("Drovnin Pavlo IV-83");
MODULE_DESCRIPTION("Lab5");
MODULE_LICENSE("Dual BSD/GPL");

static int amount = 1;
module_param(amount, uint, S_IRUGO);
MODULE_PARM_DESC(times, "Amount of outputting Hello worlds");

static int __init hello_init(void)
{
  uint i = 0;

  if(amount == 0)
  {
    printk(KERN_WARNING "You entered 0");
  } 
  else if(amount >= 5 && amount <= 10) 
  {
    printk(KERN_WARNING "You entered parameter between 5 and 10");
  } 
  else if(amount > 10)
  {
    printk(KERN_ERR "You entered parameter bigger than 10");
    return -EINVAL;
  }

  for(i=0; i<amount; i++)
  {
    printk(KERN_EMERG "Hello, world!\n");
  }

  printk(KERN_INFO "Amount: %d\n", amount);

  return 0;
}

static void __exit hello_exit(void)
{
  /* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
