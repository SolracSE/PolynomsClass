###############################################################################
#
# This class was coded by: Carlos Salas
# At date: June/2020
#
# mail: csalaseiroa@correo.ugr.es or carlossealternativo@gmail.com
#
###############################################################################
# PolynomsClass
Class which helps to work with polynoms. You will have multiple operations,
constructors, etc. It is coded using c++ but commented in Sapanish.

It will be translated to English soon.


# ./include/Polinomio.h

This file is the header where the class is declared and all of its methods.

You have to include this header to your main.cpp or wherever this class 
will be used.


# ./src/Polinomio.cpp

This file contains all the code of the class.



# How to compile

When compiling you will need a main.cpp and theese two files.

At first your main.cpp and your Polinomio.cpp must be compiled to object files
including the folder where Polinomio.h is located. G++ example:

g++ -c ./src/Polinomio.cpp -I./include
g++ -c ./src/main.cpp -I./include

Then you can compile your executable with the object files. G++ example:

g++ -o ./bin/EXecutable Polinomio.o main.o

# Suggestions and questions

Feel free to mail me whenever you want. I will answer as soon as I can.

My mails are at the top of this file.