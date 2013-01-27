strassen: strassen.c main.c
	gcc -O3 -o strassen strassen.c main.c

clean:
	/bin/rm *.o strassen
