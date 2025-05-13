# Memory map of current process
This program scanning an address space of the current process by using `mach_vm_region` function and dumps for each region its address, size, protection, etc.

Also the program dumps executable images of the current process by scanning images, that `dyld` has loaded.

## Compile & run

```sh
gcc -o memory-map main.c && ./memory-map
```

## Analysis
I found only one potentially executable image (region with protection `r-x`) in building memory map. It matches with the header of the executable image of the current program. After research I understood that it is normal because of many reasons:

- `dyld` can put headers of executable images in one place that called `dyld_shared_cache`;
- it can be common to different processes;
- and of course regions with headers can be unavailable for scanning by using `mach_vm_region`.