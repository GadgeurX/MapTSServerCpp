#include "Player.hpp"

Player::Player(std::string login, std::string email, std::string password)
{
	this->login = login;
	this->email = email;
	this->password = password;
}

const evpp::TCPConnPtr& Player::getConnection()
{
	return this->conn;
}

void Player::setConnection(const evpp::TCPConnPtr& conn)
{
	this->conn = conn;
}
