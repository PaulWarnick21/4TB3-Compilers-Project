compiler = ./Compiler/
cpp = ./C-Program/
java = ./Java-Program/
COMPILERHEADERS = $(compiler)parser.h $(compiler)abstractSyntaxTree.h
COMPILEROBJECTS = $(compiler)scanner.o
ADDNUM = add_num

CC=g++
JAVA=javac
JASMIN=jasmin

all:
	make tb3
	make addNum
	make run

%.o: %.c $(COMPILERHEADERS)
	$(CC) -c $< -o $@

tb3: $(COMPILEROBJECTS)
	$(CC) $(COMPILEROBJECTS) -o $@

addNum:
	$(CC) -c $(cpp)$(ADDNUM).c -o $(cpp)$(ADDNUM).o
	$(CC) $(cpp)$(ADDNUM).o -o $(cpp)$(ADDNUM)
	$(JAVA) $(java)$(ADDNUM).java
	./tb3 $(cpp)$(ADDNUM).c
	$(JASMIN) $(cpp)$(ADDNUM).j


#cleanup function
tb3Clean:
	rm $(COMPILEROBJECTS) tb3

addNumClean:
	rm $(cpp)$(ADDNUM) *.class $(java)*.class $(cpp)$(ADDNUM).j
