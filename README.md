# cblackjack

## Generate Build 

```
sulaco-mac:~$ cd ~/git/cblackjack_build/
sulaco-mac:~/git/cblackjack_build$ cmake ../cblackjack -G "Eclipse CDT4 - Unix Makefiles"
-- Eclipse version is set to 3.6 (Helios). Adjust CMAKE_ECLIPSE_VERSION if this is wrong.
-- Configuring done
-- Generating done
-- Build files have been written to: /home/devadmin/git/cblackjack_build
sulaco-mac:~/git/cblackjack_build$ 
```

### Build

```
sulaco-mac:~/git/cblackjack_build$ cmake --build . --clean-first
Scanning dependencies of target cblackjack
[ 50%] Building C object src/CMakeFiles/cblackjack.dir/main.c.o
[100%] Linking C executable cblackjack
[100%] Built target cblackjack
sulaco-mac:~/git/cblackjack_build$ 

```

### Execute

```
sulaco-mac:~/git/cblackjack_build$ bin/cblackjack 
Hello
sulaco-mac:~/git/cblackjack_build$ 
```
