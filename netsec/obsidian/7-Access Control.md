The access control is composed of various mechanism and actors, but we will focus on the subject, or entity, the access control module and the policy decision point (or PDP). This elements (with the exception of the subject) are contained inside an outer and an inner boundary.

Some remarks regarding the access control isolation boundaries:
- The outer boundary prevents the by-passing of the guard who authorizes all resources request
- the inner boundar protects the integrity of the audit log

NB: Principle of least priviledge: every subject must be able to access only the information and resources necessary for its legittimate purpose

NB: Need to know principle: a process should have access only to the needed object, been able to make only the needed operation and only during the needed time

NB: Domain of protection: a set of objects and access rights

#### AC definition
An AC is a process which grants or denies access to resources and data of a system. Its purpose is to protect resources from unauthorized access by using, depending on the context, various AC policies, or set of rules

#### Structured approach
A structured approach to the AC divides policies a the higher level, followed by model and enforcement. In this case policies represent how they are specified, model models the meaning and enforcement how policies are implemented.

This method is usefull for implementing the use of automated reasoning to perform security analysis and to separate concerns

NB: Confused deputy: during a privilege escalation attack, the attacker does not have access to a resource, so it uses another subject, which has access, as an intermediary for read or modifying the data

# AC models

## AC matrix
The ACM lists all subjects and resources, and for each cell lists the permitted actions

## Discretionary AC
DAC policies are determinated by the owner user, this way no central entity is needed. This method is typically used in OSs.
To simplify administration, large organization arrange users in groups, and determine the policies based on the group and not the single user

DAC offers the pros of flexibility and a more intuitive implementation. On the other hand, the protective state of resources is subjective to the owner and vulnerable to user's mistakes. DAC are also vulnerable to trojans, or malicious software unknowingly executed by users with their user priviledge

## Mandatory AC
This policies are managed by a central identity which decides who can do what and on which resources. sharing is enforced by the use of security labels and somethimes legal requirements.

All this points leads to a multi-level security model. This model has the objective of preventing the release of sensitive information to untrusted users.
With this system, information is labeled with a sensitivity label, which joins a linear ordered set of sensitivity values (example: unclassified $\to$ confidential $\to$ topsecret) and the category to which the information belongs.
When a resource is created, is the resource creator that applies a sensitivity label bases on some criteria.
In multy level security, also the user is assigned clearance (or categorized) based on the security level and a set of need-to-know categories.

After having defined sensitivity labels and clearances, the AC compares them and if the user has access to the data based on the No Read Up and No Write Down properties: the first one declares that for accessing data you need to be on a higher or equal clearance level than the object. The second one instead says that higher level