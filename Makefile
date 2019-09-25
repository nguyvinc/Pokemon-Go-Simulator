CC = g++
exe_file = go

$(exe_file): driver.o cave.o event.o flying.o location.o pokemon.o pokestop.o psychic.o rock.o
	$(CC) driver.o cave.o event.o flying.o location.o pokemon.o pokestop.o psychic.o rock.o -o $(exe_file)	
driver.o: driver.cpp
	$(CC) -c driver.cpp
cave.o: cave.cpp
	$(CC) -c cave.cpp
event.o: event.cpp
	$(CC) -c event.cpp
flying.o: flying.cpp
	$(CC) -c flying.cpp
location.o: location.cpp
	$(CC) -c location.cpp
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
pokestop.o: pokestop.cpp
	$(CC) -c pokestop.cpp
psychic.o: psychic.cpp
	$(CC) -c psychic.cpp
rock.o: rock.cpp
	$(CC) -c rock.cpp
	
debug:
	$(CC) -c driver.cpp
	$(CC) -c cave.cpp
	$(CC) -c event.cpp
	$(CC) -c -DDEBUG flying.cpp
	$(CC) -c -DDEBUG location.cpp
	$(CC) -c pokemon.cpp
	$(CC) -c pokestop.cpp
	$(CC) -c -DDEBUG psychic.cpp
	$(CC) -c -DDEBUG rock.cpp
	$(CC) driver.o cave.o event.o flying.o location.o pokemon.o pokestop.o psychic.o rock.o -o $(exe_file)
	
clean:
	rm -f *.out *.o $(exe_file)