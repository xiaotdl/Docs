# The Linux Kernel
http://www.tldp.org/LDP/tlk/tlk-toc.html

## Hardware Basics

### CPU (Central Processing Unit) | microprocessor | processor
The microprocessor calculates, performs logical operations and manages data flows by reading instructions from memory and then executing them.

Microprocessors operate on binary data; that is data composed of ones and zeros.

The processor's execution is governed by an external clock. This clock, the system clock, generates regular clock pulses to the processor and, at each clock pulse, the processor does some work.
A 100Mhz processor will receive 100,000,000 clock ticks every second. The processors perform different amounts of work per clock tick.

Most processors have the following special purpose, dedicated, **registers**:
- Program Counter (PC)
This register contains the address of the next instruction to be executed.
- Stack Pointer (SP)
Processors have to have access to large amounts of external read/write random access memory (RAM) which facilitates temporary storage of data. The stack is a way of easily saving and restoring temporary values in external memory.
Some processor's stacks grow upwards towards the top of memory whilst others grow downwards towards the bottom, or base, of memory. Some processor's support both types, for example ARM.
- Processor Status (PS)
Instructions may yield results. For example, most processors have at least two modes of operation, kernel (or supervisor) and user. The PS register would hold information identifying the current mode.

### Memory

### Buses
The individual components of the system board are interconnected by multiple connection systems known as buses.
The system bus is divided into three logical functions; **the address bus**, **the data bus** and **the control bus**.
**The address bus** specifies the memory locations (addresses) for the data transfers.
**The data bus** holds the data transfered. The data bus is bidirectional; it allows data to be read into the CPU and written from the CPU.
**The control bus** contains various lines used to route timing and control signals throughout the system.
Many flavours of bus exist, for example ISA and PCI buses are popular ways of connecting peripherals to the system.

### Controllers and Peripherals
The controllers are processors like the CPU itself, they can be viewed as intelligent helpers to the CPU.

### Address Spaces
system space memory, I/O space memory

### Timers
a special peripheral called the Real Time Clock (RTC) provides: a reliable time of day, and an accurate timing interval.
The RTC has its own battery so that it continues to run even when the PC is not powered on, this is how your PC always ``knows'' the correct date and time.
The interval timer allows the operating system to accurately schedule essential work.


## Software Basics

### Computer Languages

#### Assembly Languages
Assembler, a program which takes a human readable source file and assembles it into machine code.

#### The C Programming Language and Compiler
Assembly language is not portable, being tied to one particular processor family, while C language is machine independant.
A compiler reads the C program and translate it into assembly language, generating machine specific code from it.
A good compiler can generate assembly instructions that are very nearly as efficient as those written by a good assembly programmer.

#### Linkers
Linkers are programs that link together several object modules and libraries to form a single, coherent, program.

### What is an Operating System?
An operating system is a collection of system programs which allow the user to run application software.
The operating system abstracts the real hardware of the system and presents the system's users and its applications with a virtual machine.

#### Memory management
One of the basic tricks of any operating system is the ability to make a small amount of physical memory behave like rather more memory.
This apparently large memory is known as **virtual memory**.
The idea is that the software running in the system is fooled into believing that it is running in a lot of memory.
The system divides the memory into easily handled pages and swaps these pages onto a hard disk as the system runs.
The software does not notice because of another trick, multi-processing.

#### Processes
Each process in turn for a short period. This period of time is known as a **time-slice**.
This trick is known as **multi-processing** or **scheduling** and it fools each process into thinking that it is the only process.
Processes are protected from one another so that if one process crashes or malfunctions then it will not affect any others.
The operating system achieves this by giving each process a **separate address space** which only they have access to.

#### Device drivers
Device drivers make up the major part of the Linux kernel.
Like other parts of the operating system, they operate in a highly privileged environment and can cause disaster if they get things wrong.
Device drivers control the interaction between the operating system and the hardware device that they are controlling.
For example, the filesystem makes use of a general block device interface when writing blocks to an IDE disk.
The driver takes care of the details and makes device specific things happen.
Device drivers are specific to the controller chip that they are driving which is why, for example, you need the NCR810 SCSI driver if your system has an NCR810 SCSI controller.

#### The Filesystems
In Linux, filesystems are combined into a single hierarchical tree structure that represents the filesystem as a single entity.
One of the most important features of Linux is its support for many different filesystems. This makes it very flexible and well able to coexist with other operating systems.
The most popular filesystem for Linux is the EXT2 filesystem and this is the filesystem supported by most of the Linux distributions.

The block device drivers hide the differences between the physical block device types (for example, IDE and SCSI) and,
so far as each filesystem is concerned, the physical devices are just linear collections of blocks of data.
The block sizes may vary between devices, for example 512 bytes is common for floppy devices, whereas 1024 bytes is common for IDE devices.
And, again, this is hidden from the users of the system. An EXT2 filesystem looks the same no matter what device holds it.

### Kernel Data Structures
Mostly these data structures (e.g. pstree) exist in physical memory and are accessible only by the kernel and its subsystems.
Data structures contain data and pointers; addresses of other data structures or the addresses of routines.
Taken all together, the data structures used by the Linux kernel can look very confusing.
Every data structure has a purpose and although some are used by several kernel subsystems, they are more simple than they appear at first sight.

Understanding the Linux kernel hinges on understanding its data structures and the use that the various functions within the Linux kernel makes of them. This book bases its description of the Linux kernel on its data structures. It talks about each kernel subsystem in terms of its algorithms, its methods of getting things done, and their usage of the kernel's data structures.

#### Linked Lists
#### Hash Tables
As a hash table speeds up access to commonly used data structures, Linux often uses hash tables to implement caches.
#### Abstract Interfaces
The Linux kernel often abstracts its interfaces. An interface is a collection of routines and data structures which operate in a particular way.

## Memeory Management
The memory management subsystem is one of the most important parts of the operating system.

Virtual memory does more than just make your computer's memory go further. The memory management subsystem provides:
- Large Address Spaces
The operating system makes the system appear as if it has a larger amount of memory than it actually has.
The virtual memory can be many times larger than the physical memory in the system,
- Protection
Each process in the system has its own virtual address space. These virtual address spaces are completely separate from each other and so a process running one application cannot affect another. Also, the hardware virtual memory mechanisms allow areas of memory to be protected against writing. This protects code and data from being overwritten by rogue applications.
- Memory Mapping
Memory mapping is used to map image and data files into a processes address space. In memory mapping, the contents of a file are linked directly into the virtual address space of a process.
- Fair Physical Memory Allocation
The memory management subsystem allows each running process in the system a fair share of the physical memory of the system,
- Shared Virtual Memory
Although virtual memory allows processes to have separate (virtual) address spaces, there are times when you need processes to share memory.
For example there could be several processes in the system running the bash command shell. Rather than have several copies of bash, one in each processes virtual address space, it is better to have only one copy in physical memory and all of the processes running bash share it.
Dynamic libraries are another common example of executing code shared between several processes.

Shared memory can also be used as an Inter Process Communication (IPC) mechanism, with two or more processes exchanging information via memory common to all of them. Linux supports the Unix TM System V shared memory IPC.

### An Abstract Model of Virtual Memory
Abstract model of Virtual to Physical address mapping.
To make this translation easier, virtual and physical memory are divided into handy sized chunks called **pages**.
These pages are all the same size, they need not be but if they were not, the system would be very hard to administer.
Linux on Alpha AXP systems uses 8 KB pages and on Intel x86 systems it uses 4 KB pages. Each of these pages is given a unique number; the page frame number (PFN).

In this paged model, a virtual address is composed of two parts; an offset, and a virtual page frame number.
If the page size is 4 Kbytes, bits 11:0 of the virtual address contain the offset and bits 12 and above are the virtual page frame number.
Each time the processor encounters a virtual address it must extract the offset and the virtual page frame number. The processor must translate the virtual page frame number into a physical one and then access the location at the correct offset into that physical page. To do this the processor uses **page tables**.
Page tables map each processes virtual pages into physical pages in memory.
Each entry in the theoretical page table contains the following information:
- Valid flag. This indicates if this page table entry is valid,
- The physical page frame number that this entry is describing,
- Access control information. This describes how the page may be used. Can it be written to? Does it contain executable code?

If the entry is invalid(**page fault**), the process has accessed a non-existent area of its virtual memory. In this case, the processor cannot resolve the address and must pass control to the operating system so that it can fix things up.

e.g.
Process X's Virtual Memory: VPFN0~VPFN7
Process X's Page Table: VPFN0=>PFN6, ...

Process Y's Virtual Memory: VPFN0~VPFN7
Process Y's Page Table: VPFN0=>PFN3, ...

Pysical Memory: PFN0~PFN4

#### Demand Paging
This technique of only loading virtual pages into memory as they are accessed is known as **demand paging**.

#### Swapping
If a process needs to bring a virtual page into physical memory and there are no free physical pages available, the operating system must make room for this page by discarding another page from physical memory.
The set of pages that a process is currently using is called the **working set**. An efficient swap scheme would make sure that all processes have their working set in physical memory.
Linux uses a Least Recently Used (LRU) page aging technique to fairly choose pages which might be removed from the system.

#### Shared Virtual Memory
Virtual memory makes it easy for several processes to share memory.
All memory access are made via page tables and each process has its own separate page table.
For two processes sharing a physical page of memory, its physical page frame number must appear in a page table entry in both of their page tables.
The shared physical page does not have to exist at the same place in virtual memory for any or all of the processes sharing it.

#### Physical and Virtual Addressing Modes
The Linux kernel is linked to run in physical address space.
Most multi-purpose processors support the notion of a physical address mode as well as a virtual address mode.

#### Access Control
The **page table** entries also contain **access control** information. As the processor is already using the page table entry to map a processes virtual address to a physical one, it can easily use the access control information to check that the process is not accessing memory in a way that it should not.
Most processors have at least two modes of execution: kernel and user. You would not want kernel code executing by a user or kernel data structures to be accessible except when the processor is running in kernel mode.

### Caches
Linux uses a number of memory management related caches:

#### Buffer Cache
The buffer cache contains data buffers that are used by the block device drivers.

These buffers are of fixed sizes (for example 512 bytes) and contain blocks of information that have either been read from a block device or are being written to it. A block device is one that can only be accessed by reading and writing fixed sized blocks of data. All hard disks are block devices.

The buffer cache is indexed via the device identifier and the desired block number and is used to quickly find a block of data. Block devices are only ever accessed via the buffer cache. If data can be found in the buffer cache then it does not need to be read from the physical block device, for example a hard disk, and access to it is much faster.

#### Page Cache
This is used to speed up access to images and data on disk.

It is used to cache the logical contents of a file a page at a time and is accessed via the file and offset within the file. As pages are read into memory from disk, they are cached in the page cache.

#### Swap Cache
Only modified (or dirty) pages are saved in the swap file.

So long as these pages are not modified after they have been written to the swap file then the next time the page is swapped out there is no need to write it to the swap file as the page is already in the swap file. Instead the page can simply be discarded. In a heavily swapping system this saves many unnecessary and costly disk operations.

#### Hardware Caches
One commonly implemented hardware cache is in the processor; a cache of Page Table Entries.
The processor does not always read the page table directly but instead caches translations for pages as it needs them.

### Linux Page Tables

