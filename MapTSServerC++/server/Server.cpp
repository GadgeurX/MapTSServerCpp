#include "Server.hpp"

Server::Server()
{
}

void Server::run()
{
	std::string addr = "0.0.0.0:9099";
	int thread_num = 4;
	evpp::EventLoop loop;
	evpp::TCPServer server(&loop, addr, "MapTSServer", thread_num);
	server.SetMessageCallback([](const evpp::TCPConnPtr& conn,
		evpp::Buffer* msg) {
			PacketProcessor::Instance()->execute(conn, packet::GetPacket(msg->data()));
		});

	server.SetConnectionCallback([](const evpp::TCPConnPtr& conn) {
		if (conn->IsConnected()) {
			LOG_INFO << "A new connection from " << conn->remote_addr();
		}
		else {
			LOG_INFO << "Lost the connection from " << conn->remote_addr();
		}
		});
	server.Init();
	server.Start();
	loop.Run();
}
