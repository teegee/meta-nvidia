inherit module
do_compile[depends] += "virtual/kernel:do_shared_workdir"
EXTRA_OEMAKE_append = " \
    SYSSRC=${STAGING_KERNEL_DIR} \
    KERNEL_OUTPUT=${STAGING_KERNEL_BUILDDIR} \
    "

SRC_URI += "file://0001-uvm8_va_block.c-include-task_stack.h.patch"
