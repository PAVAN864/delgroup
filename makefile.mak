delgroup.exe:server1.o client.o
				gcc  server1.c client.c
server1.o:server1.c
				gcc  -c server1.c
client.o:client.c server.h
				gcc -c client.c