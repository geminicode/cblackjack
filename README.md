# cblackjack

# Requirements

# Dependencies

* CMake 3.10.x
* Google Test/Mock
* Doxygen
* Graphviz
* GCOV
* LCOV

## CMake

```
sulaco-mac:cblackjack darrell$ brew install doxygen
==> Downloading https://homebrew.bintray.com/bottles/doxygen-1.8.18.high_sierra.bottle.tar.gz
==> Downloading from https://akamai.bintray.com/63/630a2c57c428c9ae42d5d6f6f5986a08292db010c51f407c1bbb6224c4d9ddf7?__
######################################################################## 100.0%
==> Pouring doxygen-1.8.18.high_sierra.bottle.tar.gz  
/usr/local/Cellar/doxygen/1.8.18: 11 files, 17.9MB
sulaco-mac:cblackjack darrell$ which doxygen
/usr/local/bin/doxygen
```

## Graphviz

```
sulaco-mac:cblackjack darrell$ brew install graphviz
==> Downloading https://homebrew.bintray.com/bottles/libpng-1.6.37.high_sierra.bottle.tar.gz
==> Downloading from https://akamai.bintray.com/bb/bbdd94bdd5954bc50c096391486e67265dce5631efb913dcffe4469806a242b6?__
######################################################################## 100.0%
...
```

## GCOV


## LCOV



# CMake

```
sulaco-mac:~$ cd ~/git/cblackjack_build/
sulaco-mac:~/git/cblackjack_build$ cmake -DCMAKE_BUILD_TYPE=Debug ../cblackjack -G "Eclipse CDT4 - Unix Makefiles"
-- Eclipse version is set to 3.6 (Helios). Adjust CMAKE_ECLIPSE_VERSION if this is wrong.
-- Configuring done
-- Generating done
-- Build files have been written to: /home/devadmin/git/cblackjack_build
sulaco-mac:~/git/cblackjack_build$
```

## Build

```
sulaco-mac:~/git/cblackjack_build$ cmake --build . --clean-first
Scanning dependencies of target cblackjack
[ 50%] Building C object src/CMakeFiles/cblackjack.dir/main.c.o
[100%] Linking C executable cblackjack
[100%] Built target cblackjack
sulaco-mac:~/git/cblackjack_build$
```

## Test

```
sulaco-mac:cblackjack_build darrell$ ctest
Test project /Users/darrell/git/cblackjack_build
    Start 1: card_test
1/1 Test #1: card_test ........................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.02 sec
sulaco-mac:cblackjack_build darrell$
```

## XUnit.xml

```
sulaco-mac:cblackjack_build darrell$ ctest --no-compress -T Test
Cannot find file: /Users/darrell/git/cblackjack_build/DartConfiguration.tcl
   Site:
   Build name: (empty)
Cannot find file: /Users/darrell/git/cblackjack_build/DartConfiguration.tcl
Test project /Users/darrell/git/cblackjack_build
    Start 1: card_test
1/1 Test #1: card_test ........................   Passed    0.06 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.13 sec
sulaco-mac:cblackjack_build darrell$ ls Testing/20200515-1757/Test.xml
Testing/20200515-1757/Test.xml
sulaco-mac:cblackjack_build darrell$
```

## Code Coverage (In Progess)

CTest also supports code coverage and reporting.  

Note: This step may take a few minutes.

```
sulaco-mac:cblackjack_build darrell$ ctest -T coverage
Cannot find file: /Users/darrell/git/cblackjack_build/DartConfiguration.tcl
   Site:
   Build name: (empty)
Cannot find file: /Users/darrell/git/cblackjack_build/DartConfiguration.tcl
Performing coverage
```

# Execute

```
sulaco-mac:~/git/cblackjack_build$ bin/cblackjack
Hello
sulaco-mac:~/git/cblackjack_build$
```
