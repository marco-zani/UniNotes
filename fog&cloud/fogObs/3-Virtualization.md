The **first datacenters had most servers idle** because of the inability of OSs to provide isolated ambients for multiple services (One application per server). To solve this, it has been implemented the virtualization of multiple servers inside the same physical machine

>Virtualisation broadly describes the separation of a service  from the underlying physical delivery of that service
>
  (VMware definition)

  
Virtualization offers various advantages and disadvantages:

 advantages | disadvantages  
-- | --
**Isolation** | **Additional overhead** 
Consolidation | more difficult handling of heterogeneous hardware
Optimized energy consuption |
**Flexibility and agility** |
easier disaster recovery |
rapid deployment of new servers |
 

# Definitions

## Layering
Used to simplify system complexity, in virtualization it **separates hardware, software, OS, libraries and applications**. The interfaces who manage the communication between layers are:
 -  Application Program Interface (**API**)
	 - **library functions**
	-  defines the set of instruction the HW can execute giving access to the ISA
 -  Application Binary Interface (**ABI**)
	 - **System calls**
	-  the application and libraries modules used to **access the HW**
 -  Instruction Set Architecture (**ISA**)
	 - **machine instructions**
	 - the list of **instruction executable by the hardware**  

## Hypervisor (VMM)
Is the **software** in charge of the **virtualization**, meaning **partitioning resources** to each VM while **guaranteeing that VMs won't get access outside their boundaries**.

In practice are **stripped-down OS**, with a set of native drivers to manage hardware. The Virtual Machine Monitor must satisfy three characteristics:
 -  The **environments virtualized must be identical to a real machine**
 -  It must be **efficient**
 -  Should have the **complete control** of the physical resources
 

## Other definitions
- **Virtual Machine**: Software emulation of a physical machine
- **Host OS**: OS running on the physical machine
- **Guest OS**: OS running on the VM
- **Virtual Hardware**: HW provided by the VMM with the same characteristics of a given HW profile
- **Virtualized Components**: the virtual CPU, memory and I/O
  

# CPU Virtualization
When a VMM assigns a CPU to the VM, it might use a different ISA from the physical architecture, so **we need to emulate the CPU instead of virtualising it**. This might result is **lesser efficient** VM.
  
## X86
In the X86 world we have **three levels of virtualization**:
 -  **Full virtualization**
 -  **Paravirtualization**
 -  **Hardware assisted virtualization**

X86 defines **4 priviledge ring levels**, ascending from 0 to 3 from most priviledged (level 0 is reserved for the kernel) to less priviledged. This is used to implement **two models**: **0/1/3** and **0/3/3** (VMM/guest OS/applications).
Using this system allowes the definition of different types of instructions:

 -  **Privileged instruction**: If run in the wrong context **will generate a trap**. Can't be executed by the guest OS

 > [!important]- Context switch
> When a priviledged instruction is executed, the OS must interveen and execute a context switch, which consist in changing the ring level, executing the instruction and return to the previous level. **The entire operation is cost heavy**

 -  **Sensitive instruction**: An instruction **leaking information** about the physical state of the CPU
	-  In modern hardware, all sensitive instructions are privileged instructions


## Traps
A trap is **when an user mode instruction must be handled in kernel mode**, by the **hardware exception handler vector**.
They occur with **exceptions**, **system calls** or **hardware interrupts**.

> [!info]- SYSENTER/SYSEXIT
> new way to access interrupt code: instead of starting the routine to detect the code section, you just write the memory address of the code

#### Trap&Emulate paradigm
The **guest OS executes a privileged instruction**, which launches a trap and **is intercepted by the VMM**, who **emulates** the privileged instruction if legitimate.

So, if the trap is **caused by an application**, it is **passed to the guest OS**. If it's **caused by the guest OS**, the **VM state must be adjusted**.

All traps must be handled by the VMM

With the different cases:
 -  **System call**
	-  The CPU will trap the system call and send it to the interrupt handler vector, which is **processed by the VMM who'll return it to the guest OS**
 -  **Privileged instruction**
	-  They will be **trapped to the VMM for emulation** and then **jumped back to the guest OS**
 -  **HW Interrupt**
	-  The CPU traps to the interrupt handler of the VMM which **jumps it to the guest OS interrupt handler**

