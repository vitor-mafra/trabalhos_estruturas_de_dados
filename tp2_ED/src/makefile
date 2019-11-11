agendaDeViagens: main.o visita.o agenda.o
	@echo "Unindo os arquivos..."
	g++ main.o visita.o agenda.o -o agendaDeViagens

main.o: main.cpp
	@echo "Compilando..."
	g++ -c main.cpp

visita.o : lib/visita.h visita.cpp
	g++ -c visita.cpp

agenda.o: lib/agenda.h agenda.cpp
	g++ -c agenda.cpp

run: agendaDeViagens
	@echo "Acessando a agenda de viagens do Rick..."
	@echo "Let's go, Morty!"
	./agendaDeViagens

clean:
	@echo "Limpando a agenda de viagens..."
	@echo "Oh geez, Rick!"
	rm *.o agendaDeViagens