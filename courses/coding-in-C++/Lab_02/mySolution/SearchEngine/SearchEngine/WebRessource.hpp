#ifndef WEBRESSOURCE_HPP
#define WEBRESSOURCE_HPP

#include <stdlib.h>
#include <string>

class WebRessource {
private:
	std::string address;
	std::string information;
	uint8_t ranking;
	uint8_t popularity;

public:
	WebRessource(std::string address, std::string information, uint8_t ranking, uint8_t popularity)
	{
		this->address = address;
		this->information = information;
		this->ranking = ranking;
		this->popularity = popularity;
	}

	std::string get_address()
	{
		return this->address;
	}

	std::string get_information()
	{
		return this->information;
	}

	uint8_t get_ranking()
	{
		return this->ranking;
	}

	void set_address(std::string address) {
		this->address = address;
	}

	void set_information(std::string information) {
		this->information = information;
	}

	void set_ranking(uint8_t ranking) {
		this->ranking = ranking;
	}

	void set_popularity(uint8_t popularity) {
		this->popularity = popularity;
	}
};
#endif