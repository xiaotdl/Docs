# DBMS Tutorial
Database Management System
https://beginnersbook.com/2015/04/dbms-tutorial/


## Intro to DBMS
- What's the need of DBMS?
When dealing with huge amount of data, there are two things that require optimization:
1) Storage of data
2) Retrieval of data


- Storage
According to the principles of database systems, the data is stored in such a way that it acquires lot less space as the redundant data (duplicate data) has been removed before storage.
e.g. several account(checking, saving, etc.) shares the same user info

- Fast Retrieval of data


### DBMS Application
- Telecom: DB tracks calls made, network usage, customer details etcs. data updated every milisecond.
- Industry: DB tracks supply chain, product unit ins and outs.
- Banking System: DB stores customer info, tracking day to day credit/debit transactions, generating bank statements etc.
- Education sector: DB stores and retrieves student details, staff details, course details, exam details, payroll data, attendance details, fees details etc.
- Online shopping: DB stores product info, customer info(address, preference etc.),
credit details.


### Advantages of DBMS over FS(file system)

- Drawbacks of FS
    - Data Isolation: data are scattered in various files, and files may be in different formats, writing new application programs to retrieve data is difficult.
    - Duplication of data: redundunt data.
    - Dependency on application programs - changing files would lead to change in app.

- Advantages of DBMS over FS
    - No redundant data: redundancy is removed by data normalization.
    - Data consistency and integrity: data normalization takes care of it too.
    - Secure: Each user has a different set of access.
    - Privacy: Limited access.
    - Easy access to data.
    - Easy recovery.
    - Flexible.

- Disadvantages of DBMS:
    - DBMS implementation cost is high compared to the FS
    - Complexity: DB is complex to understand
    - Performance: varies based on app.


## View of Data in DBMS
**Abstraction** is one of the main features of database systems. Hiding irrelevant details from user and providing abstract view of data to users, helps in easy and efficient user-database interaction.

To understand the view of data, you must have a basic knowledge of data abstraction and instance & schema. Refer these two tutorials to learn them in detail.
- Data abstraction
- Instance and schema

### Data Abstraction in DBMS
This process of hiding irrelevant details from user is called data abstraction.

We have 3 levels of abstraction:
- Physical level: It describes how data is actually stored in DB.
- Logical level: It describes what data is stored in DB.
- View level: It describes the user interaction with DB.

e.g. Customer Table
At physical level, these records are described as blocks of storage(bytes, gigabytes, terabytes etc.) in memory/disk. These details are often hidden from the programmers.

At logical level, these records are described as fields and attributes along with their data types, their relationship can be logically implemented. The programmers generally work at this level.

At view level, user just interact with system with the help of GUI and enter the details at the screen, they are not aware of how data is stored and what data is stored.


### Instance and schema in DBMS
- Definition of schema:
Design of a DB is called the schema.
Database schema defines the variable declarations in tables that belong to a particular database

Schema is of 3 types:
- Physical schema: how data stored in blocks of storage
- Logical schema: programmers and DB admin work at this level
- View schema: end user interact with DB system

- Definition of instance:
The data stored in database at a particular moment of time is called instance of database.


## Data models in DBMS
A Data Model is a logical structure of Database. It describes the design of database to reflect entities, attributes, relationship among data, constrains etc.

Types of Data Models:
- Object based logical models - Describe data at the conceptual and view levels.
    - E-R Model
    - Object oriented Model
- Record based logical models - These models specify logical structure of DB with records, fields, and attributes.
    - Relational Model
    - Hierarchical Model
    - Network Model - Network Model is same as hierarchical model except that it has graph-like structure rather than a tree-based structure. Unlike hierarchical model, this model allows each record to have more than one parent record.
- Physical Data Models – These models describe data at the lowest level of abstraction.


### E-R Model in DBMS
ER Model: entity-relationship model, is a systematic way of describing and defining a buisiness process. An ER model is typically implemented as a DB.
The main components of E-R model are:
- entity set
- relationship set.

