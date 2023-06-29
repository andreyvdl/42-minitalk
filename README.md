<div align="center">
  <img src="https://github.com/gawbsouza/42-pdh/blob/main/dark/minitalk_dark.svg"><br>
  <a href="https://github.com/gawbsouza/42-pdh"><img src="https://github.com/gawbsouza/42-pdh/blob/main/badge/42pdh_badge.svg"></a>
</div>

___
Program name | Files to turn in | External functions | Result
:---: | :---: | :---: | :--:
client, server	| *.c, *.h, Makefile| libft functions, write, signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit | 125/100%

## Objective

> You must create a communication program in the form of a client and a server.   
> The server must be started first. After its launch, it has to print its PID.   
The client takes two parameters:
> * The server PID.  
> * The string to send.  
> 
> The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.

## Execution

```sh
make
```

on terminal 1:

```sh
./server
```

on terminal 2:

```sh
./client server_pid string
```

OR

```sh
make bonus
```

on terminal 1:

```sh
./server
```

on terminal 2:

```sh
./client server_pid string
```
