## UID: 705747359

(IMPORTANT: Only replace the above numbers with your true UID, do not modify spacing and newlines, otherwise your tarfile might not be created correctly)

# A Kernel Seedling

proc_count is a kernel program that will record the number of running processes to the file /proc/count

## Building

In bash,  run " make " . This will create several files. 

## Running

In bash, run " sudo insmod proc_count.ko " . This will insert the module into the kernel
At this point, the program should be working. You can check this by looking for proc_count with "sudo dmesg -l info" or "cat /proc/count"

## Cleaning Up

In bash, run " sudo rmmod proc_count ". This should remove the module and file. 
You can also run " make clean " to remove the built versio nof proc_count.

## Testing

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on <https://www.kernel.org/>.
