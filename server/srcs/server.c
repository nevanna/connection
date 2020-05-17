#include "new.h"


int main(int argc, char **argv)
{
	t_new new;

	new.ip_adr = NULL;
	new.port = 1234;
	new.change_fl = 0;
	ft_create_connection(&new);
	ft_close(&new);
	return(0);
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



