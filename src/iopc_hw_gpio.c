#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/slab.h>
#include <linux/list.h>
#include "iopc_core_gpio.h"

static struct iopc_gpio_t iopc_gpio_list[] = {
	{
		.gc = {
			.label = "iopc_gpio0",
			.ngpio = 8,
			.base = 0,
			/*
			.request = iopc_gpio_request,
			.get_direction = iopc_gpio_get_direction,
			.direction_input = iopc_gpio_direction_input,
			.direction_output = iopc_gpio_direction_output,
			.get = iopc_gpio_get,
			.set = iopc_gpio_set,
			.set_multiple = iopc_gpio_set_multiple,
			.set_debounce = iopc_gpio_set_debounce,
			.to_irq = iopc_gpio_to_irq,
			.dbg_show = iopc_gpio_dbg_show,
			.free = iopc_gpio_free,
			*/
		},
	}, {
		.gc = {
			.label = "iopc_gpio1",
			.ngpio = 8,
			.base = 8,
			/*
			.request = iopc_gpio_request,
			.get_direction = iopc_gpio_get_direction,
			.direction_input = iopc_gpio_direction_input,
			.direction_output = iopc_gpio_direction_output,
			.get = iopc_gpio_get,
			.set = iopc_gpio_set,
			.set_multiple = iopc_gpio_set_multiple,
			.set_debounce = iopc_gpio_set_debounce,
			.to_irq = iopc_gpio_to_irq,
			.dbg_show = iopc_gpio_dbg_show,
			.free = iopc_gpio_free,
			*/
		},
	},
};

static int iopc_hw_gpio_init(void)
{
	printk(KERN_INFO "IOPC HW GPIO init.\n");
	register_gpio_list(ARRAY_SIZE(iopc_gpio_list), &iopc_gpio_list[0]);

	return 0;
}

static void iopc_hw_gpio_exit(void)
{
	struct iopc_gpio_t* gpio = NULL;
	int i = 0;
	printk(KERN_INFO "IOPC HW GPIO destroy\n");
	unregister_gpio_list(ARRAY_SIZE(iopc_gpio_list), &iopc_gpio_list[0]);
}

module_init(iopc_hw_gpio_init);
module_exit(iopc_hw_gpio_exit);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("YuanYu Lin <yuanyu.lin@gmail.com>");
MODULE_DESCRIPTION("IOPC HW GPIO driver");
