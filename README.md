## UID: 705747359

# A Kernel Seedling

proc_count is a kernel program that will record the number of running processes to the file /proc/count

## Building

This program is built with the aid of a Makefile. Run " make " in bash. The Makefile will create several files and build the program. 


## Running

In bash, after building, run " sudo insmod proc_count.ko " . This will insert the module into the kernel
At this point, the program should be working. You can check this by looking for proc_count with "sudo dmesg -l info" or "cat /proc/count"

## Cleaning Up

In bash, run " sudo rmmod proc_count ". This should remove the module and file. If sucessful, " cat /proc/count " should return an error. 
You can also run " make clean " to remove the built version of proc_count

## Testing

tested on 5.14.8-arch-1
