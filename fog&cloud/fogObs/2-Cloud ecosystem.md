Cloud computing is defined by **deployment model**, **delivery models**, **infrastructure**, **resources** and **defining attributes**.

## Actors

Thanks to the NIST reference model, we identify, as **actors of cloud computing** services, the following:
- the **service consumer**
- the **broker**, **intermediary** between providers and consumers
- the **service provider**
- the **auditor**, which makes independent assessment of the performance and security of a cloud service
- the **carrier**, which **provides connectivity**

## Definitions

####  Virtualization
Is the **ability to hide the physical characteristics** of the resources **to the applications, systems and users using them**

  
####  Tenancy
A single or multi -tenancy cloud service, is determined **if the customer interacts with a personal instance** of the software **or a shared one**. In the second case, the **group of users is called a tenant**.
The two methods determine how resource management and costs are divided between users
  

####  Elasticity
This is the **property to increase or decrease resource as needed**, all within a short time. This allowes to **fight** the episodes of **under or overprovisioning**, or underutilisation and saturation of resources

Exercise:

  | 
------------ | ------------
peak demand (Pd) | average utilisation (Au) 
pay as you go (Pg) | buying cost (Bc) 
Pd x 24 =  buying utilisation server hours (BuSh) |
Au x 24 =  cloud utilisation server hours (CuSh) |
  
Cloud computing is also a great way to manage demand bursts due to external events.
In any case, is difficult to predict peak utilisation, and the consequent under (or over) provisioning leads to lost revenue, in one case for maintence cost, in the other for rejected users with their revenue
  

####  Transference and migration
Another advantage of cloud computing is the **transference of risk**  of underprovisioning **to a third party**
  
In any case, **resource utilization, physical plant and operational costs must be taken in account** when considering migrating. **It can be detrimental** to migrate to the cloud **if the transfer time is higher than the time to locally process the data**
  

##  Deployment models
they determine the ownership, size and access to cloud services
  
####  Public cloud
**Developed for the general public or a lange industry** group by an organisation selling the service. The resources and infrastructure are managed by the provider. It uses a multi-tenancy model

####  Private cloud
**Used only by an organisation**, is developed by the consuming organisation or another party. **Resources** are **located on or off-premise** based on the company preference

####  Community cloud
Used by a **group of organisations with common** concern (like policies or security considerations), is managed by the organisations or a third party

####  Hybrid cloud
It's a mashup of different type of clouds based on the various concerns
  
##  Delivery models
####  Software-as-a-Service (SaaS)
The user can **only access to the service offered** by the provider. This is not suitable 
when the data should not be allowed to be hosted externally

####   Platform-as-a-Service (PaaS)
Allowes the user to **install** his **applications and services** by the **use of tools supported by the provider**. It still hasn't got the access to the HW. PaaS is not suggested when application must be portable or when in need of hardware or software customization

####   Infrastructure-as-a-Service (IaaS)
The provider gives to the user **dedicated HW and VM to manage**. With this model the user has max control over everything except the underlying cloud infrastructure

##  The ecosystem
The **main cloud providers are Amazon** (Iaas), **Google and Microsoft** (SaaS and Paas), but we have also open source services like aucalyptus, OpenNebula and OpenStack
  
####  AWS
Composed of interconnected servers with high speed connection, it **offers** computing and storage **services based on availability zones** with different prices.

The user chooses an availability zone and **instance type**, which **determines the hardware's specs**. Then a Virtual Machine is installed on a located system and a IP address is provided (through DHCP). The user is able to interact through an AWS Management console, SDK libraries or raw REST requests.

Some examples of AWS services:
##### Computing
- **EC2** - **Elastic Cloud** Computing
   -  Manages virtual machine instances by selecting hardware, images and network configurations
   - The instances are differentiated by family, generation and size
##### Storage
- **S3** - Simple **Storage** System
   -  Service used to store large amount of data
- **EBS** - Elastic **Block Store**
   -  Provides block storage **to EC2 instances**, which sees them as disks
##### Databases
- **SimpleDB**
- **SQS** - Simple **Queue** Service
##### Cloud management
- **CloudWatch**
   - **Monitoring** infrastructure used by developers and sys admins 

####  Google

Google offers both **Saas** like Gmail,docs, Google Drive, calendar... and **PaaS**: AppEngine, Google Base...
  

####  Microsoft

Microsoft offers the cloud services of **azure** for cumputation and storage of data, plus fabric controller


#### Opensource cloud

**OpenStack** and **Eucalyptus** provide IaaS and SaaS platforms to operate (Eucalyptus is also compatible with AWS), meanwhile **Open-nebula** is used for managing distributed data center infrastructures


Next -> [[3-Virtualization]]