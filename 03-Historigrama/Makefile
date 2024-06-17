CC=gcc
standar=main.o graficadora.o
headers=histograma.h graficadora.h
output=histograma

1: enum-switch clean
2: goto clean
3: rec clean

enum-switch: $(standar) histograma-1-enum-switch.o $(headers)
	$(CC) $(standar) histograma-1-enum-switch.o -o $(output)

goto: $(standar) histograma-2-goto.o $(headers)
	$(CC) $(standar) histograma-2-goto.o -o $(output)

rec: $(standar) histograma-3-rec.o $(headers)
	$(CC) $(standar) histograma-3-rec.o -o $(output)

clean:
	del -f *.o 
#	rm  -f *.o Para Unix
.PHONY: 1 2 3 x clean