Here are the geometric shapes and their meaning in an E-R Diagram:
- Rectangle: Represents Entity Sets
- Ellipses: Attributes
- Diamonds: Relationship Set
- Lines: They link attributes to Entity Sets and Entity Sets to Relationship Set
- Double Ellipses: Multivalued Attributes
- Dashed Ellipses: Derived Attributes
- Double Rectangles: Weak Entity Sets
- Double Lines: Total participation of an entity in a relationship set

e.g. E-R Diagram..


### Relational Model in DBMS
In relational model, the data and relationships are represented by collection of inter-related tables.

Each table is a group of column and rows, where column represents attribute of an entity and rows represents records.

The rows with values are the records (commonly known as tuples).


#### RDBMS Concepts
relational database management system

A relational database has following major components:
- Table
- Record/Tuple
- Field
- Attribute

Table:
A table is a collection of data represented in rows and columns.

Record/Tuple:
Each row of a table is known as record or it is also known as tuple.

Field:
Each column in the first row.

Attribute:
Each cell are known as attributes in a database.


### Hierarchical model in DBMS
In hierarchical model, data is organized into a tree like structure with each record is having one parent record and many children.
The main drawback of this model is that, it can have only one to many relationships between nodes.


### Network Model in DBMS


## Database languages
DB languages are used for store, read, update the DB.
There are several languages that can be used for this purpose: one of them is SQL (Structured Query Language).

Types of DBMS languages:
- Data Definition Language (DDL)
    DDL is used for specifying the DB schema.
    Let’s take SQL for instance to categorize the statements that comes under DDL:
    - CREATE, create DB
    - ALTER, alter the structure of DB
    - DROP, drop the DB instance
    - TRUNCATE, delete tables in a DB instance
    - RENAME, rename a DB instance

- Data Manipulation Language (DML)
    DML is used for accessing and manipulating data is a DB.
    - SELECT, read records from table(s)
    - INSERT, insert records into table(s)
    - UPDATE, update data in table(s)
    - DELETE, delete all records from the table

- Data Control Language (DCL)
    DCL is used for granting and revoking user access to the DB
    - GRANT, grant access to user
    - REVOKE, revoke access to user

In practical data definition language, data manipulation language and data control languages are not separate language; rather they are the parts of a single database language such as SQL.


## Keys in DBMS
Key plays an important role in relational database:
- it is used for identifying **unique rows** from table
- it also establishes **relationship among tables**.

Types of keys in DBMS:
- Primary Key
    A primary key is a column or set of columns in a table that uniquely identifies tuples (rows) in that table.
- Super Key
    A super key is a set of one or more columns(attrs) to uniquely identify rows in a table.
- Candidate Key
    A super key with no redundant attribute is known as candidate key.
- Alternate Key
    Out of all candidate keys, only one gets selected as primary key, remaining keys are known as alternate or secondary keys.
- Composite Key
    A composite key consists of more than one attribute to uniquely identify rows.
- Foreign Key
    Foreign keys are the columns of a table that points to the primary key of another table. They act as cross-reference between tables.

### Primary Key
- We denote the primary key by underlining the column name.

- The value of primary key should be unique for each row of the table. Primary key column cannot contain duplicate values.

- Primary key column should not contain nulls.

- Primary keys are not necessarily to be a single column; more than one column can also be a primary key for a table. For e.g. {Stu_Id, Stu_Name} collectively can play a role of primary key in the above table, but that does not make sense because Stu_Id alone is enough to uniquely identifies rows in a table then why to  make things complex. Having that said, we should choose more than one columns as primary key only when there is no single column that can play the role of primary key.


How to choose a primary key?
1) Either to create a column and let DB automatically have numbers in increasing order for each row;
2) or choose a column making sure that it does not contains duplicates and nulls.


### Super Key & Candidate Key
How candidate key is different from super key?
Answer is simple – Candidate keys are selected from the set of super keys, the only thing we take care while selecting candidate key is: It should not have any redundant attribute. That’s the reason they are also termed as minimal super key.

