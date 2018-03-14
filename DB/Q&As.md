> What are the standard SQL commands every SQL developer should know?

The basic SQL commands can be organized into the following categories:

Data Manipulation Language (DML)
    INSERT: Creates records. The “Create” in CRUD.
    SELECT: Retrieves records. The “Read” in CRUD.
    UPDATE: Modifies records. The “Update” in CRUD.
    DELETE: Deletes records. The “Delete” in CRUD.

Data Definition Language (DDL)
    CREATE: Creates a new object.
    ALTER: Alters an existing object.
    DROP: Deletes an existing object.

Data Control Language: (DCL)
    GRANT: Grants privileges to users.
    REVOKE: Revokes privileges previously granted to a user.

In practice however, you should be aware that your typical developer is most likely going to answer this question with CRUD (Create, Read, Update, and Delete), the four essential database operations for database manipulation. Bonus points if they also mention some of the others.


> What is a NULL value and how does it differ from a zero value?

0 - 0
NULL - N/A


> What are SQL Constraints?

Constraints are rules you can place on columns or tables to limit the type of data that can be entered into a table. This prevents errors and can improve the accuracy and reliability of the database as a whole. Common constraints include:

    NOT NULL: Prevents a column from having a NULL value.
    DEFAULT: Specifies a default value for a column where none is specified.
    PRIMARY KEY: Uniquely identifies rows/records within a database table.
    FOREIGN KEY: Uniquely identifies rows/records from external database tables.
    UNIQUE: Ensures all values are unique.
    CHECK: Checks values within a column against certain conditions.
    INDEX: Quickly creates and retrieves data from a database.


> Name four ways to maintain data integrity within a RDBMS.

When it comes to storing data accurately, consistently, and reliably within a RDBMS, there are four general types of data integrity that you can implement:

    Domain (Column) Integrity: Restricts the type, format, or range of values to enforce valid entries.
    Entity (Row) Integrity: Avoids duplicate rows in tables.
    Referential Integrity: Ensures rows used by other records cannot be deleted.
    User-Defined Integrity: Enforces rules set by the user that do not fall into the other categories.


> What is the purpose of database normalization and how does it work?

The primary purpose of normalization is to make databases more efficient by eliminating redundant data and ensuring data dependencies are coherent. Storing data logically and efficiently reduces the amount of space the database takes up and improves performance. The set of guidelines used to achieve normalization are called normal forms, numbered from 1NF to 5NF. A form can be thought of as a best-practice format for laying out data within a database


> Explain left/right/inner/outter joins.

https://stackoverflow.com/questions/13997365/sql-joins-as-venn-diagram


> Default JOIN?

Inner join.


> What is wrong with the SQL query below?

    SELECT UserId, AVG(Total) AS AvgOrderTotal
    FROM Invoices
    HAVING COUNT(OrderId) >= 1

The issue here is that there must be a GROUP BY clause here. This query will get the average order amount by customer (UserId) where the customer has at least 1 order. The correct query is listed below:

    SELECT UserId, AVG(Total) AS AvgOrderTotal
    FROM Invoices
    GROUP BY Userid
    HAVING COUNT(OrderId) >= 1


> Write a SQL query to find the 10th tallest peak (“Elevation”) from a “Mountain” table. Assume that there are at least 10 records in the Mountain table. Explain your answer.

SELECT Elevation FROM
(
  SELECT DISTINCT Elevation FROM Mountain ORDER BY Elevation DESC LIMIT 10
) AS Mt
ORDER BY Elevation
LIMIT 1;


> How do you maintain database integrity where deletions from one table will automatically cause deletions in another table?

You create a trigger that will automatically delete elements in the second table when elements from the first table are removed.


> What port does SQL server run on?

1433 is the standard port for SQL server.












