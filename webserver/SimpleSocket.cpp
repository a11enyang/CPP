#include "SimpleSocket.hpp"

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol)
{
	connection = socket(domain, service, protocol);
}
