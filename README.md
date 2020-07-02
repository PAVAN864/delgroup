# delgroup

- Program in C to mimic the “delgroup” command on Linux. This command will delete a group. 
- It handles 2 files “gshadow” and “group”. Both these files are in some folder specified by an environment variable PFILE. 
- The program takes all arguments as command line arguments

##Instructions to execute the Program:
1. Clone this repository 
```
git clone https://github.com/Abhishek4848/delgroup.git
```
2. The two files as mentioned in the question should be present in a folder and change the path to the file accordingly prior to execution.
3. Executing the program<br />
Windows
```
mingw32-make -f makefile.mk
```<br/>
Linux<br />
```
make -f makefile.mk
```
4. hen "./a.exe" or "./a.out" depending on OS to run the program
5. After compilation type "delgroup groupname" to execute the program successfully.
