# RedReader (rer)

RedReader is a lightweight terminal syntax highlighter it's not the best but it's small and fast

# Fully Supported Languages
 - C
 - C++
 - Python

# Compatibility

## Required To Make ( Can be uninstalled after )

[Git](https://git-scm.com/)

[GNU Make](https://www.gnu.org/software/make/) - Not for Windows Native

[GCC](https://gcc.gnu.org/)

## Windows

[Cygwin](https://www.cygwin.com/) - Git

Native - Git

## Linux

[Ubuntu](https://ubuntu.com/) - Git

[Arch](https://archlinux.org/) - Git

Other - Git


# Install

***I suggest using `strip -s` on it***

***Strip with `sudo strip -s /usr/bin/rer` after installation***

Binary is placed in `/usr/bin/rer`

## Cygwin
```
$ make mk

$ make cyg
```

## Windows

```
> mkdir .\bin

> gcc .\src\*.c -o .\bin\rer
```

output file in `.\bin\rer.exe` move it to were ever you want

## Linux
```
$ make mk

$ make linux
```
