bison -v -d jlang.y

flex jlang.lex
/D/MinGW/bin/gcc -o lab3 main.c -lfl