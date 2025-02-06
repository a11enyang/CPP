#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <sys/socket.h>

namespace HDE
{
	class SimpleSocket
	{
	private:
		int connection;
	public:
		SimpleSocket(int domain, int service, int protocol);
	};

}



#endif