e.g.
Employee Table
Emp_SSN     Emp_Number  Emp_Name
123456789   226         Steve
999999321   227         Ajeet
888997212   228         Chaitanya
777778888   229         Robert

Super keys:
{Emp_SSN}
{Emp_Number}
{Emp_SSN, Emp_Number}
{Emp_SSN, Emp_Name}
{Emp_SSN, Emp_Number, Emp_Name}
{Emp_Number, Emp_Name}
All of the above sets are able to uniquely identify rows of the employee table.

Candidate Keys:
As I stated above, they are the minimal super keys with no redundant attributes.
{Emp_SSN}
{Emp_Number}

Primary key:
Primary key is being selected from the sets of candidate keys by database designer. So Either {Emp_SSN} or {Emp_Number} can be the primary key.


### Alternate Key
Out of all candidate keys, only one gets selected as primary key, remaining keys are known as alternative or secondary keys.

### Composite Key (aka Compound Key)
A key that consists of more than one attribute to uniquely identify rows (also known as records & tuples) in a table is called composite key.

### Foreign Key
Note: Practically, the foreign key has nothing to do with the primary key tag of another table, if it points to a unique column (not necessarily a primary key) of another table then too, it would be a foreign key. So, a correct definition of foreign key would be: Foreign keys are the columns of a table that points to the candidate key of another table.


## Constraints in DBMS
Constrains enforce limits to the data or type of data that can be inserted/updated/deleted from a table.

Types of constraints:
- NOT NULL
- UNIQUE
- DEFAULT
- CHECK
- Key Constraints - PK, FK
- Domain Constraints
- Mapping Constraints

NOT NULL:
NOT NULL constraint makes sure that a column does not hold NULL value.
e.g.
CREATE TABLE STUDENT(
    ROLL_NO INT NOT NULL,
);

UNIQUE:
UNIQUE Constraint enforces a column or set of columns to have unique values.
e.g.
CREATE TABLE STUDENT(
    STU_ADDRESS VARCHAR (35) UNIQUE,
);

DEFAULT:
The DEFAULT constraint provides a default value to a column when there is no value provided while inserting a record into a table.
e.g.
CREATE TABLE STUDENT(
    EXAM_FEE INT  DEFAULT 10000,
);

CHECK:
This constraint is used for specifying range of values for a particular column of a table.
e.g.
CREATE TABLE STUDENT(
    ROLL_NO   INT  NOT NULL CHECK(ROLL_NO >1000) ,
);

Key constraints:
PK: uniq and not null
e.g.
CREATE TABLE STUDENT(
    ROLL_NO   INT  NOT NULL,
    PRIMARY KEY (ROLL_NO)
);

FK: points to PK/Candidate key of another table.


### Domain constraints:
Domain constraints are user defined data type and we can define them like this:

Domain Constraint = data type + Constraints (NOT NULL / UNIQUE / PRIMARY KEY / FOREIGN KEY / CHECK / DEFAULT)

e.g.
create domain id_value int
constraint id_test
check(value > 100);

create table student_info (
    stu_id id_value PRIMARY KEY,
);

e.g.
I want to create a table “bank_account” with “account_type” field having value either “checking” or “saving”:

create domain account_type char(12)
constraint acc_type_test
check(value in ("Checking", "Saving"));

create table bank_account (
    account_type account_type
);


### Mapping constraints:
Mapping constraints can be explained in terms of mapping cardinality:

- One to One
An entity of entity-set A can be associated with at most one entity of entity-set B.
An entity in entity-set B can be associated with at most one entity of entity-set A.

- One to Many
An entity of entity-set A can be associated with any number of entities of entity-set B.
An entity in entity-set B can be associated with at most one entity of entity-set A.

- Many to One
An entity of entity-set A can be associated with at most one entity of entity-set B.
An entity in entity-set B can be associated with any number of entities of entity-set A.

- Many to Many
 An entity of entity-set A can be associated with any number of entities of entity-set B.
 An entity in entity-set B can be associated with any number of entities of entity-set A.

