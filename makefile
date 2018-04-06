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
	make javac++
	make addNum
	# make run

%.o: %.c $(COMPILERHEADERS)
	$(CC) -c $< -o $@

javac++: $(COMPILEROBJECTS)
	$(CC) $(COMPILEROBJECTS) -o $@

addNum:
	$(CC) -c $(cpp)$(ADDNUM).c -o $(cpp)$(ADDNUM).o
	$(CC) $(cpp)$(ADDNUM).o -o $(cpp)$(ADDNUM)
	$(JAVA) $(java)$(ADDNUM).java
	./javac++ $(cpp)$(ADDNUM).c
	$(JASMIN) $(cpp)$(ADDNUM).j


#cleanup function
clean: javac++Clean addNumClean

javac++Clean:
	rm $(COMPILEROBJECTS) javac++

addNumClean:
	rm $(cpp)$(ADDNUM) *.class $(java)*.class $(cpp)$(ADDNUM).j
