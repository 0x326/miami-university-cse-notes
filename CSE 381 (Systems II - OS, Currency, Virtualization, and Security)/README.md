[Wikipedia-Protection_ring]: https://en.wikipedia.org/wiki/Protection_ring
[Wikipedia-Client-server]: https://en.wikipedia.org/wiki/Client%E2%80%93server_model
[Wikipedia-Peer-to-peer]: https://en.wikipedia.org/wiki/Peer-to-peer
[Wikipedia-Trap]: https://en.wikipedia.org/wiki/Trap_(computing)
[Wikipedia-Interrupt]: https://en.wikipedia.org/wiki/Interrupt
[Wikipedia-Direct-memory-access]: https://en.wikipedia.org/wiki/Direct_memory_access
[Wikipedia-Endianness]: https://en.wikipedia.org/wiki/Endianness
[Wikipedia-Operating_system]: https://en.wikipedia.org/wiki/Operating_system
[Wikipedia-Monolithic_kernel]: https://en.wikipedia.org/wiki/Monolithic_kernel
[Wikipedia-Microkernel]: https://en.wikipedia.org/wiki/Microkernel
[Wikipedia-Computer_multitasking]: https://en.wikipedia.org/wiki/Computer_multitasking
[Wikipedia-Booting]: https://en.wikipedia.org/wiki/Booting
[Wikipedia-LILO]: https://en.wikipedia.org/wiki/LILO_(boot_loader)
[Wikipedia-GNU_GRUB]: https://en.wikipedia.org/wiki/GNU_GRUB
[Wikipedia-BIOS]: https://en.wikipedia.org/wiki/BIOS
[Wikipedia-Unified_Extensible_Firmware_Interface]: https://en.wikipedia.org/wiki/Unified_Extensible_Firmware_Interface
[Wikipedia-Hardlink]: https://en.wikipedia.org/wiki/Hardlink
[Wikipedia-Symbolic_link]: https://en.wikipedia.org/wiki/Symbolic_link
[Wikipedia-System_call]: https://en.wikipedia.org/wiki/System_call
[Wikipedia-Multithreading]: https://en.wikipedia.org/wiki/Multithreading_(computer_architecture)
[Wikipedia-Amdahl's_law]: https://en.wikipedia.org/wiki/Amdahl's_law
[Wikipedia-Race_condition]: https://en.wikipedia.org/wiki/Race_condition#Software
[Wikipedia-Concurrency]: https://en.wikipedia.org/wiki/Concurrency_(computer_science)
[Wikipedia-Parallel_computing]: https://en.wikipedia.org/wiki/Parallel_computing
[Wikipedia-Task_parallelism]: https://en.wikipedia.org/wiki/Task_parallelism
[Wikipedia-Data_parallelism]: https://en.wikipedia.org/wiki/Data_parallelism
[Wikipedia-Pipeline]: https://en.wikipedia.org/wiki/Pipeline_(computing)
[Wikipedia-Journaling_file_system]: https://en.wikipedia.org/wiki/Journaling_file_system

# CSE 381: Systems II - OS, Currency, Virtualization, and Security

## Open course material

- https://github.com/angrave/SystemProgramming/wiki

## Topics

- [User mode vs. Kernel mode][Wikipedia-Protection_ring]
- Network architecture

    - [Client-server][Wikipedia-Client-server]
    - [Peer-to-peer][Wikipedia-Peer-to-peer]

- [Traps][Wikipedia-Trap] vs. [Interrupts][Wikipedia-Interrupt]
- [Direct memory access][Wikipedia-Direct-memory-access]
- [Endianness][Wikipedia-Endianness]
- [Operating System][Wikipedia-Operating_system]
- Interprocess communication (IPC)

    - Shared memory
    - Message passing

- [Monolithic kernel architecture][Wikipedia-Monolithic_kernel] vs. [microkernel architecture][Wikipedia-Microkernel]
- [Multitasking][Wikipedia-Computer_multitasking] (preemptive vs. cooperative)
- [Boot sequence][Wikipedia-Booting]

    1. Power on
    2. Hardware loads firmware from ROM
    3. Firmware performs POST
    4. Firmware loads the first-stage bootloader from MBR and passes it control
    5. First-stage bootloader loads second-stage bootloader from disk and passes it control
    6. Second-stage bootloader loads the OS kernel and passes it control
    7. OS kernel initializes
    8. Graphical shell starts

- Bootloaders: [GRUB][Wikipedia-GNU_GRUB] & [LILO][Wikipedia-LILO] (no longer common)
- [BIOS][Wikipedia-BIOS] (succeeded by [UEFI][Wikipedia-Unified_Extensible_Firmware_Interface])
- [Hardlinks][Wikipedia-Hardlink] vs. [Softlinks][Wikipedia-Symbolic_link]
- [syscalls][Wikipedia-System_call]
- [Multithreading][Wikipedia-Multithreading]
- [Amdalh's Law][Wikipedia-Amdahl's_law]
- [Race conditions][Wikipedia-Race_condition]
- Traditional UNIX scheduler
- [Concurrency][Wikipedia-Concurrency] vs. [Parallelism][Wikipedia-Parallel_computing]

    - [Data parallelism][Wikipedia-Data_parallelism]
    - [Task parallelism][Wikipedia-Task_parallelism]

- [CPU pipeline][Wikipedia-Pipeline]
- [Journaling file system][Wikipedia-Journaling_file_system]

## Helpful links

- https://stackoverflow.com/a/5769803
- https://stackoverflow.com/a/8004250
- https://stackoverflow.com/a/10279752
- https://youtu.be/ehyO7mxeU74
- https://en.wikipedia.org/wiki/Multiprocessing
- https://en.wikipedia.org/wiki/Multithreading_(computer_architecture)
- https://en.wikipedia.org/wiki/Data_parallelism
- https://en.wikipedia.org/wiki/Task_parallelism
- https://en.wikipedia.org/wiki/Instruction-level_parallelism
- https://en.wikipedia.org/wiki/Temporal_multithreading
- https://en.wikipedia.org/wiki/Simultaneous_multithreading
- https://en.wikipedia.org/wiki/Pipeline_(computing)
- https://en.wikipedia.org/wiki/Hyper-threading
- https://en.wikipedia.org/wiki/CPU_cache#Cache_miss
- https://stackoverflow.com/a/32941238
- https://stackoverflow.com/a/8514943
- https://serverfault.com/a/38817
- https://stackoverflow.com/a/12769035
- https://stackoverflow.com/a/2109363
- https://www.kernel.org/doc/html/latest/filesystems/ext4/index.html
- https://unix.stackexchange.com/a/153640
- https://youtu.be/2quKyPnUShQ
- https://stackoverflow.com/a/17478535
- https://en.wikipedia.org/wiki/Fragmentation_(computing)
- https://en.wikipedia.org/wiki/Memory_segmentation
- https://en.wikipedia.org/wiki/Segmentation_fault
- https://en.wikipedia.org/wiki/Core_dump
- https://stackoverflow.com/q/16643180
- https://stackoverflow.com/a/40002566
- https://en.wikipedia.org/wiki/Page_table
- https://en.wikipedia.org/wiki/Dirty_bit
- https://en.wikipedia.org/wiki/Paging
- https://en.wikipedia.org/wiki/Page_Size_Extension
- https://en.wikipedia.org/wiki/CPUID
- https://en.wikipedia.org/wiki/Wait-for_graph
- https://en.wikipedia.org/wiki/Round-robin_scheduling
- https://en.wikipedia.org/wiki/Multilevel_queue
- https://en.wikipedia.org/wiki/Multilevel_feedback_queue
- https://stackoverflow.com/a/4800535
- https://defuse.ca/blog/why-unsafe-state-deadlock.html
- https://cs.stackexchange.com/a/45149
- https://stackoverflow.com/a/247026
- https://stackoverflow.com/a/19194580
- https://en.wikipedia.org/wiki/Cache_replacement_policies
- https://en.wikipedia.org/wiki/Page_(computer_memory)
