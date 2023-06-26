# Introduction
The challenges of cloud storage are:
- **reliability** at the lowest possible cost
- **concurrent data access** , solved thanks to data replication but requires
- Maintaining **consistency** between different copies of data
- reduce **access time** and supporting multimedia accessing

### Storage models
They describe the **layout of a data structure** in a physical storage. They require **read/write coherence** and **before-or-after atomicity**, or the necessity make read/writes most efficient and less overlapping as possible

##### Block storage
It manages data as blocks withing sectors and tracks. It focuses on **speed and efficiency**, and is commonly used in databases

##### File storage
Data is managed in structured files and a **file system** is exposed to operate with it, some times over a network protocol.
This method doesn't work very well with large amounts of data

##### Object storage
It manages data as objects, containing the data itself, **metadata** and a unique **identifier**. It is specialized for **data continuously growing**

### Database Management System
A DBMS is a software that controls access to the database, but in the cloud we need a distributed database system. An example is amazon dynamo


# Block storage
Base foundation for other solutions

## Storage area network
Used for connecting storage devices between each other and with servers. This way servers only need to know the logical address

## Open stack Cinder
It implements services and libraries to provide **access to block storage** resources. It's used to provide persistent external storage to VMs and containers


# File systems
A file system controls how data (file and directories) is stored and retrieved

#### Unix File System (UFS)
Unix uses a **layered** and **hierarchical** design to provide flexibility and scalability to the file system. Is also used metadata to maintain the file system philosophy 

Is based on the Inode data structure

The layering divides the physical organization in the lower layers, and in the upper layers is placed the logical organization

## Distributed FS

#### Network File System (NFS)
The design objective is to integrate the existing semantics for the UFS in a client-server model while allowing clients to be supported on different OSs.
The interaction happens by using **Remote Procedure Calls**, and files are identified by a **file handle** (fh)

NFS uses a **vnode layer** which determines if the file target is in the local or remote file system, and in the second case implements the operations to retrieve it. 

When a remote file is required, the vnode layer passes the request to the vnode layer on the remote host

#### Designs and policies for distributed fs
- once a file is closed, the server will have the newest version
- policies to write a block:
	- **Delay in write-backs**: a block is written on the cache and only after a delay is written on the disk
	- **Write-through**: the block is written as soon as it's available on the cache