e.g.
CREATE TABLE Customer (
    customer_id int PRIMARY KEY NOT NULL,
    first_name varchar(20),
    last_name varchar(20)
);

CREATE TABLE Order (
    order_id int PRIMARY KEY NOT NULL,
    customer_id int,
    order_details varchar(50),
    constraint fk_Customers foreign key (customer_id)
           references dbo.Customer
);

Assuming, that a customer orders more than once, the above relation represents one to many relation.


### Cardinality in DBMS
In DBMS you may hear cardinality term at two different places and it has two different meanings as well.

1) In Context of Data Models:
In terms of data modeling, cardinality refers to the relationship between two tables.
They can be of four types:
- One to One
- One to Many
- Many to One
- Many to Many

2) In Context of Query Optimization:
In terms of query, the cardinality refers to the uniqueness of a column in a table.
The column with all unique values would be having the high cardinality and the column with all duplicate values would be having the low cardinality. These cardinality scores helps in query optimization.


## Functional Dependency in DBMS
The attributes of a table is said to be dependent on each other when an attribute of a table uniquely identifies another attribute of the same table.

For example: Suppose we have a student table with attributes: Stu_Id, Stu_Name, Stu_Age. Here Stu_Id attribute uniquely identifies the Stu_Name attribute of student table because if we know the student id we can tell the student name associated with it. This is known as functional dependency and can be written as Stu_Id->Stu_Name or in words we can say Stu_Name is functionally dependent on Stu_Id.

Formally:
If column A of a table uniquely identifies the column B of same table then it can represented as A->B (Attribute B is functionally dependent on attribute A)


### Trivial functional dependency
The dependency of an attribute on a set of attributes is known as trivial functional dependency if the set of attributes includes that attribute.

Symbolically: A ->B is trivial functional dependency if B is a subset of A.

The following dependencies are also trivial: A->A & B->B

e.g.
{Student_Id, Student_Name} -> Student_Id is a trivial functional dependency as Student_Id is a subset of {Student_Id, Student_Name}.  That makes sense because if we know the values of Student_Id and Student_Name then the value of Student_Id can be uniquely determined.

Also, Student_Id -> Student_Id & Student_Name -> Student_Name are trivial dependencies too.


### Non trivial functional dependency
If a functional dependency X->Y holds true where Y is not a subset of X then this dependency is called non trivial Functional dependency.

e.g.
An employee table with three attributes: emp_id, emp_name, emp_address.
The following functional dependencies are non-trivial:
emp_id -> emp_name (emp_name is not a subset of emp_id)
emp_id -> emp_address (emp_address is not a subset of emp_id)

Completely non trivial FD:
If a FD X->Y holds true where X intersection Y is null then this dependency is said to be completely non trivial function dependency.


### Multivalued dependency
Multivalued dependency occurs when there are more than one independent multivalued attributes in a table.

e.g.
bike_model  manuf_year  color
M1001   2007    Black
M1001   2007    Red
M2012   2008    Black
M2012   2008    Red
M2222   2009    Black
M2222   2009    Red
Here columns manuf_year and color are independent of each other and dependent on bike_model. In this case these two columns are said to be multivalued dependent on bike_model. These dependencies can be represented like this:

bike_model ->> manuf_year

bike_model ->> color


### Transitive Dependency
A functional dependency is said to be transitive if it is indirectly formed by two functional dependencies. For e.g.

X -> Z is a transitive dependency if the following three functional dependencies hold true:
    X->Y
    Y does not ->X
    Y->Z

Note: A transitive dependency can only occur in a relation of three of more attributes. This dependency helps us normalizing the database in 3NF (3rd Normal Form).

e.g.
Book    Author  Author_age
Game of Thrones George R. R. Martin 66
Harry Potter    J. K. Rowling   49
Dying of the Light  George R. R. Martin 66
{Book} ->{Author} (if we know the book, we knows the author name)

{Author} does not ->{Book}

{Author} -> {Author_age}

