# 4TB3-Compilers-Project

# General Overview
  Our overall goal is to take any c file and convert it to a java class file. We first take the c read every character and then convert it to jasmin assembly code, into a **file.j**. We can then use jasmin to convert the **.j** file to a class file.

# How to run
  - Download the repository
  - Download JASMIN
    - Mac people can run ``brew jasmin``
    - Windows people can go to **http://jasmin.sourceforge.net**
    - Linux can install using the terminal installer like **apt-get**, **yum**
  - Run ``make`` this will compile the compiler and one of the test cases ``add_num``
    - To run the c test case go to C-Program and run ``./add_num``
    - To run the java test case go to Java-Program and run ``java add_num``
    - To run the parsed file from the home directory run ``java add_num``
  - There are other options in the make file that you can run which will clean the code and just compile the compiler

# How to contribute
  1. Create an issue wait for approval
  2. Fork the project & clone locally
  3. Create an upstream remote and sync your local copy before you branch
  4. Branch for each separate piece of work
  5. Do the work, write good commit messages
  6. Push to your origin repository
  7. Create a new Pull Request in GitHub