### Page Allocation and Deallocation
All of the physical pages in the system are described by the **mem_map** data structure which is a list of **mem_map_t**
structures which is initialized at boot time.
Each mem_map_t describes a single physical page in the system. Important fields (so far as memory management is concerned) are:
- count
    This is a count of the number of users of this page. The count is greater than one when the page is shared between many processes,
- age
    This field describes the age of the page and is used to decide if the page is a good candidate for discarding or swapping,
- map_nr
    This is the physical page frame number that this mem_map_t describes.

#### Page Allocation
Pages are allocated in blocks which are powers of 2 in size. That means that it can allocate a block 1 page, 2 pages, 4 pages and so on.

#### Page Deallocation
Allocating blocks of pages tends to fragment memory with larger blocks of free pages being broken down into smaller ones. The page deallocation code recombines pages into larger blocks of free pages whenever it can. In fact the page block size is important as it allows for easy combination of blocks into larger blocks.

### Memory Mapping
When an image is executed, the contents of the executable image must be brought into the processes virtual address space. The same is also true of any shared libraries that the executable image has been linked to use. The executable file is not actually brought into physical memory, instead it is merely linked into the processes virtual memory.
This linking of an image into a processes virtual address space is known as **memory mapping**.

Every processes virtual memory is represented by an **mm_struct** data structure.
This contains information about the image that it is currently executing (for example bash) and also has pointers to a number of **vm_area_struct** data structures.
Each **vm_area_struct** data structure describes the start and end of the area of virtual memory, the processes access rights to that memory and a set of operations for that memory. These operations are a set of routines that Linux must use when manipulating this area of virtual memory.

### Demand Paging
Once an executable image has been memory mapped into a processes virtual memory it can start to execute.
As only the very start of the image is physically pulled into memory it will soon access an area of virtual memory that is not yet in physical memory. When a process accesses a virtual address that does not have a valid page table entry, the processor will report a page fault to Linux.

The **page fault** describes the virtual address where the page fault occurred and the type of memory access that caused.

Linux must differentiate between pages that are in the swap file and those that are part of an executable image on a disk somewhere. It does this by using the page table entry for this faulting virtual address.

### The Linux Page Cache
The role of the Linux page cache is to speed up access to files on disk.
Memory mapped files are read a page at a time and these pages are stored in the page cache.
**page cache** consists of 1) the **page_hash_table**, 2) a vector of pointers to **mem_map_t** data structures.

Each file in Linux is identified by a VFS inode data structure (described in Chapter  filesystem-chapter) and each VFS inode is unique and fully describes one and only one file. The index into the page table is derived from the file's VFS inode and the offset into the file.

### Swapping Out and Discarding Pages
When physical memory becomes scarce the Linux memory management subsystem must attempt to free physical pages. This task falls to the **kernel swap daemon (kswapd)**.
The Kernel swap daemon (kswapd) is started by the kernel init process at startup time and sits waiting for the kernel swap timer to periodically expire.
Every time the timer expires, the swap daemon looks to see if the number of free pages in the system is getting too low. It uses two variables, free_pages_high and free_pages_low to decide if it should free some pages.
free pages > free_pages_high: sleep and wait until next interval
free pages < free_pages_low: the kernel swap daemon will try three ways to reduce the number of physical pages being used by the system:
    1) Reducing the size of the buffer and page caches,
    2) Swapping out System V shared memory pages,
    3) Swapping out and discarding pages.

#### Reducing the Size of the Page and Buffer Caches
#### Swapping Out and Discarding Pages
The swap daemon looks at each process in the system in turn to see if it is a good candidate for swapping.

### The Swap Cache
When swapping pages out to the swap files, Linux avoids writing pages if it does not have to.
Linux uses the **swap cache** to track these pages.
The swap cache is a list of page table entries, one per physical page in the system.
When Linux needs to swap a physical page out to a swap file it consults the swap cache and, if there is a valid entry for this page, it does not need to write the page out to the swap file. This is because the page in memory has not been modified since it was last read from the swap file.
The entries in the swap cache are page table entries for swapped out pages. They are marked as invalid but contain information which allow Linux to find the right swap file and the right page within that swap file.

### Swapping Pages In
Accessing a page of virtual memory that is not held in physical memory causes a page fault to occur. The page fault is the processor signalling the operating system that it cannot translate a virtual address into a physical one. In this case this is because the page table entry describing this page of virtual memory was marked as invalid when the page was swapped out. The processor cannot handle the virtual to physical address translation and so hands control back to the operating system describing as it does so the virtual address that faulted and the reason for the fault.
The generic page fault handling code looks for the page table entry for the faulting virtual address. If the page table entry it finds is for a swapped out page, Linux must swap the page back into physical memory.


## Processes
Linux kernal creates, manages, and deletes the processes in the system.

A program is a set of machine code instructions and data stored in an executable image on disk and is, as such, a passive entity;
A process can be thought of as a computer program in action.

It is the **scheduler** which chooses which is the most appropriate process to run next and Linux uses a number of **scheduling** strategies to ensure fairness.

### Linux Processes
Linux manages processes in the system.
Each process is represented by a **task_struct** data structure (task and process are terms that Linux uses interchangeably).
The **task** vector is an array of pointers to every task_struct data structure in the system.
This means that the maximum number of processes in the system is limited by the size of the task vector, by default it has 512 entries.
As processes are created, a new task_struct is allocated from system memory and added into the task vector. To make it easy to find, the current, running, process is pointed to by the **current** pointer.

As well as the normal type of process, Linux supports **real time processes**. These processes have to react very quickly to external events (hence the term ``real time'') and they are treated differently from normal user processes by the scheduler.

