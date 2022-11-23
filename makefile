.PHONY: all recursived loopd loops recursives clean
all : recursived loopd loops recursives mains maindloop maindrec
loopd : libclassloops.so
loops : libclassloops.a
recursived : libclassrec.so
recurisives : libclassrec.a


libclassloops.a : advancedClassificationLoop.o basicClassification.o
	ar -rc libclassloops.a advancedClassificationLoop.o basicClassification.o

libclassrec.a : advancedClassificationRecursion.o basicClassification.o
	ar -rc libclassrec.a advancedClassificationRecursion.o basicClassification.o

libclassrec.so :  advancedClassificationRecursion.c basicClassification.c
	gcc -Wall -fPIC -c advancedClassificationRecursion.c basicClassification.c
	gcc -shared -Wall advancedClassificationRecursion.o basicClassification.o -o libclassrec.so
	export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

libclassloops.so :  advancedClassificationLoop.c basicClassification.c
	gcc -Wall -fPIC -c advancedClassificationLoop.c basicClassification.c
	gcc -shared -Wall advancedClassificationLoop.o basicClassification.o -o libclassloops.so
	export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

mains : main.o NumClass.h libclassrec.a
	gcc -Wall main.c -L. ./libclassrec.a -o mains

maindloop : main.o NumClass.h libclassloops.so
	gcc -Wall main.c -L. ./libclassloops.so -o maindloop

maindrec : main.o NumClass.h libclassrec.so
	gcc -Wall main.c -L. ./libclassrec.so -o maindrec

clean :
	rm maindrec maindloop mains *.o *.so *.a

