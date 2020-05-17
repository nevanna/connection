#include "new.h"


int main(int argc, char **argv)
{
	t_new new;


	if (argc == 2)
		if (!(ft_atoi(argv[1]) == 2))
			ft_return("error: wrong argv");
		else
		{
			new.net_flag = 2;
			new.ip_adr = "127.0.0.1";
			new.port = 1234;
		}
	else
		new.net_flag = 0;

	ft_create_connection(&new);
	//fill ip struct
	//NULL - server
	ft_close(&new);
	return (0);
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