Although the task_struct data structure is quite large and complex, but its fields can be divided into a number of functional areas:
- State
    - Running: process is running or ready to run(waiting to be assigned to one of the system's CPUs)
    - Waiting: process is waiting for an event or for a resource.
        Linux differentiates two types of waiting process: interruptible vs. uninterruptible:
        - Interruptible processes can be interrupted by signals.
        - Uninterruptible processes are waiting directly on hardware conditions and cannot be interrupted under any circumstances.
    - Stopped: process has been stopped, usually by receiving a signal.
    - Zombie: process is halted, however, for some reason, still has a **task_struct** data structure in the task vector.

- Scheduling Info
    The scheduler needs this info in order to fairly decide which process in the system most deserves to run.

- Identifiers
    Every process in the system has a process identifier. It's not an index into the task vector. It is simply a number.
    Each Process also has User and Group identifiers. These are used to control the processes' access to the files and devices in the system.

- Inter-Process Communication
    Linux supports the classic Unix IPC mechanism of signals, pipes, semaphores, and also the System V IPC mechanism of shared memory, semaphores, and message queues.

- Links
    In a Linux system, every process has a parent process, except the initial process. New processes are not created, they are copied, or rather cloned from previous processes. Every task_struct representing a process keeps pointers to its parent process and to its siblings
    e.g. pstree
    init(1)-+-crontd(98)
            |-kerneld(18)
            `-syslogd(78)
    Additionally, all of the processes are held in a doubly linked list whose root is the **init** processes task_struct data structure.

- Times and Timers
    The kernel keeps track of process creation time as well as the CPU time during its lifetime. Each clock tick, the kernel updates the amount of time in **jiffies** that current process has spent in system and in user mode.
    Linux also supports process specific interval timers. Process can use system calls to set up timers to send signals to themselves when the timers expire. These timers can be single-shot or periodic timers.

- File System
    Processes can open and close files as they wish and the process task_struct contains pointers to descriptors for each open file as well as pointers to **two VFS inodes**.
    Each VFS inode uniquely describes a file or a directory within a file system and also provides a uniform interface to the underlying file systems.
    The first is to the root of the process (its home directory);
    The second is to its current or pwd directory.
    These two VFS inodes have their count fields incremented to show that one or more processes are referencing them. This is why you cannot delete the directory that a process has as its pwd directory set to, or for that matter one of its sub-directories.

- Virtual Memory
    Most processes have some virtual memory (kernel threads and daemons do not) and the Linux kernel must track how that virtual memory is mapped onto the system's physical memory.

- Processor Specific Context
    A process could be thought of as the sum total of the system's current state. Whenever a process is running, it is using the processor's registers, stacks and so on. This is the processes context and when a process is suspended, all of the CPU specific context must be saved in the task_struct for the process. When a process is restarted by the scheduler its context is restored from here.

#### Identifiers
Linux, like all Unix, uses user and group identifiers to check for access rights to files and images in the system.
There are four pairs of process and group identifiers held in a process's task_struct:
- uid and gid
    user id and group id of the user that the process is running on behalf of.
- effective uid and gid
    There are some programs which change the uid and gid from the executing process into their own, e.g. through setuid program. The kernel checks the effective uid and gid whenever it checks for privilege rights.
- file system uid and gid
    These are normally the same as the effective uid and gid and are used when checking file system access rights.
    They are needed for NFS mounted filesystems where the user mode NFS server needs to access files as if it were a particular process. In this case, only the file system uid and gid are changed (not the effective uid and gid).
- saved uid and gid
    These are mandated by the POSIX standard and are used by programs which change the processes' uid and gid via system calls.

#### Scheduling
All processes run partially in user mode and partially in system mode.
User mode has far less privileges than system mode. Each time a process makes a system call it swaps from user mode to system mode and continues executing. At this point, the kernal is executing on behalf of the process.
In Linux, processes do not preempt the current, running process, they cannot stop it from running so that they can run. Each process decides to relinquish the CPU when it has to wait for some system event. For example, a process may have to wait for a char to be read from a file. This waiting happens within the system call, in system mode; the process used a library function to open and read the file and then made system calls to read bytes from the open file. In this case, the waiting process will be suspended and another more deserving process will be chosen to run.

Linux uses a pre-emptive scheduling scheme. Each process is allowed to run for a small amount of time, 200ms, and when this time has expired, another process is selected to run. This small amount of time is known as **time-slice**.

A runnable process is one which is waiting only for CPU to run on.
For the scheduler to fairly allocate CPU time between the runnable processes, it keeps info in the task_struct for each process:
- policy
    scheduling policy. There are two types of Linux processes: normal and real-time. Real-time processes have a higher priority than all of the other processes.
    Real-time processes may have two types of policy: round-robin and FIFO.
- priority
    The amount of time-slices when a process is allowed to run.
- rt_priority
    Real-time priority.
- counter
    The amount of time (in jiffies) left that this process is allowed to run for. Initially set to priority and decremented each clock tick.

The scheduler runs from serverl places within the kernel.
e.g. it runs after putting the current process onto a wait queue, it may also runs at the end of a system call.
Each time the scheduler runs it does the following:
- kernel work
    The scheduler runs the bottom half handlers and processes the scheduler task queue.
- current process
- process selection
    The scheduler looks through the processes on the run queue looking for the most deserving process to run. real-time process has a higher weighting than ordinary process. The weight for a normal process is its counter but for a real-time process it is counter plus 1000.
- swap processes
    The swapping of process context takes place at the end of the scheduler. The context includes a snapshot of the machine state including program counter(PC), all of the processor's registers, page tables entries, etc.

#### Scheduling in Multiprocessor Systems

### Files
A Process's Files:
task\_struct: fs(->fs\_struct), files(->files\_struct)
fs\_struct: count, umask,\*tool, \*pwd
files\_struct: count, close\_on\_exec, open\_fs, fd[0]..fd[255](->file)
file: f\_mode, f\_inode, f\_op(->file op routines), etc.

There are two data structures that describe file system specific information for each process in the system.
1) **fs_struct** contains pointers to this process's VFS inodes and its umask. The umask is the default mode that new files will be created in, and it can be changed via system calls.
2) **files_struct** contains information about all of the files that this process is currently using.
   For each file descriptor(\*file):
   - f\_mode field describes what mode the file has been created in; read only, read and write or write only.
   - f\_pos holds the position in the file where the next read or write operation will occur.
   - f\_inode points at the VFS inode describing the file.
   - f\_ops is a pointer to a vector of routine addresses; one for each function that you might wish to perform on a file, one for each function that you might wish to perform on a file.

Every time a file is opened, one of the free file pointers in the files_struct is used to point to the new file structure. Linux processes expect three file descriptors to be open when they start. These are known as standard input, standard output and standard error and they are usually inherited from the creating parent process. All accesses to files are via standard system calls which pass or return file descriptors. These descriptors are indices into the process's fd vector, so standard input, standard output and standard error have file descriptors 0, 1 and 2. Each access to the file uses the file data structure's file operation routines to together with the VFS inode to achieve its needs.

### Virtual Memory
Linux uses a technique called **demand paging** where the virtual memory of a process is brought into physical memory only when a process attempts to use it.
Instead of loading the code and data into physical memory straight away, the Linux kernel alters the process's page table, marking the virtual areas as existing but not in memory. When the process attempts to acccess the code or data the system hardware will generate a page fault and hand control to the Linux kernel to fix things up.

The Linux kernel needs to manage all of these areas of virtual memory and the contents of each process's virtual memory is described by a **mm_struct** data structure pointed at from its **task_struct**.
The process's **mm_struct** data structure also contains information about the loaded executable image and a pointer to the process's page tables. It contains pointers to a list of **vm_area_struct** data structures, each representing an area of virtual memory within this process.
task_struct -> mm_struct -> vm_area_struct -> procoess virtual memory (data)
                        `-> vm_area_struct -> procoess virtual memory (code)

This linked list is in ascending virtual memory order.
To speed up this access, Linux also arranges the vm_area_struct data structures into an AVL (Adelson-Velskii and Landis) tree.

When a process allocates virtual memory, Linux does not actually reserve physical memory for the process. Instead, it describes the virtual memory by creating a new vm_area_struct data structure. This is linked into the process's list of virtual memory. When the process attempts to write to a virtual address within that new virtual memory region then the system will page fault. The processor will attempt to decode the virtual address, but as there are no Page Table Entries for any of this memory, it will give up and raise a page fault exception, leaving the Linux kernel to fix things up. Linux looks to see if the virtual address referenced is in the current process's virtual address space. If it is, Linux creates the appropriate PTEs and allocates a physical page of memory for this process. The code or data may need to be brought into that physical page from the filesystem or from the swap disk.

### Creating a Process
The init kernel thread or process has a process identifier of 1 as it is the system's first real process. It does some initial setting up of the system (such as opening the system console and mounting the root file system) and then executes the system initialization program.

When cloning processes Linux allows the two processes to share resources rather than have two separate copies. This applies to the process's files, signal handlers and virtual memory. Cloning a process's virtual memory is through 'copy on write'. When one of the processes attempts to write to this virtual memory a page fault will occur. It is at this point that Linux will make a copy of the memory and fix up the two processes' page tables and virtual memory data structures.

### Times and Timers
A process can use these timers to send itself various signals each time that they expire. Three sorts of interval timers are supported:
- Real
    This timer ticks in real time, and when the timer has expired, the process is sent a SIGALRM signal.
- Virtual
    This timer only ticks when the process is running and when it expires it sends a SIGVTALRM signal.
- Profile
    This timer ticks both when the process is running and when the system is executing on behalf of the process itself. SIGPROF is signalled when it expires.

### Executing Programs
In Linux, as in Unix TM, programs and commands are normally executed by a **command interpreter**. A command interpreter is a user process like any other process and is called a **shell**.

There are many shells in Linux, some of the most popular are **sh**, **bash** and **tcsh**.
For each command entered, the shell searches the directories in the **process's search path**, held in the **PATH** environment variable, for an executable image with a matching name.

Normally the shell waits for the command to complete, or rather for the child process to exit. You can cause the shell to run again by pushing the child process to the background by typing **control-Z**, which causes a **SIGSTOP** signal to be sent to the child process, stopping it. You then use the shell command **bg** to push it into a background, the shell sends it a **SIGCONT** signal to restart it.

SIGSTOP tells a process to “hold on” and SIGCONT tells a process to “pick up where you left off”. This can work really well for rsync jobs since you can pause the job, clear up some space on the destination device, and then resume the job. The source rsync process just thinks that the destination rsync process is taking a long time to respond.

#### ELF
Linux binary formats.
##### ELF Shared Libraries
A dynamically linked image, on the other hand, does not contain all of the code and data required to run.
Linux uses several dynamic linkers, ld.so.1, libc.so.1 and ld-linux.so.1, all to be found in /lib. The libraries contain commonly used code such as language subroutines. Without dynamic linking, all programs would need their own copy of the these libraries and would need far more disk space and virtual memory. In dynamic linking, information is included in the ELF image's tables for every library routine referenced. The information indicates to the dynamic linker how to locate the library routine and link it into the program's address space.

#### Script Files
Script files are executables that need an interpreter to run them.
Linux uses the standard Unux TM convention of having the first line of a script file contain the name of the interpreter. So, a typical script file would start:
#!/usr/bin/perl
The script binary loader tries to find the intepreter for the script.

## Interprocess Communication Mechanisms (IPC)
Processes communicate with each other and with the kernel to coordinate their activities. Common IPC includes Signals, Pipes, Sockets, System V IPC, etc.

### Signals
They are used to signal asynchronous events to one or more processes.
A signal could be generated by a keyboard interrupt or an error condition such as the process attempting to access a non-existent location in its virtual memory.
Signals are also used by the shells to signal job control commands to their child processes.

List a system's set of signals:
$ kill -l

Processes can choose to ignore most of the signals that are generated, with two notable exceptions:
- neither the SIGSTOP signal which causes a process to halt its execution,
- nor the SIGKILL signal which causes a process to exit can be ignored.
Otherwise though, a process can choose just how it wants to handle the various signals.
Processes can block the signals and, if they do not block them, they can either choose to handle them themselves or allow the kernel to handle them. If the kernel handles the signals, it will do the default actions required for this signal.
Signals have no inherent relative priorities. If two signals are generated for a process at the same time then they may be presented to the process or handled in any order.
Also there is no mechanism for handling multiple signals of the same kind. There is no way that a process can tell if it received 1 or 42 SIGCONT signals.

Linux implements signals using information stored in the task_struct for the process.
The number of supported signals is limited to the word size of the processor. Processes with a word size of 32 bits can have 32 signals whereas 64 bit processors have up to 64 signals.
The currently pending signals are kept in the **signal field** with a mask of blocked signals held in **blocked**.
Linux also holds information about how each process handles every possible signal and this is held in an array of **sigaction** data structures pointed at by the **task_struct** for each process. **sigaction** can be 1) the address of a signal handle routine, 2) 'IGNORE' that tells Linux to ignore it, or 3) 'DEFAULT' that let the kernal handle it.

Not every process in the system can send signals to every other process, the kernel can and super users can. Normal processes can only send signals to processes with the same uid and gid or to processes in the same process group.

### Pipes
process1:file:inode --> tmp VFS inode <-- process2:file:inode
             :f_op=write     ||                   :f_op=read
                             \/
                       shared data page

In Linux, a pipe is implemented using two file data structures which both point at the same temporary VFS inode which itself points at a physical page within memory.
Linux must **synchronize access to the pipe**. It must make sure that the reader and the writer of the pipe are in step and to do this it uses **locks**, **wait queues** and **signals**.

If there is enough room to write all of the bytes into the pipe and, so long as the pipe is not locked by its reader, Linux locks it for the writer and copies the bytes to be written from the process's address space into the shared data page. If the pipe is locked by the reader or if there is not enough room for the data then the current process is made to sleep on the pipe inode's wait queue and the scheduler is called so that another process can run. It is interruptible, so it can receive signals and it will be woken by the reader when there is enough room for the write data or when the pipe is unlocked. When the data has been written, the pipe's VFS inode is unlocked and any waiting readers sleeping on the inode's wait queue will themselves be woken up.

Processes are allowed to do non-blocking reads (it depends on the mode in which they opened the file or pipe) and, in this case, if there is no data to be read or if the pipe is locked, an error will be returned. This means that the process can continue to run.
The alternative is to wait on the pipe inode's wait queue until the write process has finished.
When both processes have finished with the pipe, the pipe inode is discarded along with the shared data page.

Linux also supports **named pipes**, also known as **FIFOs** because pipes operate on a First In, First Out principle. The first data written into the pipe is the first data read from the pipe. Unlike pipes, FIFOs are not temporary objects, they are entities in the file system and can be created using the mkfifo command. Processes are free to use a FIFO so long as they have appropriate access rights to it. The way that FIFOs are opened is a little different from pipes. A pipe (its two file data structures, its VFS inode and the shared data page) is created in one go whereas a FIFO already exists and is opened and closed by its users. Linux must handle readers opening the FIFO before writers open it as well as readers reading before any writers have written to it. That aside, FIFOs are handled almost exactly the same way as pipes and they use the same data structures and operations.

### Sockets

#### System V IPC Mechanisms
Linux supports three types of interprocess communication mechanisms that first appeared in Unix TM System V (1983). These are:
- message queues,
- semaphores,
- shared memory.
These System V IPC mechanisms all share common authentication methods.

All Linux data structures representing System V IPC objects in the system include an **ipc_perm** structure which contains the owner and creator process's user and group identifiers, the access mode for this object (owner, group and other) and the IPC object's key. The key is used as a way of locating the System V IPC object's reference identifier. Two sets of keys are supported: public and private.

#### Message Queues
Message queues allow one or more processes to write messages, which will be read by one or more reading processes.

Linux maintains a list of message queues, the **msgque** vector; each element of which points to a **msqid_ds** data structure that fully describes the message queue. When message queues are created a new msqid_ds data structure is allocated from system memory and inserted into the vector.

#### Semaphores
In its simplest form a semaphore is a location in memory whose value can be tested and set by more than one process. The test and set operation is, so far as each process is concerned, uninterruptible or atomic; once started nothing can stop it. The result of the test and set operation is the addition of the current value of the semaphore and the set value, which can be positive or negative. Depending on the result of the test and set operation one process may have to sleep until the semphore's value is changed by another process. Semaphores can be used to implement critical regions, areas of critical code that only one process at a time should be executing.

Say you had many cooperating processes reading records from and writing records to a single data file. You would want that file access to be strictly coordinated. You could use a semaphore with an initial value of 1 and, around the file operating code, put two semaphore operations, the first to test and decrement the semaphore's value and the second to test and increment it. The first process to access the file would try to decrement the semaphore's value and it would succeed, the semaphore's value now being 0. This process can now go ahead and use the data file but if another process wishing to use it now tries to decrement the semaphore's value it would fail as the result would be -1. That process will be suspended until the first process has finished with the data file. When the first process has finished with the data file it will increment the semaphore's value, making it 1 again. Now the waiting process can be woken and this time its attempt to increment the semaphore will succeed.

semaphore = 1
process1 access file
    test(semaphore) >= 0
    process1 holds the file
    semaphore--
