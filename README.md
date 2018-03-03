# Y86_64 Pipeline Demo

Simulates the pipeline behaviour of a y86-64 processor, including detection of hazards and stalling.

![Screenshot](screenshot.png)

# Requirements
 * GNU Make
 * GCC

 This was developed using 64-bit Cygwin on Windows but was tested in 64-bit Debian Linux as well.

 # Building
 Just build the Makefile:
 ```
 $ cd src
 $ make
 ```

 # Running
 Command line syntax:
 ```
 $ ./pipe [y86-64 object code file] (optional start address)
 ```

 For example:
 ```
 $ ./pipe ../input/Sample1.mem 0x5013
 ```
