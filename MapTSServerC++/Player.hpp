#pragma once
#include <evpp\tcp_conn.h>

class Player {
public:
	Player(std::string login, std::string email, std::string password);
	uint32_t id;
	std::string login;
	std::string email;
	std::string password;
	const evpp::TCPConnPtr& getConnection();
	void setConnection(const evpp::TCPConnPtr& conn);
private:
	evpp::TCPConnPtr conn;
};