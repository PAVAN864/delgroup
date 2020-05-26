a.out : delgroup_server.o delgroup_client.o
	gcc delgroup_server.o delgroup_client.o
delgroup_server.o : delgroup_server.c delgroup_server.h
	gcc -c delgroup_server.c
delgroup_client.o : delgroup_client.c delgroup_server.h
	gcc -c delgroup_client.c
