/*Name : Ankush Gauro
Quiz 4
ID: 108593237
oracle id: dbs211_241zbb10*/

CREATE TABLE STUDENT (
    Campus_no CHAR(1),
    mn NUMERIC(3),
    Stud_lname CHAR(15),
    Stud_fname CHAR(15),
    Stud_pgm CHAR(3) DEFAULT 'CPA',
    Locker_no NUMERIC(3),
    PRIMARY KEY (Campus_no, mn),
    FOREIGN KEY (Stud_pgm) REFERENCES PGM(Pgm_id),
    CONSTRAINT chk_locker_no UNIQUE (Locker_no)
);

CREATE TABLE PGM (
    Pgm_id CHAR(3) PRIMARY KEY,
    CHECK (Pgm_id IN ('CPA', 'CPD')),
    Pgm_name CHAR(40) UNIQUE NOT NULL,
    No_semesters NUMERIC(1) UNIQUE CHECK (No_semesters >= 0 AND No_semesters <= 6)
);

INSERT INTO Student (Campus_no, mn, Stud_lname, Stud_fname, Locker_no)
VALUES ('M', 999, 'Ankush', 'Gauro', 888);
 
INSERT INTO PGM (Pgm_id, Pgm_name, No_semesters)
VALUES ('CPP', 'Computer Programming', 4);