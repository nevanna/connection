#include "new.h"


int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();
	IPaddress ip;

	//fill ip struct
	//NULL - server

	//SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
	SDLNet_ResolveHost(&ip, "www.linux.org", 80);

	//client socet for only 1 client
	TCPsocket client;

	const char * http = "GET / HTTP/1.1\nHost: www.linux.org\n\n"; //if all will be ok it send to us sourse code of webpage
	client = SDLNet_TCP_Open(&ip);
	int len = ft_strlen(http);

	SDLNet_TCP_Send(client, http, len+1);
	char text[10000]; //1400 max in tcp

	//return siz eof resive

	while( SDLNet_TCP_Recv(client, text, 10000))
		printf("%s", text);
	SDLNet_TCP_Close(client);
	SDLNet_Quit();
	SDL_Quit();
}


/* проверяем через командную строку такой комбинацией
telnet 127.0.0.1 1234
команда лупбек   порт
*/

/* результат выполнения
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Hello client!
Connection closed by foreign host.
*/