Therefore as per the rule of transitive dependency: {Book} -> {Author_age} should hold, that makes sense because if we know the book name we can know the author’s age.


## Normalization in DBMS: 1NF, 2NF, 3NF and BCNF in DB
Normalization is a process of organizing the data in database to avoid:
- data redundancy
- insertion|update|deletion anomaly.

Let’s discuss about anomalies first then we will discuss normal forms with examples.

### Anomalies in DBMS
There are three types of anomalies that occur when the database is not normalized. These are – Insertion, update and deletion anomaly.

Let’s take an example to understand this.

emp_id  emp_name    emp_address emp_dept
101 Rick    Delhi   D001
101 Rick    Delhi   D002
123 Maggie  Agra    D890
166 Glenn   Chennai D900
166 Glenn   Chennai D004

The above table is not normalized. We will see the problems that we face when a table is not normalized.

- Update anomaly
In the above table we have two rows for employee Rick as he belongs to two departments of the company. If we want to update the address of Rick then we have to update the same in two rows or the data will become inconsistent. If somehow, the correct address gets updated in one department but not in other then as per the database, Rick would be having two different addresses, which is not correct and would lead to inconsistent data.

- Insert anomaly
Suppose a new employee joins the company, who is under training and currently not assigned to any department then we would not be able to insert the data into the table if emp_dept field doesn’t allow nulls.

- Delete anomaly
Suppose, if at a point of time the company closes the department D890 then deleting the rows that are having emp_dept as D890 would also delete the information of employee Maggie since she is assigned only to this department.

To overcome these anomalies we need to normalize the data. In the next section we will discuss about normalization.


### Normalization
Here are the most commonly used normal forms:
    - First normal form(1NF)
    - Second normal form(2NF)
    - Third normal form(3NF)
    - Boyce & Codd normal form (BCNF)

#### First normal form (1NF) 一格不能有多个值 => 没法query
As per the rule of first normal form:
- an attribute (column) of a table cannot hold multiple values. It should hold only atomic values.


emp_id  emp_name    emp_address emp_mobile
101 Herschel    New Delhi   8912312390
102 Jon         Kanpur      8812121212, 9900012222


This table is not in 1NF。
To make the table complies with 1NF we should have the data like this:
emp_id  emp_name    emp_address emp_mobile
101 Herschel    New Delhi   8912312390
102 Jon         Kanpur      8812121212
102 Jon         Kanpur      9900012222


#### Second normal form (2NF) 符合第一范式，且同一行不能有值取决于其他FK候选值 => 数据冗余
A table is said to be in 2NF if both the following conditions hold:
- Table is in 1NF (First normal form)
- No non-prime attribute is dependent on the proper subset of any candidate key of table.

An attribute that is not part of any candidate key is known as non-prime attribute.

e.g.
teacher_subject table:
teacher_id  subject teacher_age
111 Maths   38
111 Physics 38
222 Biology 38
333 Physics 40
333 Chemistry   40

Candidate Keys: {teacher_id, subject}
Non prime attribute: teacher_age

It is not in 2NF because non prime attribute teacher_age is dependent on teacher_id alone which is a proper subset of candidate key.

To make the table complies with 2NF we can break it in two tables like this:
teacher_details table:

teacher_details table:
teacher_id  teacher_age
111 38
222 38
333 40

teacher_subject table:
teacher_id  subject
111 Maths
111 Physics
222 Biology
333 Physics
333 Chemistry


#### Third Normal form (3NF) (state, city, district)-> zip-> employeeID
A table design is said to be in 3NF if both the following conditions hold:
- Table must be in 2NF
- Transitive functional dependency of non-prime attribute on any super key should be removed.

An attribute that is not part of any candidate key is known as non-prime attribute.
An attribute that is a part of one of the candidate keys is known as prime attribute.

In other words 3NF can be explained like this: A table is in 3NF if it is in 2NF and for each functional dependency X-> Y at least one of the following conditions hold:
- X is a super key of table
- Y is a prime attribute of table

