#include <mach/mach.h>
#include <mach/mach_vm.h>
#include <mach-o/dyld.h>
#include <stdio.h>

#if defined(__LP64__)
    #define IMG_HEADER_FORMAT "   Header: 0x%016lx\n"
#else
    #define IMG_HEADER_FORMAT "   Header: 0x%08lx\n"
#endif

void dump_memory_map() {
    mach_vm_address_t address = 0;
    mach_vm_size_t size = 0;
    kern_return_t kr;
    task_t task = mach_task_self();

    while (1) {
        vm_region_basic_info_data_64_t info;
        mach_msg_type_number_t count = VM_REGION_BASIC_INFO_COUNT_64;
        mach_port_t object_name;

        kr = mach_vm_region(
            task,
            &address,
            &size,
            VM_REGION_BASIC_INFO_64,
            (vm_region_info_t)&info,
            &count,
            &object_name
        );

        if (kr != KERN_SUCCESS)
            break;

        printf(
            "Region at: 0x%llx, size: 0x%llx\n  Protection: ",
            address,
            size
        );
        if (info.protection & VM_PROT_READ) {
            printf("r");
        } else {
            printf("-");
        };
        if (info.protection & VM_PROT_WRITE) {
            printf("w");
        } else {
            printf("-");
        }
        if (info.protection & VM_PROT_EXECUTE) {
            printf("x");
        } else {
            printf("-");
        }
        printf("\n");
        printf("  Shared: %d\n", info.shared);
        printf("  Inheritance: %d\n", info.inheritance);

        address += size;
    }
}

void dump_loaded_images_by_dydld() {
    uint32_t n = _dyld_image_count();
    for (uint32_t i = 0; i < n; ++i) {
        const char *name = _dyld_get_image_name(i);
        const struct mach_header *header = _dyld_get_image_header(i);

        printf("📦 Image %u:\n", i);
        printf("   Name:  %s\n", name);
        printf(IMG_HEADER_FORMAT, (unsigned long)header);
    }
}

int main() {
    dump_memory_map();
    printf("----------------------------\n");
    dump_loaded_images_by_dydld();
    return 0;
}
