A5:	main.o Escape.o Hero.o Ninja.o  Snorc.o  Participant.o  random.o MoveBehaviour.o
	g++ -o A5 main.o Escape.o Hero.o Ninja.o  Snorc.o Participant.o random.o MoveBehaviour.o

main.o:	main.cc  Escape.h 
	g++ -c main.cc

Escape.o:	Escape.cc Escape.h List.h Hero.h Snorc.h Participant.h MoveBehaviour.h Ninja.h 
	g++ -c Escape.cc


Snorc.o:	Snorc.cc Snorc.h Participant.h
	g++ -c Snorc.cc


random.o:	random.cc  defs.h 
	g++ -c random.cc

Participant.o:	Participant.cc  Participant.h MoveBehaviour.h
	g++ -c Participant.cc

Hero.o:	Hero.cc Hero.h Participant.h MoveBehaviour.h
	g++ -c Hero.cc

Ninja.o:	Ninja.cc Ninja.h Participant.h MoveBehaviour.h
	g++ -c Ninja.cc

MoveBehaviour.o: MoveBehaviour.cc MoveBehaviour.h
	g++ -c MoveBehaviour.cc

clean:
	rm -f *.o A5