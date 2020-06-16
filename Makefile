CC := gcc

comi:main.o list.o befile.o sybla.o uril.o ops.o centre.o
	gcc -g  -o $@ $^
main.o:main.c
	gcc -c  $<
befile.o:befile.c befile.h
	gcc -c $<
centre.o:centre.c centre.h
	gcc -c $<
uril.o:uril.c uril.h
	gcc -c $<
sybla.o:sybla.c sybla.h
	gcc -c $<
list.o:list.c list.h
	gcc -c $<
ops.o:ops.c ops.h
	gcc -c $<
.PHONY:clean
clean:
	@rm -fr $(OBJ)/*.o $(BIN_DIR)