#### x86 notes
**x86 is difficult to virtualize** because every privileged instruction is more **timeconsuming** and some sensitive instruction do not trigger a trap, **leading to an incorrect emulation**. The major **solutions** are changing the OS with paravirtualization or the dinamic detection of sensitive instructions, but the **most common is hardware supported virtualization**, which makes all sensitive instruction priviledged.

## Dynamic Binary Translation (DBT)
DBT is the fully virtualized approach which **translates non virtualizable ISA at run-time**. This solves the sensitive instruction issue without modifing the guest OS or the hardware, but the **overhead is much bigger**. So, to improve performances, we can **adopt caching techniques**

VMware created a system which inspected the code of the guest OS and modify it with safe instructions. This determined lesser interventions of the VMM during execution


## Para-Virtualization (PV)
The **guest OS is modified** and knows that it's running on a VM, and in some cases, **knows it has to give control to the VMM**. Non-virtualizable syscalls are replaced with **hypervisor calls**, which doesn't trigger traps.

The **guest OS** is **depriviledged** (RING 1) and is introduced to **efficient mechanisms to communicate with the hypervisor**:
- in **guest to hypervisor communications** are used **hypercalls**, which are synchronous paravirtualized instructions
- in **hypervisor to guest communications**, the hypervisor **notifies asynchronously** certain events like interrupts

Paravirtualization results more performant thanks to a simpler implementation, but **not all OS are compatable**, only modifiable ones


## Hardware assisted vitualization (HVM)
To provide a more efficient and easier to implement virtualization, hardware support like **intel VT-X** and **AMD SVM** are introduced.
The idea behind HVM is to avoid sensitive instructions by **providing a new running mode**, **VMX** (Virtual Machine eXtensions) which provides **two new operating levels, root** and **non-root** mode, that enables a higher class of privilege over the existing four rings


> [!important]+ TLDR;
> By providing a root mode, this allowes the Guest OS to run on Ring 0 and use non priviledged ring 0 instructions without needing a context switch


Intel VTx implements the **switch between root modes** (with the relative registers) in a **single atomic operation**. It also introduces the **VMCS memory structure** which is adapted to **represent the data modifications needed to change states**: guest state, control data (or trap conditions) and host processor information

In summary, **HVM reduces virtualization overhead and minimizes VMM intervention**

## CPU virtualization summary
- **DBT** is highly compatable but **slow**
- **paravirtualization** has high performance but on a **selection of OSs**
- **HVM** is the **most used** technique


# Memory virtualisation
Each OS keeps tables to **translate virtual memory in physical memory**, this is called **memory paging**. In x86 this is **managed by** the HW through the **Memory Management Unit** (**MMU**)

**Processes use virtual addresses** (or **Logical Page Numbers**, LPNs), and the **MMU translates them to physical** (**PPNs**). It's also used a **cache for recent pages** called **TLB** (Translation Lookaside Buffer). It uses a **hit or miss system** to quickly access data

This method is simple, optimized and garantees isolation

## Shadow page table
To **translate the guest OS virtual address to the host physical address**, we implement a shadow table, which **keeps track of the mapping** between guest virtual address and host physical address. This buffer is invisible to the guest and is **exposed and used by only the CPU**. **This buffer is managed by the hypervisor** which **intercepts accesses** to this table and behaves accordingly 

## EPT/RVI
The **shadow page table page fault requires an overhead**, to avoid it, Intel/AMD introduced **Extended Page Table/Rapid Virtualization Indexing**. With this technology, the VMM keeps the **mappings** in a nested level, which **are exposed to the CPU**. It's then **the hardware who double walks the pages** to find the correspondent physical address. 

This **removes** the requirement of a **shadow table**, but **increases the cost of a single page walk**. For this reason, the **TLB cache is more critical**. For increasing TLB efficiency, **larger pages of memory are used** (intel huge pages)

For **optimization**, **TLBs use a identifier** (**Tagged TLB**) for each virtual processor, enabling them to access the same TLB at the same time


# I/O virtualization
Based on the type of device or if the OS is shared/dedicated, we define several Techniques

