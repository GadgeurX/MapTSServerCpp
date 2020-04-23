#include "PacketProcessor.hpp"

PacketProcessor* PacketProcessor::instance = nullptr;

void register_packet(const evpp::TCPConnPtr& conn, packet::RegisterPacket* packet) {
	Game::Instance()->playerManager->registerPlayer(packet->login()->str(), packet->email()->str(), packet->password()->str());
}

void login_packet(const evpp::TCPConnPtr& conn, packet::LoginPacket* packet) {
	Game::Instance()->playerManager->loginPlayer(conn, packet->login()->str(), packet->password()->str());
}

PacketProcessor* PacketProcessor::Instance()
{
	if (PacketProcessor::instance == nullptr)
		PacketProcessor::instance = new PacketProcessor();
	return PacketProcessor::instance;
}

void PacketProcessor::execute(const evpp::TCPConnPtr& conn, const packet::Packet* packet)
{
	PacketProcessor::packets[packet->data_type()](conn, packet->data());
}

std::map<packet::PacketType, processorFunc> PacketProcessor::packets = {
	{packet::PacketType::PacketType_RegisterPacket, (processorFunc)&register_packet},
	{packet::PacketType::PacketType_LoginPacket, (processorFunc)&login_packet},
};