e.g. employee_details table
emp_id  emp_name    emp_zip emp_state   emp_city    emp_district
1001    John    282005  UP  Agra    Dayal Bagh
1002    Ajeet   222008  TN  Chennai M-City
1006    Lora    282007  TN  Chennai Urrapakkam
1101    Lilly   292008  UK  Pauri   Bhagwan
1201    Steve   222999  MP  Gwalior Ratan


Super keys: {emp_id}, {emp_id, emp_name}, {emp_id, emp_name, emp_zip}…so on
Candidate Keys: {emp_id}
Non-prime attributes: all attributes except emp_id are non-prime as they are not part of any candidate keys.

Here, emp_state, emp_city & emp_district dependent on emp_zip.
emp_zip is dependent on emp_id that makes non-prime attributes (emp_state, emp_city & emp_district) transitively dependent on super key (emp_id).
This violates the rule of 3NF.

To make this table complies with 3NF we have to break the table into two tables to remove the transitive dependency:

employee table:
emp_id  emp_name    emp_zip
1001    John    282005
1002    Ajeet   222008
1006    Lora    282007
1101    Lilly   292008
1201    Steve   222999


employee_zip table:
emp_zip emp_state   emp_city    emp_district
282005  UP  Agra    Dayal Bagh
222008  TN  Chennai M-City
282007  TN  Chennai Urrapakkam
292008  UK  Pauri   Bhagwan
222999  MP  Gwalior Ratan

#### Boyce Codd normal form (BCNF)
It is an advance version of 3NF that’s why it is also referred as 3.5NF.
BCNF is stricter than 3NF. A table complies with BCNF if it is in 3NF and for every functional dependency X->Y, X should be the super key of the table.

Example: Suppose there is a company wherein employees work in more than one department. They store the data like this:

emp_id  emp_nationality emp_dept    dept_type   dept_no_of_emp
1001    Austrian    Production and planning D001    200
1001    Austrian    stores  D001    250
1002    American    design and technical support    D134    100
1002    American    Purchasing department   D134    600

Functional dependencies in the table above:
emp_id -> emp_nationality
emp_dept -> {dept_type, dept_no_of_emp}

Candidate key: {emp_id, emp_dept}

The table is not in BCNF as neither emp_id nor emp_dept alone are keys.



To make the table comply with BCNF we can break the table in three tables like this:
emp_nationality table:
emp_id  emp_nationality
1001    Austrian
1002    American

emp_dept table:
emp_dept    dept_type   dept_no_of_emp
Production and planning D001    200
stores  D001    250
design and technical support    D134    100
Purchasing department   D134    600

emp_dept_mapping table:
emp_id  emp_dept
1001    Production and planning
1001    stores
1002    design and technical support
1002    Purchasing department

Functional dependencies:
emp_id -> emp_nationality
emp_dept -> {dept_type, dept_no_of_emp}

Candidate keys:
For first table: emp_id
For second table: emp_dept
For third table: {emp_id, emp_dept}

This is now in BCNF as in both the functional dependencies left side part is a key.


## Transaction Management in DBMS
A transaction is a set of logically related operations.
For example, you are transferring money from your bank account to your friend’s account, the set of operations would be like this:

### Simple Transaction Example
1. Read your account balance
2. Deduct the amount from your balance
3. Write the remaining balance to your account
4. Read your friend’s account balanace
5. Add the amount to his account balance
6. Write the new updated balance to his account

This whole set of operations can be called a transaction.
Although I have shown you read, write and update operations in the above example but the transaction can have operations like read, write, insert, update, delete.


### Transaction failure in between the operations
The main problem that can happen during a transaction is that the transaction can fail before finishing the all the operations in the set. This can happen due to power failure, system crash etc. This is a serious problem that can leave database in an inconsistent state.

To solve this problem, we have the following two operations
- Commit: If all the operations in a transaction are completed successfully then commit those changes to the database permanently.
- Rollback: If any of the operation fails then rollback all the changes done by previous operations.

Even though these operations can help us avoiding several issues that may arise during transaction but they are not sufficient when two transactions are running **concurrently**.

