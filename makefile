strtest: list.c
	gcc list.c -o list

clean:
	rm *~	

run: list
./list