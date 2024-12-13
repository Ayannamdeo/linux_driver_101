# Character Device Drivers

Data Access:

- Character devices provide unbuffered, sequential access to hardware. Data is read and written one character (or byte) at a time.
  Examples:
- Common examples include keyboards, mice, serial ports, and printers.
  Operations:
- Character device drivers typically implement operations such as open(), close(), read(), and write(), which handle individual characters or bytes.
  Buffering:
- They usually do not perform buffering. Each read or write operation directly interacts with the device, making it suitable for devices that require immediate processing.
- A Character Device is a device whose driver communicates by sending and receiving single characters (bytes, octets). Example - serial ports, parallel ports, sound cards, keyboard, terminals.
- Sequential access: Character devices typically provide sequential access to data, meaning that the operating system reads or writes data in a linear fashion.
- Variable-size data: Character devices often handle variable-size data, such as characters or packets, rather than fixed-size blocks.
- No buffering: Character devices typically do not use buffering, as the data is transmitted in a linear fashion.

# Block Device Drivers

Data Access:

- Block devices provide buffered, random access to hardware. Data is read and written in blocks (fixed-size chunks), typically ranging from 512 bytes to several kilobytes.
  Examples:
- Examples include hard drives, SSDs, and USB drives.
  Operations:
- Block device drivers also implement open(), close(), read(), and write(), but these operations deal with blocks of data rather than individual characters.
  Buffering:
- They utilize buffering and caching mechanisms to optimize read and write operations, allowing for more efficient data transfer and better performance.
- A Block Device is a device whose driver communicates by sending entire blocks of data. Example - hard disks, USB cameras, Disk-On-Key.
- Random access: Block devices allow for random access to data, meaning that the operating system can read or write data to any location on the device without having to read or write the entire device.
- Fixed-size blocks: Block devices divide the storage space into fixed-size blocks, typically 512 bytes or 4KB, which are the basic units of data transfer.
- Buffering: Block devices use a buffer cache to improve performance by reducing the number of physical disk I/O operations.

## tldr

Basically the same as buying soda by the bottle, or by the crate.

Character-driven will send one character at the time, thus you need a small load to carry, but have to make many requests.

Block-driven means you get a large collection of characters (data) so you have a bigger load but have to do less requests.

Block-driven is useful when you know how much data you can expect, which is often the case with files on disk.

Character-driven is more practical when you don’t know when your data will stop thus you keep it running until no more characters get through. For example, an Internet connection, as you don’t know the size of the data stream that you will receive from the server.

## exp

i mainly learned about linux (primarily linux driver development), deeper and
advanced understanding of C lang. I built and implemented a linux driver from
scratch( a simple character driver specifically) it was a loadable kernel
module/driver , in doing so i learned a lot about types of drivers like - (
char driver, block driver, network driver), user and kernel spaces or
privileged and unprivileged modes, system calls, built-in drivers and loadable
kernel drivers. i learned about adjacent but relevant topics like SSH into a
remote device, virtualisation by QEMU, theory behind kernel, bootloader (grub),
ROM firmwares (bios, uefi), dtb (device tree blob).

i also gained a deeper understanding of C lang by familiarising with concepts
like - data alignment, padding, packing (compiler directives), pointer decay (array decay to pointers),
printf race conditions, stream fflush, bitwise Operations - practical usage of shift operation(game
controller buttons, multiplication), practical application of "and" "or"
operation (used in file permissions), sbrk program break and heap boundary,
pretouching, two's complement, unsigned char ( 7 bit ascii ), \_\_cdeclaration - rtl, caller-unwind.
