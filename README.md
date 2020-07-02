# delgroup

- Program in C to mimic the “delgroup” command on Linux. This command will delete a group. 
- It handles 2 files “gshadow” and “group”. Both these files are in some folder specified by an environment variable PFILE. 
- The program takes all arguments as command line arguments

## Instructions to execute the Program:
1. Clone this repository 
```
git clone https://github.com/Abhishek4848/delgroup.git
```
2. Change directory to the program folder
```
cd delgroup
```
3. Executing the program
  - Windows
```
mingw32-make -f makefile.mk
./a.exe
```
  - Linux
```
make -f makefile.mk
./a.out
```
4. After compilation type "delgroup groupname" to execute the program successfully.
