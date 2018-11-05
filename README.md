## Invertcase command :
### This command takes string arguments and prints out the case inverted string. Eg.
```bash
$ invertcase hello World!
HELLO wORLD!
```
## Changed the process scheduling algorithm to priority based from the original round robin method.
## Implemented the cps, chpr syscalls which shows the name ,pid, state, priority of all current processes and change priority of a given process respectively :

### ```testbench``` is used to run a test program that runs for ~30 seconds.

### All the processes are initially given priority 60.

### Initially if we run ps command output is

```python
Name	PID	 Status	     Priority
init 	 1 	 SLEEPING 	 60
sh 	   2 	 SLEEPING 	 60
ps 	   3 	 RUNNING 	  60
```

### Two processes with same priority were created with command testbench.

```python
Name	PID	 Status	     Priority
init 	 1 	 SLEEPING 	 60
sh 	   2 	 SLEEPING 	 60
ps 	   8 	 RUNNING 	  60
testbench 	 5 	 RUNNABLE 	 60
testbench 	 7 	 RUNNING  	 60
```

### A process with priority 75 was created by first running testbench and setting the priority to 75 by calling setpriority function.

```python
Name	PID	 Status	     Priority
init 	 1 	 SLEEPING 	 60
sh  	  2 	 SLEEPING 	 60
ps 	   31 	 RUNNING 	 60
testbench 	 28 	 RUNNING 	 75
```

### Now another process with priority 60 was created.

```python
Name	PID	 Status	     Priority
init 	 1 	 SLEEPING 	 60
sh 	   2 	 SLEEPING 	 60
ps 	   34 	 RUNNING 	 60
testbench 	 28 	 RUNNABLE 	75
testbench 	 33 	 RUNNING 	 60
```

### The process with priority 75 was pre-emepted to RUNNABLE state and process with priority 60 is in RUNNING state.

## COMPARISON BETWEEN ROUND-ROBIN AND PRIORITY SCHEDULING

#### In round-robin all processes are scheduled in a circular manner.

#### Whereas in priority scheduling a process is preemped if a higher process with higher priority comes and rescheduling is done.

#### In priority scheduling starvation takes place ie., lower priorities are not allocated CPU until all the processes with higher priority are added.

* * *

# The MIT-xv6 OS

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

# ACKNOWLEDGMENTS

xv6 is inspired by John Lions's Commentary on UNIX 6th Edition (Peer
to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14,
2000)). See also <https://pdos.csail.mit.edu/6.828/>, which
provides pointers to on-line resources for v6.

xv6 borrows code from the following sources:
    JOS (asm.h, elf.h, mmu.h, bootasm.S, ide.c, console.c, and others)
    Plan 9 (entryother.S, mp.h, mp.c, lapic.c)
    FreeBSD (ioapic.c)
    NetBSD (console.c)

The following people have made contributions: Russ Cox (context switching,
locking), Cliff Frey (MP), Xiao Yu (MP), Nickolai Zeldovich, and Austin
Clements.

We are also grateful for the bug reports and patches contributed by Silas
Boyd-Wickizer, Anton Burtsev, Cody Cutler, Mike CAT, Tej Chajed, eyalz800,
Nelson Elhage, Saar Ettinger, Alice Ferrazzi, Nathaniel Filardo, Peter
Froehlich, Yakir Goaron,Shivam Handa, Bryan Henry, Jim Huang, Alexander
Kapshuk, Anders Kaseorg, kehao95, Wolfgang Keller, Eddie Kohler, Austin
Liew, Imbar Marinescu, Yandong Mao, Matan Shabtay, Hitoshi Mitake, Carmi
Merimovich, Mark Morrissey, mtasm, Joel Nider, Greg Price, Ayan Shafqat,
Eldar Sehayek, Yongming Shen, Cam Tenny, tyfkda, Rafael Ubal, Warren
Toomey, Stephen Tu, Pablo Ventura, Xi Wang, Keiichi Watanabe, Nicolas
Wolovick, wxdao, Grant Wu, Jindong Zhang, Icenowy Zheng, and Zou Chang Wei.

The code in the files that constitute xv6 is
Copyright 2006-2018 Frans Kaashoek, Robert Morris, and Russ Cox.

# ERROR REPORTS

Please send errors and suggestions to Frans Kaashoek and Robert Morris
(kaashoek,rtm@mit.edu). The main purpose of xv6 is as a teaching
operating system for MIT's 6.828, so we are more interested in
simplifications and clarifications than new features.

# BUILDING AND RUNNING XV6

To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run
"make". On non-x86 or non-ELF machines (like OS X, even on x86), you
will need to install a cross-compiler gcc suite capable of producing
x86 ELF binaries (see <https://pdos.csail.mit.edu/6.828/>).
Then run "make TOOLPREFIX=i386-jos-elf-". Now install the QEMU PC
simulator and run "make qemu".
