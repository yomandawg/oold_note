# Learn SQL

* SQL - **S**tructured **Q**uery **L**anguage
* RDBMS - SQLite **R**elational **D**atabase **M**anagement **S**ystem



## Manipulation



### Relational Databases

* *Relational Database* - database that organizes information into one or more tables
* *Table* - collection of data organized into rows and columns; sometimes referred to as *relations*
  * `celebs`
* *column* - set of data values of a particular type
  * `id` `name` `age`
* *row* - single record in a table
  * first row in the `celebs` has:
    * `id` of `1`
    * `name` of `Justin Bieber`
    * `age` of `22`
* All data stored in a relational database is of a certain types are:
  * `INTEGER`: positive or negative whole number
  * `TEXT`: a text string
  * `DATE`: date formatted as YYYY-MM-DD
  * `REAL`: decimal value



### Statements

* *Statement* - text that the database recognizes as a valid commmand

  * always end with `;`

  ```sql
  CREATE TABLE table_name (
     column_1 data_type, 
     column_2 data_type, 
     column_3 data_type
  );
  ```

* Components of a statement:

  * `CREATE TABLE` is a *clause*: perform specific tasks, also referred to as *commands*
  * `table_name` refers to the name of the table that the command is applied to
  * `(column_1 data_type, column_2 data_type, column_3 data_type)` is a *parameter*
    * list of columns, data types, or values that are passed to a clause as an argument
    * the parameter is a list of column names and the associated data type

  Example) `SELECT * FROM celebs;`
  * `SELECT` and `FROM` are the clauses
  * applying the command to the `celebs` table



### Create

* `CREATE` statements allow us to create a new table in the database

  ```sql
  CREATE TABLE celebs (
     id INTEGER, 
     name TEXT, 
     age INTEGER
  );
  ```

  * `CREATE TABLE` is a clause to create a new table
  * `celebs` is the name of the table
  * `(id INTEGER, name TEXT, age INTEGER)` is a list of parameters defining column and  data type:
    * `id` is the first column, stores value of data type `INTEGER`
    * `name` is the second column, stores data type `TEXT`
    * `age` is the third, stores the data type `INTEGER`



### Insert

* `INSERT` inserts a new row into a table

  ```SQL
  INSERT INTO celebs (id, name, age) 
  VALUES (1, 'Justin Bieber', 22);
  ```

  * `INSERT INTO` is a clause that adds the specified row or rows
  * `celebs` is the name of the table the row is added to
  * `(id, name, age)` is a parameter identifying the columns that data will be inserted into
  * `values` is a clause that indicates the data being inserted
    * `(1, 'Justin Bieber', 22)` is the parameter
  * `1` is an integer that will be inserted into the `id` column
  * `Justin Bieber` is the text that will be inserted into the `name` column
  * `22` is an integer that will be inserted into the `age` column



### Select

* `SELECT` statements are used to fetch data from a database

  `SELECT name FROM celebs;`

  * returns all data in the `name` column of the `celebs` table
  * `SELECT` is a clause that indicates that the statement is a query.
  * `name` specifies the column to query data from
  * `FROM celebs` specifies the name of the table to query data from
    * data is queried from the `celebs` table

  `SELECT * FROM celebs;`

  * `*` is a special character allowing you to select every column in a table

* `SELECT` always return a new table called the *result set*



### Alter

* `ALTER TABLE` statement adds a new column to a table

  ```sql
  ALTER TABLE celebs 
  ADD COLUMN twitter_handle TEXT;
  ```

  * `ALTER TABLE` is a clause that lets you make the specified changes
  * `celebs` is the name of the table that is being created
  * `ADD COLUMN` is a clause that lets you add a new column to a table
    * `twitter_handle` is the name of the new column being added
    * `TEXT` is the data type for the new column
  * `NULL` is a special value in SQL that represents missing or unknown data.
    * the rows that existed before the column was added have `NULL` values for `twitter_handle`



### Update

* `UPDATE` statement edits a row in a table

