#include "main.hpp"
#include <cstdlib>
#include <ctime>
ft_irc::IrcServer *g_server_link = NULL;

void check_input(int argc, char **argv)
{
    if (argc != 3) {
		ft_irc::Console::log("Wrong argument"
				, ft_irc::Console::GENERAL);
		ft_irc::Console::log("Usage: ./ircserv <port> <password>"
				, ft_irc::Console::GENERAL);
		ft_irc::abort();
    }
    if (6 < std::strlen(argv[1])
			|| std::atoi(argv[1]) < 1024
			|| std::atoi(argv[1]) > 0xffff) {
		ft_irc::Console::log("Error: port must be in range [1024:65535]"
				, ft_irc::Console::GENERAL);
		ft_irc::abort();
    }
}

int main(int argc, char **argv)
{
	std::srand(std::time(0));
	signal(SIGINT, ft_irc::ft_sig_handler);
	ft_irc::Console::set_log_level(ft_irc::Console::DEBUG);
    check_input(argc, argv);
    int port = atoi(argv[1]);
	ft_irc::Console::log("Init server, port - ", port, ft_irc::Console::GENERAL);
	g_server_link = new ft_irc::IrcServer(port, argv[2]);
    g_server_link->run();
}