To handle those problems we need to understand database ACID properties.


## ACID properties
To ensure the integrity of data during a transaction，the database system maintains the following properties. These properties are widely known as ACID properties:

- Atomicity
    Transfer money from account A to B would be a single step
- Consistency
    To preserve the consistency of database, the execution of transaction should take place in isolation (that means no other transaction should run concurrently when there is a transaction already running).
    Otherwise e.g. $400 -> $200, $300; ($300, $300, $400);
- Isolation
    For every pair of transactions, one transaction should start execution only when the other finished execution.
- Durability
    Once a transaction completes successfully, the changes it has made into the database should be permanent even if there is a system failure. The recovery-management component of database systems ensures the durability of transaction.


## Concurrency Control
When more than one transactions are running simultaneously there are chances of a conflict to occur which can leave database to an inconsistent state. To handle these conflicts we need concurrency control in DBMS, which allows transactions to run simultaneously but handles them in such a way so that the integrity of data remains intact.


### Solution of Conflicts: Locks
A lock is kind of a mechanism that ensures that the integrity of data is maintained.
There are two types of a lock that can be placed while accessing the data so that the concurrent transaction can not alter the data while we are processing it.
1. Shared Lock(S)
2. Exclusive Lock(X)

Shared Lock(S):
Shared lock is placed when we are reading the data, multiple shared locks can be placed on the data but when a shared lock is placed no exclusive lock can be placed.

Exclusive Lock(X):
Exclusive lock is placed when we want to read and write the data. This lock allows both the read and write operation, Once this lock is placed on the data no other lock (shared or Exclusive) can be placed on the data until Exclusive lock is released.

Lock Compatibility Matrix
__________________________
|     |   S    |    X    |
|-------------------------
|  S  | True   |   False |
|-------------------------
|  X  | False  |   False |
--------------------------

## Deadlock
A deadlock is a condition wherein two or more tasks are waiting for each other in order to be finished but none of the task is willing to give up the resources that other task needs. In this situation no task ever gets finished and is in waiting state forever.

### Coffman conditions
Coffman stated four conditions for a deadlock occurrence. A deadlock may occur if all the following conditions holds true.
1) Mutual exclusion condition:
    There must be at least one resource that cannot be used by more than one process at a time.
2) Hold and wait condition:
    A process that is holding a resource can request for additional resources that are being held by other processes in the system.
3) No preemption condition:
    A resource cannot be forcibly taken from a process. Only the process can release a resource that is being held by it.
4) Circular wait condition:
    A condition where one process is waiting for a resource that is being held by second process and second process is waiting for third process ….so on and the last process is waiting for the first process. Thus making a circular chain of waiting.


### Deadlock Handling
- Ignore the deadlock (Ostrich algorithm)

- Deadlock detection
    Resource scheduler is one that keeps the track of resources allocated to and requested by processes. Thus, if there is a deadlock it is known to the resource scheduler. This is how a deadlock is detected.
    Terminating processes involved in deadlock..

- Deadlock prevention
1) Removing mutual exclusion:
    All resources must be sharable that means at a time more than one processes can get a hold of the resources. That approach is practically impossible.
2) Removing hold and wait condition:
    This can be removed if the process acquires all the resources that are needed before starting out. Another way to remove this to enforce a rule of requesting resource when there are none in held by the process.
3) Preemption of resources:
    Preemption of resources from a process can result in rollback and thus this needs to be avoided in order to maintain the consistency and stability of the system.
4) Avoid circular wait condition:
    This can be avoided if the resources are maintained in a hierarchy and process can hold the resources in increasing order of precedence. This avoid circular wait. Another way of doing this to force one resource per process rule – A process can request for a resource once it releases the resource currently being held by it. This avoids the circular wait.

- Deadlock Avoidance
Deadlock can be avoided if resources are allocated in such a way that it avoids the deadlock occurrence. There are two algorithms for deadlock avoidance.
    Wait/Die
    Wound/Wait
