* You can use the `UPDATE` statement when you want to change existing records

  ```sql
  UPDATE celebs 
  SET twitter_handle = '@taylorswift13' 
  WHERE id = 4;
  ```

  * updates the record with and `id` value of `4` to have the `twitter_handle` `@taylorswift13`
  * `UPDATE` is a clause that edits a row in the table
  * `celebs` is the name of the table
  * `SET` is a clause that indicates the column to edit
    * `twitter_handle` is the name of the column that is going to be updated
    * `@taylorswift13` is the new value that is going to be inserted into the `twitter_handle` column
  * `WHERE` is a clause that indicates which row(s) to update with the new column value
    * row with a `4` in the `id` column is the row that will have the `twitter_handle` updated to



### Delete

* `DELETE FROM` statement deletes one or more rows from a table

  ```sql
  DELETE FROM celebs 
  WHERE twitter_handle IS NULL;
  ```

  * `DELETE FROM` is a clause that lets you delete rows from a table
  * `celebs` is the name of the table we want to delete rows from
  * `WHERE` is a clause that lets you select which rows you want to delete
    * delete all of the rows where the `twitter_handle` `IS NULL`
  * `IS NULL` is a condition in SQL that returns true when the value is `NULL` and false otherwise



### Constraints

* *Constraints* add information about how a column can be used

* invoked after specifying the data type for a column

  ```sql
  CREATE TABLE celebs (
     id INTEGER PRIMARY KEY, 
     name TEXT UNIQUE,
     date_of_birth TEXT NOT NULL,
     date_of_death TEXT DEFAULT 'Not Applicable'
  );
  ```

  * `PRIMARY KEY` columns can be used to uniquely identify the row
  * `UNIQUE` columns have a different value for every row
    * similar to `PRIMARY KEY` except a table can have different `UNIQUE` columns

  * `NOT NULL` columns must have a value
  * `DEFAULT` takes an assumed value for an inserted row if the new row does not specify a value



---



## Queries

* core purpose of the SQL language - to retrieve information stored in a database
* communicate with the database by asking questions and having the result set return data



### Select

* select individual columns by there names (separated by a comma):

  ```sql
  SELECT column1, column2 
  FROM table_name;
  ```

  * line breaks don't mean anything specific in SQL



### As

* `AS` is a keyword that allows you to *rename* a column or table using an alias

  ```SQL
  SELECT name AS 'Titles'
  FROM movies;
  ```

  * rename the `name` column as `Titles`



### Distinct

* `DISTINCT` is used to return unique values in the output.

  * filters out all duplicate values in the specified column(s).

  ```sql
  SELECT DISTINCT tools
  FROM inventory;
  ```

  * easier to see the different possible `genre`s in the `movie` table after the data has been filtered



### Where

* `WHERE` clause restricts the query results in order to obtain only the information we want

  ```sql
  SELECT *
  FROM movies
  WHERE imdb_rating > 8;
  ```

  * filters the result set to only include top rated movies

  * `imdb_rating > 8` is the condition for filtering
    * only rows with a value greater than 8 in the `imdb_rating` column will be returned

* *operator* returning *true* or *false*

  * `=` `!=` `>` `<` `>=` `<=`



### Like 1

* `LIKE` is a useful operator for comparing similar values

  ```sql
  SELECT * 
  FROM movies
  WHERE name LIKE 'Se_en';
  ```

  * `LIKE` is a special operator used with the `WHERE` clause to search for a specific pattern
  * `name LIKE 'Se_en'` is a condition evaluating the `name` column for a specific pattern
  * `Se_en` represents a pattern with a *wildcard* character
    * `_` means you can substitute any individual character without breaking the pattern
      * names `Seven` `Se7en` both match this pattern



### Like 2

* `%`  is a wildcard character that matches zero or more missing letters in the pattern

  ```sql
  SELECT * 
  FROM movies
  WHERE name LIKE 'A%';
  ```

  * `A%` matches all movies with names that begin with letter 'A'
  * `%a` matches all movies that end with 'a'