process2 acess file, with blocking flag
    test(semaphore) >= 0
    process2 go into semaphore waiting queue and blocked
process3 acess file, with non-blocking flag
    test(semaphore) >= 0
    process3 will fail to set semaphore and process returns
if process1 crashed somehow, kernel will undo process1's set operation to semaphore.

#### Shared Memory
Shared memory allows one or more processes to communicate via memory that appears in all of their virtual address spaces. The pages of the virtual memory is referenced by page table entries in each of the sharing processes' page tables. It does not have to be at the same address in all of the processes' virtual memory. As with all System V IPC objects, access to shared memory areas is controlled via keys and access rights checking. Once the memory is being shared, there are no checks on how the processes are using it. They must rely on other mechanisms, for example System V semaphores, to synchronize access to the memory.

shmid_ds:attaches->vm_area_struct
When process no longer need access to shared memory, it deattaches from it.


### Peripheral Component Interconnect (PCI)
PCI is a standard that describes how to connect the peripheral components of a system together in a structured and controlled way. The standard describes the way that the system components are electrically connected and the way that they should behave. This chapter looks at how the Linux kernel initializes the system's PCI buses and devices.

Peripheral devices have their own memory spaces. The CPU can access these spaces, but access by the devices into the system's memory is very strictly controlled using DMA (Direct Memory Access) channels.
ISA devices have access to two address spaces, ISA I/O (Input/Output) and ISA memory.
PCI has three; PCI I/O, PCI Memory and PCI Configuration space.
All of these address spaces are also accessible by the CPU with the the PCI I/O and PCI Memory address spaces being used by the device drivers and the PCI Configuration space being used by the PCI initialization code within the Linux kernel.

#### PCI Address Spaces

#### PCI Configuration Headers

#### Linux PCI Initialization
The PCI initialisation code in Linux is broken into three logical parts:
1) PCI Device Driver
This pseudo-device driver searches the PCI system starting at Bus 0 and locates all PCI devices and bridges in the system. It builds a linked list of data structures describing the topology of the system. Additionally, it numbers all of the bridges that it finds.
2) PCI BIOS
This software layer provides the services described in bib-pci-bios-specification.
3) PCI Fixup
System specific fixup code tidies up the system specific loose ends of PCI initialization.


## Interrupts and Interrupt Handling
Whilst the kernel has generic mechanisms and interfaces for handling interrupts, most of the interrupt handling details are architecture specific.

Some of the physical pins of the CPU are wired such that changing the voltage (for example changing it from +5v to -5v) causes the CPU to stop what it is doing and to start executing special code to handle the interruption; the interrupt handling code. One of these pins might be connected to an interval timer and receive an interrupt every 1000th of a second, others may be connected to the other devices in the system, such as the SCSI controller.

Systems often use an interrupt controller to group the device interrupts together before passing on the signal to a single interrupt pin on the CPU. This saves interrupt pins on the CPU and also gives flexibility when designing systems. The interrupt controller has mask and status registers that control the interrupts. Setting the bits in the mask register enables and disables interrupts and the status register returns the currently active interrupts in the system.

Each system has its own interrupt routing mechanisms and the operating system must be flexible enough to cope.

When a hardware interrupt occurs the CPU stops executing the instructions that it was executing and jumps to a location in memory that either contains the interrupt handling code or an instruction branching to the interrupt handling code. This code usually operates in a special mode for the CPU, interrupt mode, and, normally, no other interrupts can happen in this mode. There are exceptions though; some CPUs rank the interrupts in priority and higher level interrupts may happen. This means that the first level interrupt handling code must be very carefully written and it often has its own stack, which it uses to store the CPU's execution state (all of the CPU's normal registers and context) before it goes off and handles the interrupt. Some CPUs have a special set of registers that only exist in interrupt mode, and the interrupt code can use these registers to do most of the context saving it needs to do.

When the interrupt has been handled, the CPU's state is restored and the interrupt is dismissed. The CPU will then continue to doing whatever it was doing before being interrupted. It is important that the interrupt processing code is as efficient as possible and that the operating system does not block interrupts too often or for too long.

### Programmable Interrupt Controllers
...


## Device Drivers
One of the purposes of an operating system is to hide the peculiarities of the system's hardware devices from its users. For example the Virtual File System presents a uniform view of the mounted filesystems irrespective of the underlying physical devices.

The CPU is not the only intelligent device in the system, every physical device has its own hardware controller. The keyboard, mouse and serial ports are controlled by a SuperIO chip, the IDE disks by an IDE controller, SCSI disks by a SCSI controller and so on. Each hardware controller has its own control and status registers (CSRs) and these differ between devices.

The software that handles or manages a hardware controller is known as a device driver. The Linux kernel device drivers are, essentially, a shared library of privileged, memory resident, low level hardware handling routines. It is Linux's device drivers that handle the peculiarities of the devices they are managing.

One of the basic features of  is that it abstracts the handling of devices. All hardware devices look like regular files; they can be opened, closed, read and written using the same, standard, system calls that are used to manipulate files. Every device in the system is represented by a device special file, for example the first IDE disk in the system is represented by /dev/hda. For block (disk) and character devices, these device special files are created by the mknod command and they describe the device using major and minor device numbers. Network devices are also represented by device special files but they are created by Linux as it finds and initializes the network controllers in the system. All devices controlled by the same device driver have a common major device number. 

Linux supports three types of hardware device: 1) character, 2) block and 3) network.
- Character devices are read and written directly without buffering, for example the system's serial ports /dev/cua0 and /dev/cua1.
- Block devices can only be written to and read from in multiples of the block size, typically 512 or 1024 bytes. Block devices are accessed via the buffer cache and may be randomly accessed, that is to say, any block can be read or written no matter where it is on the device. Block devices can be accessed via their device special file but more commonly they are accessed via the file system. Only a block device can support a mounted file system.
- Network devices are accessed via the BSD socket interface and the networking subsytems described in the Networking chapter (Chapter  network-chapter).