- sequential or concurrent write-sharing: if multiple clients can (or can't) modifiy the same file at the same time

#### General Parallel File System (GPFS)
It emplies concurrent execution of I/O operations, or **parallel I/O**. GPFS is designed for performance with large clusters and requires the disk to be interconnected through a Storage Are Network (SAN)

GPFS uses **write-ahead logs**: when a client makes a write operation, the metadata is written before on a log file and only after that the disk is updated. 
It also uses **data striping**, or segmenting data on different drives to allowe for concurrence and better performance, but can cause bigger data losses if a disk fails. To improve fault tolerance, the data is **replicated** on two different disks

#### Google File System (GFS)
This filesystem is focused on scalability and reliability with **large file sizes** (from GB to TB). The most common operations are appends and sequential reads

The design decisions rotate around **segmenting files** in large chunks, implementing **atomic append operations**, focusing on **high-bandwidth** instead of low latency, **removing caching** on the client, **checkpointing and fast recovery** mechanisms, efficient garbage collectors and channeling critical operation through a master component

GFS files are segmented in large **chunks** of 64 MB to **reduce** the **metadata and  requests** to locate a chunk (it's more likely that different data is on the same chunk) . Each chunk has his unique handler

The **master** mantains information about the system and a number of **chunk servers** (running under linux). 
When a request is sent, the **master assigns a lease** to the chunk server and his replicas. After this the client sends the data to all the servers and then a write request to the primary chunk server after all the acks are received. The primary server sends write to all secondaries and after receiveng all the acks it sends one back to the client

# Locks and consensus
OSs use lock managers to enable **controlled access** to shared storage and ensure **atomicity**. 
To elect a reliable master, consensus must be reached

## Locks
#### Types of locks
- **Advisory** locks: bases on the assumption that all precesses correctly access the medium
- **Mandatory** locks: block access to all processes that do not hold the locks
- **Fine-grained** locks: locks with little lease time
- **Coarse-grained** locks: locks with long lease time

#### Systematic approach to locking
Two approaches are available: **delegating to clients** the implementation of a consensus algorithm or **crate a locking service** to which the clients depend. The second solution is **easier to maintain** and achieves **high availabilty**, but can generate **scalability issues**

## Chubby
Is a **lock service** seveloped by google which provides an **interface** focused on providing availability and reliabilty. It uses **PAXOS** with lease timers for asynchonous consensus

The design decisions are using **lock service** and use **small files to advertise** clients and their parameters.
Chubby works best in an environment with thousands of clients using consistent cache semantics, access control and coarse-grained lock

#### Organization
Chubby consist in a small set of server (typically 5, known as **replicas**) known as a **cell**. Each cell uses PAXOS to elect a **master** which **satisfies read and write requests** alone. If the master fails or the lease expires, PAXOS is run again inside the cell.
Clients, using the chubby library,  finds the master by contacting a replica which returns the identity of the master

Chubby exports a **simpler** file system **interface** than unix, using a common prefix, followed by the name of the chubby cell and then the note, or resource, inside the cell

#### Nodes
**A node** in chubby **is a file or a directory**,  can be either permanent or ephemeral and uses metadata like checksums, ACL data and handles (like unix file descriptor)

Each chubby node can act as a reader/writer advisory lock. The read lock is in **shared mode** meanwhile the writer lock is in **exclusive mode**, the difference is if more than one client can or can't hold the lock at the same time

##### In short
Chubby is a distributed lock service for coarse-grained synchronization fo ditributed systems. Uses distributed consensus for fault tolerance plus consistent client-side caching.
His usage consist in electing a primary server, provide a name service, a standard repository for files and known locations for metadata

# Distributed databases


> [!info]+ BASE
> Is the evolution of ACID properties:
> - Basically Available (swaps consistency for availability)
> - Soft state (Data can be out sync for a small period of time. Swaps consistency for performance)
> -  Eventually consistent (the system will eventually converge to an agreed written value)


## Google Big Table
GBT is a flexible and high permance distributed storage system. it's different from a database, it's a  **multi-dimensional sorted map**.

It uses **GFS** to **store** metadata tablets (tablets location), logs and the data itself in the form of **SSTables** (Sorted String Tables) collections. 

A SSTable contains a **sequence of** 64 KB **blocks**, whose **index is stored at the end of the file**. This allowes to load indexes while loading the block and do lookpus in a single seek

BigTable uses chubby to store the root tablet, the bigtable schema, ACLs and discover tablet servers 

#### Master and tablets servers

The **master server assigns tablets** to tablet servers, monitors their status, and **balances their load**. It also acts as the garbage collector, handles schema changes and initiates tablets merging

The **tablet servers** manage sets of tablets and read/write requests. They also **split tablets** that have grown to much. They are directly responsable for tablet location, information and reads/writes, so that the client doesn't need to rely on the master

![[GFStabletRetrieval.png]]

#### GBT implementation
A tablet server acquires on startup an exclusive **chubby lock which determines his abilty to serve** his tablets

On startup:
1. the master grabs the master chubby lock to **prevent concurrent** master **instantiations**
2. scans the network to **find live tablet servers** and what tablets are assigned to them
3. Lastly uses the root and metadata tables to **detect unassigned tablets**

When a **tablet server stops serving**, is the **master** which detects the change of status and **reassigns the tablets** to other servers.

When a **server stops responding**, the **master tries to acquire the server lock**:
- if it's **available**, then **removes the server** from the servers list56
- if it **fails**, it means is isolated and fucking **kills himself** to lose the master status

#### Tablet serving
In a **write** operation:
1. the server **checks** if the request is **correct** and if the sender is authorized to write
2. the **data is written onto a commit log**, which, after gets commited, will insert his contents into the memtable

In a **read** operation:
1. the server **checks** if the request is correct and if the sender is authorized to read
2. the server **read a merged view** of the **SSTables** and the **memtable**

To **recover** a tablet the **tablet server reads the records** reguarding him in the metadata table and recontructs the memtable by **applying all the updates** registered 

#### Compactions
When a **memtable reaches a threshold**, is frozen and **converted into a new SSTable**, all meanwhile a new memtable is created (**minor compaction**). This achieves lower memory usage on the server

To avoid reaching high numbers of SSTables, a few **SSTable and the memtable are periodically merged** (**merging compaction**)

Lastly we have **major compation** which consist of **rewriting all SSTable into one** which contains no deleted data or deletion information. Bigtable regurarly applies major compaction to his tablets


# Distributed object storage
## OpenStack Swift
It's a software-defined **distributed object storage system** optimized for multi-tenancy, high concurrency and scalability. It **provides a simple REST-based API**.

Features:
- s3 APIs
- quotas and access control
- various storage policies to differentiate service levels
- offers authentication

#### Hierarchy 
1. **Account**: occupies the higher level and is created by the provider. It defines the namespace for containers
2. **Container**: namespace for objects (like a folder). They can receive ACLs configurations or storage policies
3. **Object**: stores data in un uncompressed and unencrypted format, with metadata

#### Swift architecture
Switft is composed of proxy server, RIng, storage servers and consistency servers

The **proxy server** is responsible for tying together the architecture: it **implements the API**, manages user requests, checks the servers status and handles failures

The **rings determine where data should reside** through. It also determins the device used for handoffs in case of failure.
It uses partitions and replicas isolated in as many distinct places (regions, devices,...) to limit failure and have the highest number of available replicas as possible. Data is evenly distributed based on weights

A **storage server manages objects stored on local devices**. This objects are binary files with metadata.
The **container server** stores a list of objects to **keep track of which container contains** them and create statistics. A similar role is occupied by account servers which store information about containers

**Consistency servers** manage specific roles:
- Replicator: keeps the system consistent when facing temporary errors
- Updater: queues updates that couldn't be immediately processed
- Auditors: They check for the integrity of objects, containers and accounts

##### PUT operation example
![[PUToperation.png]]

next->[[6-Resource orchestration]]