* can also use `%` both before and after a pattern:

  ```sql
  SELECT * 
  FROM movies 
  WHERE name LIKE '%man%';
  ```

  * any movies that contains the word 'man' in its name will be returned in the result
  * `LIKE` is not case sensitive
    * both 'Batman' and 'Man of Steel' will appear in the result of the query



### IS NULL

* unknown values are indicated by `NULL`

  * operators to use: `IS NULL` `IS NOT NULL`
  * not possible to test for `NULL` values with comparison operators such as `!=`

  ```sql
  SELECT name
  FROM movies 
  WHERE imdb_rating IS NOT NULL;
  ```

  * filter for all movies with an IMDb rating



### Between

* `BETWEEN` operator can be used in a `WHERE` clause to filter the result set within a certain *range*

  ```sql
  SELECT *
  FROM movies
  WHERE name BETWEEN 'A' AND 'J';
  ```

  * filters the result set to only include movies with `name`s that begin with letters 'A' up to, *but not including* 'J'.

  ```sql
  SELECT *
  FROM movies
  WHERE year BETWEEN 1990 AND 1999;
  ```

  * filter the result set to only include movies with `year`s between 1990 up to, *and including* 1999

* `BETWEEN` two letters *is not* inclusive of the second letter

* `BETWEEN` two numbers *is* inclusive of the second number



### And

* `AND` *combines multiple conditions* in a `WHERE` clause to make the result set more specific

  ```sql
  SELECT * 
  FROM movies
  WHERE year BETWEEN 1990 AND 1999
     AND genre = 'romance';
  ```

  * `year BETWEEN 1990 AND 1999` is the first condition
  * `genre = 'romance'` is the second condition
  * `AND` combines the two conditions



### Or

* `OR` operator in a `WHERE` clause displays a a row if *any* condition is true

  ```sql
  SELECT *
  FROM movies
  WHERE year > 2014
     OR genre = 'action';
  ```

  * `year > 2014` is the first condition
  * `genre = 'action'` is the second condition
  * `OR` combines the two conditions

  

### Order By

* *sort* the results using `ORDER BY` making the data more useful and easier to analyze

  ```sql
  SELECT *
  FROM movies
  ORDER BY name;
  ```

  * sort everything by the movie's title from A through Z
  * `ORDER BY` is a clause that indicates you want to sort the result set by a particular column
  * `name` is the specified column

   ```sql
  SELECT *
  FROM movies
  WHERE imdb_rating > 8
  ORDER BY year DESC;
   ```

  * sort things in decreasing order
  * `DESC` is a keyword used in `ORDER BY` to sort the results in *descending order*
  * `ASC` is a keyword used in `ORDER BY` to sort the results in *ascending order*

* note that `ORDER BY` always goes after `WHERE`



### Limit

* most SQL tables contain hundreds of thousands of records

* important to cap the number of rows in the result

  ```sql
  SELECT *
  FROM movies
  LIMIT 10;
  ```

  * `LIMIT` is a clause that lets you specify the maximum number of rows the result set will have
  * `LIMIT` always goes at the very end of the query



### Case

* `CASE` statement allows us to create *different outputs* (usually in the `SELECT` statment)

  * SQL's way of handiling *if-then* logic

* condense the ratings in `movies` to three levels:

  1. If the rating is above 8, then it is Fantastic
  2. If the rating is above 6, then it is Poorly Received
  3. Else, Avoid at All Costs

  ```sql
  SELECT name,
   CASE
    WHEN imdb_rating > 8 THEN 'Fantastic'
    WHEN imdb_rating > 6 THEN 'Poorly Received'
    ELSE 'Avoid at All Costs'
   END
  FROM movies;
  ```

  * Each `WHEN` tests a condition and the following `THEN` gives us the string if the condition is true
  * `ELSE` gives us the string if *all* the above conditions are false
  * `CASE` statements must end with `END`

  ```sql
  SELECT name,
   CASE
    WHEN imdb_rating > 8 THEN 'Fantastic'
    WHEN imdb_rating > 6 THEN 'Poorly Received'
    ELSE 'Avoid at All Costs'
   END AS 'Review'
  FROM movies;
  ```

  * when the result is too long, rename the column to 'Review' using `AS`