There are many different device drivers in the Linux kernel (that is one of Linux's strengths) but they all share some common attributes:
- kernel code
Device drivers are part of the kernel and, like other code within the kernel, if they go wrong they can seriously damage the system. A badly written driver may even crash the system, possibly corrupting file systems and losing data,
- kernel interfaces
Device drivers must provide a standard interface to the Linux kernel or to the subsystem that they are part of. For example, the terminal driver provides a file I/O interface to the Linux kernel and a SCSI device driver provides a SCSI device interface to the SCSI subsystem which, in turn, provides both file I/O and buffer cache interfaces to the kernel.
- kernel mechanisms and services
Device drivers make use of standard kernel services such as memory allocation, interrupt delivery and wait queues to operate,
- Loadable
Most of the Linux device drivers can be loaded on demand as kernel modules when they are needed and unloaded when they are no longer being used. This makes the kernel very adaptable and efficient with the system's resources,
- Configurable
Linux device drivers can be built into the kernel. Which devices are built is configurable when the kernel is compiled,
- Dynamic
As the system boots and each device driver is initialized it looks for the hardware devices that it is controlling. It does not matter if the device being controlled by a particular device driver does not exist. In this case the device driver is simply redundant and causes no harm apart from occupying a little of the system's memory.

### Polling and Interrupts
Each time the device is given a command, for example ``move the read head to sector 42 of the floppy disk'' the device driver has a choice as to how it finds out that the command has completed. The device drivers can either **poll** the device or they can use **interrupts**.

Polling the device usually means reading its status register every so often until the device's status changes to indicate that it has completed the request. As a device driver is part of the kernel it would be disasterous if a driver were to poll as nothing else in the kernel would run until the device had completed the request. Instead polling device drivers use system timers to have the kernel call a routine within the device driver at some later time. This timer routine would check the status of the command and this is exactly how Linux's floppy driver works. Polling by means of timers is at best approximate, a much more efficient method is to use interrupts.

An interrupt driven device driver is one where the hardware device being controlled will raise a hardware interrupt whenever it needs to be serviced. For example, an ethernet device driver would interrupt whenever it receives an ethernet packet from the network. The Linux kernel needs to be able to deliver the interrupt from the hardware device to the correct device driver. This is achieved by the device driver registering its usage of the interrupt with the kernel. It registers the address of an interrupt handling routine and the interrupt number that it wishes to own. You can see which interrupts are being used by the device drivers, as well as how many of each type of interrupts there have been, by looking at /proc/interrupts.

How an interrupt is delivered to the CPU itself is architecture dependent but on most architectures the interrupt is delivered in a special mode that stops other interrupts from happening in the system. A device driver should do as little as possible in its interrupt handling routine so that the Linux kernel can dismiss the interrupt and return to what it was doing before it was interrupted. Device drivers that need to do a lot of work as a result of receiving an interrupt can use the kernel's bottom half handlers or task queues to queue routines to be called later on.

### Direct Memory Access (DMA)
A DMA controller allows devices to transfer data to or from the system's memory without the intervention of the processor. A PC's ISA DMA controller has 8 DMA channels of which 7 are available for use by the device drivers. Each DMA channel has associated with it a 16 bit address register and a 16 bit count register. To initiate a data transfer the device driver sets up the DMA channel's address and count registers together with the direction of the data transfer, read or write. It then tells the device that it may start the DMA when it wishes. When the transfer is complete the device interrupts the PC. Whilst the transfer is taking place the CPU is free to do other things.

### Memory

### Hard Disks
A lot of Linux systems have a single disk with three partitions; one containing a DOS filesystem, another an EXT2 filesystem and a third for the swap partition.

During initialization Linux maps the topology of the hard disks in the system. It finds out how many hard disks there are and of what type. Additionally, Linux discovers how the individual disks have been partitioned. This is all represented by a list of gendisk data structures pointed at by the gendisk_head list pointer.

#### IDE Disks (Integrated Disk Electronic Disks)
The most common disks used in Linux systems today are Integrated Disk Electronic or IDE disks. IDE is a disk interface rather than an I/O bus like SCSI. Each IDE controller can support up to two disks, one the master disk and the other the slave disk.

#### SCSI Disks(Small Computer System Interface Disks)
The SCSI (Small Computer System Interface) bus is an efficient peer-to-peer data bus that supports up to eight devices per bus, including one or more hosts.

### Network Devices
A network device is, so far as Linux's network subsystem is concerned, an entity that sends and receives packets of data. This is normally a physical device such as an ethernet card. Some network devices though are software only such as the loopback device which is used for sending data to yourself. Each network device is represented by a device data structure. Network device drivers register the devices that they control with Linux during network initialization at kernel boot time. The device data structure contains information about the device and the addresses of functions that allow the various supported network protocols to use the device's services. These functions are mostly concerned with transmitting data using the network device. The device uses standard networking support mechanisms to pass received data up to the appropriate protocol layer. All network data (packets) transmitted and received are represented by sk_buff data structures, these are flexible data structures that allow network protocol headers to be easily added and removed. How the network protocol layers use the network devices, how they pass data back and forth using sk_buff data structures is described in detail in the Networks chapter (Chapter  networks-chapter). This chapter concentrates on the device data structure and on how network devices are discovered and initialized.

The device data structure contains information about the network device:
- Name
    Some common network devices are:
    /dev/ethN - Ethernet devices
    /dev/slN - SLIP devices
    /dev/pppN - PPP devices
    /dev/loopback - Loopback devices
- Bus Information
- Interface Flags
    These describe the characteristics and abilities of the network device:
    IFF_UPInterface is up and running,
    ...
- Protocol Information
    Each device describes how it may be used by the network protocool layers:
    - mtu
    The size of the largest packet that this network can transmit not including any link layer headers that it needs to add. This maximum is used by the protocol layers, for example IP, to select suitable packet sizes to send.
    - Family
    The family indicates the protocol family that the device can support.   The family for all Linux network devices is **AF_INET**, the Internet address family.
    - Type
    The hardware interface type describes the media that this network device is attached to. There are many different types of media that Linux network devices support. These include Ethernet, X.25, Token Ring, Slip, PPP and Apple Localtalk.
    - Addresses
    The device data structure holds a number of addresses that are relevent to this network device, including its IP addresses.
    - Packet Queue
    - Support Functions

####  Initializing Network Devices
Network device drivers can, like other Linux device drivers, be built into the Linux kernel. Each potential network device is represented by a device data structure within the network device list pointed at by dev_base list pointer.


## The File system
This chapter describes how the Linux kernel maintains the files in the file systems that it supports. It describes the Virtual File System (VFS) and explains how the Linux kernel's real file systems are supported.

One of the most important features of Linux is its support for many different file systems. This makes it very flexible and well able to coexist with many other operating systems. At the time of writing, Linux supports 15 file systems; ext, ext2, xia, minix, umsdos, msdos, vfat, proc, smb, ncp, iso9660, sysv, hpfs, affs and ufs, and no doubt, over time more will be added.

An important development took place when the EXT file system was added into Linux.
The real file systems were separated from the operating system and system services by an interface layer known as the Virtual File System (VFS).

### The Second Extended File system (EXT2)
The EXT2 file system, like a lot of the file systems, is built on the premise that the data held in files is kept in data blocks. These data blocks are all of the same length and, although that length can vary between different EXT2 file systems the block size of a particular EXT2 file system is set when it is created (using mke2fs). Every file's size is rounded up to an integral number of blocks. If the block size is 1024 bytes, then a file of 1025 bytes will occupy two 1024 byte blocks. Unfortunately this means that on average you waste half a block per file. Usually in computing you trade off CPU usage for memory and disk space utilisation.
EXT2 defines the file system topology by describing each file in the system with an inode data structure. An inode describes which blocks the data within a file occupies as well as the access rights of the file, the file's modification times and the type of the file. Every file in the EXT2 file system is described by a single inode and each inode has a single unique number identifying it. The inodes for the file system are all kept together in inode tables. EXT2 directories are simply special files (themselves described by inodes) which contain pointers to the inodes of their directory entries.

Physical Layout of the EXT2 File system:
Block Group 0, ..., Block Group N
||
\/
Super Block, Group Descriptor, Block Bitmap, Inode Bitmap, Inode Table, Data Blocks.

#### The EXT2 Inode
In the EXT2 file system, the inode is the basic building block; every file and directory in the file system is described by one and only one inode. The EXT2 inodes for each Block Group are kept in the inode table together with a bitmap that allows the system to keep track of allocated and unallocated inodes.
An EXT2 inode, amongst other information, it contains the following fields:
- mode
    This holds two pieces of information; what this inode describes and the permissions that users have to it.
For EXT2, an inode can describe one of file, directory, symbolic link, block device, character device or FIFO.
- Owner Information
    The user and group identifiers of the owners of this file or directory.
- Size
    The size of the file in bytes,
- Timestamps
    The time that the inode was created and the last time that it was modified,
- Datablocks
    Pointers to the blocks that contain the data that this inode is describing. The first twelve are pointers to the physical blocks containing the data described by this inode and the last three pointers contain more and more levels of indirection. For example, the double indirect blocks pointer points at a block of pointers to blocks of pointers to data blocks. This means that files less than or equal to twelve data blocks in length are more quickly accessed than larger files.

#### The EXT2 Superblock
The Superblock contains a description of the basic size and shape of this file system. The information within it allows the file system manager to use and maintain the file system. Usually only the Superblock in Block Group 0 is read when the file system is mounted but each Block Group contains a duplicate copy in case of file system corruption. Amongst other information it holds the:

- Magic Number
    This allows the mounting software to check that this is indeed the Superblock for an EXT2 file system. For the current version of EXT2 this is 0xEF53.
- Revision Level
    The major and minor revision levels allow the mounting code to determine whether or not this file system supports features that are only available in particular revisions of the file system. There are also feature compatibility fields which help the mounting code to determine which new features can safely be used on this file system,
- Mount Count and Maximum Mount Count
    Together these allow the system to determine if the file system should be fully checked. The mount count is incremented each time the file system is mounted and when it equals the maximum mount count the warning message ``maximal mount count reached, running e2fsck is recommended'' is displayed,
- Block Group Number
    The Block Group number that holds this copy of the Superblock,
- Block Size
    The size of the block for this file system in bytes, for example 1024 bytes,
- Blocks per Group
    The number of blocks in a group. Like the block size this is fixed when the file system is created,
- Free Blocks
    The number of free blocks in the file system,
- Free Inodes
    The number of free Inodes in the file system,
- First Inode
    This is the inode number of the first inode in the file system. The first inode in an EXT2 root file system would be the directory entry for the '/' directory.

#### The EXT2 Group Descriptor
Each Block Group has a data structure describing it. Like the Superblock, all the group descriptors for all of the Block Groups are duplicated in each Block Group in case of file system corruption.

Each Group Descriptor contains the following information:
- Blocks Bitmap
    The block number of the block allocation bitmap for this Block Group. This is used during block allocation and deallocation,
- Inode Bitmap
    The block number of the inode allocation bitmap for this Block Group. This is used during inode allocation and deallocation,
- Inode Table
    The block number of the starting block for the inode table for this Block Group. Each inode is represented by the EXT2 inode data structure described below.
- Free blocks count, Free Inodes count, Used directory count

#### EXT2 Directories
In the EXT2 file system, directories are special files that are used to create and hold access paths to the files in the file system.

A directory file is a list of directory entries, each one containing the following information:
- inode
    The inode for this directory entry. This is an index into the array of inodes held in the Inode Table of the Block Group.
- name length
    The length of this directory entry in bytes,
- name
    The name of this directory entry.

The first two entries for every directory are always the standard ``.'' and ``..'' entries meaning ``this directory'' and ``the parent directory'' respectively.

#### Finding a File in an EXT2 File System
To find the inode representing this file within an EXT2 file system the system must parse the filename a directory at a time until we get to the file itself.

#### Changing the Size of a File in an EXT2 File System


### The Virtual File System (VFS)
The figure shows the relationship between the Linux kernel's Virtual File System and it's real file systems. The virtual file system must manage all of the different file systems that are mounted at any given time. To do this it maintains data structures that describe the whole (virtual) file system and the real, mounted, file systems.

          VFS  --  Inode Cache
         /  \  `-  Directory Cache
        /    \
     MINIX  EXT2
        \    /
        Buffer Cache
          |
        Disk Drivers

Rather confusingly, the VFS describes the system's files in terms of superblocks and inodes in much the same way as the EXT2 file system uses superblocks and inodes. Like the EXT2 inodes, the VFS inodes describe files and directories within the system; the contents and topology of the Virtual File System. From now on, to avoid confusion, I will write about VFS inodes and VFS superblocks to distinquish them from EXT2 inodes and superblocks.

As each file system is initialised, it registers itself with the VFS. This happens as the operating system initialises itself at system boot time. The real file systems are either built into the kernel itself or are built as loadable modules.

As the system's processes access directories and files, system routines are called that traverse the VFS inodes in the system.

For example, typing ls for a directory or cat for a file cause the the Virtual File System to search through the VFS inodes that represent the file system. As every file and directory on the system is represented by a VFS inode, then a number of inodes will be being repeatedly accessed. These inodes are kept in the inode cache which makes access to them quicker.
The VFS also keeps a cache of directory lookups so that the inodes for frequently used directories can be quickly found.

All of the Linux file systems use a common buffer cache to cache data buffers from the underlying devices to help speed up access by all of the file systems to the physical devices holding the file systems.
As blocks are read by the file systems they are saved in the global buffer cache shared by all of the file systems and the Linux kernel. Buffers within it are identified by their block number and a unique identifier for the device that read it.
Some devices support read ahead where data blocks are speculatively read just in case they are needed.

#### The VFS Superblock
Every mounted file system is represented by a VFS superblock; amongst other information, the VFS superblock contains the:
- Device
    This is the device identifier for the block device that this file system is contained in. For example, /dev/hda1, the first IDE hard disk in the system has a device identifier of 0x301,
- Inode pointers
    The mounted inode pointer points at the first inode in this file system. The covered inode pointer points at the inode representing the directory that this file system is mounted on. The root file system's VFS superblock does not have a covered pointer,
- Blocksize
    The block size in bytes of this file system, for example 1024 bytes,
- Superblock operations
    A pointer to a set of superblock routines for this file system. Amongst other things, these routines are used by the VFS to read and write inodes and superblocks.
- File System type
    A pointer to the mounted file system's file_system_type data structure,
- File System specific
    A pointer to information needed by this file system,

#### The VFS Inode
Like the EXT2 file system, every file, directory and so on in the VFS is represented by one and only one VFS inode.

The information in each VFS inode is built from information in the underlying file system by file system specific routines. VFS inodes exist only in the kernel's memory and are kept in the VFS inode cache as long as they are useful to the system. Amongst other information, VFS inodes contain the following fields:
- device
    This is the device identifer of the device holding the file or whatever that this VFS inode represents,
- inode number
    This is the number of the inode and is unique within this file system. The combination of device and inode number is unique within the Virtual File System,
- mode
    Like EXT2 this field describes what this VFS inode represents as well as access rights to it,
- user ids
    The owner identifiers,
- times
    The creation, modification and write times,
- block size
    The size of a block for this file in bytes, for example 1024 bytes,
- inode operations
    A pointer to a block of routine addresses. These routines are specific to the file system and they perform operations for this inode, for example, truncate the file that is represented by this inode.
- count
    The number of system components currently using this VFS inode. A count of zero means that the inode is free to be discarded or reused,
- lock
    This field is used to lock the VFS inode, for example, when it is being read from the file system,
- dirty
    Indicates whether this VFS inode has been written to, if so the underlying file system will need modifying,
- file system specific information

#### Registering the File Systems
When you build the Linux kernel you are asked if you want each of the supported file systems. When the kernel is built, the file system startup code contains calls to the initialisation routines of all of the built in file systems.

Linux file systems may also be built as modules and, in this case, they may be demand loaded as they are needed or loaded by hand using insmod. Whenever a file system module is loaded it registers itself with the kernel and unregisters itself when it is unloaded. Each file system's initialisation routine registers itself with the Virtual File System and is represented by a file_system_type data structure which contains the name of the file system and a pointer to its VFS superblock read routine.
Each **file_system_type** data structure contains the following information:
- Superblock read routine
    This routine is called by the VFS when an instance of the file system is mounted,
- File System name
    The name of this file system, for example ext2,
- Device needed
    Does this file system need a device to support? Not all file system need a device to hold them. The /proc file system, for example, does not require a block device,

You can see which file systems are registered by looking in at /proc/filesystems. For example:
$ cat /proc/filesystems
      ext2
nodev proc
      iso9660

#### Mounting a File System
$ mount -t iso9660 -o ro /dev/cdrom /mnt/cdrom

This mount command will pass the kernel three pieces of information;
1) the name of the file system,
2) the physical block device that contains the file system,
3) where in the existing file system topology the new file system is to be mounted.

Virtual File System will first try to find the file system, it searches through the list of known file systems by looking at each **file_system_type** data structure in the list pointed at by **file_systems**.

Each mounted file system is described by a **vfsmount** data structure. These are queued on a list pointed at by **vfsmntlist**.

#### Finding a File in the Virtual File System
To find the VFS inode of a file in the Virtual File System, VFS must resolve the name a directory at a time, looking up the VFS inode representing each of the intermediate directories in the name. Each directory lookup involves calling the file system specific lookup whose address is held in the VFS inode representing the parent directory. This works because we always have the VFS inode of the root of each file system available and pointed at by the VFS superblock for that system. Each time an inode is looked up by the real file system it checks the directory cache for the directory. If there is no entry in the directory cache, the real file system gets the VFS inode either from the underlying file system or from the inode cache.

#### Creating a File in the Virtual File System

#### Unmounting a File System
A file system cannot be unmounted if something in the system is using one of its files. So, for example, you cannot umount /mnt/cdrom if a process is using that directory or any of its children. If anything is using the file system to be unmounted there may be VFS inodes from it in the VFS inode cache, and the code checks for this by looking through the list of inodes looking for inodes owned by the device that this file system occupies. If the VFS superblock for the mounted file system is dirty, that is it has been modified, then it must be written back to the file system on disk. Once it has been written to disk, the memory occupied by the VFS superblock is returned to the kernel's free pool of memory. Finally the vfsmount data structure for this mount is unlinked from vfsmntlist and freed.

#### The VFS Inode Cache
The VFS inode cache is implmented as a hash table whose entries are pointers to lists of VFS inodes that have the same hash value. The hash value of an inode is calculated from its inode number and from the device identifier for the underlying physical device containing the file system. Whenever the Virtual File System needs to access an inode, it first looks in the VFS inode cache. To find an inode in the cache, the system first calculates its hash value and then uses it as an index into the inode hash table. This gives it a pointer to a list of inodes with the same hash value. It then reads each inode in turn until it finds one with both the same inode number and the same device identifier as the one that it is searching for.

However the new VFS inode is found, a file system specific routine must be called to fill it out from information read from the underlying real file system. Whilst it is being filled out, the new VFS inode has a usage count of one and is locked so that nothing else accesses it until it contains valid information.

To get the VFS inode that is actually needed, the file system may need to access several other inodes. This happens when you read a directory; only the inode for the final directory is needed but the inodes for the intermediate directories must also be read. As the VFS inode cache is used and filled up, the less used inodes will be discarded and the more used inodes will remain in the cache.

#### The Directory Cache
To speed up accesses to commonly used directories, the VFS maintains a cache of directory entries.

### The Buffer Cache
This cache is shared between all of the physical block devices; at any one time there are many block buffers in the cache, belonging to any one of the system's block devices and often in many different states. If valid data is available from the buffer cache this saves the system an access to a physical device. Any block buffer that has been used to read data from a block device or to write data to it goes into the buffer cache. Over time it may be removed from the cache to make way for a more deserving buffer or it may remain in the cache as it is frequently accessed.

Block buffers within the cache are uniquely identfied by the owning device identifier and the block number of the buffer.
When they are in the buffer cache they are also queued onto Least Recently Used (LRU) lists. There is an LRU list for each buffer type and these are used by the system to perform work on buffers of a type, for example, writing buffers with new data in them out to disk.
The buffer's type reflects its state and Linux currently supports the following types:
- clean
    Unused, new buffers,
- locked
    Buffers that are locked, waiting to be written,
- dirty
    Dirty buffers. These contain new, valid data, and will be written but so far have not been scheduled to write,
- shared
    Shared buffers,
- unshared
    Buffers that were once shared but which are now not shared,

kernel daemon to perform a lot of housekeeping duties on the cache but some happen automatically as a result of the cache being used.

#### The **bdflush** Kernel Daemon
The bdflush kernel daemon is a simple kernel daemon that provides a dynamic response to the system having too many dirty buffers; buffers that contain data that must be written out to disk at some time.
It is started as a kernel thread at system startup time and, rather confusingly, it calls itself ``kflushd'' and that is the name that you will see if you use the ps command to show the processes in the system. Mostly this daemon sleeps waiting for the number of dirty buffers in the system to grow too large. As buffers are allocated and discarded the number of dirty buffers in the system is checked. If there are too many as a percentage of the total number of buffers in the system then bdflush is woken up. The default threshold is 60% but, if the system is desperate for buffers, bdflush will be woken up anyway. This value can be seen and changed using the update command:

$ update -d

All of the dirty buffers are linked into the BUF_DIRTY LRU list whenever they are made dirty by having data written to them and bdflush tries to write a reasonable number of them out to their owning disks. Again this number can be seen and controlled by the update command and the default is 500 dirty blocks.

#### The update Process
The update command is more than just a command; it is also a daemon.
When run as superuser (during system initialisation) it will periodically flush all of the older dirty buffers out to disk.

Whenever a dirty buffer is finished with, it is tagged with the system time that it should be written out to its owning disk. Every time that update runs it looks at all of the dirty buffers in the system looking for ones with an expired flush time. Every expired buffer is written out to disk.

### The /proc File System
The /proc file system really shows the power of the Linux Virtual File System.
It does not really exist (yet another of Linux's conjuring tricks), neither the /proc directory nor its subdirectories and its files actually exist.

The /proc file system, like a real file system, registers itself with the Virtual File System. However, when the VFS makes calls to it requesting inodes as its files and directories are opened, the /proc file system creates those files and directories from information within the kernel. For example, the kernel's /proc/devices file is generated from the kernel's data structures describing its devices.

The /proc file system presents a user readable window into the kernel's inner workings. Several Linux subsystems, such as Linux kernel modules described in chapter  modules-chapter, create entries in the the /proc file system.

### Device Special Files
Linux, like all versions of Unix TM, presents its hardware devices as special files.
So, for example, /dev/null is the null device. A device file does not use any data space in the file system, it is only an access point to the device driver.

The EXT2 file system and the Linux VFS both implement device files as special types of inode. There are two types of device file; 1) character and 2) block special files.
Within the kernel itself, the device drivers implement file semantices: you can open them, close them and so on.
Character devices allow I/O operations in character mode and block devices require that all I/O is via the buffer cache.


## Networks
Linux's networking implementation is modeled on 4.3 BSD in that it supports **BSD sockets** (with some extensions) and the **full range of TCP/IP networking**. This programming interface was chosen because of its popularity and to help applications be portable between Linux and other Unix TM platforms.

### An Overview of TCP/IP Networking
DNS names can be statically specified in the /etc/hosts file or Linux can ask a Distributed Name Server (DNS server) to resolve the name for it. In this case the local host must know the IP address of one or more DNS servers and these are specified in /etc/resolv.conf.

These registered port addresses can be seen in /etc/services.

Linux uses the Address Resolution Protocol (or ARP) to allow machines to translate IP addresses into real hardware addresses such as ethernet addresses. A host wishing to know the hardware address associated with an IP address sends an ARP request packet containing the IP address that it wishes translating to all nodes on the network by sending it to a multicast address. The target host that owns the IP address, responds with an ARP reply that contains its physical hardware address. ARP is not just restricted to ethernet devices, it can resolve IP addresses for other physical media, for example FDDI. Those network devices that cannot ARP are marked so that Linux does not attempt to ARP. There is also the reverse function, Reverse ARP or RARP, which translates phsyical network addresses into IP addresses. This is used by gateways, which respond to ARP requests on behalf of IP addresses that are in the remote network.

### The Linux TCP/IP Networking Layers
Network Application
    ||                         User Space
----++-------------------------------------
    ||                         Kernal Space
    \/
BSD Sockets
    ||        Socket Interface
    \/
INET Sockets
    ||        Protocol Layer
    \/
IP, TCP, UDP
    ||        Network Devices
    \/
Ethernet, PPP, SLIP

### The BSD Socket Interface
This is a general interface which not only supports various forms of networking but is also an inter-process communications mechanism.

Sockets could be thought of as a special case of pipes but, unlike pipes, sockets have **no limit on the amount of data** that they can contain. Linux supports several classes of socket and these are known as **address families**. This is because each class has its own method of addressing its communications.
Linux supports the following **socket address families** or domains:
- UNIX: Unix domain sockets,
- INET: The Internet address family supports communications via TCP/IP protocols
- AX25: Amateur radio X25
- IPX: Novell IPX
- APPLETALK: Appletalk DDP
- X25: X25

There are several socket types and these represent the type of service that supports the connection. Not all address families support all types of service.
Linux BSD sockets support a number of **socket types**:
- Stream
    These sockets provide reliable two way sequenced data streams with a guarantee that data cannot be lost, corrupted or duplicated in transit. Stream sockets are supported by the TCP protocol of the Internet (INET) address family.
- Datagram
    These sockets also provide two way data transfer but, unlike stream sockets, there is no guarantee that the messages will arrive. Even if they do arrive there is no guarantee that they will arrive in order or even not be duplicated or corrupted. This type of socket is supported by the UDP protocol of the Internet address family.
- Raw
    This allows processes direct (hence ``raw'') access to the underlying protocols. It is, for example, possible to open a raw socket to an ethernet device and see raw IP data traffic.
- Reliable Delivered Messages
    These are very like datagram sockets but the data is guaranteed to arrive.
- Sequenced Packets
    These are like stream sockets except that the data packet sizes are fixed.
- Packet
    This is not a standard BSD socket type, it is a Linux specific extension that allows processes to access packets directly at the device level.

#### Linux BSD Socket Data Structures

#### TCP/HTTP Listening On Ports: How Can Many Users Share the Same Port
1.) On a server, a process is listening on a port. Once it gets a connection, it hands it off to another thread. The communication never hogs the listening port.

2.) Connections are uniquely identified by the OS by the following 5-tuple: (local-IP, local-port, remote-IP, remote-port, protocol). If any element in the tuple is different, then this is a completely independent connection.

3.) When a client connects to a server, it picks a random, unused high-order source port. This way, a single client can have up to ~64k connections to the server for the same destination port.

If the incoming request is to be accepted, the server must create a new socket to accept it on:
    Proto Recv-Q Send-Q Local Address           Foreign Address         State
    tcp        0      0 0.0.0.0:500             0.0.0.0:*               LISTEN      -
    tcp        0      0 192.168.1.10:500        192.168.1.13:44444      ESTABLISHED -
    tcp        0      0 192.168.1.10:500        192.168.1.13:55555      ESTABLISHED -

### The INET Socket Layer
Its interface with the BSD socket layer is through the set of Internet address family socket operations which it registers with the BSD socket layer during network initialization. These are kept in the pops vector along with the other registered address families. The BSD socket layer calls the INET layer socket support routines from the registered INET proto_ops data structure to perform work for it.

#### Creating a BSD Socket
The system call to create a new socket passes identifiers for its 1) address family, 2) socket type and protocol.

As all files are represented by a VFS inode data structure, then in order to support file operations, BSD sockets must also be represented by a VFS inode data structure.

The newly created BSD socket data structure contains a pointer to the address family specific socket routines and this is set to the proto_ops data structure retrieved from the pops vector. Its type is set to the sccket type requested; one of SOCK_STREAM, SOCK_DGRAM and so on.

A free file descriptor is allocated from the current processes fd vector and the file data structure that it points at is initialized. This includes setting the file operations pointer to point to the set of BSD socket file operations supported by the BSD socket interface. Any future operations will be directed to the socket interface and it will in turn pass them to the supporting address family by calling its address family operation routines.

#### Binding an Address to an INET BSD Socket
In order to be able to listen for incoming internet connection requests, each server must create an INET BSD socket and bind its address to it.
 The bind operation is mostly handled within the INET socket layer with some support from the underlying TCP and UDP protocol layers. The socket having an address bound to cannot be being used for any other communication. This means that the socket's state must be TCP_CLOSE. The sockaddr pass to the bind operation contains the IP address to be bound to and, optionally, a port number.

As packets are being received by the underlying network devices they must be routed to the correct INET and BSD sockets so that they can be processed. For this reason UDP and TCP maintain hash tables which are used to lookup the addresses within incoming IP messages and direct them to the correct socket/sock pair. TCP is a connection oriented protocol and so there is more information involved in processing TCP packets than there is in processing UDP packets.

UDP maintains a hash table of allocated UDP ports, the udp_hash table. This consists of pointers to sock data structures indexed by a hash function based on the port number. As the UDP hash table is much smaller than the number of permissible port numbers (udp_hash is only 128 or UDP_HTABLE_SIZE entries long) some entries in the table point to a chain of sock data structures linked together using each sock's next pointer.

TCP is much more complex as it maintains several hash tables. However, TCP does not actually add the binding sock data stucture into its hash tables during the bind operation, it merely checks that the port number requested is not currently being used. The sock data structure is added to TCP's hash tables during the listen operation.

#### Making a Connection on an INET BSD Socket
Once a socket has been created and, provided it has not been used to listen for inbound connection requests, it can be used to make outbound connection requests. For connectionless protocols like UDP this socket operation does not do a whole lot but for connection orientated protocols like TCP it involves building a virtual circuit between two applications.

#### Listening on an INET BSD Socket
Once a socket has had an address bound to it, it may listen for incoming connection requests specifying the bound addresses. A network application can listen on a socket without first binding an address to it; in this case the INET socket layer finds an unused port number (for this protocol) and automatically binds it to the socket. The listen socket function moves the socket into state TCP_LISTEN and does any network specific work needed to allow incoming connections.

Whenever an incoming TCP connection request is received for an active listening socket, TCP builds a new sock data structure to represent it. This sock data structure will become the bottom half of the TCP connection when it is eventually accepted. It also clones the incoming sk_buff containing the connection request and queues it onto the receive_queue for the listening sock data structure. The clone sk_buff contains a pointer to the newly created sock data structure.

#### Accepting Connection Requests
The accept operation can be either blocking or non-blocking. In the non-blocking case if there are no incoming connections to accept, the accept operation will fail and the newly created socket data structure will be thrown away. In the blocking case the network application performing the accept operation will be added to a wait queue and then suspended until a TCP connection request is received.

Once a connection request has been received the sk_buff containing the request is discarded and the sock data structure is returned to the INET socket layer where it is linked to the new socket data structure created earlier. The file descriptor (fd) number of the new socket is returned to the network application, and the application can then use that file descriptor in socket operations on the newly created INET BSD socket.

### The IP Layer

#### Socket Buffers
Linux uses socket buffers or sk_buffs to pass data between the protocol layers and the network device drivers. sk_buffs contain pointer and length fields that allow each protocol layer to manipulate the application data via standard functions or ``methods''.

Each **sk_buff** has a block of data associated with it. The sk_buff has four data pointers, which are used to manipulate and manage the socket buffer's data:
- head
    points to the start of the data area in memory. This is fixed when the sk_buff and its associated data block is allocated,
- data
    points at the current start of the protocol data. This pointer varies depending on the protocol layer that currently owns the sk_buff,
- tail
    points at the current end of the protocol data. Again, this pointer varies depending on the owning protocol layer,
- end
    points at the end of the data area in memory. This is fixed when the sk_buff is allocated.

There are two length fields **len** and **truesize**:
len: the length of the current protocol packet,
truesize: the total size of the data buffer respectively.

The sk_buff handling code provides standard mechanisms for adding and removing protocol headers and tails to the application data.
These safely manipulate the data, tail and len fields in the sk_buff:
- push
    This moves the data pointer towards the start of the data area and increments the len field. This is used when adding data or protocol headers to the start of the data to be transmitted,
- pull
    This moves the data pointer away from the start, towards the end of the data area and decrements the len field. This is used when removing data or protocol headers from the start of the data that has been received,
- put
    This moves the tail pointer towards the end of the data area and increments the len field. This is used when adding data or protocol information to the end of the data to be transmitted,
- trim
    This moves the tail pointer towards the start of the data area and decrements the len field. This is used when removing data or protocol tails from the received packet.

#### Receiving IP Packets
When a network device receives packets from its network it must convert the received data into **sk_buff** data structures. These received sk_buff's are added onto the **backlog** queue by the network drivers as they are received.

If the backlog queue grows too large, then the received sk_buff's are discarded. The network bottom half is flagged as ready to run as there is work to do.

#### Sending IP Packets
Packets are transmitted by applications exchanging data or else they are generated by the network protocols as they support established connections or connections being established. Whichever way the data is generated, an sk_buff is built to contain the data and various headers are added by the protocol layers as it passes through them.

For every IP packet transmitted, IP uses the routing tables to resolve the route for the destination IP address. Each IP destination successfully looked up in the routing tables returns a **rtable** data structure describing the route to use.

#### Data Fragmentation
Every network device has a maximum packet size and it cannot transmit or receive a data packet bigger than this. The IP protocol allows for this and will fragment data into smaller units to fit into the packet size that the network device can handle. The IP protocol header includes a fragment field which contains a flag and the fragment offset.

 Each device has a field describing its maximum transfer unit (in bytes), this is the mtu field. If the device's mtu is smaller than the packet size of the IP packet that is waiting to be transmitted, then the IP packet must be broken down into smaller (mtu sized) fragments. Each fragment is represented by an sk_buff; its IP header marked to show that it is a fragment and what offset into the data this IP packet contains. The last packet is marked as being the last IP fragment. If, during the fragmentation, IP cannot allocate an sk_buff, the transmit will fail.

 The first time that the fragment of a message is received, IP creates a new ipq data structure, and this is linked into the ipqueue list of IP fragments awaiting recombination. As more IP fragments are received, the correct ipq data structure is found and a new ipfrag data structure is created to describe this fragment. Each ipq data structure uniquely describes a fragmented IP receive frame with its source and destination IP addresses, the upper layer protocol identifier and the identifier for this IP frame. When all of the fragments have been received, they are combined into a single sk_buff and passed up to the next protocol level to be processed. Each ipq contains a timer that is restarted each time a valid fragment is received. If this timer expires, the ipq data structure and its ipfrag's are dismantled and the message is presumed to have been lost in transit. It is then up to the higher level protocols to retransmit the message.

### The Address Resolution Protocol (ARP)
The Address Resolution Protocol's role is to provide translations of IP addresses into physical hardware addresses such as ethernet addresses. IP needs this translation just before it passes the data (in the form of an sk_buff) to the device driver for transmission.

The ARP protocol itself is very simple and consists of two message types, an ARP request and an ARP reply. The ARP request contains the IP address that needs translating and the reply (hopefully) contains the translated IP address, the hardware address. The ARP request is broadcast to all hosts connected to the network, so, for an ethernet network, all of the machines connected to the ethernet will see the ARP request. The machine that owns the IP address in the request will respond to the ARP request with an ARP reply containing its own physical address.

The ARP protocol layer in Linux is built around a table of arp_table data structures which each describe an IP to physical address translation. These entries are created as IP addresses need to be translated and removed as they become stale over time.
Each arp_table data structure has the following fields:
- last used
    the time that this ARP entry was last used,
- last updated
    the time that this ARP entry was last updated,
- flags
    these describe this entry's state, if it is complete and so on,
- IP address
    The IP address that this entry describes
- hardware address
    The translated hardware address
- hardware header
    This is a pointer to a cached hardware header,
- timer
    This is a timer_list entry used to time out ARP requests that do not get a response,
- retries
    The number of times that this ARP request has been retried,
- sk_buff queue
    List of sk_buff entries waiting for this IP address to be resolved

The ARP table consists of a table of pointers (the arp_tables vector) to chains of arp_table entries. The entries are cached to speed up access to them, each entry is found by taking the last two bytes of its IP address to generate an index into the table and then following the chain of entries until the correct one is found.

When an IP address translation is requested and there is no corresponding arp_table entry, ARP must send an ARP request message. It creates a new arp_table entry in the table and queues the sk_buff containing the network packet that needs the address translation on the sk_buff queue of the new entry. It sends out an ARP request and sets the ARP expiry timer running. If there is no response then ARP will retry the request a number of times and if there is still no response ARP will remove the arp_table entry. Any sk_buff data structures queued waiting for the IP address to be translated will be notified and it is up to the protocol layer that is transmitting them to cope with this failure. UDP does not care about lost packets but TCP will attempt to retransmit on an established TCP link. If the owner of the IP address responds with its hardware address, the arp_table entry is marked as complete and any queued sk_buff's will be removed from the queue and will go on to be transmitted. The hardware address is written into the hardware header of each sk_buff.

Whenever the a new entry needs to be allocated and the ARP table has reached its maximum size the table is pruned by searching out the oldest entries and removing them.

### IP Routing
 The IP routing database maintains information that gives answers to these questions. There are two databases, the most important being the **Forwarding Information Database**. This is an exhaustive list of known IP destinations and their best routes. A smaller and much faster database, the **route cache** is used for quick lookups of routes for IP destinations. Like all caches, it must contain only the frequently accessed routes; its contents are derived from the Forwarding Information Database.

Routes are added and deleted via IOCTL requests to the BSD socket interface. These are passed onto the protocol to process. The INET protocol layer only allows processes with superuser privileges to add and delete IP routes. These routes can be fixed or they can be dynamic and change over time. Most systems use fixed routes unless they themselves are routers. Routers run routing protocols which constantly check on the availability of routes to all known IP destinations. Systems that are not routers are known as end systems. The routing protocols are implemented as daemons, for example GATED, and they also add and delete routes via the IOCTL BSD socket interface.

#### The Route Cache
Whenever an IP route is looked up, the route cache is first checked for a matching route. If there is no matching route in the route cache the Forwarding Information Database is searched for a route. If no route can be found there, the IP packet will fail to be sent and the application notified. If a route is in the Forwarding Information Database and not in the route cache, then a new entry is generated and added into the route cache for this route. The route cache is a table (ip_rt_hash_table) that contains pointers to chains of rtable data structures. The index into the route table is a hash function based on the least significant two bytes of the IP address. These are the two bytes most likely to be different between destinations and provide the best spread of hash values. Each rtable entry contains information about the route; the destination IP address, the network device to use to reach that IP address, the maximum size of message that can be used and so on. It also has a reference count, a usage count and a timestamp of the last time that they were used (in jiffies). The reference count is incremented each time the route is used to show the number of network connections using this route. It is decremented as applications stop using the route. The usage count is incremented each time the route is looked up and is used to order the rtable entry in its chain of hash entries. The last used timestamp for all of the entries in the route cache is periodically checked to see if the rtable is too old.  If the route has not been recently used, it is discarded from the route cache. If routes are kept in the route cache they are ordered so that the most used entries are at the front of the hash chains. This means that finding them will be quicker when routes are looked up.

#### The Forwarding Information Database
The forwarding information database (shown in Figure  10.5 contains IP's view of the routes available to this system at this time. It is quite a complicated data structure and, although it is reasonably efficiently arranged, it is not a quick database to consult. In particular it would be very slow to look up destinations in this database for every IP packet transmitted. This is the reason that the route cache exists: to speed up IP packet transmission using known good routes. The route cache is derived from the forwarding database and represents its commonly used entries.

Several routes may exist to the same IP subnet and these routes can go through one of several gateways. The IP routing layer does not allow more than one route to a subnet using the same gateway. In other words, if there are several routes to a subnet, then each route is guaranteed to use a different gateway. Associated with each route is its metric. This is a measure of how advantagious this route is. A route's metric is, essentially, the number of IP subnets that it must hop across before it reaches the destination subnet. The higher the metric, the worse the route.

## Kernel Mechanisms

### Bottom Half Handling
There are often times in a kernel when you do not want to do work at this moment. A good example of this is during interrupt processing. When the interrupt was asserted, the processor stopped what it was doing and the operating system delivered the interrupt to the appropriate device driver. Device drivers should not spend too much time handling interrupts as, during this time, nothing else in the system can run. There is often some work that could just as well be done later on. Linux's bottom half handlers were invented so that device drivers and other parts of the Linux kernel could queue work to be done later on. Figure  11.1 shows the kernel data structures associated with bottom half handling.

There can be up to 32 different bottom half handlers; bh_base is a vector of pointers to each of the kernel's bottom half handling routines. bh_active and bh_mask have their bits set according to what handlers have been installed and are active. If bit N of bh_mask is set then the Nth element of bh_base contains the address of a bottom half routine. If bit N of bh_active is set then the N'th bottom half handler routine should be called as soon as the scheduler deems reasonable. These indices are statically defined; the timer bottom half handler is the highest priority (index 0), the console bottom half handler is next in priority (index 1) and so on. Typically the bottom half handling routines have lists of tasks associated with them. For example, the immediate bottom half handler works its way through the immediate tasks queue (tq_immediate) which contains tasks that need to be performed immediately.

Some of the kernel's bottom half handers are device specific, but others are more generic:
- TIMER
    This handler is marked as active each time the system's periodic timer interrupts and is used to drive the kernel's timer queue mechanisms,
- CONSOLE
    This handler is used to process console messages,
- TQUEUE
    This handler is used to process tty messages,
- NET
    This handler handles general network processing,
- IMMEDIATE
    This is a generic handler used by several device drivers to queue work to be done later.

Whenever a device driver, or some other part of the kernel, needs to schedule work to be done later, it adds work to the appropriate system queue, for example the timer queue, and then signals the kernel that some bottom half handling needs to be done. It does this by setting the appropriate bit in bh_active. Bit 8 is set if the driver has queued something on the immediate queue and wishes the immediate bottom half handler to run and process it. The bh_active bitmask is checked at the end of each system call, just before control is returned to the calling process. If it has any bits set, the bottom half handler routines that are active are called. Bit 0 is checked first, then 1 and so on until bit 31.

The bit in bh_active is cleared as each bottom half handling routine is called. bh_active is transient; it only has meaning between calls to the scheduler and is a way of not calling bottom half handling routines when there is no work for them to do.

### Task Queues
Task queues are the kernel's way of deferring work until later. Linux has a generic mechanism for queuing work on queues and for processing them later.

Task queues are often used in conjunction with bottom half handlers; the timer task queue is processed when the timer queue bottom half handler runs. A task queue is a simple data structure, see figure  11.2 which consists of a singly linked list of tq_struct data structures each of which contains the address of a routine and a pointer to some data.

Anything in the kernel, for example a device driver, can create and use task queues but there are three task queues created and managed by the kernel:
- timer
    This queue is used to queue work that will be done as soon after the next system clock tick as is possible. Each clock tick, this queue is checked to see if it contains any entries and, if it does, the timer queue bottom half handler is made active. The timer queue bottom half handler is processed, along with all the other bottom half handlers, when the scheduler next runs. This queue should not be confused with system timers, which are a much more sophisticated mechanism.
- immediate
    This queue is also processed when the scheduler processes the active bottom half handlers. The immediate bottom half handler is not as high in priority as the timer queue bottom half handler and so these tasks will be run later.
- scheduler
    This task queue is processed directly by the scheduler. It is used to support other task queues in the system and, in this case, the task to be run will be a routine that processes a task queue, say for a device driver.

### Timers
An operating system needs to be able to schedule an activity sometime in the future. A mechanism is needed whereby activities can be scheduled to run at some relatively precise time. Any microprocessor that wishes to support an operating system must have a programmable interval timer that periodically interrupts the processor. This periodic interrupt is known as a system clock tick and it acts like a metronome, orchestrating the system's activities.

Linux has a very simple view of what time it is; it measures time in clock ticks since the system booted. All system times are based on this measurement, which is known as jiffies after the globally available variable of the same name.

### Wait Queues
There are many times when a process must wait for a system resource. For example a process may need the VFS inode describing a directory in the file system and that inode may not be in the buffer cache. In this case the process must wait for that inode to be fetched from the physical media containing the file system before it can carry on.

The Linux kernel uses a simple data structure, a wait queue, which consists of a pointer to the processes task_struct and a pointer to the next element in the wait queue.

### Buzz Locks
These are better known as spin locks and they are a primitive way of protecting a data structure or piece of code. They only allow one process at a time to be within a critical region of code. They are used in Linux to restrict access to fields in data structures, using a single integer field as a lock. Each process wishing to enter the region attempts to change the lock's initial value from 0 to 1. If its current value is 1, the process tries again, spinning in a tight loop of code. The access to the memory location holding the lock must be atomic, the action of reading its value, checking that it is 0 and then changing it to 1 cannot be interrupted by any other process. Most CPU architectures provide support for this via special instructions but you can also implement buzz locks using uncached main memory.

When the owning process leaves the critical region of code it decrements the buzz lock, returning its value to 0. Any processes spinning on the lock will now read it as 0, the first one to do this will increment it to 1 and enter the critical region.

### Semaphores
A Linux semaphore data structure contains the following information:
- count
    This field keeps track of the count of processes wishing to use this resource. A positive value means that the resource is available. A negative or zero value means that processes are waiting for it. An initial value of 1 means that one and only one process at a time can use this resource. When processes want this resource they decrement the count and when they have finished with this resource they increment the count,
- waking
    This is the count of processes waiting for this resource which is also the number of process waiting to be woken up when this resource becomes free,
- wait queue
    When processes are waiting for this resource they are put onto this wait queue,
- lock
    A buzz lock used when accessing the waking field.

## Modules
Linux is a monolithic kernel; that is, it is one, single, large program where all the functional components of the kernel have access to all of its internal data structures and routines.

You can either load and unload Linux kernel modules explicitly using the insmod and rmmod commands or the kernel itself can demand that the kernel daemon (kerneld) loads and unloads the modules as they are needed.

Linux kernel modules can crash the kernel just like all kernel code or device drivers can.

When an attempt is made to unload a module, the kernel needs to know that the module is unused and it needs some way of notifying the module that it is about to be unloaded. That way the module will be able to free up any system resources that it has allocated, for example kernel memory or interrupts, before it is removed from the kernel. When the module is unloaded, the kernel removes any symbols that that module exported into the kernel symbol table.

### Loading a Module
There are two ways that a kernel module can be loaded.
1) The first way is to use the insmod command to manually insert the it into the kernel.
2) The second, and much more clever way, is to load the module as it is needed; this is known as **demand loading**.

When the kernel discovers the need for a module, for example when the user mounts a file system that is not in the kernel, the kernel will request that the **kernel daemon (kerneld)** attempts to load the appropriate module.

The kernel daemon is a normal user process albeit with super user privileges. When it is started up, usually at system boot time, it opens up an Inter-Process Communication (IPC) channel to the kernel. This link is used by the kernel to send messages to the kerneld asking for various tasks to be performed.

Kerneld's major function is to load and unload kernel modules but it is also capable of other tasks such as starting up the PPP link over serial line when it is needed and closing it down when it is not. Kerneld does not perform these tasks itself, it runs the neccessary programs such as insmod to do the work. Kerneld is just an agent of the kernel, scheduling work on its behalf.

### Unloading a Module
Modules can be removed using the rmmod command but demand loaded modules are automatically removed from the system by kerneld when they are no longer being used. Every time its idle timer expires, kerneld makes a system call requesting that all unused demand loaded modules are removed from the system. The timer's value is set when you start kerneld; my kerneld checks every 180 seconds. So, for example, if you mount an iso9660 CD ROM and your iso9660 filesystem is a loadable module, then shortly after the CD ROM is unmounted, the iso9660 module will be removed from the kernel.

Assuming that a module can be unloaded, its cleanup routine is called to allow it to free up the kernel resources that it has allocated.

The module data structure is marked as DELETED and it is unlinked from the list of kernel modules. Any other modules that it is dependent on have their reference lists modified so that they no longer have it as a dependent. All of the kernel memory that the module needed is deallocated.


## Processors

### X86
Intel
CISC (Complex instruction set computing)

### ARM
ARM
RISC (Reduced instruction set computing)
The ARM processor implements a low power, high performance 32 bit RISC architecture. It is being widely used in embedded devices such as mobile phones and PDAs (Personal Data Assistants).


## The Linux Kernel Sources
The Linux kernel sources have a very simple numbering system. Any even number kernel (for example 2.0.30) is a stable, released, kernel and any odd numbered kernel (for example 2.1.42 is a development kernel.

Changes to the kernel sources are distributed as patch files. The **patch** utility is used to apply a series of edits to a set of source files. So, for example, if you have the 2.0.29 kernel source tree and you wanted to move to the 2.0.30 source tree, you would obtain the 2.0.30 patch file and apply the patches (edits) to that source tree:

$ cd /usr/src/linux
$ patch -p1 < patch-2.0.30

### How The Kernel Sources Are Arranged
https://github.com/torvalds/linux

- arch
    The arch subdirectory contains all of the architecture specific kernel code. It has further subdirectories, one per supported architecture, for example arm and x86.
- include
    The include subdirectory contains most of the include files needed to build the kernel code. It too has further subdirectories including one for every architecture supported. The include/asm subdirectory is a soft link to the real include directory needed for this architecture, for example include/asm-i386. To change architectures you need to edit the kernel makefile and rerun the Linux kernel configuration program.
- init
    This directory contains the initialization code for the kernel and it is a very good place to start looking at how the kernel works.
- mm
    This directory contains all of the memory management code. The architecture specific memory management code lives down in arch/*/mm/, for example arch/i386/mm/fault.c.
- drivers
    All of the system's device drivers live in this directory. They are further sub-divided into classes of device driver, for example block.
- ipc
    This directory contains the kernels inter-process communications code.
- modules
    This is simply a directory used to hold built modules.
- fs
    All of the file system code. This is further sub-divided into directories, one per supported file system, for example vfat and ext2.
- kernel
    The main kernel code. Again, the architecture specific kernel code is in arch/*/kernel.
- net
    The kernel's networking code.
- lib
    This directory contains the kernel's library code. The architecture specific library code can be found in arch/*/lib/.
- scripts
    This directory contains the scripts (for example awk and tk scripts) that are used when the kernel is configured.

### Where to Start Looking
...



