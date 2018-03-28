#
## Makefile for kernel test
#
MODULE_NAME  = iopc_hw_gpio

obj-m      := $(MODULE_NAME).o

EXTRA_CFLAGS += -I$(SDKSTAGE)/usr/include/linux_modules_core_gpio
EXTRA_CFLAGS += -I$(KERNEL_MODULE_DIR)/include/

all:
	make CROSS_COMPILE=$(CROSS_COMPILE) ARCH=$(ARCH) -C $(LINUXKERNELROOT) M=$(KERNEL_MODULE_DIR)
clean:
	make CROSS_COMPILE=$(CROSS_COMPILE) ARCH=$(ARCH) -C $(LINUXKERNELROOT) M=$(KERNEL_MODULE_DIR) clean

