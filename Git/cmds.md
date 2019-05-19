# Bash



#### Command line

> text interface for the computer

* a program that takes in commands, which it passes on to the computer's operating system to run
* you can navigate through files and folders on your computer
* run programs, write scripts to automate common tasks, combine simple commands to handle difficult tasks


#### Filesystem

- first directory in the filesystem is the `root directory`
  - parent of al other directories and files




## Viewing and Changing the File System

* `$` *shell prompt* 
  * appears when the terminal is ready to accept a command
* `ls` *lists*
  * looks at the folder you are in
  * *options*
    * `-a` lists hidden files and directories
    * `-l` lists all contents of a directory in long format
      * access rights
      * number of hard links - number of child directories and files
      * username
      * group name
      * size of the file
      * date & time
      * name
    * `-t` order files and directories by the time 
    * `-alt` lists all contents
* `pwd` *print working directory*
  * outputs the name of the working directory
* `cd <dirname>` *change directory*
  * switches you into the directory you specify
* `..` *move up one directory*
* `mkdir <dirname>` *make directory*
* `touch <filename>` *creates a new file*
* `cp <fromname> <toname>` *copy*
* `mv` <fromname> <toname>` *move* or *rename*
* `rm <filename>` *delete*
  * `rm -r <dirname>` *delete dir*



## Redirecting Input and Output

> Redirection reroutes stdin, stdout, stderr to or from a different location

* `echo "Hello"` *accepts the standard input*

  * print out the standard output
  * `stdin` - standard input; information inputted into the terminal through the keyboard or input device
  * `stdout` - standard output; information outputted after a process is run
  * `stderr` - standard error; error message outputted by a failed process
* `echo "Hello" > hello.txt`

  * `>` commands redirects the stdin to a file
* `cat hello.txt`

  * outputs the contents of a file to the terminal
* `cat oceans.txt > continents.txt`

  * takes the stdout of the command on the left and redirects it to the files on the right; overwrites all original content
* `cat oceans.txt >> continents.txt` 

  * `>>` takes the stdout of the command on the left and appends it to the right
* `cat < lakes.txt` 

  * `<` takes the stdin from the file on the right and inputs it into the program on the left
* `cat volcanoes.txt | wc`

  * `|` *pipe* takes stdout of the command on the lfet and pipes it as stdin to the command on the right
  * output of `cat volcanoes.txt` is the stdin of `wc`
  * `cat volcanoes.txt | wc | cat > islands.txt` pipe chaining
* `wc <filename>`  *word count*
  * outputs the number of lines, words, characters
* `sort <filename>`

  * takes stdin and orders it alphabetically for the stdout
  * `cat lakes.txt | sort > sorted-lakes.txt` takes the stdout from `cat lakes.txt` and pipes it to `sort`, then the stdout of `sort` is redirected to `sorted-lakes.txt`
* `uniq <filename>` *unique*

  * filters out adjacent, duplicate lines in a file
  * efficient way to call this is to call *sort* first then pipe the stdout to `uniq`
    * `sort deserts.txt | uniq > uniq-deserts.txt`
* `grep` *global regular expression print*

  * searches file for lines that match a pattern and returns the results
  * case sensitive
  * `grep Mount mountains.txt` searches for "Mount" in `mountains.txt` 
* `grep -i` enables case insensitive
* `grep -R Arctic /home/ccuser/workspace/geography`
  * searches all files in a directory and outputs filenames and lines containing matched results
  * `-R` *recursive*
* `grep -Rl Arctic /home/ccuser/workspace/geography/`
  * searches all files in a directory and outputs only filenames with matched results
  * `-l` *files with matches*
* `sed` *stream editor*
  * accepts stdin and modifies it based on an expression, before displaying it as output data; find and replace
  * `sed 's/snow/rain/g' forests.txt`
    * `s` *substitution*
    * `snow` *search string*
    * `rain` * replacement string
    * searches `forests.txt` for the first word "snow" and replaces it with "rain"
    * `g` *global*; all instances replaced
* `head`
  * reads the first few lines of any text given to it as an input and writes them to stdout



## Configuring the Environment

* each time we launch the terminal app, it creates a new session

* the session immediately loads settings and preferences that make up the command line *environment*

* we can configure the environment to support the commands and programs we create

* this enables us to customize greetings and command aliases, and create variables to share across commands and programs

  

#### nano

* simple, command line text editor
* `nano hello.txt`
* `^` is the `ctrl` key
* `nano ~/.bash_profile`
  * `.bash_profile` - name of file used to store environment settings
  * when a session starts, it will load the contents of the bash profile before executing commands
* after changes, `source ~/.bash_profile`
  * activates changes available right away in the sessions
* `~` user's home directory
* `.` a hidden file
* `alias pd="pwd"`
  * create keyboard shortcuts

```bash
alias hy="history"
alias ll="ls -la"
```

* `export USER="Jane Doe"`
  * *environment variable*s are variables that can be used across commands and programs and hold information about the environment
  * sets the environment variable `USER` to a name "Jane Doe"
  * `export` makes the variable to be available to all child sessions initiated from the session your are in
* `echo $USER` returns the name set for the variable
* `export PS1=">> "`
  * `PS1` is a variable that defines the makeup and style of the command prompt
  * sets the command prompt variable and exports the variable.
  * `$` to `>>`
* echo $HOME
  * home directory
* echo $USER
  * name of the current user
* echo $PATH
  * environment variable that stores a list of directories separated by a colon
  * each directory contains scripts for the command line to execute
  * simply lists which directories contain scripts
  * customize the PATH variable when adding scripts of your own
  * `env | grep PATH`
    * displays the value of a single environment variable
    * stdout of `env` is piped to the `grep` then, searches for the value of the variable `PATH`
* `less <filename>`
  * similar to `cat` but adapted to handle larger files, displays files in the terminal one page at a time



## Bash Scripting

* automate repetitive tasks
* executes within a bash shell interpreter terminal
* **conventions**
  * the beginning of your script file should start with `#!/bin/bash`
    * tells the computer which type of interpreter to use for the scirpt
    * when saving the script file, place commonly used scripts in the `~/bin/`
  * to add permission to a file with filename: `script.sh`
    * `chmod +x script.sh`