## Device emulation
The **VMM gives** to the guest OS all **the specifications of a emulated device**, which **determines the drivers used** by the guest OS. Is than the **VMM** job to **remap the communication** with the physical device

This approach is simple, but at **cost of I/O latency and** load on the **CPU**


## Para-virtualized device
It uses dedicated drivers added as external modules. Modern **drivers are provided by the hypervisors**

One **example** is the **memory ballooning**, which is used to **communicate the guest memory occupation to the hypervisor**, to allow it to over-commit memory across several guests

## Direct assignment
Also called **device pass-through**, allowes the guest to **directly connect to the device**. This **limits the use of a single device to a single VM**

This might sound easy but it requires a difficult implementation thanks to the **risk of memory corruption and difficulties in mapping**

## Dedicated HW
Devices using **Direct Memory Access** are configured using the guest memory addresses, this requires that the VMM intercepts and manages this requests, leading to additional overhead

**IOMMU** works **like the MMU** but remapped for **direct assignment of I/O devices**

Another technology, **SR-IOV, allowes VMs to share the same devices**, especially network cards. The multiplexing is managed by the hardware

# Hypervisor architectures
Type-1 and type-2 hypervisors are designed for **performance or easiness of deployment**, but hybrids are possible

## Type-1
**Directly connected to the HW**, it provides the best performance. It is **basically an OS stripped of all unnecessary components**.
Having proper drivers for all HW might be difficult

Most common examples are Vmware ESXi, Xen, Microsoft Hyper-V

## Type-2
It **runs like an application** on top of the host OS. The most common examples are VirtualBox and VMware workstation


## Hybrid architecture
With this technology, **the host OS is itself the hypervisor**, so it **can occupy both roles**.
KVM uses a hybrid approach.

# OS-level virtualization
advantages | disadvantages
----|----
support for different OSs | additional overhead 
excellent isolation | need to keep the guest OS up-to-date
individual execution environment | higher booting time


## Lightweight virtualization
The objective is to create a **system scalable, elastic and isolated** but while **consuming less resources**. This is more appropriate for when classical VM aren't required or when we need to be **scalable both vertically and horizontally** (more VMs and more machines)

With OS-level virtualization, the **Linux kernel is the hypervisor**, and the **VMs are replaced by virtual environments** (or containers)

OS-level virtualization should be capable of **controlling resources**, **guarantee isolation e security** and providing a **centralized management** of the distributed system
The **isolation aspect** is very **critical** because of the uses of the container, like safe execution of unknown programs or running of multiple services 

The most used technologies are Linux cgroups and namespaces, Linux containers and Docker. 


## Linux cgroups
This technology allows the **limit and isolation of resources** usage of processes. It's composed of two parts: a **kernel feature** and **user-space tools**

Here's the list of **cgroup features**:
- **resource limiting**: limit resources to certain processes
- **prioritization**: assign larger shares to certain processes
- **accounting**: **measure** resource use
- **isolate**
- **control**: like **freezing**, **check-pointing** and **restarting** processes


> [!info]- NB: multiple processes in same cgroup
> When assigning multiple processes to a limited group, the limited resource of the group will be divided between the different processes



## Linux namespaces
**Similar to cgroups, but** it limits the processes **groups to not see each other**. It allows to create distinct virtual environments

Types of namespaces

|name space | isolates|
|---|---|
|IPC | POSIX message queues|
|Network | network devices, ports...
|Mount| Mount points
|PID| Process IDs|
|User| Users and groups IDs
|UTS| Hostname and domain name
|Cgroup| control groups


**Both cgroups and name spaces** are limited by the fact that they **provide their services to a single machine, not to an entire data-center**. Plus they are difficult to use and don't guarantee portability

#### Process namespace
**In Linux, all process originate in a single tree**. Some processes can operate on processes under them. Thanks to PID namespace, **we can have different trees isolated** one another.
It works by giving to the root process of a new tree, his own PID 1


#### Network namespace
This type of name space **allows** processes to use **different network setups** thanks to the use of **virtual network interfaces** (or veth). This veths can span multiple namespaces and are **responsible of crossing namespace border** and connecting to other namespaces or the network.

