-- Create a table
CREATE TABLE Person (
    SSN CHAR(9) NOT NULL,
    Name VARCHAR(64) NOT NULL,
    PhoneNumber INT,
    Address VARCHAR(64),
);

-- Create another table that references values in Person
-- Used in database normalization
CREATE TABLE GuestList (
    Id VARCHAR(10) NOT NULL,
    Guest CHAR(9) REFERENCES Person.SSN NOT NULL,
    EmergencyContact CHAR(9) REFERENCES Person(SSN),  -- Also valid
    Seats INT NOT NULL,
    PRIMARY KEY (Id),  -- Seems to be optional
);

-- Insert values
INSERT INTO Person (SSN, Name) VALUES ('465915467', 'John Doe'), ('324978131', 'Jane Doe');
INSERT INTO Person (Name, SSN) VALUES ('Bob', '216913827'), ('Alice', '215539117');

-- Retrieve values
SELECT (Name, PhoneNumber) FROM Person WHERE Name = 'John Doe' ORDER BY Id;
SELECT DISTINCT (Name, PhoneNumber) FROM Person WHERE Name = 'John Doe' ORDER BY Id DESC;
SELECT (Name, PhoneNumber) FROM Person WHERE Name LIKE '%Doe%' ORDER BY Id;

SELECT Person.SSN FROM Person, GuestList WHERE GuestList.Guest = Person.SSN AND SEATS > 5;

-- Delete specific values
DELETE FROM Person WHERE Id = 'johndoe';

-- Delete entire table
DROP TABLE Person;