* your terminal runs a file every time it is opened to load its configuration
* on linux style shells, this is `~/.bashrc`
* on OSX, `~/bash_profile`
* to ensure that scripts in `~/bin/` are available, you must add this directory to your `PATH` within in your configuration file: `PATH=~/bin:$PATH`
  * any scripts in the `~/bin` directory can be run from anywhere by typing the filename

* within bash scripts, variables are declared by setting the variable name equal to another value. For example, to set the variable `greeting` to "Hello", you would use the following syntax: `greeting="Hello"`
* to access the value of a variable, we use the variable name prepended with a dollar sign`$`

```sh
#!/bin/bash
phrase="Hello to you!"
echo $phrase
echo "yo man!"
```



#### Conditionals

```sh
if [ $index -lt 5]
then
  echo $index
else
  echo 5
fi
```

* `-eq` equal
* `-ne` not eqaul
* `-le` less than or equal
* `-lt` less than
* `-ge` greater than or equal
* `-gt` greater than
* `-z` is null

```sh
if [ "foo" == "$bar" ]
```

```sh
for word in $paragraph
do
  echo $word
done

while [ $index -lt 5 ]
do
  echo $index
  index=$((index + 1))
done

until [ $index -eq 5 ]
do
  echo $index
  index=$((index + 1))
done
```

```sh
echo "Guess a number"
read number
echo "You guessed $number"
```

```sh
#!/bin/bash
first_greeting="Nice to meet you!"
later_greeting="How are you?"
greeting_occasion=0
echo "How many times should I greet?"
read greeting_limit
while [ $greeting_occasion -lt $greeting_limit ]
do
  if [ $greeting_occasion -lt 1 ]
  then
    echo $first_greeting
  else
    echo $later_greeting
  fi
  greeting_occasion=$((greeting_occasion +1))
done
```

first input to cmd: `alias saycolors='./saycolors.sh' "green"'`

`./script.sh 5 #greets 5 times`



### Build a Build Script

* bash script

```sh
#!/bin/bash

echo "Begininning the build!"

firstline=$(head -n 1 source/changelog.md)

read -a splitfirstline <<< $firstline

version=${splitfirstline[1]}
echo "You are building version" $version

echo 'Do you want to continue? (enter "1" for yes, "0" for no)'
read versioncontinue

if [ $versioncontinue -eq 1 ]
then
  echo "OK"
else
  echo "Please come back when you are ready"
fi

for filename in source/*
do
  echo $filename
  if [ "$filenmae" == "source/secretinfo.md" ]
  then
    echo "Not copying" $filename
  else
    echo "Copying" $filename
    cp $filename build/.
  fi
done

cd build/
echo "Build version $version contains:"
ls
cd ..
```