This communication **works in a pipe-like connection** and allows both sides to be provided with an IP address

> [!info]- NB: Network namespace commands
> Establishing a connection is like connecting the cables between the veth and the root switch:
> `sudo ip netns add` -> creates network name space
> `sudo ip link add` / `sudo ip link set` -> manages the cable
>
> `ip netns exec` -> executes process in network namespace

#### Other namespaces
- **Mount namespace** allows new file systems with relative disk partitions, mount points...
- **UTS namespace**, bo', **deprecated**
- **User namespace** allows a process to have root privileges within the name space
- **IPC namespace**, for inter-process communication
- **cgroup namespace** is used to virtualize the view for cgroup files and mounts

## Linux containers
Containers provide lightweight virtualization at OS-level by **running multiple isolated Linux systems sharing the same kernel**

Basically, inside the box they look like a machine, but outside they **look like normal processes**. Containers do not emulate hardware and security is not a given feature


#### Characteristics
Compared to a VM, containers are **lighter and faster, but less isolated**, secure and do not provide the usage of different OSs

Containers are also more **agile for** application creation and **deployment**,  **portable** for cloud and OS distribution and offer a **more dense resource utilization**

#### LXC
Is the **union of cgroups, namespaces and other** features:
- kernel namespaces (isolation)
- chroots
- control groups (resource management)
- kernel capabilities
- Apparmor and SELinux profiles (security)
- Seccomp policies

LXC is used because it takes the features of the subcomponents but uses **each one to complement the other**, while doing it all in a easier maner through the container configuration file

The only **limitations** are in **check-pointing and migration**, and **not guaranteed** resource **isolation and portability**


## Docker
Docker provides a **lightweight, portable and self-contained package** focused on **application deployment** and execution that runs everywhere

Docker works on **seperation of environments, resource sandboxing** (with cgroups and namespaces), **transparent networking** and provides a **unified environment** for applications handling

If the app works locally, it works everywhere. Docker also separates the concerns of a developer or a DevOps

#### Docker vs LXC
docker is optimized for application's deployment, is portable and has a simplified interface but more powerfull management tools

Other features are automatic building, union file system, versioning, component re-use, sharing, better documentation and integration with other services


#### Docker functioning
Docker images are templates used for creating an instance called container.

All images are stored in a registry either public or private
- `docker search`
- `docker pull` or `docker push`


to manage local images
- `docker images` or `docker image list`
- `docker image rm` or `docker rmi`
- `docker run` with the options `-p` and `-v` to expose ports or mount folders

to manage containers
- `docker ps` with the option `-a`
- `docker inspect`
- `docker rm`
- `docker start`, `docker stop`, `docker kill`
- `docker exec` or `docker exec -it <container> bash`
- `docker logs -f `
- `docker cp`


#### Docker network
Docker **automatically implements a private network**  with all the appropriate routing tables and ip addresses. Connectivity is provided when at least one port is exposed to the outside.
Containers connect to a linuxbridge (docker0)

Is then the **libnetwork component** to carry out network operations, like deciding ip addresses and endpoint configurations


#### Union file system
For isolation and portability, **containers can/must replicate** entire **file systems**, resulting in a bigger container size

UNF mounts multiple directories to the root and follows a **layer model**: **writable higher layers and read-only lower layers**. When modifing data, it **only modifies copied files on the higher layer** and substitutes a file with a **whiteout when deleting**

This way **only differences are stored** and container size is reduced

**Docker uses OverlalyFS** which builds from a base image, different modifications (seen as layers) to reach the final image. All this is written in the Dockerfile

#### Other things about Docker
- The life cycle is composed by:
	- Build -> Test -> Push -> Deploy -> Manage -> Monitor -> Update
- Docker is appreciated because of continuous delivery, improved security, reproducibility and no issues with compatibility 
- For orchestration we can use DockerSwarm, Kubernetes (Kind)
- Docker compose allows for multi-container applications



## Summary
**Lightweight virtualisation** is more used thanks to:
- **more** resource **efficiency**
- **reduced** operating **costs**
- **strong isolation** which leads to multiple processes

**Docker is the pinnacle technology** at the moment


Next -> [[4-Cloud Networking]]