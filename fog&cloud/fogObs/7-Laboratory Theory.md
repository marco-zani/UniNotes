# Open Stack
Open stack is **a set of services for cloud infrastructure management**. It manages VM
The major services are:

#### Keystone
It provides control over **authentication and access**

#### Horizon
Is a **web based dashboard** for services and resources management

#### Nova
It **manages the infrastructure**, in detail the instances, networks, users and projects. It also provides sub-services like **cloud-init** for instances initialization and **security group** for managing policies and firewalls

#### Neutron
Manages **networking services**

#### Glance
Manages **VM's images**

#### Cinder
Manages **block storage**

#### Swift
Manages **object storage**

# Kubernets
Is a **container orchestrator** and is organized in **master and workers nodes**

#### Master node
It behaves as an **entry point for administrative operations** and **manages** kubernetes **clusters**.

Is composed of a **API server**, a **work scheduler**, a **control manager** for checking the status of the clusters and a **status store** called etcd

#### Worker node
This are **the machines who run the applications**.

They contain **Pods**, or **groups of containers under the same scheduling**. 
To access to the services provided by the containers, **we directly connect to the worker node**

Worker nodes are **composed of**:
- a **container run-time**, which runs containers in docker
- the **kubelet**, an agent with the role of **communicating with the master node** and checking the containers status
- the **kube-proxy**, which configures the **Service as connection Endpoint** to allow us to connect to the Pods

## Pods
As the smallest component, Pods rappresent instances of a service (**micro services**). Given their semplicity, they **must be managed externally by controllers**

#### Replica controller
Is located in the controller manager inside the master node. His job is to **check the right amount of replicas** of a Pod

#### Deployment controller
Also located in the controller manager, it **provides the updates** to the Pod and replicas configurations. It also provides the deployment recording, a **roll back mechanism**

## Kubernetes objects
Kubernetes uses **objects** models **to represent the entities** in the clusters. The **data** contained in the object covers **what applications are running** and on which node, the **applied policies**, the **resources usage** and their **status**.
Objects are contained in a **.yaml** file

#### Namespaces
Kubernetes uses namespaces to **partition clusters int sub-clusters**. We also use **resource quotas** to divide cluster resources between namespaces.

#### Labels and Selectors
We can use labels and selectors to **organize and retrieve groups of** objects (**entities**). Other tools are **configMap** and **secret API** resources which are used for passing configuration details and sensitive informations (like passwords)

## Kubernetes connectivity
#### CNI
Container Network Interface **is a specification** with the **role of assigning IP addresses to pods**. CNI connects to the underlying software bridge to get the IP address and forwards it to the requested container

#### Inter-container communication
To communicate between containers, kubernetes uses namespaces. In detail, **inside a pod, containers share network namespaces**

#### Pod-to-Pod communication
To enstablish Pod-to-Pod communication, kubernetes avoids any NAT and **uses software defined networking**. One example is **Flannel**, which uses UDP to encapsulate generic packets

#### External world-to-Pod communication
**A service is a group of pods and policies** achieved through the use of labels and selectors. A service is then **accessed by the user instad of** accessing directly the **pod**. This allowes for a **faster recovery** if a pod fails.

The **kube-proxy** is a daemon who **checks the master node for updates on services and endpoints**. It also configures IP tables to **capture traffic going to the cluster IP and forwards it towards** one of the **endpoints**

Services can be of different types:
- **ClusterIP**: makes the service **reachable only from within the cluster**
- **NodePort**: **exposes the service** on each node at a static port. Creates a NodePort in order to work properly
- **LoadBalancer**: exposes the service using a loadBalancer. Creates a ClusterIP and a NodePort
- **External name**: maps the service to the contents of the **externalName field**. **Doesn't apply proxying**

#### Ingress
ingress is a tool for **decoupling routing routes to the service** through a collection of rules and a load balancer. It also provides services like TLS and path based routing

With an Ingress implementation, **users connect to an Ingress endpoint which then forwards to the service** according to configuration. 
All this is managed by the Ingress controller

## Kubernetes storage
To **overcome the issue of losing data when a container crashes**, kubernetes uses volumes, or **a directory backed by a storage medium that outlives containers** and is **shared inside the pod**

There are **different types of volumes**: **EmptyDir** is the default, but we can also **mount different filesystems**, use **secret volume** to pass sensitive informations and the **hostpath** type to share a directory with the host

Kubernetes persisten volumes can be **statically provided** by an administrator **or dynamically** through the storage class resource.
We use the **PersisteVolumeClaim API to request for storage**

## Kubernetes scheduler
It covers the **role of assigning pods to nodes** using constraints, available resources and customisable algorithms.

The scheduler uses a two step operation of **filtering and scoring**. The filtering consist on checking affinity and user-defined contraints in the nodeSelector field. Scoring is then applied to the remaining pods to find the most suitable

## Other services
#### Helm
Is a **packet manager** used to manage applications inside the cluster